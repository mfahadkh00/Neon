
#ifndef Students_H
#define Students_H
#include"Registrations.h"
#include"Person.h"
//#include"Department.h"
#include<iostream>
class Courses;

class Students:
	public virtual Person
{
private:
	//char rollno[7];
	int rollno; //191244 --> 6 digit rollno
	int course_count; //Max Workload = 5 courses
	Registrations** course_reg;
public:   
	Students();
	Students(const char n[], int roll); //const char roll[]
	Students(const char n[], const char uname[], const char pw[], int roll);
	void registercourse(Registrations* ptr);
	bool unregistercourse(Registrations* ptr);
	bool withdrawcourse(Courses* obj);

	void viewAttendance(Courses* obj);
	void viewMarks(Courses* obj);

	int getRollNo()
	{
		return rollno;

	}
	int getCourseCount()
	{
		return course_count;
	}
	Registrations** getCourseList()
	{
		return course_reg;
	}
	void print()
	{
		Person::print();
		cout << "\t" << rollno<<"\t";
		for (int i = 0; i < course_count; i++)
		{
			cout << course_reg[i]->getCourseID() << "\t";
		}
	}
	
	//Students operator=(const Students& s1);
	
	~Students();
	

	
};

#endif


