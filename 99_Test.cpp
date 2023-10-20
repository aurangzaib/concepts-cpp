#include <iostream>
#include <vector>
#include <array>

using namespace std;
void func_abc(const vector<int> &vec, const string str) {
    // element
    cout << vec.at(1) << endl;
    cout << str << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    func_abc((vector<int>){1, 2, 3, 4}, "Hello World");
}