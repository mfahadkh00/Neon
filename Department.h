#ifndef Department_H
#define Department_H

#include"ManagerIT.h"
#include"Courses.h"
#include"Teacher.h"
#include"Students.h"
#include"HOD.h"
#include"TAssistant.h"
#include<fstream>
using namespace std;

class ManagerIT;
class Department
{
	char deptName[3];//EE,CS,MM
	
	ManagerIT* manager;
	HOD *deptHead;

	Teacher** staff_list; //max 100
	Courses** coursesoffered; //max 50
	Students** student_list; //max 500
	Registrations** list_Registrations; //max 2000
	
	int noOfCourses;
	int std_count;
	int facultyCount;
	int registrationsCount;

	Students* activeUser; //Login and set this
public:
	Department();
	Department( const char name[]);
	Department(const char name[], int ccount, int scount, int fcount, int rgcount, ManagerIT*mgr, HOD* HD);

	//objects created in University and pointer sent here
	void addStudent(Students* std); 
	Courses* addCourse(Courses*obj);
	void addTeacher(Teacher* obj);

	void registerCourse();
	void unregisterCourse();
	void withdrawCourse();

	void createHOD(Teacher* obj);
	void createTA();
	void HODregistration();
	void HODunRegister();
	void HODassignCourse(Teacher*obj, Courses* crs);
	void HODviewGrades();
	void viewAttendance();
	void viewMarks();
	void changeStdPassword();

	//void deleteStudent();
	//void deleteFaculty();

	void setManager(ManagerIT* guy)
	{
		manager = guy;
	}
	void setTA(TAssistant* obj, Courses* obj2)
	{
		getCoursebyID(obj2->getID())->setTA(obj);
	}
	void setActiveUser(Students* std)
	{
		activeUser = std;
	}
	void setHOD(HOD* obj)
	{
		deptHead = obj;
	}
	void setCounts(int s, int f,int c,int r)
	{
		noOfCourses = c;
		std_count = s;
		facultyCount = f;
		registrationsCount = r;
	}
	void setDepName(const char x[])
	{
		for (int i = 0; i < strlen(x); i++)
			deptName[i] = x[i];
	}
	
	void loadData();
	void saveData();
	Courses* addCoursefromFile(Courses* obj);
	void registerCoursefromFile(Students* std, char temp[]);

	int getCoursesCount()
	{
		return noOfCourses;
	}
	int getStudentCount()
	{
		return std_count;
	}
	int getFacultyCount()
	{
		return facultyCount;
	}
	int getRegistrationCount()
	{
		return registrationsCount;
	}
	char* getdepName()
	{
		return deptName;
	}
	
	ManagerIT* getManager()
	{
		return manager;
	}
	Courses* getCourse(int k)
	{
		return coursesoffered[k];
	}
	Courses** getCourseList()
	{
		return coursesoffered;
	}
	Courses* getCoursebyID(char ID[])
	{
		for (int i = 0; i < noOfCourses; i++)
		{
			if (strcmp(coursesoffered[i]->getID(),ID)==0)
			{
				return coursesoffered[i];
			}
		}
		throw 'c';
	}
	Registrations* getStdRegistration(int rn,const char id[]);
	Registrations** getRegistrationList()
	{
		return list_Registrations;
	}
	Students* getStudent(int rn);
	Students** getStudentList()
	{
		return student_list;
	}
	bool studentExists(int rn);
	bool RegistrationExists(int rn, const char id[]);
	bool TeacherCourseExists(Courses* obj, Teacher* tch)
	{
		for (int i = 0; i < tch->getCourseCount(); i++)
		{
			if (strcmp(tch->getCourseList()[i]->getID(), obj->getID()) == 0)
			{
				return true;
			}
		}
		return false;
	}
	bool courseExists(char ID[])
	{
		for (int i = 0; i < noOfCourses; i++)
		{
			if (strcmp(coursesoffered[i]->getID(), ID) == 0)
			{
				return true;
			}
		}
		return false;
	}
	Teacher* getTeacher(int ID);
	Teacher** getTeacherList()
	{
		return staff_list;
	}
	HOD* getHOD()
	{
		return deptHead;
	}
	void print()
	{
		cout << "\n\nDepartment\t"<<deptName << "\nCourseCount" << noOfCourses <<"\nrgcount" << registrationsCount<<"\n";
		cout << manager->getName() << manager->getEmpID()<< "\n\nStudent Count\t" << std_count<<"\n";
		for (int i = 0; i < std_count; i++)
			cout << student_list[i]->getName()<<"\t"<<student_list[i]->getRollNo()<<"\n";
		cout << "\n\n" << "Faculty Count\t"<<facultyCount<<"\n";
		for (int i = 0; i < facultyCount; i++)
			cout << staff_list[i]->getName() << "\t" << staff_list[i]->getEmpID() << "\n";
		//cout << deptHead->getName() << deptHead->getEmpID()<<"\n";
		for (int i = 0; i < noOfCourses; i++)
			cout << "\nCourse" << coursesoffered[i]->getName();

	}
	~Department();
};

#endif
/*
f2.open("StudentListbyDepartment.txt", ios::app);
f2.open("CourseListbyDepartment.txt", ios::app);
f2.open("StudentListbyCourses.txt", ios::app);
f3.open("Attendance.txt", ios::app);*/