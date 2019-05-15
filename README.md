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
	
Beginning:
<img width="927" alt="Screen Shot 2019-05-15 at 8 58 09 AM" src="https://user-images.githubusercontent.com/23105576/57782576-249ddf00-76f2-11e9-90f7-0d4e559ead3b.png">

...Depts in the middle

Ending

<img width="929" alt="Screen Shot 2019-05-15 at 8 58 22 AM" src="https://user-images.githubusercontent.com/23105576/57782303-90337c80-76f1-11e9-8ea1-46e37611a5de.png">


### 2. search command: 

The search command performs a department or college-wide search by course number or instructor prefix. The user is first prompted for a department name, e.g. “CS”, or “all” which means the college. The user is then prompted to enter a course number or instructor prefix. All input is case-sensitive. Here’s a departmental search for CS 341:

<img width="828" alt="Screen Shot 2019-05-15 at 9 00 05 AM" src="https://user-images.githubusercontent.com/23105576/57782757-7cd4e100-76f2-11e9-9abe-16a690e2319a.png">

And a departmental search by instructor prefix “Bel”:

<img width="824" alt="Screen Shot 2019-05-15 at 9 00 30 AM" src="https://user-images.githubusercontent.com/23105576/57782760-7d6d7780-76f2-11e9-9b9a-32afd13bced1.png">

Here are college-wide searches by course number and instructor prefix. Note that for college-wide searches, the output is sorted first by department, then course #, then section # (for a course # search), and by instructor, then course #, then section # (for a prefix search).

<img width="547" alt="Screen Shot 2019-05-15 at 9 01 07 AM" src="https://user-images.githubusercontent.com/23105576/57782765-7e9ea480-76f2-11e9-9883-656b4799bee0.png">

<img width="541" alt="Screen Shot 2019-05-15 at 9 01 15 AM" src="https://user-images.githubusercontent.com/23105576/57782769-80686800-76f2-11e9-8e70-8d652e40f48a.png">
<img width="639" alt="Screen Shot 2019-05-15 at 9 01 25 AM" src="https://user-images.githubusercontent.com/23105576/57782771-8100fe80-76f2-11e9-8868-8b8ca6d1bac3.png">

### 3. unknown command:

The unknown command performs a department or college-wide search for all courses whose Grading type is Course::Unknown. The user is prompted for a department name, e.g. “CS”, or “all” which means the college. Here are the unknown courses for the ME department (output ordered by course #, then section #):

<img width="608" alt="Screen Shot 2019-05-15 at 9 03 13 AM" src="https://user-images.githubusercontent.com/23105576/57782779-82cac200-76f2-11e9-911f-2e1b76083c57.png">

Here are the unknown courses college-wide (output is ordered by dept name, course #, section #):

<img width="618" alt="Screen Shot 2019-05-15 at 9 03 23 AM" src="https://user-images.githubusercontent.com/23105576/57782789-852d1c00-76f2-11e9-97d0-285abe8e09be.png">

### 4. dfw command (D's, F's, and Withdrawals):

The dfw command performs a department or college-wide search for all courses whole DFW rate exceeds a threshold input by the user. Here’s an example for the CS department with a threshold of 40.0%, notice the output is in descending order by DFW rate:

<img width="529" alt="Screen Shot 2019-05-15 at 9 04 33 AM" src="https://user-images.githubusercontent.com/23105576/57782796-86f6df80-76f2-11e9-9d76-a970b935e8da.png">

Here’s a college-wide search for courses with a DFW rate above 40.0%:

<img width="468" alt="Screen Shot 2019-05-15 at 9 04 52 AM" src="https://user-images.githubusercontent.com/23105576/57782800-89593980-76f2-11e9-8300-824a77b685cf.png">

### 5. letterA command:

The dfw command performs a department or college-wide search for all courses whole percentage of letter A grades exceeds a threshold input by the user. Here’s an example for the CS department with a letter A threshold of 80.0%. Notice the output is in descending order the percentage of A grades, where if 2 courses have the same percentage, the output is then ordered by dept, course #, section # (all in ascending order)

<img width="432" alt="Screen Shot 2019-05-15 at 9 05 45 AM" src="https://user-images.githubusercontent.com/23105576/57782809-8b22fd00-76f2-11e9-8424-67f16c564d6c.png">

Here’s an example of a college-wide search for courses above 99.0%:

<img width="445" alt="Screen Shot 2019-05-15 at 9 25 29 AM" src="https://user-images.githubusercontent.com/23105576/57783329-8ca0f500-76f3-11e9-8832-67ca6265299f.png">

*more departments in alphabetical order by department name*

<img width="442" alt="Screen Shot 2019-05-15 at 9 25 40 AM" src="https://user-images.githubusercontent.com/23105576/57783332-8e6ab880-76f3-11e9-8b9c-23ae0bfa344f.png"> 
