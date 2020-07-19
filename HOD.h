#pragma once
#include "Teacher.h"
class HOD :
	public Teacher
{
public:
	HOD()
	{	}
	HOD(const char n[], int ID, Department* dep) : Teacher(n, ID, dep), Employee(n, ID), Person(n)
	{}
	HOD(const char name[], const char uname[], const char pw[], int empID,Department* dtemp) : Person(name), Employee(name, empID)
	{
		Person::setuser(uname);
		Person::setpw(pw);
		course_count = 0;
		primaryDep = dtemp;
	}

	~HOD()
	{

	}
};

