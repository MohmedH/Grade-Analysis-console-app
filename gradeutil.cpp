/*gradeutil.cpp*/
 
//
// Prof. Joe Hummel
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #02: GradeUtil API (Solution)
// 
 
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
 
#include "gradeutil.h"
 
using namespace std;
 
 
//
// API:
//
 
// 
// ParseCourse:
//
// Parses a CSV (comma-separated values) line into a Course
// object, which is then returned.  The given line must have
// the following format:
//
//   Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
//
// Example:
//   BIOE,101,01,Intro to Bioengineering,22,8,2,1,0,1,0,0,0,5,Eddington
//
// Note the lack of spaces, except perhaps in the title.
// If the given line does not have this format, the behavior 
// of the function is undefined (it may crash, it may throw
// an exception, it may return).
//
Course ParseCourse(string csvline)
{
  Course  course;
  string  value;
 
  stringstream  ss(csvline);
   
  // format: Dept,Number,Section,Title,A,B,C,D,F,I,NR,S,U,W,Instructor
   
  getline(ss, course.Dept, ',');
 
  getline(ss, value, ',');
  course.Number = stoi(value);
  getline(ss, value, ',');
  course.Section = stoi(value);
 
  getline(ss, course.Title, ',');
 
  getline(ss, value, ',');
  course.NumA = stoi(value);
  getline(ss, value, ',');
  course.NumB = stoi(value);
  getline(ss, value, ',');
  course.NumC = stoi(value);
  getline(ss, value, ',');
  course.NumD = stoi(value);
  getline(ss, value, ',');
  course.NumF = stoi(value);
 
  getline(ss, value, ',');
  course.NumI = stoi(value);
  getline(ss, value, ',');
  course.NumNR = stoi(value);
  getline(ss, value, ',');
  course.NumS = stoi(value);
  getline(ss, value, ',');
  course.NumU = stoi(value);
  getline(ss, value, ',');
  course.NumW = stoi(value);
 
  getline(ss, course.Instructor, ',');
 
  //
  // done, return course object:
  //
  return course;
}
 
//Dept ParseDept(string name, vector<string> csvlines)
//{
//  Dept dept;
//  
//  return dept;
//}
//
//College ParseCollege(string name, vector<string> csvlines)
//{
//  College college;
//  
//  return college;
//}
 
 
//
// GetDFWRate:
//
// Returns the DFW rate as a percentage for a given course, 
// department, or college.  For a course whose grading type 
// is defined as Course::Letter, the DFW rate is defined as
// 
//   # of D grades + F grades + Withdrawals
//   -------------------------------------- * 100.0
//   # of A, B, C, D, F grades + Withdrawls
//
// The numerator is returned via the reference parameter DFW;
// the denominator is returned via the reference parameter N.
// If the course grading type is not Course::Letter, the DFW
// rate is 0.0, and parameters DFW and N are set to 0.  
//
// When computed for a dept or college, all courses of type 
// Course::Letter are considered in computing an overall DFW 
// rate for the dept or college.  The reference parameters 
// DFW and N are also computed across the dept or college.
//
double GetDFWRate(const Course& c, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
   
  //
  // how was course graded?  If not a letter, then cannot compute
  // DFW rate, so return 0.0:
  //
  Course::GradingType grading = c.getGradingType();
     
  if (grading != Course::Letter)
    return 0.0;
       
  //
  // we have letter grades (at least 1), so compute DFW rate:
  //
  DFW = c.NumD + c.NumF + c.NumW;
  N   = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW;
   
  if (N == 0) // just in case, guard against divide by 0:
    return 0.0;
     
  return (static_cast<double>(DFW) / static_cast<double>(N)) * 100.0;
}
 
