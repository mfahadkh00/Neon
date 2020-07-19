#include"Person.h"
#include"Students.h"
#include"Employee.h"
#include"ManagerIT.h"
#include"Teacher.h"
#include"Courses.h"
#include"Teacher.h"
#include"Department.h"
#include"University.h"
#include<iostream>
#include<fstream>
using namespace std;
void loadData(University& uni, Teacher**& tch, Students**& std, TAssistant**& TAs, ManagerIT**& mgr, HOD**& HD)
{
	ifstream fin;

	//University File
	fin.open("University.txt", ios::in);
	while (!fin.eof())
	{
		int dcount, scount, fcount, tcount, mcount, hcount;
		char n[30];

		fin.getline(n, 30, ',');
		//					fin.ignore(1,'\n');;
		fin >> dcount;
		fin.ignore(1, '\n');;
		//for (int i = 0; i < dcount; i++)
		//{
			//fin.get(n, ',');
			//					fin.ignore(1,'\n');;
		fin >> scount;
		fin.ignore(1, '\n');;
		fin >> fcount;
		fin.ignore(1, '\n');;
		fin >> tcount;
		fin.ignore(1, '\n');;
		fin >> mcount;
		fin.ignore(1, '\n');;
		fin >> hcount;

		//dept[i]->setDepName(n);
		//dept = new Department * [dcount];
		tch = new Teacher * [fcount];
		std = new Students * [scount];
		mgr = new ManagerIT * [mcount];
		HD = new HOD * [hcount];
		TAs = new TAssistant * [tcount];

		/*///*for (int i = 0; i < dcount; i++)
		//	dept[i] = new Department;*/
		//for (int i = 0; i < fcount; i++)
		//	tch[i] = new Teacher;
		///*for (int i = 0; i < scount; i++)
		//	std[i] = new Students;*/
		//for (int i = 0; i < tcount; i++)
		//	TAs[i] = new TAssistant;
		//for (int i = 0; i < mcount; i++)
		//	mgr[i] = new ManagerIT;
		//for (int i = 0; i < hcount; i++)
		//	HD[i] = new HOD;*/

		uni.setMasterListfromFile(tch, std, TAs, mgr, HD);
		//uni.setCounts(dcount, scount, fcount, tcount, mcount, hcount);
		uni.setName(n);
		//}
	}
	fin.close();
	//removing courses
	fin.open("StudentMasterList.txt", ios::in);
	if (fin)
	{
		//while (!fin.eof())
		//{
		int scount;
		fin >> scount;
		for (int i = 0; i < scount; i++)
		{
			char name[30], uname[10], pw[7];
			int rn, ccount;
			fin.ignore(1, '\n');
			fin.getline(name, 30, ',');
			//fin.ignore(1, '\n');;
			fin.getline(uname, 10, ',');
			//fin.ignore(1, '\n');;
			fin.getline(pw, 7, ',');
			//fin.ignore(1, '\n');;
			fin >> rn;
			//fin.ignore(1, '\n');;
			//fin >> ccount;
			//fin.ignore(1, '\n');;

			std[i] = new Students(name, uname, pw, rn);
			uni.addStudent(std[i]);
		}
		//}
	}
	else
		cout << "Failed to read StudentMasterList\n";
	fin.close();

	fin.open("IT_MasterList.txt", ios::in);
	if (fin)
	{
		//while (!fin.eof())
		//{
		int fcount;
		fin >> fcount;
		for (int i = 0; i < fcount; i++)
		{
			char name[30], uname[10], pw[7], d[3];
			int empID, ccount;
			fin.ignore(1, '\n');
			fin.getline(name, 30, ',');
			//fin.ignore(1, '\n');
			fin.getline(uname, 10, ',');
			//fin.ignore(1, '\n');
			fin.getline(pw, 7, ',');
			//fin.ignore(1, '\n');
			fin >> empID;
			//fin.ignore(1, '\n');

			mgr[i] = new ManagerIT(name, empID, uname, pw);
			uni.addManager(mgr[i]);
		}
		//}
	}
	else
		cout << "Failed to read ITMasterList\n";
	fin.close();


	fin.open("DepartmentMasterList.txt", ios::in);
	if (fin)
	{
		//SetManager and HOD here or just manager cuz setting HOD in HODMasterList
		//while (!fin.eof())
		//{
			//Dcount
			//DeptName,ITManager_empID \n
		char dname[30];
		int ITid, dcount = 0;
		fin >> dcount;
		fin.ignore(1, '\n');
		for (int i = 0; i < dcount; i++)
		{
			fin.getline(dname, 30, ',');
			//fin.ignore(1, '\n');
			fin >> ITid;

			//dept[i] =new Department(dname);
			//Composition
			uni.addDept(dname);

			ManagerIT* temp = uni.findManager(ITid);
			uni.getDepartmentptr()[i]->setManager(temp);

		}

		//}
	}
	else
		cout << "Failed to read DeptMasterList\n";
	fin.close();

	//CourseList/Count Removed from TeacherMasterList
	fin.open("TeachersMasterList.txt", ios::in);
	if (fin)
	{
		//while (!fin.eof())
		//{
		int fcount;
		fin >> fcount;
		fin.ignore(1);
		for (int i = 0; i < fcount; i++)
		{
			char name[30], uname[10], pw[7], d[3], cid[7];
			int empID, ccount;
			fin.getline(name, 30, ',');
			//fin.ignore(1);
			fin.getline(uname, 10, ',');
			//fin.ignore(1);
			fin.getline(pw, 7, ',');
			//fin.ignore(1, '\n');;
			fin >> empID;
			fin.ignore(1, '\n');
			fin.getline(d, 3, '\n');  //Match D with Dept List
			//fin.ignore(1, '\n');
			 //fin.ignore(1, '\n');;
			//fin >> ccount;
			//fin.ignore(1, '\n');;

			//IF teacher teaches all courses from single dep then this will work
			//for sake of getting it done we gonna assume only one dep
			Department* dtemp = uni.getDepartmentbyID(d);
			//with CourseCount tch[i] = new Teacher(name, uname, pw, empID, ccount, dtemp);
			tch[i] = new Teacher(name, uname, pw, empID, dtemp);
			uni.addTeacher(tch[i]);
			//Not reading courses rn

			//for (int j = 0; j < ccount; j++)
			//{
			//	fin.ignore();
			//	fin.getline(cid,7,',');
			//	fin.ignore(1, '\n');
			//	Courses* ctemp=dtemp->getCoursebyID(cid);
			//	tch[i]->addCourse(ctemp);
			//	coursetemptemp->SetTeacher(tch[i]);
			//}
		}
		//}
	}
	else
		cout << "Failed to read TeacherMasterList\n";
	fin.close();

	fin.open("HODMasterList.txt", ios::in);
	if (fin)
	{
		//while (!fin.eof())
		//{
			//ignoring courses for now
		int fcount;
		fin >> fcount;
		fin.ignore();

		for (int i = 0; i < fcount; i++)
		{
			char name[30], uname[10], pw[7], d[3], cid[7];
			int empID, ccount;
			fin.getline(name, 30, ',');
			//fin.ignore(1);
			fin.getline(uname, 10, ',');
			//fin.ignore(1);
			fin.getline(pw, 7, ',');
			//fin.ignore(1, '\n');;
			fin >> empID;
			fin.ignore(1, '\n');
			fin.getline(d, 3, '\n');
			//fin >> ccount;
			//fin.ignore(1, '\n');;

			Department* dtemp = uni.getDepartmentbyID(d);
			HD[i] = new HOD(name, uname, pw, empID, dtemp);
			dtemp->setHOD(HD[i]);
			uni.addHOD(HD[i]);
			//for (int j = 0; j < ccount; j++)
			//{
			//	fin.getline(cid, 7, ',');
			//	fin.ignore(1, '\n');
			//	Courses* ctemp = dtemp->getCoursebyID(cid);
			//	HD[i]->addCourse(ctemp);
			//	ctemp->SetTeacher(tch[i]);
			//}

		}
		//}
	}
	else
		cout << "Failed to read HODMasterList\n";
	fin.close();

	//Creating courses
	fin.open("CourseListbyDepartment.txt", ios::in);
	if (fin)
	{

		fin.ignore(1, '\n');
		for (int i = 0; i < uni.getDeptcount(); i++)
		{
			char dname[3], CID[7], cname[30];
			int ccount, empID, RN, scount;
			fin.getline(dname, 3, ',');
			//fin.ignore(1, '\n');;
			fin >> ccount;
			fin.ignore(1, '\n');
			for (int j = 0; j < ccount; j++)
			{
				fin.getline(CID, 7, ',');
				//fin.ignore(1);
				fin.getline(cname, 30, ',');
				//fin.ignore(1);
				fin >> scount;
				fin.ignore(1, '\n');;
				fin >> empID;
				fin.ignore(1, '\n');;
				fin >> RN;

				//TAssistant* tatemp = uni.findTA(RN);
				if (uni.findTeacher2(empID) == 0) //HOD NOT TEACHER
				{
					HOD* htemp = uni.findHOD(empID);
					Courses Ctemp(CID, cname, htemp);
					Courses* c2 = uni.getDepartmentptr()[i]->addCoursefromFile(&Ctemp);
					htemp->addCourse(c2);
					c2->SetTeacher(htemp);
					//tatemp->setCourse(c2);
					//c2->setTA(tatemp);

				}
				else
				{
					Teacher* ttemp = uni.findTeacher(empID);
					Courses Ctemp(CID, cname, ttemp);
					Courses* c2 = uni.getDepartmentptr()[i]->addCoursefromFile(&Ctemp);
					ttemp->addCourse(c2);
					c2->SetTeacher(ttemp);
					//tatemp->setCourse(c2);
					//c2->setTA(tatemp);



				}
				//TAssistant* tatemp = uni.findTA(RN);
				//Courses Ctemp(CID, cname, ttemp, tatemp);


				//new object created in addCoursefromFile and parameters copied
				//c2->setTA(tatemp);
				fin.ignore(1, '\n');

			}

			//}
		}
	}
	else
		cout << "Failed to read CourseListbyDepartment\n";
	fin.close();

	fin.open("TAMasterList.txt", ios::in);
	if (fin)
	{
		//Name, username, pw, TACID, rollno, empID, depName
		int TAcount;
		fin >> TAcount;
		fin.ignore(1, '\n');
		for (int i = 0; i < TAcount; i++)
		{
			char name[30], uname[10], pw[7], TACID[7], dname[3];
			int rn, emp;
			fin.getline(name, 30, ',');
			fin.getline(uname, 10, ',');
			fin.getline(pw, 7, ',');
			fin.getline(dname, 3, ',');
			fin.getline(TACID, 7, ',');
			//fin.ignore();
			fin >> rn;
			fin.ignore();
			fin >> emp;
			Department* d = uni.getDepartmentbyID(dname);
			Courses* ctemp = d->getCoursebyID(TACID);
			TAs[i] = new TAssistant(name, uname, pw, TACID, rn, emp, d, ctemp);
			uni.addTA(TAs[i]);
			ctemp->setTA(TAs[i]);
			fin.ignore(1, '\n');
		}
		//cout << uni.getTAMasterList()[0]->getName() << "\n" << uni.getTAMasterList()[1]->getName();;
		//system("pause");

	}
	else
		cout << "TAMasterList could not be read\n";
	fin.close();


	//Registering courses
	fin.open("StudentListbyCourses.txt", ios::in);
	if (fin)
	{
		//while (!fin.eof())
		//{
		fin.ignore(1, '\n');
		char dname[3], CID[7];
		int ccount, rn, scount;
		for (int i = 0; i < uni.getDeptcount(); i++)
		{
			fin.getline(dname, 3, ',');
			fin >> ccount;
			fin.ignore(1, '\n');;

			for (int j = 0; j < ccount; j++)
			{
				fin.getline(CID, 7, ',');
				//fin.ignore(1, '\n');;
				fin >> scount;
				fin.ignore(1, '\n');

				for (int k = 0; k < scount; k++)
				{
					fin >> rn;
					fin.ignore(1, '\n');;

					//Register Students from same Deptfunction but use file
					Students* temp = uni.getStudent(rn);
					uni.getDepartmentbyID(dname)->addStudent(temp);
					uni.getDepartmentbyID(dname)->registerCoursefromFile(temp, CID);

				}
			}

		}
		//}
	}
	else
		cout << "Couldnt read StudentListbyCourses\n";
	fin.close();
	
	fin.open("StudentListbyDepartment.txt", ios::app);
	if (fin)
	{
		//while (!fin.eof())
		//{
		fin.ignore(1, '\n');
		char dname[3], CID[7];
		int ccount, rn, scount;
		for (int i = 0; i < uni.getDeptcount(); i++)
		{
			fin.getline(dname, 3, ',');
			//fin.ignore(1, '\n');;
			fin >> scount;
			fin.ignore(1, '\n');

			for (int j = 0; j < scount; j++)
			{
				fin >> rn;
				fin.ignore(1, '\n');
				Students* temp = uni.getStudent(rn);
				uni.getDepartmentbyID(dname)->addStudent(temp);
				//fin.ignore(1, '\n');


			}
		}
		//}
	}
	else
		cout << "\nStudent-Dep not read\n";
	fin.close();
	
	fin.open("TeacherListbyDepartment.txt", ios::app);
	if (fin)
	{
		//while (!fin.eof())
		//{
			char dname[3], CID[7];
			int ccount, empID, tcount;
			for (int i = 0; i < uni.getDeptcount(); i++)
			{
				fin.getline(dname, 3, ',');
				//fin.ignore(1, '\n');;
				fin >> tcount;
				fin.ignore(1, '\n');

				for (int j = 0; j < tcount; j++)
				{
					fin >> empID;
					fin.ignore(1, '\n');
					Teacher* temp = uni.findTeacher(empID);
					uni.getDepartmentbyID(dname)->addTeacher(temp);
				}
			}
		//
	}
	else
		cout << "\nTeacher-Dep not read\n";
	fin.close();

	fin.open("Attendance.txt", ios::in);
	if (fin)
	{
		fin.ignore(1, '\n');

		int rn, scount, lcount, stat, initialized;
		char dname[3], cid[7];
		for (int z = 0; z < uni.getDeptcount(); z++)
		{
			fin.getline(dname, 3, '\n');
			int ccount = uni.getDepartmentbyID(dname)->getCoursesCount();
			//fin.ignore(1, '\n');
			for (int x = 0; x < ccount; x++)
			{
				fin.getline(cid, 7, ',');
				//fin.ignore(1, '\n');
				fin >> scount;
				fin.ignore(1, '\n');
				fin >> lcount;
				fin.ignore();
				fin >> initialized;
				if (initialized == 1)
				{
					Courses* temp = uni.getDepartmentbyID(dname)->getCoursebyID(cid);
					temp->initializeAttendance();
					temp->setTotalLec(lcount);
					for (int i = 0; i < scount; i++)
					{
						fin >> rn;
						fin.ignore(1, '\n');

						for (int j = 1; j <= lcount; j++)
						{
							fin >> stat;
							fin.ignore(1, '\n');
							temp->setAttendance(i, j, stat);
						}
					}
				}
				fin.ignore(1, '\n');

			}
		}

	}
	else
		cout << "\Failed to read Attendance\n";
	fin.close();
	
	////Handled in TeacherMasterList
//fin.open("CoursesbyTeacher.txt", ios::app);


	/*//if (fin)
	//{
	//	while (!fin.eof())
	//	{
	//		char dname[3], CID[7];
	//		int ccount, empID, tcount;
	//		for (int i = 0; i < uni.getDeptcount(); i++)
	//		{
	//			fin.getline(dname, 3, ',');
	//			fin.ignore(1, '\n');;
	//			fin >> tcount;
	//			fin.ignore(1, '\n');

	//			for (int j = 0; j < tcount; j++)
	//			{
	//				fin >> empID;
	//				fin.ignore(1, '\n');
	//				Teacher* temp = uni.findTeacher(empID);
	//				uni.getDepartmentbyID(dname)->addTeacher(temp);

	//			}
	//		}
	//	}
	//}
	//else
	//	cout << "\nTeacher-Dep not opened\n";
	//fin.close();
	*/
	fin.open("Evaluations.txt", ios::in);
	if (fin)
	{
		for (int i = 0; i < uni.getDeptcount(); i++)

		{
			char dname[3], cid[7], grade[2];
			int rn, scount, qcount, acount;
			float qmark, amark, omark, weight;
			bool wdrw, evalInitial;
			fin.getline(dname, 3, '\n');
			int ccount = uni.getDepartmentbyID(dname)->getCoursesCount();
			//fin.ignore(1, '\n');
			for (int x = 0; x < ccount; x++)
			{
				int w1, w2, w3, w4, w5,wth;
				fin.getline(cid, 7,',');
				//fin.ignore(1, '\n');
				fin >> scount;
				fin.ignore(1, '\n');
				fin >> evalInitial;
				fin.ignore(1, '\n');
				if (evalInitial)
				{
					fin >> w1;
					fin.ignore();
					fin >> w2;
					fin.ignore();
					fin >> w3;
					fin.ignore();
					fin >> w4;
					fin.ignore();
					fin >> w5;
					fin.ignore();
					uni.getDepartmentbyID(dname)->getCoursebyID(cid)->initializeEvaluationfromFile(w1, w2, w3, w4, w5);

					//RN,quizcount,q1,q2,q3,asgcount,asg1,asg2,asg3,mid,project,final,totalabs
					//,gpa,weightage[5],grade,boolWithdraw
					Evaluation** temp = uni.getDepartmentbyID(dname)->getCoursebyID(cid)->getEvaluationList();
					for (int b = 0; b < scount; b++)
					{
						temp[b]->initializeEval();
						fin >> rn;
						fin.ignore(1, '\n');
						fin >> qcount;
						fin.ignore(1, '\n');
						temp[b]->setRollNo(rn);
						for (int j = 0; j < qcount; j++)
						{
							fin >> qmark;
							fin.ignore(1, '\n');

							temp[b]->setQmark(qmark);
						}

						fin >> acount;
						fin.ignore(1, '\n');
						for (int j = 0; j < acount; j++)
						{
							fin >> amark;
							fin.ignore(1, '\n');
							temp[b]->setAmark(amark);
						}
						for (int j = 1; j <= 5; j++)
						{
							fin >> omark;
							temp[b]->setotherMark(j, omark);
							fin.ignore(1, '\n');
						}
						//for (int j = 0; j < 5; j++)
						//{
							//fin >> weight;
							//temp[b]->setWeight(j, omark);
							//fin.ignore(1, '\n');
						//}

						fin.getline(grade, 2, ',');
						//fin.ignore(1, '\n');
						fin >> wth;
						fin.ignore(1, '\n');
						if (wth == 0)
						{
							temp[b]->setWithdraw(false);
						}
						else
							temp[b]->setWithdraw(true);

						temp[b]->setGrade(grade);
						//fin.ignore(1, '\n');
					}
				}
			}
		}
	}
	else
		cout << "\nFailed to read Evaluation\n";
	fin.close();

//	system("pause");
	system("CLS");
	

}
void main()
{
	University FAST("FAST");
	Students** std = 0;
	Teacher** trs = 0;
	HOD** HDD = 0;
	ManagerIT** IT = 0;
	TAssistant** TA = 0;
/*	Students s1("Fahad", 191244);
	Students s2("Ali", 174351);
	Students s3("Imran", 191144);

	Department EE("EE");
	Department CS("CS");

	Courses CS1("CS117A", "Programming Fundamentals A");
	Courses CS2("EE221A", "Assembly Language A");
	Courses CS3("MT224A", "Advanced Calculus B");

	Teacher t1("Alex", 1345, &EE);
	Teacher t2("Jacob", 1745, &EE);

	HOD HD1("Asif", 8525, &EE);
	HOD HD2("Zeeshan", 7417, &CS);
	
	ManagerIT EEmanager("David", 1485, "user12345", "pw1234");
	ManagerIT CSmanager("Imran", 5271, "hell12345", "pw1234");

	Students** std=new Students*[100];
	Teacher** trs =new Teacher * [50];
	HOD** HDD=new HOD*[20];
	ManagerIT** IT=new ManagerIT*[20];
	TAssistant** TA=new TAssistant*[50];

	FAST.setMasterListfromFile(trs, std, TA, IT, HDD);
	Department* d1=FAST.addDept("EE");
	//Department* d2=FAST.addDept("CS");
	Courses*c1=d1->addCourse(&CS1);
	Courses* c2=d1->addCourse(&CS2);
	Courses*c3=d1->addCourse(&CS3);
	TAssistant ta1("Zane", "myTA12345", "123456", c1->getID(), 123385, 2311, d1, c1);
	TAssistant ta2("Mick", "king12345", "123456", c2->getID(), 321385, 4711, d1, c2);
	TAssistant ta3("Mary", "TA1234567", "123456", c3->getID(), 852147, 7411, d1, c3);

	d1->HODassignCourse(&t1, c1);
	d1->HODassignCourse(&t2, c2);
	d1->HODassignCourse(&t2, c3);

	d1->addTeacher(&t1);
	d1->addTeacher(&t2);
	d1->setTA(&ta1, c1);
	FAST.addTA(&ta1);
	d1->setTA(&ta2, c2);
	FAST.addTA(&ta2);
	d1->setTA(&ta3, c3);
	FAST.addTA(&ta3);

	FAST.addHOD(&HD1);
	//FAST.addHOD(&HD2);
	FAST.addStudent(&s1);
	FAST.addStudent(&s2);
	FAST.addTeacher(&t1);
	FAST.addTeacher(&t2);
	FAST.addStudent(&ta1);
	FAST.addStudent(&ta2);
	FAST.addStudent(&ta3);
	FAST.addManager(&EEmanager);
	//FAST.addManager(&CSmanager);

	//= MIT.getDepartment(0);
	//Department* d2 = MIT.getDepartment(1);

	d1->addStudent(&s1);
	d1->addStudent(&s2);
	d1->addStudent(&ta1);
	d1->addStudent(&ta2);
	d1->addStudent(&ta3);
	d1->setManager(&EEmanager);
	//d2->setManager(&CSmanager);
	d1->registerCoursefromFile(&s1, c1->getID());
	d1->registerCoursefromFile(&s2, c1->getID());
	d1->registerCoursefromFile(&s1, c2->getID());
	d1->registerCoursefromFile(&s2, c2->getID());
	HD1.setuser("hod123456");
	HD1.setpw("123456");
	HD2.setuser("987654hod");
	HD2.setpw("123456");
	s1.setuser("123456std");
	s1.setpw("123456");
	s2.setuser("king12345");
	s2.setpw("123456");
	t1.setuser("std456789");
	t1.setpw("123456");
	t1.setuser("alpha1234");
	t1.setpw("123456");
	//c1->initializeEvaluation();
	//c2->initializeEvaluation();
	//c1->initializeAttendance();
	//c2->initializeAttendance();
	//cout << d1->getCourseList()[2]->getID();*/
		
	//FAST.saveData();
	//system("CLS");
	loadData(FAST,trs,std,TA, IT, HDD);
	FAST.loginEngine();


	//Testing Inputs
	//system("CLS");
	/*FAST.print();
	cout << "\nStudentMasterList\n";
	for (int i = 0; i < FAST.getStdCount(); i++)
	{
		std[i]->print();
		cout << "\n";
	}
	cout << "\n\nITMasterList\n";
	for (int i = 0; i < FAST.getITcount(); i++)
	{
		IT[i]->print();
		cout << "\n";
	}
	cout << "\n\nTeacherMasterlist\n";
	for (int i = 0; i < FAST.getFacultyCount(); i++)
	{
		trs[i]->print();
		cout << "\n";
	}
	cout << "\n\nHODMasterlist\n";
	for (int i = 0; i < FAST.getHODCount(); i++)
	{
		HDD[i]->print();
		cout << "\n";
	}
	cout << "\n\nTAMasterlist\n";
	for (int i = 0; i < FAST.getTAcount(); i++)
	{
		TA[i]->print();
		cout << "\n";
	}
	for (int i = 0; i < FAST.getDeptcount(); i++)
	{
		FAST.getDepartmentptr()[i]->print();
		cout << "\n";
		for (int j = 0; j < FAST.getDepartmentptr()[i]->getCoursesCount(); j++)
		{
			FAST.getDepartmentptr()[i]->getCourseList()[j]->print();
		}

	}

	system("pause");
	system("CLS");
	
	FAST.loginEngine();
	
	
	
	
	
	//	cout << IT[0]->getName();
	//cout << endl << t1.getName();
	//dept[0]->print();
	//dept[1]->print();


	/*ofstream fout;
	fout.write((char*)&FAST, sizeof(FAST));
	fout.write((char*)&EE, sizeof(EE));
	fout.close();


	cout << "Data Output\n";
	
	University NUST;
	Students m1;
	Department XY;
	ifstream fin;
	fin.open("University.txt", ios::in);
	fin.read((char*)&NUST, sizeof(NUST));
	fin.read((char*)&XY, sizeof(XY));
	fin.close();*/

	//ofstream fout;
	//fout.open("University.txt", ios::app);
	//fout << FAST.getName() << "," << FAST.getDeptcount() << "," << FAST.getStdCount() << "," << FAST.getFacultyCount() << "," << FAST.getHODCount() << "," << FAST.getTAcount();
	//fout.close();
	//cout << "Data Output\n";
	//cout << NUST;
	//cout << NUST.getName() << NUST.getDeptcount() << "\n" << XY.getdepName() << XY.getStudentCount();
}