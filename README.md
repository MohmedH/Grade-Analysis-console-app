# Grade-Analysis-console-app
Grade Analysis console app in C++

### 1) First Step was to develop test cases against a Grade Analysis utility library. About 10 test cases were written using the Catch framework (https://github.com/catchorg/Catch2).

### 2) Once the test cases were written, I had to use those test cases to implement the functions that would be inside the Grade Analysis Utility Library. This included functions for computing grade distributions, DFW rates, etc. 

### 3) Now that the functions were made, and they passed all the test cases that I wrote, it was time to put those functions to use in an application. 

### The files you see in Master, are the files for the application. This application will input the data (CSV FILE GIVEN ABOVE), parse, and then accept commands from the user to search and analyze this data. 

	1. Summary of a department or college

	2. Search by course # or instructor prefix

	3. List of courses with grading type of unknown

	4. List of courses by DFW rate

	5. List of courses by percentage of A letter grades


### Upon input of the file you are given out quick stats about the entire college from the CSV file:

<img width="962" alt="Stats" src="https://user-images.githubusercontent.com/23105576/57782290-8a3d9b80-76f1-11e9-9948-fd87aa070e17.png">

#### Once the summary is output, the program prompts the user to input a command. The user can input commands in any order, and can input any number of commands. The “#” command ends the program. There are 5 commands: “summary”, “search”, “unknown”, “dfw”, and “letterA”. Commands are case-sensitive, and any other input should result in the output “**unknown command”. Here’s an example:

<img width="743" alt="Screen Shot 2019-05-15 at 8 55 55 AM" src="https://user-images.githubusercontent.com/23105576/57782293-8b6ec880-76f1-11e9-8897-f285d2140099.png">

### 1. summary command:

The summary command outputs a college-wide summary, or a departmental summary. The user is prompted for a department name, e.g. “CS”, or “all” which means the college. The input is case-sensitive. Here’s a departmental summary:

<img width="923" alt="Screen Shot 2019-05-15 at 8 58 01 AM" src="https://user-images.githubusercontent.com/23105576/57782298-8dd12280-76f1-11e9-9422-e20303488d32.png">

This is for 'all'
	
Beginning 


...Depts in the middle

Ending

<img width="929" alt="Screen Shot 2019-05-15 at 8 58 22 AM" src="https://user-images.githubusercontent.com/23105576/57782303-90337c80-76f1-11e9-8ea1-46e37611a5de.png">


### 2. search command: 

The search command performs a department or college-wide search by course number or instructor prefix. The user is first prompted for a department name, e.g. “CS”, or “all” which means the college. The user is then prompted to enter a course number or instructor prefix. All input is case-sensitive. Here’s a departmental search for CS 341:

//IMG

And a departmental search by instructor prefix “Bel”:

//IMG

Here are college-wide searches by course number and instructor prefix. Note that for college-wide searches, the output is sorted first by department, then course #, then section # (for a course # search), and by instructor, then course #, then section # (for a prefix search).

//IMG

//IMG
//IMG

### 3. unknown command:

The unknown command performs a department or college-wide search for all courses whose Grading type is Course::Unknown. The user is prompted for a department name, e.g. “CS”, or “all” which means the college. Here are the unknown courses for the ME department (output ordered by course #, then section #):

//img

Here are the unknown courses college-wide (output is ordered by dept name, course #, section #):

//img

### 4. dfw command (D's, F's, and Withdrawals):

The dfw command performs a department or college-wide search for all courses whole DFW rate exceeds a threshold input by the user. Here’s an example for the CS department with a threshold of 40.0%, notice the output is in descending order by DFW rate:

//img

Here’s a college-wide search for courses with a DFW rate above 40.0%:

//img

### 5. letterA command:

The dfw command performs a department or college-wide search for all courses whole percentage of letter A grades exceeds a threshold input by the user. Here’s an example for the CS department with a letter A threshold of 80.0%. Notice the output is in descending order the percentage of A grades, where if 2 courses have the same percentage, the output is then ordered by dept, course #, section # (all in ascending order)

//img

Here’s an example of a college-wide search for courses above 99.0%:

//img 