double GetDFWRate(const Dept& dept, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
   
  for (const Course& c : dept.Courses)
  {
    if (c.getGradingType() != Course::Letter)
      continue;  // skip
     
    // course had letter grades, so include in DFW calculation:
    DFW += (c.NumD + c.NumF + c.NumW);
    N   += (c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW);
  }
   
  if (N == 0) // just in case, guard against divide by 0:
    return 0.0;
     
  return (static_cast<double>(DFW) / static_cast<double>(N)) * 100.0;
}
 
double GetDFWRate(const College& college, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
   
  for (const Dept& dept : college.Depts)
  {
    for (const Course& c : dept.Courses)
    {
      if (c.getGradingType() != Course::Letter)
        continue;  // skip
     
      // course had letter grades, so include in DFW calculation:
      DFW += (c.NumD + c.NumF + c.NumW);
      N   += (c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW);
    }
  }
    
  if (N == 0) // just in case, guard against divide by 0:
    return 0.0;
     
  return (static_cast<double>(DFW) / static_cast<double>(N)) * 100.0;
}

double GetDFWRate(const map<string,Dept> &v, int& DFW, int& N)
{
  DFW = 0;
  N   = 0;
   
  for (auto& dept : v)
  {
    for (const Course& c : dept.second.Courses)
    {
      if (c.getGradingType() != Course::Letter)
        continue;  // skip
     
      // course had letter grades, so include in DFW calculation:
      DFW += (c.NumD + c.NumF + c.NumW);
      N   += (c.NumA + c.NumB + c.NumC + c.NumD + c.NumF + c.NumW);
    }
  }
    
  if (N == 0) // just in case, guard against divide by 0:
    return 0.0;
     
  return (static_cast<double>(DFW) / static_cast<double>(N)) * 100.0;
}  

 
 
//
// GetGradeDistribution
//
// Returns an object containing the grade distribution for a given
// course, dept or college.  For a course whose grading type is
// defined as Course::Letter, the grade distribution is defined by
// the following values:
//
//   N: the # of A, B, C, D, F grades
//   NumA, NumB, NumC, NumD, NumF: # of A, B, C, D, F grades
//   PercentA, PercentB, PercentC, PercentD, PercentF: % of A, B, 
//     C, D, F grades.  Example: PercentA = NumA / N * 100.0
//
// If the course grading type is not Course::Letter, all values
// are 0.  When computed for a dept or college, all courses of
// type Course::Letter are considered in computing an overall 
// grade distribution for the dept or college.
//
GradeStats GetGradeDistribution(const Course& c)
{
  GradeStats stats;
   
  //
  // how was course graded?  If not a letter, then cannot compute
  // grade distributions:
  //
  Course::GradingType grading = c.getGradingType();
     
  if (grading != Course::Letter)
    return stats;
       
  //
  // we have letter grades (at least 1), so compute distribution:
  //
  stats.N = c.NumA + c.NumB + c.NumC + c.NumD + c.NumF;
 
  if (stats.N == 0) // just in case, guard against divide by 0:
    return stats;
 
  stats.NumA = c.NumA;
  stats.PercentA = (static_cast<double>(stats.NumA) / static_cast<double>(stats.N)) * 100.0;
   
  stats.NumB = c.NumB;
  stats.PercentB = (static_cast<double>(stats.NumB) / static_cast<double>(stats.N)) * 100.0;
   
  stats.NumC = c.NumC;
  stats.PercentC = (static_cast<double>(stats.NumC) / static_cast<double>(stats.N)) * 100.0;
   
  stats.NumD = c.NumD;
  stats.PercentD = (static_cast<double>(stats.NumD) / static_cast<double>(stats.N)) * 100.0;
   
  stats.NumF = c.NumF;
  stats.PercentF = (static_cast<double>(stats.NumF) / static_cast<double>(stats.N)) * 100.0;
 
  return stats;  
}
 
