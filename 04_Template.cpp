#include <iostream>
using namespace std;

// ==========================================================================================================
// Template
// ==========================================================================================================

template <typename T, typename U>
auto multiplier(const T &a, const U &b) {
  return a * b;
}

template <class T, class U>
auto divider(const T &a, const U &b) {
  return a / b;
}

//----------------------------------------------------------------
int main() {
  auto result_int       = multiplier(2, 3);
  auto result_double    = multiplier(2, 3.123);
  auto result_double2   = multiplier<int, double>(2, 3.123);

  result_int            = divider(2, 3);
  result_double         = divider(2, 3.123);
  result_double2        = divider<int, double>(2, 3.123);

  return 0;
}