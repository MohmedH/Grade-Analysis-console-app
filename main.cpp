/*main.cpp*/

/*
// Mohmed Hira
// U. of Illinois, Chicago
// CS 341, Spring 2019
// Project #03: GradeUtil API
*/ 

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip> 
#include <map>

#include "gradeutil.h"
//#include "gradeutil.cpp"

using namespace std;

int main()
{
	//Needed for GradeScope Submission
	cout << std::fixed;
	cout << std::setprecision(2);

	std::vector<College> G;
	map<string,Dept> D;

	string s;
	string college;
	string semester;
	int year;
	string temp;

	string line;
	cin >> s;

	std::ifstream file;

	file.open(s);

	while(!file.good())
	{
		cout << "File no good, try again: ";
		cin >> s;
		file.open(s);
	}

	//---------------------------------------------------------------------------------------
	getline(file, line);
	stringstream ss(line);

	getline(ss, college, ',');
	getline(ss, semester, ',');
	getline(ss, temp, ',');
	year = stoi(temp);
	cout << "** College of " << college << ", " << semester << " " << year << " **" << endl;
	//----------------------------------------------------------------------------------------

	//Skip out the headers in the CSV file
	getline(file, line);

	//Parse thorugh the CSV file an input into a Data Strcture------------------------------------
	while(getline(file, line))
	{
		Course Cor = ParseCourse(line);
		Dept dept = Cor.Dept;
		auto it = D.find(Cor.Dept);
		if(it != D.end() ){
			it->second.Courses.push_back(Cor);
		}else{
			dept.Courses.push_back(Cor);
			D.insert(make_pair(Cor.Dept,dept));
		}

	}
	//CLOSE THE FILE 
	file.close();
	//------------------------------------------------------------------------------------------------------------

	//PRINT OUT SUMMARY FROM CSV FILE --------------------------------------------------------------------------------
	int numStu = 0;
	int numCour = 0;
	int tempDFW = 0;
	int tempN = 0;
	double tDFWR = 0.0;

	for(auto &g : D)
	{
		numCour = numCour + g.second.getNumCourse();
		numStu = numStu + g.second.getNumStudent();
	}
	auto gg = GetGradeDistribution(D);
	tDFWR = GetDFWRate(D,tempDFW,tempN);

	cout << "# of courses taught: " <<  numCour << endl;
	cout << "# of students taught: " <<  numStu << endl;
	cout << "grade distribution (A-F): " << gg.PercentA << "%, " << gg.PercentB << "%, " << gg.PercentC << "%, " << gg.PercentD << "%, "<< gg.PercentF << "% "<< endl;
	cout << "DFW rate: " << tDFWR << "% " << endl << endl;
	//END OF SUMMARY CSV FILE --------------------------------------------------------------------------------------------------

	cout << "Enter a command> ";
	string command;
	cin >> command;

	while( command != "#")
	{
		//1)SUMMARY FUNCTION----------------------------------------------------------------------------------------------
		if(command == "summary")
		{
			string t;
			cout << "dept name, or all? ";
			cin >> t;

			if(t == "all")
			{
				for(auto &de : D)
				{
					auto gs = GetGradeDistribution(de.second);
					
					int N = gs.N;
					int DFW = de.second.numDFW();
					double DFWrate = GetDFWRate(de.second,DFW,N);

					cout << de.first << ":" << endl;
					cout << " # courses taught: " << de.second.getNumCourse() << endl;
					cout << " # students taught: " << de.second.getNumStudent() << endl;
					cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
					cout << " DFW rate: " << DFWrate << "% " << endl;

				}

			}
			else
			{
				auto it = D.find(t);

				if(it != D.end()){
					cout << it->first << ":" << endl;
					cout << " # courses taught: " << it->second.getNumCourse() << endl;
					cout << " # students taught: " << it->second.getNumStudent() << endl;

					auto gs = GetGradeDistribution(it->second);
					cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;

					int N = gs.N;
					int DFW = it->second.numDFW();
					double DFWrate = GetDFWRate(it->second,DFW,N);
					cout << " DFW rate: " << DFWrate << "% " << endl;

				}else{
					cout << "**dept not found" << endl;
				}	
				
			}
			
		}//END OF SUMMARY-----------------------------------------------------------------------------------
		else if(command == "dfw")
		{
			cout<< "dept name, or all? ";
			string n;
			cin >> n;

			cout<< "dfw threshold? ";
			double tre;
			cin >> tre;
			std::vector<Course> sol;

			if( n == "all")
			{
				sol = DFWThresh(D,tre);

				if(sol.size() == 0)
				{
					cout << "**none found" << endl;
				}
				else
				{
					for(auto &c : sol)
					{
						auto gs = GetGradeDistribution(c);
				
						int N = c.getNumStudents();
						int DFW = c.numDFW();
						double DFWrate = GetDFWRate(c,DFW,N);
						string cType;

						if(c.getGradingType() == Course::Letter)
						{
							cType = "letter";
						}else if(c.getGradingType() == Course::Satisfactory)
						{
							cType = "satisfactory";
						}else
						{
							cType = "unknown";
						}

						cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
						cout << " # students: " << c.getNumStudents() << endl;
						cout << " course type: " << cType << endl; 
						cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
						cout << " DFW rate: " << DFWrate << "% " << endl;
					}
						
				}
			}
			else
			{
				auto it = D.find(n);

				if(it != D.end())
				{
					sol = DFWThresh(it->second.Courses,tre);

					if(sol.size() == 0)
					{
						cout << "**none found" << endl;
					}
					else
					{
						for(auto &c : sol)
						{
							auto gs = GetGradeDistribution(c);
					
							int N = c.getNumStudents();
							int DFW = c.numDFW();
							double DFWrate = GetDFWRate(c,DFW,N);
							string cType;

							if(c.getGradingType() == Course::Letter)
							{
								cType = "letter";
							}else if(c.getGradingType() == Course::Satisfactory)
							{
								cType = "satisfactory";
							}else
							{
								cType = "unknown";
							}

							cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
							cout << " # students: " << c.getNumStudents() << endl;
							cout << " course type: " << cType << endl; 
							cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
							cout << " DFW rate: " << DFWrate << "% " << endl;
						}

					}
				}
				else
				{
					cout << "**dept not found" << endl;		
				}	

			}

		}
		else if(command == "search")
		{

			string sC;
			int cOp = 0;
			string preF;
			std::vector<Course> reT;
			std::vector<Course> solA;

			cout<< "dept name, or all? ";
			cin >> sC;

			if(sC == "all")
			{
				cout << "course # or instructor prefix? ";
				cin >> preF;

				stringstream st(preF);
				st >> cOp;

				if(st.fail())
				{
					for(auto &kp : D)
					{
						reT = FindCourses(kp.second,preF);
						solA.insert(solA.end(),reT.begin(),reT.end());
					}

					if(solA.size() == 0)
					{
						cout << "**none found" << endl;
					}
					else
					{
						sort(solA.begin(),solA.end(),
							[=](const Course &a, const Course &b)
							{
								if(a.Instructor == b.Instructor)
							    {
							      if(a.Number == b.Number)
							      {
							        if(a.Section == b.Section)
							        {
							          return(a.Section > b.Section);

							        }
							        else
							        {
							          return(a.Section < b.Section);
							        }
							      }
							      else
							      {
							        return(a.Number < b.Number);
							      }
							    }
							    else
							    {
							      return(a.Instructor < b.Instructor);
							    }

							});

						for(auto &c : solA)
						{
							auto gs = GetGradeDistribution(c);
					
							int N = c.getNumStudents();
							int DFW = c.numDFW();
							double DFWrate = GetDFWRate(c,DFW,N);
							string cType;

							if(c.getGradingType() == Course::Letter)
							{
								cType = "letter";
							}else if(c.getGradingType() == Course::Satisfactory)
							{
								cType = "satisfactory";
							}else
							{
								cType = "unknown";
							}

							cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
							cout << " # students: " << c.getNumStudents() << endl;
							cout << " course type: " << cType << endl; 
							cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
							cout << " DFW rate: " << DFWrate << "% " << endl;
						}
					}


				}
				else
				{
					for(auto &kp : D)
					{
						reT = FindCourses(kp.second,cOp);
						solA.insert(solA.end(),reT.begin(),reT.end());
					}

					if(solA.size() == 0)
					{
						cout << "**none found" << endl;
					}
					else
					{

						sort(solA.begin(),solA.end(),
							[=](const Course &a, const Course &b)
							{
								if(a.Dept == b.Dept)
							    {
							      if(a.Number == b.Number)
							      {
							        if(a.Section == b.Section)
							        {
							          return(a.Section > b.Section);

							        }
							        else
							        {
							          return(a.Section < b.Section);
							        }
							      }
							      else
							      {
							        return(a.Number < b.Number);
							      }
							    }
							    else
							    {
							      return(a.Dept < b.Dept);
							    }

							});

						for(auto &c : solA)
						{
							auto gs = GetGradeDistribution(c);
					
							int N = c.getNumStudents();
							int DFW = c.numDFW();
							double DFWrate = GetDFWRate(c,DFW,N);
							string cType;

							if(c.getGradingType() == Course::Letter)
							{
								cType = "letter";
							}else if(c.getGradingType() == Course::Satisfactory)
							{
								cType = "satisfactory";
							}else
							{
								cType = "unknown";
							}

							cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
							cout << " # students: " << c.getNumStudents() << endl;
							cout << " course type: " << cType << endl; 
							cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
							cout << " DFW rate: " << DFWrate << "% " << endl;
						}
					}

				}

			}
			else
			{

				cout << "course # or instructor prefix? ";
				cin >> preF;
				auto it = D.find(sC);
				
				if(it != D.end())
				{

					stringstream st(preF);
					st >> cOp;

					//IF IT FAILS THEY INPUT A PREFIX OR PROF
					if(st.fail())
					{
						reT = FindCourses(it->second,preF);

						if(reT.size() == 0)
						{
							cout << "**none found" << endl;
						}
						else
						{
							for(auto &c : reT)
							{
								auto gs = GetGradeDistribution(c);
						
								int N = c.getNumStudents();
								int DFW = c.numDFW();
								double DFWrate = GetDFWRate(c,DFW,N);
								string cType;

								if(c.getGradingType() == Course::Letter)
								{
									cType = "letter";
								}else if(c.getGradingType() == Course::Satisfactory)
								{
									cType = "satisfactory";
								}else
								{
									cType = "unknown";
								}

								cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
								cout << " # students: " << c.getNumStudents() << endl;
								cout << " course type: " << cType << endl; 
								cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
								cout << " DFW rate: " << DFWrate << "% " << endl;
							}
						}

					}
					else
					{
						reT = FindCourses(it->second,cOp);

						if(reT.size() == 0)
						{
							cout << "**none found" << endl;
						}
						else
						{
							for(auto &c : reT)
							{
								auto gs = GetGradeDistribution(c);
						
								int N = c.getNumStudents();
								int DFW = c.numDFW();
								double DFWrate = GetDFWRate(c,DFW,N);
								string cType;

								if(c.getGradingType() == Course::Letter)
								{
									cType = "letter";
								}else if(c.getGradingType() == Course::Satisfactory)
								{
									cType = "satisfactory";
								}else
								{
									cType = "unknown";
								}

								cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
								cout << " # students: " << c.getNumStudents() << endl;
								cout << " course type: " << cType << endl; 
								cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
								cout << " DFW rate: " << DFWrate << "% " << endl;
							}
						}


					}

				}
				else
				{
					cout << "**dept not found" << endl;
				}
			}

		}
		else if(command == "letterA")
		{
			cout<< "dept name, or all? ";
			string n;
			cin >> n;

			cout<< "letter A threshold? ";
			double tre;
			cin >> tre;
			std::vector<Course> sol;

			if(n == "all")
			{
				sol = LetterAThresh(D,tre);

				if(sol.size() == 0)
				{
					cout << "**none found" << endl;
				}
				else
				{
					for(auto &c : sol)
					{
						auto gs = GetGradeDistribution(c);
				
						int N = c.getNumStudents();
						int DFW = c.numDFW();
						double DFWrate = GetDFWRate(c,DFW,N);
						string cType;

						if(c.getGradingType() == Course::Letter)
						{
							cType = "letter";
						}else if(c.getGradingType() == Course::Satisfactory)
						{
							cType = "satisfactory";
						}else
						{
							cType = "unknown";
						}

						cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
						cout << " # students: " << c.getNumStudents() << endl;
						cout << " course type: " << cType << endl; 
						cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
						cout << " DFW rate: " << DFWrate << "% " << endl;
					}
						
				}

			}
			else
			{

				auto it = D.find(n);

				if(it != D.end())
				{
					sol = LetterAThresh(it->second.Courses,tre);

					if(sol.size() == 0)
					{
						cout << "**none found" << endl;
					}
					else
					{
						for(auto &c : sol)
						{
							auto gs = GetGradeDistribution(c);
					
							int N = c.getNumStudents();
							int DFW = c.numDFW();
							double DFWrate = GetDFWRate(c,DFW,N);
							string cType;

							if(c.getGradingType() == Course::Letter)
							{
								cType = "letter";
							}else if(c.getGradingType() == Course::Satisfactory)
							{
								cType = "satisfactory";
							}else
							{
								cType = "unknown";
							}

							cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
							cout << " # students: " << c.getNumStudents() << endl;
							cout << " course type: " << cType << endl; 
							cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
							cout << " DFW rate: " << DFWrate << "% " << endl;
						}

					}
				}
				else
				{
					cout << "**dept not found" << endl;
				}
			}

		}
		else if(command == "unknown")
		{
			std::vector<Course> sol;
			string ukC;
			cout<< "dept name, or all? ";
			cin >> ukC;

			if(ukC == "all")
			{
				for(auto &d : D)
				{
					for(auto &c : d.second.Courses)
					{
						if(c.getGradingType() == Course::Unknown)
						{
							sol.push_back(c);
						}
					}
				}

				if(sol.size() == 0)
				{
					cout << "**none found" << endl;
				}
				else
				{
					sort(sol.begin(),sol.end(),
						[=](const Course &a, const Course &b)
						{
							if(a.Dept == b.Dept)
						    {
						      if(a.Number == b.Number)
						      {
						        if(a.Section == b.Section)
						        {
						          return(a.Section > b.Section);

						        }
						        else
						        {
						          return(a.Section < b.Section);
						        }
						      }
						      else
						      {
						        return(a.Number < b.Number);
						      }
						    }
						    else
						    {
						      return(a.Dept < b.Dept);
						    }

						});

						for(auto &c : sol)
							{
								auto gs = GetGradeDistribution(c);
						
								int N = c.getNumStudents();
								int DFW = c.numDFW();
								double DFWrate = GetDFWRate(c,DFW,N);
								string cType;

								if(c.getGradingType() == Course::Letter)
								{
									cType = "letter";
								}else if(c.getGradingType() == Course::Satisfactory)
								{
									cType = "satisfactory";
								}else
								{
									cType = "unknown";
								}

								cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
								cout << " # students: " << c.getNumStudents() << endl;
								cout << " course type: " << cType << endl; 
								cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
								cout << " DFW rate: " << DFWrate << "% " << endl;
							}
				}
			}
			else
			{
				auto it = D.find(ukC);

				if(it != D.end())
				{
					for(auto &d : it->second.Courses)
					{
						if(d.getGradingType() == Course::Unknown)
						{
							sol.push_back(d);
						}
					}

					if(sol.size() == 0)
					{
						cout << "**none found" << endl;
					}
					else
					{
						sort(sol.begin(),sol.end(),
						[](const Course &a, const Course &b){

							if(a.Number == b.Number)
							{
								if(a.Section == b.Section)
								{
									return(a.Section > b.Section);

								}else
								{
									return(a.Section < b.Section);
								}

							}
							else
							{
								return(a.Number < b.Number);
							}

						});
					}

					for(auto &c : sol)
					{
						auto gs = GetGradeDistribution(c);
				
						int N = c.getNumStudents();
						int DFW = c.numDFW();
						double DFWrate = GetDFWRate(c,DFW,N);
						string cType;

						if(c.getGradingType() == Course::Letter)
						{
							cType = "letter";
						}else if(c.getGradingType() == Course::Satisfactory)
						{
							cType = "satisfactory";
						}else
						{
							cType = "unknown";
						}

						cout << c.Dept << " " << c.Number << " (section " << c.Section << "): " << c.Instructor << endl;
						cout << " # students: " << c.getNumStudents() << endl;
						cout << " course type: " << cType << endl; 
						cout << " grade distribution (A-F): " << gs.PercentA << "%, " << gs.PercentB << "%, " << gs.PercentC << "%, " << gs.PercentD << "%, "<< gs.PercentF << "% "<< endl;
						cout << " DFW rate: " << DFWrate << "% " << endl;
					}

				}
				else
				{
					cout << "**dept not found" << endl;	
				}
			}

		}
		else{
			cout << "**unknown command" << endl;
		}


		cout << "Enter a command> ";
		cin >> command;

	}

	return 0;
}