GradeStats GetGradeDistribution(const Dept& dept)
{
  //
  // let's collect all the data in a course object, then we can call 
  // getGradeDistribution to do the work:
  //
  Course  all;
 
  //
  // loop through courses in dept, accumulating the grades:
  //
  for (const Course& c : dept.Courses)
  {
    if (c.getGradingType() != Course::Letter)
      continue;  // skip
     
    // course had letter grades, so include in computation:
    all.NumA += c.NumA;
    all.NumB += c.NumB;
    all.NumC += c.NumC;
    all.NumD += c.NumD;
    all.NumF += c.NumF;
  }
   
  //
  // and compute:
  //
  return GetGradeDistribution(all);
}
 
GradeStats GetGradeDistribution(const College& college)
{
  //
  // let's collect all the data in a course object, then we can call 
  // getGradeDistribution to do the work:
  //
  Course  all;
 
  //
  // loop through every dept in the college, and for every dept, loop
  // through the courses and accumulate all the grades:
  //
  for (const Dept& dept : college.Depts)
  {
    for (const Course& c : dept.Courses)
    {
      if (c.getGradingType() != Course::Letter)
        continue;  // skip
     
      // course had letter grades, so include in computation:
      all.NumA += c.NumA;
      all.NumB += c.NumB;
      all.NumC += c.NumC;
      all.NumD += c.NumD;
      all.NumF += c.NumF;
    }
  }
   
  //
  // and compute:
  //
  return GetGradeDistribution(all);
}
 
GradeStats GetGradeDistribution(const map<string,Dept> &v)
{
  //
  // let's collect all the data in a course object, then we can call 
  // getGradeDistribution to do the work:
  //
  Course  all;
 
  //
  // loop through every dept in the college, and for every dept, loop
  // through the courses and accumulate all the grades:
  //
  for (auto &kp : v)
  {
    for (const Course& c : kp.second.Courses)
    {
      if (c.getGradingType() != Course::Letter)
        continue;  // skip
     
      // course had letter grades, so include in computation:
      all.NumA += c.NumA;
      all.NumB += c.NumB;
      all.NumC += c.NumC;
      all.NumD += c.NumD;
      all.NumF += c.NumF;
    }
  }
   
  //
  // and compute:
  //
  return GetGradeDistribution(all);
}
 
