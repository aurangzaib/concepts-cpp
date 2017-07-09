// resources used:
//
// back_insertor --> http://www.cplusplus.com/reference/iterator/back_inserter/
// back_insertor iterator is a type of output iterator
// allows to insert element in the end of container instead of replacing the element (e.g. in std::copy)
// using = expands the container

// iterator --> http://en.cppreference.com/w/cpp/iterator/iterator
// changes are implemented to remove the element from back of the container.
//
// http://www.cplusplus.com/reference/utility/pair/pair/
// pair --> couples together a pair of values. values can be of different types -- a tuple
//
// https://stackoverflow.com/questions/3413470/what-is-stdmove-and-when-should-it-be-used
// std::move is used instead of std::copy
//
// http://www.cprogramming.com/tutorial/typedef.html
// typedef
//

#include <algorithm>
#include <iostream>
#include <vector>

template<class T>
class iterator : public std::iterator<std::input_iterator_tag, void, void, void, void> {
public:
    T *container;
    // default ctor
    // nullptr
    iterator() : container(0) {}
    // copy ctor
    explicit iterator(T &c) : container(&c) {}
    // operators overloading
    typename T::value_type operator*() {
        // get last element of vector
        auto value(container->back());
        // remove last element
        container->pop_back();
        return value;
    }
    iterator &operator=(typename T::const_reference value) { return *this; }
    iterator operator++(int) { return *this; }
};

// check if two containers are equal or not
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

// functor to sort std::pair by first element.
// first element in our case is container2 elements
//
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
//
// Performs a parallel sort of the ranges [keys_first, keys_last) and
// [values_first, values_last), preserving the ordering relation between
// values and keys. Sends key and value output to keys_out and values_out.
//
// This works by building a vector of std::pairs, sorting them by the key
// element, then returning the sorted pairs as two separate sequences.

template<typename A, typename B, typename C, typename X, typename Y, typename Z>
void parallel_sort(C &container2_begin,
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
// debug the containers
template<typename A, typename B>
void debug_containers(const std::vector<A> &container1, const std::vector<B> &container2) {
    for (unsigned int i = 0; i < container2.size(); ++i)
        std::cout << container2[i] << ": "
                  << container1[i] << std::endl;
}
int main() {

    // containers
    std::vector<std::string> container1{"zero", "three", "one", "two"};
    std::vector<int> container2{0, 7, 1, 3};

    // input iterator begin
    iterator<std::vector<std::string> > container1_begin(container1);
    iterator<std::vector<int> > container2_begin(container2);

    // input iterator end
    iterator<std::vector<int> > container2_end;
    // parallel sort
    parallel_sort<int, std::string>(container2_begin,
                                    container2_end,
                                    container1_begin,
                                    std::back_inserter(container2),
                                    std::back_inserter(container1));

    // debugging
    debug_containers(container1, container2);
    return 0;
}