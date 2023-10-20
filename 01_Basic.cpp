#pragma once
#include <iostream>
#include <string>

// ==========================================================================================================
// Fonts
// ==========================================================================================================

// Courier New
// Source Code Pro
// Fira Code

// ==========================================================================================================
// Notes
// ==========================================================================================================

// sizeof (var):        To get size of a variable
// Precedence:          BODMAS (Bracket Order Divide Multiply Add Subtract)
// Static storage:      Global variables (default initialized to 0)
// Automatic storage:   Local variables  (default initialized to random number)
// C++ namespace:       Python module:

// ==========================================================================================================
// Initialization
// ==========================================================================================================

int a0 = 1;  // C initialization
int b0(2);   // Constructor initialization
int c0{3};   // Uniform initialization

// ==========================================================================================================
// Datatype
// ==========================================================================================================

// char         1 byte
// bool         1 byte
// int          4 byte
// long         4 byte
// float        4 byte
// int64        8 byte
// double       8 byte
// long double  8 byte
// long long    8 byte
// auto         Only on declaration. Not for function param / return type

// ==========================================================================================================
// Abbreviatins
// ==========================================================================================================

// ANSI         American National Standard Institure
// ISO          International Standard Origanization
// GNU          GNU Is Not Unix
// GCC          GNU Compiler Collection
// Binary       Machine Code / Object Code (*.o)
// Linking      Link multiple C++ files to generate one machine code
// Compile      C++ to machine code (object code)
// Loading      Load machine code into memory

// ==========================================================================================================
// Namespace
// ==========================================================================================================

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

//----------------------------------------------------------------
int main() {
    // Namespace
    int a = 3;
    std::cout << ::a;                // global
    std::cout << some_namespace::a;  // namespace
    std::cout << SN::b;              // namespace
    std::cout << a;                  // local
    std::cout << c;                  // nameless namespace

    // ==========================================================================================================
    // Post and pre increment/decrement
    // ==========================================================================================================
    int c = 0;
    c++;  // get value, then increment for next time
    ++c;  // increment, then get incremented value

    return 0;
}
