/*test01.cpp*/

//
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

TEST_CASE( "Test 03", "[Project01]" ) 
{
    Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
  Course C2("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
        
    Dept D("CS");
      
    D.Courses.push_back(C);
    D.Courses.push_back(C2);
    
    int DFW = -1;
    int N = -1;
    
    
    double r = GetDFWRate(D,DFW,N);
    
    
    REQUIRE(DFW == 127);
    REQUIRE(N == 163);
    REQUIRE(abs(r-77.914) < 0.001); 
    
  
}

TEST_CASE( ) 
{
  Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
    
    
    Dept D("CS");
      
    D.Courses.push_back(C);
    
    int DFW = -1;
    int N = -1;
    
    
    double r = GetDFWRate(D,DFW,N);
    
    
    REQUIRE(DFW == 0);
    REQUIRE(N == 0);
    REQUIRE(abs(r-0.0) < 0.001); 
    
}

