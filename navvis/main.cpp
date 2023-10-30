#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <limits>
#include <stdint.h>

/*************** Random number generation *******************/
// Taken from OpenCV
/*
 description:
  define a type CvRNG as uint64
 */
typedef uint64_t CvRNG;
#define CV_RNG_COEFF 4164903690U
/*
 description:
 if -1 is param, return range of int64_t -1
 else return the param casted as uint64_t
 */
inline CvRNG cvRNG(int64_t seed = -1) {
    CvRNG rng = seed ? (uint64_t) seed : (uint64_t) (int64_t) -1;
    return rng;
}
/* Return random 32-bit unsigned integer: */
inline unsigned cvRandInt(CvRNG *rng) {
    uint64_t temp = *rng;
    temp = (uint64_t) (unsigned) temp * CV_RNG_COEFF + (temp >> 32);
    *rng = temp;
    return (unsigned) temp;
}
/* Returns random floating-point number between 0 and 1: */
inline double cvRandReal(CvRNG *rng) {
    return cvRandInt(rng) * 2.3283064365386962890625e-10 /* 2^-32 */;
}
/**************************************************************/
/*
 description:
 class SomeThing has 1 int data member.
 it overloads () operator to return a random number of type size_t
 */
template<class T>
class SomeThing {
public:
    /*
     description:
     ctor
     */
    SomeThing(int _z) : z(_z) {}
    /*
    description:
    overloads () operator
    returns random number
    random number --> random float number (0.0 to 1.0) multiplied by range of UINT32_MAX, casted as size_t
    where float random number is generated using range of rng1
    */
    size_t operator()(T x) const {
        union {
            T a;
            size_t b;
        } u;
        u.b = 0;
        u.a = x;
        CvRNG rng1 = cvRNG(z * (z + 1) + u.b);
        return (size_t) (cvRandReal(&rng1) * (double) (UINT32_MAX));
    }
private:
    int z;
};

template<class T, class H=SomeThing<T> >
class SomeClass {
public:
    /*
     description:
     ctor
     no default ctor provided
     no copy ctor provided
     */
    SomeClass(int nb, int nh);
    /*
     dtor
    */
    ~SomeClass();
    /*
     member func
     return type: void
     */
    void c();
    /*
     member func
     return type: void
     */
    void f(const T &x);
    /*
     const member func
     return type: bool
    */
    bool g(const T &x) const;
    /*
     const member func
     return type: bool
    */
    bool h() const;
    /*
     const member func
     return type: size_t
    */
    size_t u() const;
private:
    unsigned char *arr_;
    int l_;
    int c_;
    size_t b_;
    std::vector<H> ff;
};

/*
 description:
 class SomeClass has 5 data members:
 	arr_ 	-->
 	l_	 	-->
 	c_	 	-->
 	b_	 	--> used as a divisor of remainder operator
 	ff	 	-->
 */

#include <cstring>

/*
 description:
 ctor
 private data members are initialized
 arr_                               --> dynamically allocated of size l_
 arr_                               --> populated using member function c
 ff.push_back(H(i))                 --> property z in vector ff is populated using loop counter
                                    --> H(i) creates an instance of SomeThing with z=1
 */
template<class T, class H>
SomeClass<T, H>::SomeClass(int nb, int nh)
        : l_(0), c_(0), arr_(0) {
    b_ = nb;
    l_ = nb / 8 + 1;
    arr_ = new unsigned char[l_];
    c();
    for (int i = 1; i <= nh; i++)
        ff.push_back(H(i));
    /*
    on loop completion:
    ff has size nh
    ff contains nh number of instances of class SomeThing with property z ranging from 1 to nh
    */
}
/*
 description:
 dtor                               --> release memory of dynamically allocated array arr_
 */
template<class T, class H>
SomeClass<T, H>::~SomeClass() {
    if (arr_)
        delete[] arr_;
}
/*
 description:

 memset(::)                         --> set n bytes of arr_ to 0
 where number of bytes              --> sizeof(unsigned char) * l_
 where sizeof(unsigned char)        --> 1
 c_                                 --> tells how many times arr_ has been accessed
 c_ = 0                             --> resets the count of "number for times arr_ is accessed"
 */
template<class T, class H>
void SomeClass<T, H>::c() {
    memset(arr_, 0, sizeof(unsigned char) * l_);
    c_ = 0;
}
/*
 description:
 loop over vector ff
 b_                                 --> nb
 ff[i]                              --> get value  ranging from 1 to nh
 ff[i](x)                           --> generates random int number
 ff[i](x) % b_                      --> remainder of random number and b_
 e.g. if x=100, (ff[i](x) % b_)     --> returns 27,3,32,15,19,11,23,23 on loop completion
 key/8                              --> because arr_ is 1/8th of ff size (i.e. l_ = nb / 8 + 1)
 1 << (key % 8)                     --> right shift (key % 8) by 1. e.g. if (key%8) is 3, (1 << key%8) is 7
 |=                                 --> bitwise OR arr_[key/8] with result of (unsigned char) (1 << (key % 8))
 */
template<class T, class H>
void SomeClass<T, H>::f(const T &x) {
    for (size_t j = 0; j < ff.size(); j++) {
        auto f = ff[j](x);
        auto fg = ff[j](x) % b_;
        size_t key = ff[j](x) % b_;
        arr_[key / 8] |= (unsigned char) (1 << (key % 8));
    }
    c_++;
}
/*
 description:
 loop over vector ff
 assign remainder of ff[j](x) and b_ to key
 z +=                               --> increment z by 1
                                    --> if key/8th element of arr_ and (unsigned char) (1 << (key % 8)) are both 1

                                    --> & is used to check if both operands are 1
 */
template<class T, class H>
bool SomeClass<T, H>::g(const T &x) const {
    size_t z = 0;
    for (size_t j = 0; j < ff.size(); j++) {
        size_t key = ff[j](x) % b_;
        z += (arr_[key / 8] & (unsigned char) (1 << (key % 8))) > 0 ? 1 : 0;
    }
    return (z == ff.size());
}
/*
 description:
 returns false                      --> if ::f(params) is not called once
                                    --> i.e. arr_ is not accessed

 returns true                       --> if ::f(params) has been called at least once
                                    --> i.e. arr_ is accessed at least once
 */
template<class T, class H>
bool SomeClass<T, H>::h() const {
    return (u() == 0);
}
/*
 description:
 returns c_                         --> tells how many times arr_ is accessed
 */
template<class T, class H>
size_t SomeClass<T, H>::u() const {
    return c_;
}

template
class SomeThing<int>;

template
class SomeClass<int>;
// ...

int main() {
    SomeClass<int> a(32, 8);
    a.f(2333);
}