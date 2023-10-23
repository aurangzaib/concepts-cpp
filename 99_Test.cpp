#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <list>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    tuple<int, double, string> tpl = {3, 6.3, "hello"};
    cout << std::get<2>(tpl);
    cout << std::tuple_size<decltype(tpl)>::value;

}