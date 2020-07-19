//#include"Department.h"
#ifndef Courses_H
#define Courses_H
//#include"Department.h"
#include"Evaluation.h"
//#include"TAssistant.h"
#include"Teacher.h"
#include"Registrations.h"
class Teacher;
class TAssistant;
class Students;
class Courses
{
	char courseID[7]; //CS117A, CS117B, EE224C
	char courseName[30]; //Programming Fundamentals
	int std_count; //max 50
	
	Teacher* course_instructor;
	TAssistant* TA;
	Registrations** std_list;
	Evaluation** eval;
	
	int** attendance; //2 lectures/week x 15 weeks in semester = 30 lectures/semester
	int total_lec; //Max 30 lectures
	bool evalInitialize;
	bool instructor;
	bool attendInitialize;

	//int** eval;
	
public:
	Courses();
	Courses(const char ID[], const char name[]);
	Courses(const char ID[], const char name[],Teacher* ttemp);
	
	void initializeAttendance();
	void manageAttendance();
	void viewAttendance(int y);
	
	void initializeEvaluation();
	void initializeEvaluationfromFile(int a, int b, int c, int d, int e);
	void manageEvaluation();
	void manageTAEvaluation();
	void viewEvaluation(const int &rn);

	void HOD_Grades();
	
	void registerStudent(Registrations* std);
	bool unRegisterStudent(Registrations* std);
	bool withdrawCourse(Registrations* std);

	char* getID()
	{
		return courseID;

	}
	char* getName()
	{
		return courseName;
	}
	int getStudentcount()
	{
		return std_count;
	}
	void createTA(Students* std)
	{
		TA = (TAssistant*)std;
		
	}
	void setTA(TAssistant* obj)
	{
		TA = obj;
	}
	void SetTeacher(Teacher* obj)
	{
		course_instructor = obj;
	}
	Teacher* getTeacher()
	{
		return course_instructor;
	}
	int getStdCount()
	{
		return std_count;
	}
	Evaluation** getEvalPtr()
	{
		return eval;
	}
	Registrations** getRgsPtr()
	{
		return std_list;
	}
	TAssistant* getTA()
	{
		return TA;
	}
	Evaluation** getEvaluationList()
	{
		return eval;
	}
	void print()
	{
		cout << courseID << '\t' << courseName << '\t'
			<< std_count << '\t'<<course_instructor->getName()<<course_instructor->getEmpID()<<"\n";
	}
	int getTotalLec()
	{
		return total_lec;
	}
	int getAttendance(int k)
	{
		return *attendance[k];
	}
	bool getEvalInitialzier()
	{
		return evalInitialize;
	}
	bool getAttendInitialize()
	{
		return attendInitialize;
	}
	void setAttendance(int scount,int lcount,int m)
	{
		attendance[scount][lcount] = m;
	}
	void setTotalLec(int k)
	{
		total_lec = k;
	}
	void setEvalInitialzier(bool k)
	{
		evalInitialize=k;
	}
	
	
	
	~Courses();
};

#endif // !Courses_H


