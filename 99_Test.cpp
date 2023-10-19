#include <iostream>
#include <array>
#include <vector>

using namespace std;

template <typename T>
void func_vec(const vector<T> &vec) {
    cout << "Function: func_vec: " << vec.at(0) << endl;
}

template <typename T, size_t N>
void func_arr(const array<T, N> &arr) {
    cout << "Function: func_arr: " << arr.at(0) << endl;
}

void func_arr(const int *ptr_arr) {
    cout << "Function: func_arr(ptr): " << ptr_arr[0] << endl;
}


int main(){
    array  arr = {1,2,3,4,5};
    vector vec = {1,2,3,4,5};

    cout << arr.front() << endl;
    cout << arr.begin() << endl;
    cout << arr.back()  << endl;
    cout << arr.end()   << endl;

    for (const auto &iterator : vec) {
        cout << iterator << endl;
    }

    func_vec(vec);
    func_arr(arr);
    func_arr(arr.begin());

    int my_var          = 123;
    int *ptr            = &my_var; // nonconst a/d, nonconst val
    const int *ptr      = &my_var; // nonconst a/d, const val
    int *const ptr      = &my_var; // const a/d, const val
    const int *const ptr= &my_var; // const a/d, const val

}