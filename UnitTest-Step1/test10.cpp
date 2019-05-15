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

//..
TEST_CASE( "Test 10", "[Project01]" ) 
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
    
   Course C4("CE", "Professional Seminar", 362, 01, "Rey", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C5("CE", "Professional Seminar", 400, 02, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C6("IE", "Professional Seminar", 400, 01, "Reed", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C7("IE", "Professional Seminar", 362, 01, "Rey", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C8("IE", "Professional Seminar", 500, 01, "Troy", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C9("ChemE", "Professional Seminar", 499, 01, "Keller", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C10("ChemE", "Professional Seminar", 501, 01, "Reynolds", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C11("ChemE", "Professional Seminar", 499, 01, "Telly", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C12("T", "Professional Seminar", 502, 01, "Hummel", 
           /*A-F*/ -5, -10, -16, -300, -664, 
           /*I,S,U,W,NR*/ 0, 0, 2, -938, 1);
    
   Course C13("T", "Professional Seminar", 200, 01, "Akins", 
           /*A-F*/ -5, -10, -16, -300, -664, 
           /*I,S,U,W,NR*/ 0, 0, 2, -938, -1);
    
    Dept CS;
    Dept CE;
    Dept IE;
    Dept ChemE;
    Dept T;
    
    
    CS.Courses.push_back(C);
    CS.Courses.push_back(C1);
    CS.Courses.push_back(C2);
    
    CE.Courses.push_back(C3);
    CE.Courses.push_back(C4);
    CE.Courses.push_back(C5);
    
    IE.Courses.push_back(C6);
    IE.Courses.push_back(C7);
    IE.Courses.push_back(C8);
    
    ChemE.Courses.push_back(C9);
    ChemE.Courses.push_back(C10);
    ChemE.Courses.push_back(C11);
    
    T.Courses.push_back(C12);
    T.Courses.push_back(C13);
    
    
    College Engine;
    
    Engine.Depts.push_back(CS);
    Engine.Depts.push_back(CE);
    Engine.Depts.push_back(IE);
    Engine.Depts.push_back(ChemE);
    Engine.Depts.push_back(T);
   
    vector<Course> sol = FindCourses(Engine,101);
    
    REQUIRE(sol.size() == 0);
    
    sol = FindCourses(Engine, 200);
    
    REQUIRE(sol.size() == 1);
    REQUIRE(sol[0].Number == 200);
    
    sol = FindCourses(Engine, 362);
    
    REQUIRE(sol.size() == 2);
    REQUIRE(sol[0].Dept.compare("CE") == 0);
    REQUIRE(sol[1].Dept.compare("IE") == 0);
    
    sol = FindCourses(Engine, 400);
    
    REQUIRE(sol.size() == 4);
    
    REQUIRE(sol[0].Dept.compare("CE") == 0);
    REQUIRE(sol[1].Dept.compare("CS") == 0);
    REQUIRE(sol[2].Dept.compare("CS") == 0);
    REQUIRE(sol[3].Dept.compare("IE") == 0);
    
    REQUIRE(sol[0].Section == 02);
    REQUIRE(sol[1].Section == 02);
    REQUIRE(sol[2].Section == 03);
    REQUIRE(sol[3].Section == 01);
       
}

TEST_CASE() 
{
   Course C("CS", "Professional Seminar", 400, 03, "Remmel", 
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
    
   Course C4("CE", "Professional Seminar", 362, 02, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C5("CE", "Professional Seminar", 400, 02, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C6("IE", "Professional Seminar", 400, 01, "Reed", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C7("IE", "Professional Seminar", 362, 03, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C8("IE", "Professional Seminar", 500, 01, "Troy", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C9("ChemE", "Professional Seminar", 499, 01, "Keller", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C10("ChemE", "Professional Seminar", 501, 01, "Reynolds", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C11("ChemE", "Professional Seminar", 499, 01, "Telly", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C12("T", "Professional Seminar", 502, 01, "Hummel", 
           /*A-F*/ -5, -10, -16, -300, -664, 
           /*I,S,U,W,NR*/ 0, 0, 2, -938, 1);
    
   Course C13("T", "Professional Seminar", 200, 01, "Akins", 
           /*A-F*/ -5, -10, -16, -300, -664, 
           /*I,S,U,W,NR*/ 0, 0, 2, -938, -1);
    
    Dept CS;
    Dept CE;
    Dept IE;
    Dept ChemE;
    Dept T;
    
    
    CS.Courses.push_back(C);
    CS.Courses.push_back(C1);
    CS.Courses.push_back(C2);
    
    CE.Courses.push_back(C3);
    CE.Courses.push_back(C4);
    CE.Courses.push_back(C5);
    
    IE.Courses.push_back(C6);
    IE.Courses.push_back(C7);
    IE.Courses.push_back(C8);
    
    ChemE.Courses.push_back(C9);
    ChemE.Courses.push_back(C10);
    ChemE.Courses.push_back(C11);
    
    T.Courses.push_back(C12);
    T.Courses.push_back(C13);
    
    
    College Engine;
    
    Engine.Depts.push_back(CS);
    Engine.Depts.push_back(CE);
    Engine.Depts.push_back(IE);
    Engine.Depts.push_back(ChemE);
    Engine.Depts.push_back(T);
   
    vector<Course> sol = FindCourses(Engine,"Ak");
    
    REQUIRE(sol.size() == 1);
    
    sol = FindCourses(Engine, "Wa");
    REQUIRE(sol.size() == 0);
    
    sol = FindCourses(Engine, "Hu");
    
    REQUIRE(sol.size() == 4);
    
    REQUIRE(sol[0].Number == 362);
    REQUIRE(sol[0].Section == 02);
    REQUIRE(sol[1].Number == 362);
    REQUIRE(sol[1].Section == 03);
    REQUIRE(sol[2].Number == 400);
    REQUIRE(sol[2].Section == 02);
    REQUIRE(sol[3].Number == 502);
    REQUIRE(sol[3].Section == 01);
    
    sol = FindCourses(Engine, "Re");
    
    REQUIRE(sol.size() == 5);
    
    REQUIRE(sol[0].Instructor.compare("Reed") == 0);
    REQUIRE(sol[1].Instructor.compare("Reed") == 0);
    REQUIRE(sol[2].Instructor.compare("Remmel") == 0);
    REQUIRE(sol[3].Instructor.compare("Remmel") == 0);
    REQUIRE(sol[4].Instructor.compare("Reynolds") == 0);
    
    REQUIRE(sol[0].Number == 400);
    REQUIRE(sol[1].Number == 401);
    REQUIRE(sol[2].Number == 400);
    REQUIRE(sol[3].Number == 400);
    REQUIRE(sol[4].Number == 501);

    REQUIRE(sol[0].Section == 01);
    REQUIRE(sol[1].Section == 01);
    REQUIRE(sol[2].Section == 02);
    REQUIRE(sol[3].Section == 03);
    REQUIRE(sol[4].Section == 01);
        
       
}