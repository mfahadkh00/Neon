#pragma once
#ifndef Teacher_H
#define Teacher_H
#include "Employee.h"
using namespace std;
//#include"Courses.h"
class Department;
class Courses;


class Teacher :
	public virtual Employee
{
protected:
	int course_count; //max 3 courses
	Courses** course_list;
	Department* primaryDep;
	

public:
	Teacher();
	Teacher(const char n[], int ID, Department* dep);
	Teacher(const char name[], const char uname[], const char pw[], int empID,Department*dtemp);

	void manageAttendance();
	void initializeAttendance(); //Only After 2 weeks of Uni start
	
	void initializeEval();
	void manageEval();
	
	void setPrimaryDep(Department* dep)
	{
		primaryDep = dep;
	}
	void addCourse(Courses* obj);
	void print()
	{
		Employee::print();
		cout << "\t" << course_count << '\t';
	}
	int getCourseCount()
	{
		return course_count;
	}
	Department* getPrimaryDep()
	{
		return primaryDep;
	}
	Courses** getCourseList()
	{
		return course_list;
	}
	~Teacher()
	{
		delete[]course_list;
		course_list = 0;
		primaryDep = 0;
	}
};


#endif // !Teacher_H


