#include "Teacher.h"
#include"Courses.h"

#include<iostream>
using namespace std;
Teacher::Teacher()
{
	course_count = 0;
	course_list = 0;
	primaryDep = 0;
}
Teacher::Teacher(const char n[], int ID, Department* dep) : Employee(n, ID), Person(n)
{
	//std::cout << "Teacher constructor\n";
	course_list = new Courses*[3];
	course_count = 0;
	primaryDep = dep;
	//cinFix = 0;
}
Teacher::Teacher(const char name[], const char uname[], const char pw[], int empID,  Department* dtemp) :Person(name), Employee(name, empID)
{
	Person::setuser(uname);
	Person::setpw(pw);
	course_count = 0;//ccount;
	course_list = new Courses * [3];
	primaryDep = dtemp;
}

void Teacher::manageAttendance()
{
	/*char x;
	std::cin >> x;*/

	std::cout << "\nEnter the 6 digit Course ID to manage attendance\n";
	char id[7];
	//if (cinFix % 2 != 0)
	//std::cin.ignore();
	//std::cin.clear();
	cin.ignore();
	std::cin.getline(id, 7);
	//cinFix++;

	bool match = false;
	for (int i = 0; i < course_count; i++)
	{
		if (strcmp(id, course_list[i]->getID()) == 0)
		{
			if (course_list[i]->getAttendInitialize() == 1)
			{
				course_list[i]->manageAttendance();
			}
			else
				std::cout << "Initialize Attendance before Managing\n";
			match = true;
		}
	}
	if (!match)
	{
		std::cout << "Invalid Course ID Entered\n";
		cin.ignore();
		cin.getline(id, 7);
		for (int i = 0; i < course_count; i++)
		{
			if (strcmp(id, course_list[i]->getID()) == 0)
			{
				course_list[i]->manageAttendance();
				match = true;
			}
		}

		if (!match)
			cout << "Invalid Course Entered, Failed to Manage Attendance\n";

	}
}

void Teacher::initializeAttendance()
{
	cout << "Initializing Attendance Register for All Courses\n";
	for (int i = 0; i < course_count; i++)
	{
		course_list[i]->initializeAttendance();
	}
}

void Teacher::initializeEval()
{
	std::cout << "Enter the 6 character Course ID for which you want to initialize Evaluations\n";
	char temp[7];
	std::cin.ignore();
	std::cin.getline(temp, 7);
	
	bool flag = false;
	for (int i = 0; i < course_count; i++)
	{
		if (strcmp(temp, course_list[i]->getID()) == 0)
		{
			course_list[i]->initializeEvaluation();
			flag = true;
		}
	}
	if (!flag)
		std::cout << "No matching course found\n";
}

void Teacher::manageEval()
{
	std::cout << "Enter Course ID to Manage Evaluation\n";
	cin.ignore();
	char temp[7];
	cin.getline(temp, 7);

	//Teacher
	bool flag = false;
	for (int i = 0; i < course_count; i++)
	{
		if (strcmp(temp, course_list[i]->getID()) == 0)
		{
			if (course_list[i]->getEvalInitialzier() == 1)
				course_list[i]->manageEvaluation();
			else
				std::cout << "Initialize Evaluation before Managing\n";
			
			flag = true;
		}
	}
	if (!flag)
		std::cout << "No matching course found\n";
}

void Teacher::addCourse(Courses* obj)
{
	course_list[course_count++] = obj;
}