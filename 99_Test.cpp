#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <list>

using namespace std;

template <typename T>
void tester(T func) {
    int num2 = 34;
    func(num2);
}
int main() {
    int num1 = 33;
    // Lamda expression
    auto func = [&num1](int num2) -> void {
        cout << num1 << endl;
        cout << num2 << endl;
    };

    tester(func);
}