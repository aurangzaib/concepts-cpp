
#include <iostream>
/*
- Function is a not first class citizen (not passable, not returnable). Use Lambda

*/

using namespace std;
int a = 4;

void func(){
  int a = 4;
  cout << "value: " << ::a << endl;

}

int main() {
  int a = 3;
  int *ptr = &a;
  func();
}

