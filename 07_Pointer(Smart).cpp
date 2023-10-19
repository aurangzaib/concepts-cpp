#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <array>

using namespace std;

// ================================================================
// Link
// ================================================================
// https://learn.microsoft.com/en-us/cpp/cpp/pointers-cpp?view=msvc-170
// https://cplusplus.com/reference/memory/unique_ptr
// https://en.cppreference.com/w/cpp/memory

// ================================================================
// Unique pointer (C++ Pointer)
// ================================================================
void unique_pointer() {
  // RAII: Resource Acquisition is Initialization
  // It has automatic deletion
  int var = 123;
  unique_ptr<int> ptr(new int{var});
  cout << *ptr << endl;
  cout << ptr << endl;
}

// ================================================================
// Shared pointer (C++ Pointer)
// ================================================================

// ================================================================
// Weak pointer (C++ Pointer)
// ================================================================

//-------------------------------------------------------------------
int main() {
  unique_pointer();
  return 0;
}