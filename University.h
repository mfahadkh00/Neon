#ifndef University_H
#define University_H
#include"Department.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
class University
{
private:
	char name[30];

	Department** dept_list; //Max 10
	Students** student_masterList; //Max 1000
	Teacher** faculty_masterList; //Max 500
	TAssistant** TA_masterList; //Max 200
	ManagerIT** IT_masterList; //Max 10
	HOD** HOD_masterList;//Max 10

	int dept_count;
	int studentMasterCount;
	int facultyMasterCount;
	int TA_MasterCount;
	int IT_MasterCount;
	int HOD_MasterCount;

	int userType = 0; //1 Student, 2 HOD, 3 Teacher, 4 TA, 5 ITManager

	//friend ostream& operator<<(ostream& x, const University& obj);
	//friend istream& operator>>(istream& x, University&obj);

public:

	University();
	University(const char n[]);

	//deepcopy all dept members
	void addDept(Department* dept);
	Department* addDept(const char n[])
	{
		dept_list[dept_count++] = new Department(n);
		return dept_list[dept_count - 1];
	}
	void addStudent(Students* std)
	{
		student_masterList[studentMasterCount++] = std;
	}
	void addTA(TAssistant* std)
	{
		TA_masterList[TA_MasterCount++] = std;
	}
	void addTeacher(Teacher* obj)
	{
		faculty_masterList[facultyMasterCount++] = obj;
	}
	void addHOD(HOD* obj)
	{
		bool duplicate = false;
		for (int i = 0; i < HOD_MasterCount; i++)
		{
			if (obj->getEmpID() == HOD_masterList[i]->getEmpID())
				duplicate = true;
		}
		if (!duplicate)
		{
			HOD_masterList[HOD_MasterCount++] = obj;
			obj->getPrimaryDep()->setHOD(obj);

		}
		else
			std::cout << "HOD " << obj->getEmpID() << " Already Exists in University\n";
	}
	void addManager(ManagerIT* obj)
	{
		IT_masterList[IT_MasterCount++] = obj;

	}
	void deleteStudent(Students*obj);
	void deleteFaculty(Teacher*obj);

	void loginEngine();
	void saveData();

	void studentDashboard(Students* std);
	void teacherDashboard(Teacher* obj);
	void HOD_Dashboard(HOD* obj);
	void ITDashboard(ManagerIT* obj);
	void TA_Dashboard(TAssistant*obj);


	Department* findStudentdept(Students* std);
	Teacher* findTeacher(int id)
	{
		for (int i = 0; i < facultyMasterCount; i++)
		{
			if (faculty_masterList[i]->getEmpID() == id)
				return faculty_masterList[i];
		}
		throw 1;
	}
	Teacher* findTeacher2(int id)
	{
		for (int i = 0; i < facultyMasterCount; i++)
		{
			if (faculty_masterList[i]->getEmpID() == id)
				return faculty_masterList[i];
		}
		return 0;
	}
	HOD* findHOD(int id)
	{
		for (int i = 0; i < HOD_MasterCount; i++)
		{
			if (HOD_masterList[i]->getEmpID() == id)
				return HOD_masterList[i];
		}
		return 0;
	}

	ManagerIT* findManager(int id)
	{
		for (int i = 0; i < IT_MasterCount; i++)
		{
			if (IT_masterList[i]->getEmpID() == id)
				return IT_masterList[i];
		}
		//throw 1;
	}
	TAssistant* findTA(int rn)
	{
		for (int i = 0; i < TA_MasterCount; i++)
		{
			if (TA_masterList[i]->getRollNo() == rn)
				return TA_masterList[i];
		}
	}
	TAssistant** getTAMasterList()
	{
		return TA_masterList;
	}
	Department* getDepartment(int i)
	{
		return dept_list[i];
	}
	Department* getDepartmentbyID(char id[])
	{
		for (int i = 0; i < dept_count; i++)
		{
			if(strcmp(id,dept_list[i]->getdepName())==0)
				return dept_list[i];

		}
	}
	Department** getDepartmentptr()
	{
		return dept_list;
	}
	Students* getStudent(int rn)
	{
		for (int i = 0; i < studentMasterCount; i++)
		{
			if (rn == student_masterList[i]->getRollNo())
				return student_masterList[i];
		}
		return 0;
		//std::cout << "No matching student found\n";
	}
	int getStdCount()
	{
		return studentMasterCount;
	}
	int getFacultyCount()
	{
		return facultyMasterCount;
	}
	int getHODCount()
	{
		return HOD_MasterCount;
	}
	int getTAcount()
	{
		return TA_MasterCount;
	}
	int getDeptcount()
	{
		return dept_count;
	}
	int getITcount()
	{
		return IT_MasterCount;
	}
	char* getName()
	{
		return name;
	}
	void setCounts(int m, int n, int p, int q, int r, int s)
	{
		dept_count = m;
		studentMasterCount = n;
		facultyMasterCount = p;
		TA_MasterCount = q;
		IT_MasterCount = r;
		HOD_MasterCount = s;
	}
	void setMasterListfromFile(Teacher** tch, Students** std, TAssistant** TAs, ManagerIT** mgr, HOD** HD)
	{
		faculty_masterList = tch;
		student_masterList = std;
		TA_masterList = TAs;
		IT_masterList = mgr;
		HOD_masterList = HD;
	}
	void setName(const char x[])
	{
		for (int i = 0; i < strlen(x); i++)
			name[i] = x[i];
	}
	void print()
	{
		cout << name << "\nDepartment Count\t" << dept_count << "\n";
		for (int i = 0; i < dept_count; i++)
		{
			cout << dept_list[i]->getdepName() << "\n";
		}
	}

	
	

	~University()
	{
		delete[]dept_list;
		dept_list = 0;
		dept_count = 0;
	}
};

#endif // !University_H
