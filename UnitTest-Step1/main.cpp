/*main.cpp*/

//
// Prof. Joe Hummel
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 
// References:
//   Unit testing based on Catch framework: https://github.com/catchorg/Catch2
//   Catch tutorial: https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top
//   install:     sudo apt-get install catch
//   compilation: g++ -g -std=c++11 -Wall main.cpp test*.cpp api.cpp -o test.exe
//   execution:   ./test.exe
//


// let Catch provide main():
#define CATCH_CONFIG_MAIN

// gain access to Catch framework:
#include "catch.hpp"


// *****************************************************************
//
// Test cases:
// 
// *****************************************************************

//
// test cases are given in separate C++ files, e.g. test01.cpp, 
// test02.cpp, etc.  These files are compiled and linked in as
// needed.  This way you can run tests one at a time, or all
// together.
//
