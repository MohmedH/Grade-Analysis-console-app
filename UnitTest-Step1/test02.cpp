// <<YOUR NAME HERE>>
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #01: Grade Analysis
// 


// *****************************************************************
//
// Test cases:
// 
// *****************************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "gradeutil.h"
#include "catch.hpp"

using namespace std;

//COVERS CASE make all4/make all5
TEST_CASE( "Test 02", "[Project01]" ) 
{
    Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
    int DFW = -1;
    int N = -1;
    
    
    double r = GetDFWRate(C,DFW,N);
    
    
    REQUIRE(DFW == 127);
    REQUIRE(N == 163);
    REQUIRE(abs(r-77.914) < 0.001); 
    
  
}
TEST_CASE() 
{
    Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
    int DFW = -1;
    int N = -1;
    
    
    double r = GetDFWRate(C,DFW,N);
    
    
    REQUIRE(DFW == 1902);
    REQUIRE(N == 1933);
    REQUIRE(abs(r-98.3962) < 0.001); 
    
  
}

TEST_CASE() 
{
     Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
    
    int DFW = -1;
    int N = -1;
    
    
    double r = GetDFWRate(C,DFW,N);
    
    
    REQUIRE(DFW == 0);
    REQUIRE(N == 0);
    REQUIRE(abs(r-0.0) < 0.001); 
    
  
}

TEST_CASE() 
{
    Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    int DFW = -1;
    int N = 1;
    
    
    double r = GetDFWRate(C,DFW,N);
    
    
    REQUIRE(DFW == 0);
    REQUIRE(N == 0);
    REQUIRE(abs(r-0.0) < 0.001); 
    
  
}

