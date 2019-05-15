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

TEST_CASE( "Test 04", "[Project01]" ) 
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
    
    College G("Engineering");
    
    G.Depts.push_back(D);
    
    int DFW = -1;
    int N = -1;
    
    
    double r = GetDFWRate(G,DFW,N);
    
    
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
    
    College G;
    
    G.Depts.push_back(D);
    
    int DFW = -1;
    int N = -1;
    
    
    double r = GetDFWRate(G,DFW,N);
    
    
    REQUIRE(DFW == 0);
    REQUIRE(N == 0);
    REQUIRE(abs(r-0.0) < 0.001); 
    
}

TEST_CASE(){
    
   Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C1("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C2("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C3("CE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C4("CE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C5("CE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C6("IE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C7("IE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C8("IE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C9("ChemE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C10("ChemE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C11("ChemE", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
   Course C12("T", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ -5, -10, -16, -300, -664, 
           /*I,S,U,W,NR*/ 0, 0, 2, -938, 1);
    
    Course C13("T", "Professional Seminar", 499, 01, "Hummel", 
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
    
    
    int DFW = -1;
    int N = -1;
    
    double r = GetDFWRate(Engine,DFW,N);
    
    REQUIRE(N == 12576);
    
    REQUIRE(DFW == 12174);
    
    REQUIRE(abs(r-96.803435) < 0.001); 
      
}

TEST_CASE(){
    
    Course C("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 11, 12, 13, 33, 56, 
           /*I,S,U,W,NR*/ 2, 88, 74, 38, 1);
    
   Course C1("CS", "Professional Seminar", 499, 01, "Hummel", 
           /*A-F*/ 5, 10, 16, 300, 664, 
           /*I,S,U,W,NR*/ 0, 0, 2, 938, 1);
    
    Dept CS;
    
    CS.Courses.push_back(C);
    CS.Courses.push_back(C1);
    
    College Engine;
    
    Engine.Depts.push_back(CS);
    
    int DFW = -1;
    int N = -1;
    
    double r = GetDFWRate(Engine,DFW,N);
    
    REQUIRE(N == 2096);
    
    REQUIRE(DFW == 2029);
    
    REQUIRE(abs(r-96.803435) < 0.001); 
      
}