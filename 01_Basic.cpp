#pragma once
#include <iostream>
#include <string>

/* For best results, use Courier New fonts */

// ================================================================
// General
// ================================================================
// sizeof (var): To get size of a variable
// Precedence:   BODMAS (Bracket Order Divide Multiply Add Subtract)

// ================================================================
// Initialization
// ================================================================

int a0=1;    // C initialization
int b0(2);   // Constructor initialization
int c0{3};   // Uniform initialization

// ================================================================
// Datatype
// ================================================================

// char         1 byte
// bool         1 byte
// int          4 byte
// long         4 byte
// float        4 byte
// int64        8 byte
// double       8 byte
// long double  8 byte
// long long    8 byte
// auto         Only on declaration. Not for function argument/return type

// ================================================================
// Abbreviatins
// ================================================================

// ANSI         American National Standard Institure
// ISO          International Standard Origanization
// GNU          GNU Is Not Unix
// GCC          GNU Compiler Collection
// Binary       Machine Code / Object Code (*.o)
// Compile      C++ to machine code (object code)
// Linking      Link multiple C++ files to generate one machine code
// Loading      Load machine code into memory

// ================================================================
// Namespace
// ================================================================

// Global namespace
int a = 0;
// Custom namespace
namespace some_namespace {
int a = 1;
int b = 2;
}  // namespace some_namespace
// Anonymous namespace
namespace {
int c = 33;
}
// Alias namespace
namespace SN = some_namespace;

// ================================================================
// Important Libraries
// ================================================================

// iostream
// string
//

// ================================================================
// Main
// ================================================================

int main() {
  // Namespace
  int a = 3;
  std::cout << ::a;
  std::cout << some_namespace::a;
  std::cout << SN::b;
  std::cout << a;
  std::cout << c;

  std::string as = "where are your";
  std::cout << as << std::endl;
  return 0;
}
