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

//COVERS CASE make all7
TEST_CASE( "Test 05", "[Project01]" ) 
{
    Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
    auto G = GetGradeDistribution(C);
    
    REQUIRE(G.N == 125);
    
    REQUIRE(abs(G.PercentA - 8.8) < 0.001);
    REQUIRE(abs(G.PercentB - 9.6) < 0.001);
    REQUIRE(abs(G.PercentC - 10.4) < 0.001);
    REQUIRE(abs(G.PercentD - 26.4) < 0.001);
    REQUIRE(abs(G.PercentF - 44.8) < 0.001);
  
}

TEST_CASE() 
{
    Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
    auto G = GetGradeDistribution(C);
    
    REQUIRE(G.N == 995);
    REQUIRE(abs(G.PercentA - 0.50251) < 0.001);
    REQUIRE(abs(G.PercentB - 1.005025) < 0.001);
    REQUIRE(abs(G.PercentC - 1.608040) < 0.001);
    REQUIRE(abs(G.PercentD - 30.15075) < 0.001);
    REQUIRE(abs(G.PercentF - 66.73366) < 0.001);
    
  
}

//TESTING SAITISFACOTRY
TEST_CASE(){
    
      Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
    
    auto G = GetGradeDistribution(C);
    
     REQUIRE(G.N == 0);
    
    REQUIRE(abs(G.PercentA - 0.0) < 0.001);
    REQUIRE(abs(G.PercentB - 0.0) < 0.001);
    REQUIRE(abs(G.PercentC - 0.0) < 0.001);
    REQUIRE(abs(G.PercentD - 0.0) < 0.001);
    REQUIRE(abs(G.PercentF - 0.0) < 0.001);
    
    
}

//TESTING UNKNOWN
TEST_CASE(){
    
      Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
    auto G = GetGradeDistribution(C);
    
     REQUIRE(G.N == 0);
    
    REQUIRE(abs(G.PercentA - 0.0) < 0.001);
    REQUIRE(abs(G.PercentB - 0.0) < 0.001);
    REQUIRE(abs(G.PercentC - 0.0) < 0.001);
    REQUIRE(abs(G.PercentD - 0.0) < 0.001);
    REQUIRE(abs(G.PercentF - 0.0) < 0.001);
    
    
}