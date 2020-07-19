#pragma once
#include"Students.h"
#include"Teacher.h"
#include"Courses.h"
class Teacher;
//class Courses;
class TAssistant :
	public Students, public Teacher
{
	char TACID[7];
	Courses* crs;
public:
	TAssistant()
	{

	}
	TAssistant(const char n[], const char uname[], const char pw[], const char TCID[], int roll, int ID, Department* dep) : Employee(n, ID), Person(n), Students(n, roll), Teacher(n, ID, dep)
	{
		for (int i = 0; i < strlen(TCID); i++)
			TACID[i] = TCID[i];
		//TACID[6] = '\0';
		Person::setuser(uname);
		Person::setpw(pw);
		crs = 0;
		//dep->getCoursebyID(TACID);
	}
	TAssistant(const char n[], const char uname[], const char pw[], const char TCID[], int roll, int ID, Department* dep,Courses* c) : Employee(n, ID), Person(n), Students(n, roll), Teacher(n, ID, dep)
	{
		for (int i = 0; i < strlen(TCID); i++)
			TACID[i] = TCID[i];
		TACID[6] = '\0';
		crs = c;
		Person::setuser(uname);
		Person::setpw(pw);
	}

	void setEmpID(int x)
	{
		Employee::setEmpID(x);
	}
	void setTACID(const char TCID[])
	{
		for (int i = 0; i < strlen(TCID); i++)
			TACID[i] = TCID[i];
		TACID[6] = '\0';
	}
	char* getTACID()
	{
		return TACID;
	}
	Courses* getCourse()
	{
		return crs;
	}
	void setCourse(Courses* c)
	{
		crs = c;
	}
	void print()
	{
		Teacher::print();
		Students::print();
		cout << "\t" << crs->getID();
	}
	void manageTAEvaluation()
	{
		std::cout << "Enter Course ID to Manage Evaluation\n";
		cin.ignore();
		char temp[7];
		cin.getline(temp, 7);

		//Teacher
		
		if (strcmp(temp, crs->getID()) == 0)
		{
			//int x = 0;
			crs->manageTAEvaluation();
		}
		else
			std::cout << "No matching course found\n";
	}
	
	virtual ~TAssistant()
	{
		crs = 0;
	}
};

