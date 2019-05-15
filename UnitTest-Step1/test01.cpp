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

//Testing Satisfactory
TEST_CASE( "Test 01", "[Project01]" ) 
{
  Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 2, 88, 0, 0, 1);
           
  REQUIRE(C.Dept == "CS");
  REQUIRE(C.Title == "Professional Seminar");
  REQUIRE(C.Number == 499);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Instructor == "Hummel");
  
  REQUIRE(C.NumA == 0);
  REQUIRE(C.NumB == 0);           
  REQUIRE(C.NumC == 0);
  REQUIRE(C.NumD == 0);
  REQUIRE(C.NumF == 0);
  
  REQUIRE(C.NumI == 2);
  REQUIRE(C.NumS == 88);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 0);
  REQUIRE(C.NumNR == 1);  
  
  REQUIRE(C.getGradingType() == Course::Satisfactory);
}

//Testing Letter
TEST_CASE( ) 
{
  Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 1, 1, 1, 1, 1, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
  REQUIRE(C.Dept == "CS");
  REQUIRE(C.Title == "Professional Seminar");
  REQUIRE(C.Number == 499);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Instructor == "Hummel");
  
  REQUIRE(C.NumA == 1);
  REQUIRE(C.NumB == 1);           
  REQUIRE(C.NumC == 1);
  REQUIRE(C.NumD == 1);
  REQUIRE(C.NumF == 1);
  
  REQUIRE(C.NumI == 0);
  REQUIRE(C.NumS == 0);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 0);
  REQUIRE(C.NumNR == 0);  
  
  REQUIRE(C.getGradingType() == Course::Letter); 
           
}

//Testing Unknown
TEST_CASE( ) 
{
  Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 0, 0, 0, 0, 0, 
           /*I,S,U,W,NR*/ 0, 0, 0, 0, 0);
    
  REQUIRE(C.Dept == "CS");
  REQUIRE(C.Title == "Professional Seminar");
  REQUIRE(C.Number == 499);
  REQUIRE(C.Section == 01);
  REQUIRE(C.Instructor == "Hummel");
  
  REQUIRE(C.NumA == 0);
  REQUIRE(C.NumB == 0);           
  REQUIRE(C.NumC == 0);
  REQUIRE(C.NumD == 0);
  REQUIRE(C.NumF == 0);
  
  REQUIRE(C.NumI == 0);
  REQUIRE(C.NumS == 0);           
  REQUIRE(C.NumU == 0);
  REQUIRE(C.NumW == 0);
  REQUIRE(C.NumNR == 0);  
  
  REQUIRE(C.getGradingType() == Course::Unknown); 
           
}

//COVERS CASE make all2
TEST_CASE(){
    
    string s = "C O M,1,0,really long course name with lots of spaces to test out the spacing,2,3,4,5,6,7,8,9,1,2,H u m mel";
    Course C = ParseCourse(s);
    
    REQUIRE(C.Title.compare("really long course name with lots of spaces to test out the spacing") == 0);
    REQUIRE(C.Dept.compare("C O M") == 0);
    REQUIRE(C.Instructor.compare("H u m mel") == 0);
    
}

TEST_CASE(){
    
    string s = " ,1,0, ,2,3,4,5,6,7,8,9,1,2, ";
    Course C = ParseCourse(s);
    
    REQUIRE(C.Title.compare(" ") == 0);
    REQUIRE(C.Dept.compare(" ") == 0);
    REQUIRE(C.Instructor.compare(" ") == 0);
    
}