//
// FindCourses(dept, courseNumber)
//
// Searches the courses in the department for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, and returned in
// ascending order by section number.
//
vector<Course> FindCourses(const Dept& dept, int courseNumber)
{
  vector<Course>  courses;
   
  //
  // looking for 1 or more courses that match the course number:
  //
  for(const Course& course : dept.Courses)
  {
    if (course.Number == courseNumber)  // match:
    {
      courses.push_back(course);
    }
  }
   
  //
  // sort the vector, first by course number then by section number:
  //
  if (courses.size() > 1)  // not required, just a tiny optimization:
  {
    sort(courses.begin(), courses.end(), 
      [](const Course& c1, const Course& c2)
      {
        if (c1.Number < c2.Number)
          return true;
        else if (c1.Number > c2.Number)
          return false;
        else // equal, determine by section number:
          if (c1.Section < c2.Section)
            return true;
          else
            return false;
      }
    );
  }
   
  return courses;
}
 
 
//
// FindCourses(dept, instructorPrefix)
//
// Searches the courses in the department for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".
//
// If none are found, then the returned vector is empty.  If 
// one or more courses are found, copies of the course objects
// are returned in a vector, with the courses appearing in 
// ascending order by course number.  If two courses have the 
// same course number, they are given in ascending order by 
// section number.  Note that courses are NOT sorted by instructor
// name.
//
vector<Course> FindCourses(const Dept& dept, string instructorPrefix)
{
  vector<Course>  courses;
   
  //
  // looking for 1 or more courses that match --- or start with ---
  // the given instrutor name:
  //
  size_t len = instructorPrefix.length();
 
  for(const Course& course : dept.Courses)
  {
    if (course.Instructor.substr(0, len) == instructorPrefix)  // match:
    {
      courses.push_back(course);
    }
  }
 
  //
  // sort the vector, first by course number then by section number:
  //
  if (courses.size() > 1)  // not required, just a tiny optimization:
  {
    sort(courses.begin(), courses.end(), 
      [](const Course& c1, const Course& c2)
      {
        if (c1.Number < c2.Number)
          return true;
        else if (c1.Number > c2.Number)
          return false;
        else // equal, determine by section number:
          if (c1.Section < c2.Section)
            return true;
          else
            return false;
      }
    );
  }
 
  return courses;
}
 
 
//
// FindCourses(college, courseNumber)
//
// Searches for all courses in the college for those that match
// the given course number.  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by department, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, int courseNumber)
{
  vector<Course>  courses;
   
  //
  // For each college, search for courses that match and collect them all
  // in a single vector:
  //
  for(const Dept& dept : college.Depts)
  {
    vector<Course> onedept = FindCourses(dept, courseNumber);
     
    for(const Course& c : onedept)
    {
      courses.push_back(c);
    }
  }
   
  //
  // now sort the courses (if any) by dept, course #, and section #:
  //
  if (courses.size() > 1)  // not required, just a tiny optimization:
  {
    sort(courses.begin(), courses.end(), 
      [](const Course& c1, const Course& c2)
      {
        if (c1.Dept < c2.Dept)
          return true;
        else if (c1.Dept > c2.Dept)
          return false;
        else // same dept, look at course #:
          if (c1.Number < c2.Number)
            return true;
          else if (c1.Number > c2.Number)
            return false;
          else // same course #, look at section #:
            if (c1.Section < c2.Section)
              return true;
            else
              return false;
      }
    );
  }
   
  return courses;
}
 
 
//
// FindCourses(college, instructorPrefix)
//
// Searches all the courses in the college for those whose 
// instructor name starts with the given instructor prefix.
// For example, the prefix "Re" would match instructors "Reed"
// and "Reynolds".  If none are found, then the returned
// vector is empty.  If one or more courses are found, copies of
// the course objects are returned in a vector, with the courses
// appearing in ascending order by instructor, then course number,
// and then section number.
//
vector<Course> FindCourses(const College& college, string instructorPrefix)
{
  vector<Course>  courses;
   
  //
  // For each college, search for courses that match and collect them all
  // in a single vector:
  //
  for(const Dept& dept : college.Depts)
  {
    vector<Course> onedept = FindCourses(dept, instructorPrefix);
     
    for(const Course& c : onedept)
    {
      courses.push_back(c);
    }
  }
   
  //
  // now sort the courses (if any) by instructor, course #, and section #:
  //
  if (courses.size() > 1)  // not required, just a tiny optimization:
  {
    sort(courses.begin(), courses.end(), 
      [](const Course& c1, const Course& c2)
      {
        if (c1.Instructor < c2.Instructor)
          return true;
        else if (c1.Instructor > c2.Instructor)
          return false;
        else // same dept, look at course #:
          if (c1.Number < c2.Number)
            return true;
          else if (c1.Number > c2.Number)
            return false;
          else // same course #, look at section #:
            if (c1.Section < c2.Section)
              return true;
            else
              return false;
      }
    );
  }
     
  return courses;
}

vector<Course> DFWThresh(const vector<Course> &v, double tresh)
{
  std::vector<Course> T;

  std::copy_if(v.begin(),v.end(), std::back_inserter(T),
    [=](const Course &a){
      int N = a.getNumStudents();
      int DFW = a.numDFW();
      double c = GetDFWRate(a,DFW,N);
      return (c > tresh);
    });

  std::sort(T.begin(),T.end(),
    [=](const Course &a, const Course &b){
      int N1 = a.getNumStudents();
      int DFW1 = a.numDFW();
      double aDfw = GetDFWRate(a,DFW1,N1);
      int N2 = b.getNumStudents();
      int DFW2 = b.numDFW();
      double bDfw = GetDFWRate(b,DFW2,N2);

      if(bDfw == aDfw)
      {
        if(a.Dept == b.Dept)
        {
          if(a.Number == b.Number)
          {
            if(a.Section == b.Section)
            {
              return(a.Section > b.Section);
            }else{
              return(a.Section < b.Section);
            }
          }
          else{
            return(a.Number < b.Number);
          }
        }
        else{
          return(a.Dept < b.Dept);
        }
      }
      else{
        return(bDfw < aDfw);
      }

    });

  return T;
}

