/*
 for object, strings and array prefer to pass as const reference
 */
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

    // function overload
    void some_func(int a, int b) {
        int c = a * b;
    }
    void some_func(float a, float b) {
        float c = a * b;
    }

    // namespace usage
    a::some;
    b::some;
    using a::some
    // now onwards some can be used instead of a::some

    // but if we want to use variables in namespace a, then:
    using namespace a;

    // static storage --> global variables (default initialized to 0)
    // automatic storage --> local variables (not default initialized)
}
