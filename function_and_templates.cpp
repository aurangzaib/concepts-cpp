int main() {
    void a_func(int &a, int b = 2) {
        // a passed by reference(address). no copy made
        // b has default value
        a *= 2;
    }
    // functions are not first class but lambda are
    // first class --> used as func param, can be returned
    // for string or objects we should normally pass by reference
    string a = "what ever";
    void a_func2(const string &a) {

    }
    // cpp doesnt have prototypical inheritance so class needs to be created before creating object
    /*
     int aObj = { x: 'x', y: 'y' };
     is not possible in cpp
     cpp has class-based inheritance
     */

    // inline can be used for short func
    inline void a_func3() {}

    // recursion

    // function overload
    void some_func(int a, int b) {
        int c = a * b;
    }
    void some_func(float a, float b) {
        float c = a * b;
    }
    // function template
    // when logic is same for different types, we can use template
    template<typename T, typename U>
    // class can be used instead of typename
    void some_func(T a, U b, int c) {
        T d = a * b * c;
    }
    // usage of function template
    some_func<int, int, 2>(1, 2);
    some_func<int, float, 2>(1, 2.0);
    // type is not necessary when calling function
    some_func(1, 2.0);

    // namespace usage
    a::some;
    b::some;
    using a::some
    // now onwards some can be used instead of a::some

    // but if we want to use variables in namespace a, then:
    using namespace a;

    // static storage --> global variables (by default initialized to 0)
    // automatic storage --> local variables (not by default initialized)

    // arrays:
    // in cpp, size must
    int some_array[10];
    int some_array2[] = {1, 2, 3, 4, 5};

    // function and array
    some_function(some_array);
    void some_function(int an_array[]) {
        cout << an_array[2];
    }
}