vector<Course> DFWThresh(const map<string,Dept> &v, double tresh)
{
  std::vector<Course> T;

  for(auto &de : v)
  {
    std::copy_if(de.second.Courses.begin(),de.second.Courses.end(), std::back_inserter(T),
    [=](const Course &a){
      int N = a.getNumStudents();
      int DFW = a.numDFW();
      double c = GetDFWRate(a,DFW,N);
      return (c > tresh);
    });
  }

  std::sort(T.begin(),T.end(),
    [=](const Course &a, const Course &b){
      int N1 = a.getNumStudents();
      int DFW1 = a.numDFW();
      double aDfw = GetDFWRate(a,DFW1,N1);
      int N2 = b.getNumStudents();
      int DFW2 = b.numDFW();
      double bDfw = GetDFWRate(b,DFW2,N2);

      if(bDfw == aDfw)
      {
        if(a.Dept == b.Dept)
        {
          if(a.Number == b.Number)
          {
            if(a.Section == b.Section)
            {
              return(a.Section > b.Section);
            }else{
              return(a.Section < b.Section);
            }
          }
          else{
            return(a.Number < b.Number);
          }
        }
        else{
          return(a.Dept < b.Dept);
        }
      }
      else{
        return(bDfw < aDfw);
      }

    });

  return T;
}

vector<Course> LetterAThresh(const std::map<string,Dept> &v, double tresh)
{
  std::vector<Course> T;

  for(auto &de : v)
  {
    std::copy_if(de.second.Courses.begin(),de.second.Courses.end(), std::back_inserter(T),
      [=](const Course &a){
        auto gs = GetGradeDistribution(a);
        return (gs.PercentA > tresh);
      });
  }

  std::sort(T.begin(),T.end(),
    [=](const Course &a, const Course &b){
      auto gssA = GetGradeDistribution(a);
      auto gssB = GetGradeDistribution(b);

      if(gssB.PercentA == gssA.PercentA)
      {
        if(a.Dept == b.Dept)
        {
          if(a.Number == b.Number)
          {
            if(a.Section == b.Section)
            {
              return(a.Section > b.Section);
            }else{
              return(a.Section < b.Section);
            }
          }
          else{
            return(a.Number < b.Number);
          }
        }
        else{
          return(a.Dept < b.Dept);
        }
      }
      else{
        return(gssB.PercentA < gssA.PercentA);
      }

    });

    return T;
}



vector<Course> LetterAThresh(const std::vector<Course> &v, double tresh)
{

  std::vector<Course> T;

    std::copy_if(v.begin(),v.end(), std::back_inserter(T),
      [=](const Course &a){
        auto gs = GetGradeDistribution(a);
        return (gs.PercentA > tresh);
      });

    std::sort(T.begin(),T.end(),
    [=](const Course &a, const Course &b){
      auto gssA = GetGradeDistribution(a);
      auto gssB = GetGradeDistribution(b);

      if(gssB.PercentA == gssA.PercentA)
      {
        if(a.Dept == b.Dept)
        {
          if(a.Number == b.Number)
          {
            if(a.Section == b.Section)
            {
              return(a.Section > b.Section);
            }else{
              return(a.Section < b.Section);
            }
          }
          else{
            return(a.Number < b.Number);
          }
        }
        else{
          return(a.Dept < b.Dept);
        }
      }
      else{
        return(gssB.PercentA < gssA.PercentA);
      }

    });

    return T;

}

