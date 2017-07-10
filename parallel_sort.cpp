// resources used:
//
// back_insertor --> http://www.cplusplus.com/reference/iterator/back_inserter/
// back_insertor iterator is a type of output iterator
// allows to insert element in the end of container instead of replacing...
// ...the element (e.g. in std::copy) using = expands the container
//
// changes are implemented to remove the element from back of the container.
// iterator --> http://en.cppreference.com/w/cpp/iterator/iterator
//
// pair --> couples together a pair of values. values can be of different types -- a tuple
// http://www.cplusplus.com/reference/utility/pair/pair/
//
// std::move is used instead of std::copy
// https://stackoverflow.com/questions/3413470/what-is-stdmove-and-when-should-it-be-used
//
// typedef
// http://www.cprogramming.com/tutorial/typedef.html
//
// using container value_type
// https://stackoverflow.com/questions/8073052/using-a-templated-parameters-value-type
//
#include <algorithm>
#include <iostream>
#include <vector>

/*
 extend stl iterator
 '* ++ =' operators overloaded
 '*' operator pulls the element from back of container
 */
template<class T>
class iterator : public std::iterator<std::input_iterator_tag, void, void, void, void> {
public:
    T *container;
    // default ctor
    // nullptr
    iterator() : container(0) {}
    // copy ctor
    explicit iterator(T &c) : container(&c) {}
    // * operator overloaded
    // auto can be used instead of 'typename T::value_type' in C++14
    // C++11 doesn't allow return type to be auto
    //
    // pop_back doesn't return value
    // so we get the value using vector_ptr->back then use vector_ptr->pop_back
    // https://github.com/godotengine/godot/issues/3763
    typename T::value_type operator*() {
        // get last element of vector
        auto value(container->back());
        // remove last element
        container->pop_back();
        return value;
    }
    // = operator overloaded
    iterator &operator=(typename T::const_reference value) { return *this; }
    // ++ operator overloaded
    iterator operator++(int) { return *this; }
};

/*
 * function
 check if two containers are equal or not
 */
template<typename T>
bool is_equal(const iterator<T> &a, const iterator<T> &b) {
    // either default ctor or empty container
    if (!a.container) {
        return !b.container || b.container->empty();
    } else if (!b.container) {
        return !a.container || a.container->empty();
    } else {
        // if a and b are not empty, then they should be equal
        return a.container == b.container;
    }
}

/*
 functor
 sort std::pair by first element.
 first element in our case is container2 elements
 */
template<typename A, typename B>
struct comparator {
    // define a type
    typedef const std::pair<A, B> &container_pair;
    // comparison
    bool operator()(container_pair a, container_pair b) {
        // ascending order
        return a.first < b.first;
    }
};

/*
 function
 pair contains container1 and container2
 un-pair the pair to get container1 and container2 separately
 */
template<typename A, typename B, typename Y, typename Z>
void un_pair(std::vector<std::pair<A, B> > pair, Y container2_out, Z container1_out) {
    for (auto i = pair.begin(); i != pair.end(); ++i) {
        // append values in container2_out and container1_out
        *container2_out = std::move(i->first);
        *container1_out = std::move(i->second);
        // increment address
        container2_out++;
        container1_out++;
    }
}
/*
  function
  sort the container1 and container2
  make a pair of container2 and container1 (pair of vector) using std::pair
  move elements from container1 and container2 to the pair
  sort the pair based on container2 using std::sort with custom comparator functor
 */
template<typename A, typename B, typename C, typename X, typename Y, typename Z>
void sort(C &container2_begin,
          C &container2_end,
          X &container1_begin,
          Y container2_out,
          Z container1_out) {

    // create a custom type: a vector of pairs
    typedef std::vector<std::pair<A, B> > container_pairs;

    // create a vector of pair of both containers
    container_pairs pair;

    // append vector with a pair of keys and values
    while (!is_equal(container2_begin, container2_end)) {
        // moving elements from container2 and container1 to pair
        // in the end, container2 and container1 will be empty
        pair.push_back({std::move(*container2_begin++), std::move(*container1_begin++)});
    }

    // sort the pair based on the comparator
    std::sort(pair.begin(), pair.end(), comparator<A, B>());

    // separate the container1 and container2 from the pair
    un_pair(pair, container2_out, container1_out);
}
/*
   function
   debug elements of containers after sorting
 */
template<typename A, typename B>
void debug_containers(const std::vector<A> &container1, const std::vector<B> &container2) {
    for (const auto c:container2) std::cout << c << " ";
    std::cout << std::endl;
    for (const auto c:container1) std::cout << c << " ";
}
int main() {

    // containers
    std::vector<std::string> container1{"nicely", "be", "this", "arranged", "should"};
    std::vector<int> container2{100, 3, 0, 7, 1};

    // input iterator begin
    iterator<std::vector<std::string> > container1_begin(container1);
    iterator<std::vector<int> > container2_begin(container2);

    // input iterator end
    iterator<std::vector<int> > container2_end;
    // parallel sort
    sort<int, std::string>(container2_begin,
                           container2_end,
                           container1_begin,
                           std::back_inserter(container2),
                           std::back_inserter(container1));

    // debugging
    debug_containers(container1, container2);
    return 0;
}