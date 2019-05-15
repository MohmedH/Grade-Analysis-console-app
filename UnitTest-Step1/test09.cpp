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

//make all10
TEST_CASE( "Test 09", "[Project01]" ) 
{
   Course C("CS", "Professional Seminar", 400, 03, "Reynolds", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C1("CS", "Professional Seminar", 401, 01, "Reed", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C2("CS", "Professional Seminar", 400, 02, "Remmel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C3("CS", "Professional Seminar", 401, 01, "Troy", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C4("CE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C5("CE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
    Dept CS;

    CS.Courses.push_back(C);
    CS.Courses.push_back(C1);
    CS.Courses.push_back(C2);
    
    CS.Courses.push_back(C3);
    CS.Courses.push_back(C4);
    CS.Courses.push_back(C5);
     
    vector<Course> sol = FindCourses(CS,"ch");
    
    REQUIRE(sol.size() == 0);
    
    sol = FindCourses(CS,"Tr");
    
    REQUIRE(sol.size() == 1);
    REQUIRE(sol[0].Number == 401);
    
    sol = FindCourses(CS,"Re");
    
    REQUIRE(sol.size() == 3);
    REQUIRE(sol[0].Section == 02);
    REQUIRE(sol[1].Section == 03);
    REQUIRE(sol[2].Section == 01);
    
     
}