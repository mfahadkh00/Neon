#include"University.h"
using namespace std;

University::University()
{
	//strcpy_s(name, "Default Uni");

	dept_list = new Department * [10];
	student_masterList = 0;
	faculty_masterList = 0;
	TA_masterList = 0;
	IT_masterList =0;
	HOD_masterList = 0;

	dept_count = 0;
	studentMasterCount = 0;
	facultyMasterCount = 0;
	TA_MasterCount = 0;
	IT_MasterCount = 0;
	HOD_MasterCount = 0;
}

University::University(const char n[])
{
	for (int i = 0; i < strlen(n); i++)
	{
		name[i] = n[i];
	}

	dept_list = new Department * [10];
	student_masterList = 0;
	faculty_masterList = 0;
	TA_masterList = 0;
	IT_masterList = 0;
	HOD_masterList = 0;


	dept_count = 0;
	studentMasterCount = 0;
	facultyMasterCount = 0;
	TA_MasterCount = 0;
	IT_MasterCount = 0;
	HOD_MasterCount = 0;

}

void University::addDept(Department* dept)
{
	dept_list[dept_count++] = new Department(dept->getdepName());
}

void University::loginEngine()
{
	system("CLS");
	char uname[10];
	char pw[7];
	cout << "\n\n\t\t\t\tWelcome to Neon_Fadi \n\n";
	cout << "\t\t\t     Make an appropriate selection\n1. Student\n2.Head of Department\n3.Teacher \n4.Teacher Assistant\n5.IT Manager\n\n\Select an option: ";
	cin >> userType;
	//flush screen if not working
	//system("CLS");

	cout << "\n\n\t\tEnter Username:\t\t";
	cin.ignore();
	cin.getline(uname, 10);

	cout << "\t\tEnter Password:\t\t";
	//cin.ignore();
	cin.getline(pw, 7);

	bool login = 0;

	switch (userType)
	{
	case(4)://TA include EmpIDs
	{
		for (int i = 0; i < TA_MasterCount; i++)
		{
			if (strcmp(TA_masterList[i]->getuser(), uname) == 0)
			{
				if (strcmp(TA_masterList[i]->getpw(), pw) == 0)
				{
					TA_Dashboard(TA_masterList[i]);
					login = 1;
				}
				else
				{
					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "\t\t\tRe-Enter Password:\t\t";
					cin.ignore();
					cin.getline(pw, 7);

					if (strcmp(TA_masterList[i]->getpw(), pw) == 0)
					{
						TA_Dashboard(TA_masterList[i]);
						login = 1;
					}

					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "To reset password press 1, else press any other number\n";
					int x = 0;
					cin >> x;

					if (x == 1)
					{
						char newPw[7];
						cout << "\t\t\tEnter New Password:\t";
						cin.ignore();
						cin.getline(newPw, 7);
						TA_masterList[i]->setpw(newPw);

						TA_Dashboard(TA_masterList[i]);
						login = 1;
					}

				}
			}

		}
		if (!login)
		{
			cout << "\t\t\tCould not find a matching Teacher Assistant Account. Please Try Again\n";
			break;
		}
		break;

	}
	case(1): //Student 
	{
		for (int i = 0; i < studentMasterCount; i++)
		{
			if (strcmp(student_masterList[i]->getuser(), uname) == 0)
			{
				//cout<<student_masterList[i]->getpw()<<"\t"<<pw<<endl;
				if (strcmp(student_masterList[i]->getpw(), pw) == 0)
				{
					studentDashboard(student_masterList[i]);
					login = 1;
					//cout << "Login Successful\n";
				}
				else
				{
					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "\t\t\tRe-Enter Password:\t\t";
					cin.ignore();
					cin.getline(pw, 7);

					if (strcmp(student_masterList[i]->getpw(), pw) == 0)
					{
						studentDashboard(student_masterList[i]);
						login = 1;
					}

					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "To reset password press 1, else press any other number\n";
					int x = 0;
					cin >> x;

					if (x == 1)
					{
						char newPw[7];
						cout << "\t\t\tEnter New Password:\t";
						cin.ignore();
						cin.getline(newPw, 7);
						student_masterList[i]->setpw(newPw);

						studentDashboard(student_masterList[i]);
						login = 1;
					}

				}
			}

		}
		if (!login)
		{
			cout << "\t\t\tCould not find a matching Student Account. Please Try Again\n";
			break;
		}
		break;
	}
	case(2): //HOD
	{
		for (int i = 0; i < HOD_MasterCount; i++)
		{
			if (strcmp(HOD_masterList[i]->getuser(), uname) == 0)
			{
				if (strcmp(HOD_masterList[i]->getpw(), pw) == 0)
				{
					HOD_Dashboard(HOD_masterList[i]);
					login = 1;
				}
				else
				{
					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "\t\t\tRe-Enter Password:\t\t";
					cin.ignore();
					cin.getline(pw, 7);

					if (strcmp(HOD_masterList[i]->getpw(), pw) == 0)
					{
						HOD_Dashboard(HOD_masterList[i]);
						login = 1;
					}

					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "To reset password press 1, else press any other number\n";
					int x = 0;
					cin >> x;

					if (x == 1)
					{
						char newPw[7];
						cout << "\t\t\tEnter New Password:\t";
						cin.ignore();
						cin.getline(newPw, 7);
						HOD_masterList[i]->setpw(newPw);

						HOD_Dashboard(HOD_masterList[i]);
						login = 1;
					}

				}
			}

		}
		if (!login)
		{
			cout << "\t\t\tCould not find a matching HOD Account. Please Try Again\n";
		}
		break;

	}
	case(3)://Teacher
	{
		for (int i = 0; i < facultyMasterCount; i++)
		{
			if (strcmp(faculty_masterList[i]->getuser(), uname) == 0)
			{
				if (strcmp(faculty_masterList[i]->getpw(), pw) == 0)
				{
					teacherDashboard(faculty_masterList[i]);
					login = 1;
				}
				else
				{
					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "\t\t\tRe-Enter Password:\t\t";
					cin.ignore();
					cin.getline(pw, 7);

					if (strcmp(faculty_masterList[i]->getpw(), pw) == 0)
					{
						teacherDashboard(faculty_masterList[i]);
						login = 1;
					}

					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "To reset password press 1, else press any other number\n";
					int x = 0;
					cin >> x;

					if (x == 1)
					{
						char newPw[7];
						cout << "\t\t\tEnter New Password:\t";
						cin.ignore();
						cin.getline(newPw, 7);
						faculty_masterList[i]->setpw(newPw);

						teacherDashboard(faculty_masterList[i]);
						login = 1;
					}

				}
			}

		}
		if (!login)
		{
			cout << "\t\t\tCould not find a matching Teacher Account. Please Try Again\n";
		}
		break;
	}
	case(5)://IT Manager
	{
		for (int i = 0; i < IT_MasterCount; i++)
		{
			if (strcmp(IT_masterList[i]->getuser(), uname) == 0)
			{
				if (strcmp(IT_masterList[i]->getpw(), pw) == 0)
				{
					//Show IT Dashboard
					login = 1;
				}
				else
				{
					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "\t\t\tRe-Enter Password:\t\t";
					cin.ignore();
					cin.getline(pw, 7);

					if (strcmp(IT_masterList[i]->getpw(), pw) == 0)
					{
						//Show IT Dashboard
						login = 1;
					}

					cout << "\t\t\tInvalid Password. Must be 6 characters\n";
					cout << "To reset password press 1, else press any other number\n";
					int x = 0;
					cin >> x;

					if (x == 1)
					{
						char newPw[7];
						cout << "\t\t\tEnter New Password:\t";
						cin.ignore();
						cin.getline(newPw, 7);
						IT_masterList[i]->setpw(newPw);

						//Show IT Dashboard
						login = 1;
					}

				}
			}

		}
		if (!login)
		{
			cout << "\t\t\tCould not find a matching IT Manager Account. Please Try Again\n";
		}
		break;
	}
	default:
	{
		cout << "\t\t\tInvalid Choice Entered. Exiting Neon_Fadi\n";
		userType = 0;
		break;
	}

	}
}

void University::deleteStudent(Students*std)
{
	//{
//	std::cout << "Enter Student Roll No to delete account. This will delete all related data as well\n";
//	int rn = 0;
//	std::cin >> rn;
//
//	if (studentExists(rn))
//	{
//		Students* temp = getStudent(rn);
//		Registrations** courseList = temp->getCourseList();
//		int tempCount = temp->getCourseCount();
//		for (int i = 0; i < tempCount; i++)
//		{
//			for (int k = 0; k < registrationsCount; k++)
//			{
//				//Find Match with RollNo first and then CourseID
//				if (list_Registrations[k]->getRollNo() == temp->getRollNo())
//				{
//					for (int j = 0; j < noOfCourses; j++)
//					{
//						if (strcmp(courseList[i]->getCourseID(), coursesoffered[j]->getID()) == 0)
//						{
//							coursesoffered[j]->unRegisterStudent(courseList[i]);
//							//std::cout << "before sorting\n";
//
//							delete list_Registrations[k];
//
//							//Rearrange master registrations array
//							for (int m = j; m < registrationsCount - 1; m++)
//							{
//								list_Registrations[m] = list_Registrations[m + 1];
//								//std::cout << "sorting\n";
//							}
//							//std::cout << "after sorting\n";
//
//
//							list_Registrations[registrationsCount - 1] = 0;
//							registrationsCount--;
//
//							std::cout << "Registration of " << temp->getRollNo() << " for " << coursesoffered[j]->getID() << " removed from Master List\n";
//
//
//							j = noOfCourses;
//							k = registrationsCount;
//							//tempCount--;
//
//						}
//
//					}
//
//				}
//
//			}
//
//
//		}
//
//		//Delete student from Student List
//		for (int i = 0; i < std_count; i++)
//		{
//			if (temp->getRollNo() == student_list[i]->getRollNo())
//			{
//				//delete student_list[i];
//
//				//Rearrange students array
//				for (int k = i; k < std_count; k++)
//					student_list[k] = student_list[k + 1];
//
//
//				student_list[std_count - 1] = 0;
//				std_count--;
//
//				i = std_count;
//				std::cout << "Student deleted from " << deptName << "\n";
//			}
//		}
//
//	}
//	else
//		std::cout << "Invalid Roll Number entered. Student does not exist in Department\n";
//
//}
//
//void Department::deleteFaculty()
//{
//	std::cout << "Enter Faculty ID to delete account. This will delete all related data as well\n";
//	int rn = 0;
//	std::cin >> rn;
//
//	if (studentExists(rn))
//	{
//		Students* temp = getStudent(rn);
//		Registrations** courseList = temp->getCourseList();
//		int tempCount = temp->getCourseCount();
//		for (int i = 0; i < tempCount; i++)
//		{
//			for (int k = 0; k < registrationsCount; k++)
//			{
//				//Find Match with RollNo first and then CourseID
//				if (list_Registrations[k]->getRollNo() == temp->getRollNo())
//				{
//					for (int j = 0; j < noOfCourses; j++)
//					{
//						if (strcmp(courseList[i]->getCourseID(), coursesoffered[j]->getID()) == 0)
//						{
//							coursesoffered[j]->unRegisterStudent(courseList[i]);
//							//std::cout << "before sorting\n";
//
//							delete list_Registrations[k];
//
//							//Rearrange master registrations array
//							for (int m = j; m < registrationsCount - 1; m++)
//							{
//								list_Registrations[m] = list_Registrations[m + 1];
//								//std::cout << "sorting\n";
//							}
//							//std::cout << "after sorting\n";
//
//
//							list_Registrations[registrationsCount - 1] = 0;
//							registrationsCount--;
//
//							std::cout << "Registration of " << temp->getRollNo() << " for " << coursesoffered[j]->getID() << " removed from Master List\n";
//
//
//							j = noOfCourses;
//							k = registrationsCount;
//							//tempCount--;
//
//						}
//
//					}
//
//				}
//
//			}
//
//
//		}
//
//		//Delete student from Student List
//		for (int i = 0; i < std_count; i++)
//		{
//			if (temp->getRollNo() == student_list[i]->getRollNo())
//			{
//				//delete student_list[i];
//
//				//Rearrange students array
//				for (int k = i; k < std_count; k++)
//					student_list[k] = student_list[k + 1];
//
//
//				student_list[std_count - 1] = 0;
//				std_count--;
//
//				i = std_count;
//				std::cout << "Student deleted from " << deptName << "\n";
//			}
//		}
//
//	}
//	else
//		std::cout << "Invalid Roll Number entered. Student does not exist in Department\n";
//
//}
cout << "Fix Delete Student Fam\n";


}

void University::deleteFaculty(Teacher* obj)
{
	cout << "Fix Delete Faculty Fam\n";
}

void University::studentDashboard(Students* std)
{
	//Match student to Department
	Department* StudentDep = findStudentdept(std);
	StudentDep->setActiveUser(std);
	int inp = 0;
	system("CLS");
	cout << "\t\t\t\t\tWelcome " << std->getName() << " (" << std->getRollNo() << ")\n";
	cout << "\t\t\tWhat would you like to do today ?\n\n1.Register a Course\t2.Unregister a Course\t3.Withdraw a Course\n\n";
	cout<<"4.View Marksheet of a Specific Course\t5.View Attendance of a Specific Course\t6.Change Password\n\n\t\t7.View Registered Courses\t8.Logout\n";
	cin >> inp;

	while (inp != 8)
	{
		system("CLS");
		std::cout << "\t\tActive User: " << std->getName() << "  (" << std->getRollNo() << ")\n\n";

		switch (inp)
		{
		case(1)://Registercourse
		{
			cout << "\t\tRegister a Course\n\n";
			StudentDep->registerCourse();
			system("pause");
			break;
		}
		case(2)://Unregistercourse
		{
			cout << "\t\tUnRegister a Course\n\n";
			StudentDep->unregisterCourse();
			system("pause");
			break;
		}
		case(3)://Withdraw Course
		{
			cout << "\t\tWithdraw Course\n\n";
			StudentDep->withdrawCourse();
			system("pause");
			break;
		}
		case(4)://Marksheet
		{
			cout << "\t\tView Marksheet of a Course\n\n";
			StudentDep->viewMarks();
			system("pause");
			break;
		}
		case(5)://Attendance
		{
			cout << "\t\tView Attendance of a Course\n\n";
			StudentDep->viewAttendance();
			system("pause");
			break;
		}
		case(6)://Change Password
		{
			cout << "\t\tChange account password\n\n";
			StudentDep->changeStdPassword();
			system("pause");
			break;
		}
		case(7)://View Registered Courses
		{
			cout << "Registered Courses List\n";
			for (int i = 0; i < std->getCourseCount(); i++)
			{
				cout << i + 1 << "\t" << std->getCourseList()[i]->getCourseID() << " - " << StudentDep->getCoursebyID(std->getCourseList()[i]->getCourseID())->getName() << "\n";
			}
			system("pause");
			break;
		}
		default:
		{
			cout << "\t\tInvalid Choice Entered. Make an appropriate selection\t\n";
			system("pause");
		}
		}

		system("CLS");
		cout << "\t\t\tWelcome " << std->getName() << " (" << std->getRollNo() << ")\n";
		cout << "\t\t\tWhat would you like to do today ?\n\n1.Register a Course\t2.Unregister a Course\t3.Withdraw a Course\n\n";
		cout << "4.View Marksheet of a Specific Course\t5.View Attendance of a Specific Course\t6.Change Password\n\n\t\t7.View Registered Courses\t8.Logout\n";
		cin >> inp;
	}
	
	//Logout Selected
	if (inp == 8)
	{
		cout << "\n\t\t\tLogging out " << std->getName() << " (" << std->getRollNo() << ")\n";
		saveData();
		loginEngine();
	}

	
}

void University::teacherDashboard(Teacher* obj)

{
	//Department* TeacherDep = obj->getPrimaryDep();
	int inp = 0;
	system("CLS");
	cout << "\t\t\t\t\tWelcome " << obj->getName() << " (" << obj->getEmpID() << ")\n";
	for (int i = 0; i < 100; i++)
		cout << "-";
	cout << "\n";
	for (int i = 0; i < 100; i++)
		cout << "-";

	cout << "\n\t\t\tWhat would you like to do today ?\n\n1.Initialize Attendance\t\t2.Manage Attendance\t\t3.Initialize Evaluations\n\n";
	cout << "4.Manage Evaluations\t\t5.Course List\t\t6.Logout\n";
	cout << "\nSelect Option:\t";
	cin >> inp;

	while (inp != 6)
	{
		system("CLS");
		cout << "\t\t\tActive User: " << obj->getName() << "  (" << obj->getEmpID() << ")\n\n";
		for (int i = 0; i < 50; i++)
			cout << "-";
		switch (inp)
		{
		case(1)://Initialize Attendance
		{
			cout << "\t\tInitializing Attendance of all Course\n\n";
			obj->initializeAttendance();
			system("pause");
			break;
		}

		case(2)://Manage Attendance
		{
			cout << "\t\tManage Attendance of a Course\n\n";
			obj->manageAttendance();
			system("pause");
			break;
		}
		case(3)://Initialize Evaluation
		{
			cout << "\t\tInitialize Evaluation of all Course\n\n";
			obj->initializeEval();
			system("pause");
			break;
		}
		case(4)://Manage Evaluations
		{
			cout << "\t\t//Manage Evaluations\n\n";
			obj->manageEval();
			system("pause");
			break;
		}
		case(5)://CourseList
		{
			cout << "\t\tCourse List\n\n";
			for (int i = 0; i < obj->getCourseCount(); i++)
			{
				cout << i + 1 << "\t" << obj->getCourseList()[i]->getID()<<" - "<<obj->getCourseList()[i]->getName()<<"\n";
			}
			system("pause");
			break;
		}
		default:
		{
			cout << "\t\tInvalid Choice Entered. Make an appropriate selection\t\n";
			system("pause");
		}
		}

		system("CLS");
		cout << "\t\t\t\t\tWelcome " << obj->getName() << " (" << obj->getEmpID() << ")\n";
		cout << "\n\t\t\tWhat would you like to do today ?\n\n1.Initialize Attendance\t\t2.Manage Attendance\t\t3.Initialize Evaluations\n\n";
		cout << "4.Manage Evaluations\t\t5.Course List\t\t6.Logout\n";
		cout << "Select Option:\t";
		cin >> inp;

	}

	//Logout Selected
	if (inp == 6)
	{
		cout << "\n\t\t\tLogging out " <<obj->getName() << "  (" << obj->getEmpID() << ")\n\n";
		
		saveData();
		loginEngine();
	}


}

void University::HOD_Dashboard(HOD* obj)
{
	int inp = 0;
	system("CLS");
	cout << "\t\t\t\t\tWelcome " << obj->getName() << " (" << obj->getEmpID() << ")\n";
	for (int i = 0; i < 100; i++)
		cout << "-";
	cout << "\n";
	for (int i = 0; i < 100; i++)
		cout << "-";

	cout << "\n\t\t\tWhat would you like to do today ?\n\n1.Assign Course to a Teacher\t\t2.Register a Student Course\t\t3.Unregister a Student Course\n\n";
	cout << "\t4.View Grades of a Course\t5.Create a TA\t\t6.Access Teacher Dashboard\n\t\t\t\t7.Logout\n";
	cout << "\nSelect Option:\t";
	cin >> inp;

	while (inp != 7)
	{
		system("CLS");
		cout << "\t\t\tActive User: " << obj->getName() << "  (" << obj->getEmpID() << ")\n\n";
		for (int i = 0; i < 50; i++)
			cout << "-";
		switch (inp)
		{
		case(1)://Assign Course to a Teacher
		{
			int rn = 0;
			char temp[7];
			cout << "\t\tAssign Course to a Teacher\n\n";
			cout << "Enter the EmpID of the Teacher\t";
			cin >> rn;
			cout << "\n\nEnter the Course ID\t";
			cin.ignore();
			cin.getline(temp, 7);
			Teacher* ptr;
			Courses* crs;
			
			if (findTeacher2(rn) != 0)
			{
				if (obj->getPrimaryDep()->courseExists(temp)==1)
				{
					ptr = findTeacher(rn);
					crs = obj->getPrimaryDep()->getCoursebyID(temp);
					obj->getPrimaryDep()->HODassignCourse(ptr, crs);
				}
				else
					cout << "Course Match not found\n";
			}
			else
				cout << "Teacher Match not found\n";
			


			system("pause");
			break;
		}

		case(2)://Register a Student Course
		{
			cout << "\t\tRegister a Student Course\n\n";
			obj->getPrimaryDep()->HODregistration();
			system("pause");
			break;
		}
		case(3)://Unregister a Student Course
		{
			cout << "\t\tUnregister a Student Course\n\n";
			obj->getPrimaryDep()->HODunRegister();
			system("pause");
			break;
		}
		case(4)://View Grades of a Course
		{
			cout << "\t\tView Grades of a Course\n\n";
			obj->getPrimaryDep()->HODviewGrades();

			system("pause");
			break;
		}
		case(5):
		{
			cout << "\tCreating a TA\n\n";
			obj->getPrimaryDep()->createTA();
			system("pause");
			break;


		}
		case(6):
		{
			cout << "\t\tTeacher Dashboard\n\n";
			teacherDashboard(obj);
			break;
		}
		default:
		{
			cout << "\t\tInvalid Choice Entered. Make an appropriate selection\t\n";
			system("pause");
		}
		}

		system("CLS");
		cout << "\t\t\t\t\tWelcome " << obj->getName() << " (" << obj->getEmpID() << ")\n";
		for (int i = 0; i < 100; i++)
			cout << "-";
		cout << "\n";
		for (int i = 0; i < 100; i++)
			cout << "-";

		cout << "\n\t\t\tWhat would you like to do today ?\n\n1.Assign Course to a Teacher\t\t2.Register a Student Course\t\t3.Unregister a Student Course\n\n";
		cout << "\t4.View Grades of a Course\t5.Create a TA\t\t6.Access Teacher Dashboard\n\t\t\t\t7.Logout\n";
		cout << "\nSelect Option:\t";
		cin >> inp;

	}

	//Logout Selected
	if (inp == 7)
	{
		cout << "\n\n\t\t\tLogging out " << obj->getName() << "  (" << obj->getEmpID() << ")\n\n";

		saveData();
		loginEngine();
	}


}

void University::ITDashboard(ManagerIT* obj)
{

	{
		int inp = 0;
		system("CLS");
		cout << "\t\t\t\t\tWelcome " << obj->getName() << " (" << obj->getEmpID() << ") to Neon IT Dashboard\n";
		for (int i = 0; i < 100; i++)
			cout << "-";
		cout << "\n";
		for (int i = 0; i < 100; i++)
			cout << "-";

		cout << "\n\t\t\tWhat would you like to do today ?\n\n1.Create Faculty Account\t\t2.Create Student Account\t\t3.Delete Faculty Account\n\n";
		cout << "\t4.Delete Student Account\t5.Update an Account\t6.Logout\n";
		cout << "\nSelect Option:\t";
		cin >> inp;

		while (inp != 6)
		{
			system("CLS");
			cout << "\t\t\tActive User: " << obj->getName() << "  (" << obj->getEmpID() << ")\n\n";
			for (int i = 0; i < 50; i++)
				cout << "-";
			switch (inp)
			{
			case(1)://Create Faculty Account
			{
				int rn = 0;
				char temp[7];
				cout << "\t\tCreate Faculty Account\n\n";
				cout << "Enter the EmpID of the Teacher\t";
				cin >> rn;

				Teacher* ptr;
				Courses* crs;
				try
				{
					ptr = findTeacher(rn);
					obj->createAcc(ptr);
				}
				catch (int i)
				{
					"No matching record of Teacher found\n";
				}

				system("pause");
				break;
			}

			case(2)://Create Student Account
			{
				int rn = 0;
				cout << "\t\tCreate Student Account\n\n";
				cout << "Enter the Roll No of the Student\t";
				cin >> rn;

				Students* ptr;
				try
				{
					ptr = getStudent(rn);
					obj->createAcc(ptr);
				}
				catch (int i)
				{
					"No matching record of Student found\n";
				}

				system("pause");
				break;
			}
			case(3)://Delete Faculty Account
			{
				int rn = 0;
				char temp[7];
				cout << "\t\Delete Faculty Account\n\n";
				cout << "Enter the EmpID of the Teacher\t";
				cin >> rn;

				Teacher* ptr;
				try
				{
					ptr = findTeacher(rn);
					deleteFaculty(ptr);
				}
				catch (int i)
				{
					"No matching record of Teacher found\n";
				}

				system("pause");
				break;
			}
			case(4)://Delete Student Account
			{
				int rn = 0;
				char temp[7];
				cout << "\t\Delete Student Account\n\n";
				cout << "Enter Student Roll No\t";
				cin >> rn;

				Students* ptr;
				try
				{
					ptr = getStudent(rn);
					deleteStudent(ptr);
				}
				catch (int i)
				{
					"No matching record of Student found\n";
				}

				system("pause");
				break;
			}
			case(5): //Update Account
			{
				int x = 0, y = 0;
				cout << "\t\tUpdate Account\n\n";
				cout << "\n1.Update Faculty Account\t\t2.Update Student Account\n";
				cout << "Select Option:\t";
				cin >> x;
				cout << "\n1.Update Username\t\t2.Update Password\n";
				cout << "Select Option:\t";
				cin >> y;

				try
				{
					if (x == 1) //Faculty Account Management
					{
						int rn = 0;
						cout << "Enter the EmpID of Faculty Member\t";
						cin >> rn;
						Teacher* ptr = findTeacher(rn);
						if (y == 1)
							obj->changeusername(ptr);
						else if (y == 2)
							obj->changepw(ptr);
						else
							throw 'a';
					}
					else if (x == 2) //Student Account Management
					{
						int rn = 0;
						cout << "Enter the Roll No of the Student\t";
						cin >> rn;
						Students* ptr = getStudent(rn);
						if (y == 1)
							obj->changeusername(ptr);
						else if (y == 2)
							obj->changepw(ptr);
						else
							throw 'a';
					}
					else
						throw'a';


				}
				catch(char a)
				{
					cout << "Invalid Choice\n";
				}
				catch (int x)
				{
					cout << "No match found in records\n";
				}
				system("pause");
				break;
			}
			default:
			{
				cout << "\t\tInvalid Choice Entered. Make an appropriate selection\t\n";
				system("pause");
			}
			}

			system("CLS");
			cout << "\t\t\t\t\tWelcome " << obj->getName() << " (" << obj->getEmpID() << ") to Neon IT Dashboard\n";
			for (int i = 0; i < 100; i++)
				cout << "-";
			cout << "\n";
			for (int i = 0; i < 100; i++)
				cout << "-";

			cout << "\n\t\t\tWhat would you like to do today ?\n\n1.Create Faculty Account\t\t2.Create Student Account\t\t3.Delete Faculty Account\n\n";
			cout << "\t4.Delete Student Account\t5.Update an Account\t6.Logout\n";
			cout << "\nSelect Option:\t";
			cin >> inp;

		}

		//Logout Selected
		if (inp == 6)
		{
			cout << "\n\t\t\tLogging out " << obj->getName() << "  (" << obj->getEmpID() << ")\n\n";
			for (int i = 0; i < 100; i++)
				cout << "-";

			saveData();
			loginEngine();
		}


	}
}

void University::TA_Dashboard(TAssistant* obj)

{
	int inp = 0;
	system("CLS");
	cout << "\t\t\t\t\tWelcome TA " << obj->getName() << " \n(" << obj->getEmpID() << " // "<<obj->getRollNo()<<")\n";
	for (int i = 0; i < 100; i++)
		cout << "-";
	cout << "\n";
	for (int i = 0; i < 100; i++)
		cout << "-";

	cout << "\n\t\t\tWhat would you like to do today ?\n\n1.Manage Evaluations \t\t2. View Student Dashboard\t\t3.Logout\n";
	cout << "\nSelect Option:\t";
	cin >> inp;

	while (inp != 3)
	{
		system("CLS");
		cout << "\t\t\tActive User: " << obj->getName() << "  (" << obj->getEmpID() << ")\n\n";
		for (int i = 0; i < 50; i++)
			cout << "-";
		switch (inp)
		{
		case(1)://Manage Evaluations
		{
			cout << "\t\t//Manage Evaluations\n\n";
			obj->manageTAEvaluation();
			system("pause");
			break;
		}
		case(2)://View Student Dashboard
		{
			studentDashboard(obj);
			break;

		}
		default:
		{
			cout << "\t\tInvalid Choice Entered. Make an appropriate selection\t\n";
			system("pause");
		}
		}

		system("CLS");
		cout << "\t\t\t\t\tWelcome TA " << obj->getName() << " \n(" << obj->getEmpID() << " // " << obj->getRollNo() << ")\n";
		cout << "\n\t\t\tWhat would you like to do today ?\n\n1.Manage Evaluations \t\t2. View Student Dashboard\t\t3.Logout\n";
		cout << "Select Option:\t";
		cin >> inp;

	}

	//Logout Selected
	if (inp == 5)
	{
		cout << "\n\t\t\tLogging out " << obj->getName() << "  (" << obj->getEmpID() << ")\n\n";
		for (int i = 0; i < 100; i++)
			cout << "-";

		saveData();
		loginEngine();
	}


}

Department* University::findStudentdept(Students* std)
{
	for (int j = 0; j < dept_count; j++)
	{
		for (int k = 0; k < dept_list[j]->getStudentCount(); k++)
		{
			if (dept_list[j]->getStudentList()[k]->getRollNo() == std->getRollNo())
			{
				//Student matched in Dept[j]
				cout << std->getRollNo() << dept_list[j]->getdepName() << "\n";
				return dept_list[j];
			}
		}
	}
	cout << "No Student-Dept match found\n";
}

void University::saveData()
{
	ofstream fout;
	ofstream f2;
	f2.open("StudentListbyDepartment.txt", ios::out);
	f2 << '\n';
	f2.close();
	f2.open("CourseListbyDepartment.txt", ios::out);
	f2 << '\n';
	f2.close();
	f2.open("StudentListbyCourses.txt", ios::out);
	f2 << '\n';
	f2.close();
	f2.open("Attendance.txt", ios::out);
	f2 << '\n';
	f2.close();
	
	
	
	//University Master File
	fout.open("University.txt", ios::out);
	if (fout)
	{
		//cout << "File opened\n";
		fout << name << "," << dept_count << "," << studentMasterCount << "," << facultyMasterCount << "," << TA_MasterCount << "," << IT_MasterCount << "," << HOD_MasterCount;
		//for (int i = 0; i < dept_count; i++)
		//{
		//	fout << dept_list[i]->getdepName() << "," << dept_list[i]->getStudentCount() << ","
		//		<< dept_list[i]->getFacultyCount() << "\n";
		//}
	}
	else
		cout << "\nUniversity.txt could not be opened\n";
	fout.close();
	//removing courses
	fout.open("StudentMasterList.txt", ios::out);
	if (fout)
	{
		fout << studentMasterCount << '\n';
		for (int i = 0; i < studentMasterCount; i++)
		{
			fout << student_masterList[i]->getName() << ',' << student_masterList[i]->getuser() << ',' <<
				student_masterList[i]->getpw() << ',' << student_masterList[i]->getRollNo() << '\n';
				
			//for (int j = 0; j < student_masterList[i]->getCourseCount(); j++)
			//{
			//	fout << student_masterList[i]->getCourseList()[j]->getCourseID() << ",";
			//}
			//fout << '\n';
		}
	}
	else
		cout << "StudentMasterList did not open\n";
	fout.close();

	fout.open("TeachersMasterList.txt", ios::out);
	if (fout)
	{
		fout << facultyMasterCount << '\n';

		for (int i = 0; i < facultyMasterCount; i++)
		{
			fout << faculty_masterList[i]->getName() << ',' << faculty_masterList[i]->getuser() << ',' <<
				faculty_masterList[i]->getpw() << ',' << faculty_masterList[i]->getEmpID() << ','
				<< faculty_masterList[i]->getPrimaryDep()->getdepName();// << ',' << faculty_masterList[i]->getCourseCount() << ',';
			/*for (int j = 0; j < faculty_masterList[i]->getCourseCount(); j++)
			{
				fout << faculty_masterList[i]->getCourseList()[j]->getID() << ",";
			}*/
			fout << '\n';
		}
	}
	else
		cout << "FacultyMasterList could not be opened\n";
	fout.close();
	
	fout.open("HODMasterList.txt", ios::out);
	if (fout)
	{
		fout << HOD_MasterCount << '\n';
		//Ignoring CourseList for now
		for (int i = 0; i < HOD_MasterCount; i++)
		{
			fout << HOD_masterList[i]->getName() << ',' << HOD_masterList[i]->getuser() << ',' <<
				HOD_masterList[i]->getpw() << ',' << HOD_masterList[i]->getEmpID() << ','
				<< HOD_masterList[i]->getPrimaryDep()->getdepName(); //<< ',' << HOD_masterList[i]->getCourseCount() << ',';
			//for (int j = 0; j < HOD_masterList[i]->getCourseCount(); j++)
			//{
			//	fout << HOD_masterList[i]->getCourseList()[j]->getID() << ",";
			//}
			fout << '\n';
		}
	}
	else
		cout << "HODMasterList could not be opened\n";
	fout.close();

	fout.open("IT_MasterList.txt", ios::out);
	if (fout)
	{
		fout << IT_MasterCount << '\n';

		for (int i = 0; i < IT_MasterCount; i++)
		{
			fout << IT_masterList[i]->getName() << ',' << IT_masterList[i]->getuser() << ',' <<
				IT_masterList[i]->getpw() << ',' << IT_masterList[i]->getEmpID() << '\n';
		}
	}
	else
		cout << "ITMasterList could not be opened\n";
	fout.close();

	
	fout.open("DepartmentMasterList.txt", ios::out);
	if (fout)
	{
		fout << dept_count<<"\n";
		for (int i = 0; i < dept_count; i++)
		{
			fout << dept_list[i]->getdepName() << "," << dept_list[i]->getManager()->getEmpID() <<"\n";
		
			ofstream f2;
			//f2.open("RegistrationsMasterList.txt", ios::app);
			
			//if (f2)
			//{
			//	f2 << dept_list[i]->getdepName() << "," << dept_list[i]->getRegistrationCount()<<"\n";
			//	for (int j = 0; j < dept_list[i]->getRegistrationCount(); j++)
			//	{
			//		f2 << dept_list[i]->getRegistrationList()[j]->getRollNo() << "," << dept_list[i]->getRegistrationList()[j]->getCourseID() << "\n";
			//	}
			//}
			//else
			//	cout << "\RegMaster not opened\n";
			//f2.close();

			f2.open("StudentListbyDepartment.txt", ios::app);
			if (f2)
			{
				f2 << dept_list[i]->getdepName() << "," << dept_list[i]->getStudentCount() << "\n";
				for (int j = 0; j < dept_list[i]->getStudentCount(); j++)
				{
					f2 << dept_list[i]->getStudentList()[j]->getRollNo()<<"\n";
				}
			}
			else
				cout << "\nStudent-Dep not opened\n";
			f2.close();

			//f2.open("TeacherListbyDepartment.txt", ios::app);
			//if (f2)
			//{
			//	f2 << dept_list[i]->getdepName() << "," << dept_list[i]->getFacultyCount() << "\n";
			//	for (int j = 0; j < dept_list[i]->getFacultyCount(); j++)
			//	{
			//		f2 << dept_list[i]->getTeacherList()[j]->getEmpID() << "\n";
			//	}
			//}
			//else
			//	cout<< "\nTeacher-Dep not opened\n";
			//f2.close();

			f2.open("CourseListbyDepartment.txt", ios::app);
			if (f2)
			{
				//DepName,CourseCount;
				//courseID, courseName, stdCount, instructor_empID, TA_RollNo
				f2 << dept_list[i]->getdepName() << "," << dept_list[i]->getCoursesCount() << "\n";
				for (int j = 0; j < dept_list[i]->getCoursesCount(); j++)
				{
					f2 << dept_list[i]->getCourseList()[j]->getID()<<","<< dept_list[i]->getCourseList()[j]->getName()
						<< "," << dept_list[i]->getCourseList()[j]->getStdCount() << "," << dept_list[i]->getCourseList()[j]->getTeacher()->getEmpID()
						<< "," << dept_list[i]->getCourseList()[j]->getTA()->getEmpID() << "\n";
				}

			}
			else
				cout << "\Courses-Dep not opened\n";
			f2.close();

			//f2.open("CoursesbyTeacher.txt", ios::app); //Handled in TchMasterList
			
			//if (f2)
			//{
			//	//f2 << dept_list[i]->getdepName() << "," << dept_list[i]->getFacultyCount() << "\n";
			//	for (int j = 0; j < dept_list[i]->getFacultyCount(); j++)
			//	{
			//		f2 << dept_list[i]->getTeacherList()[j]->getEmpID() << "\n";
			//	}
			//}
			//else
			//	cout << "\nTeacher-Courses not opened\n";
			//f2.close();

			f2.open("StudentListbyCourses.txt", ios::app);
			if (f2)
			{
				f2 << dept_list[i]->getdepName() << "," << dept_list[i]->getCoursesCount() << "\n";
				//Course Grouping Students
				for (int j = 0; j < dept_list[i]->getCoursesCount(); j++)
				{
					//StudentByCourses
					f2 << dept_list[i]->getCourseList()[j]->getID() <<','<< dept_list[i]->getCourseList()[j]->getStdCount()<<'\n';
					for (int k = 0; k < dept_list[i]->getCourseList()[j]->getStdCount(); k++)
					{
						f2 << dept_list[i]->getCourseList()[j]->getRgsPtr()[k]->getRollNo() << '\n';
					}


					//Attendance
					ofstream f3;
					f3.open("Attendance.txt", ios::app);
					if (f3)
					{
						f3 << dept_list[i]->getdepName() << "\n";//<<dept_list[i]->getCoursesCount() <<"\n";

						f3 << dept_list[i]->getCourseList()[j]->getID() << "," << dept_list[i]->getCourseList()[j]->getStdCount() << "," <<
							dept_list[i]->getCourseList()[j]->getTotalLec() <<","<< dept_list[i]->getCourseList()[j]->getAttendInitialize()<<'\n';
						for (int k = 0; k < dept_list[i]->getCourseList()[j]->getTotalLec(); k++)
						{
							f3 << dept_list[i]->getCourseList()[j]->getAttendance(k), ",";
						}
						f3 << '\n';
					}
					else
						cout << "Attendance did not open\n";
					f3.close();
				}
			}
			else
				cout << "\Courses-Student not opened\n";
			f2.close();
		}
		//cout << "\nDeptMaster File created\n";
	}
	else
		cout << "\nDeparttmentMasterList.txt could not be opened\n";
	fout.close();

	//ofstream f2;
	f2.open("TeacherListbyDepartment.txt", ios::out);
	if (f2)
	{
		for (int i = 0; i < dept_count; i++)
		{
			f2 << dept_list[i]->getdepName() << "," << dept_list[i]->getFacultyCount() << "\n";
			for (int j = 0; j < dept_list[i]->getFacultyCount(); j++)
			{
				f2 << dept_list[i]->getTeacherList()[j]->getEmpID() << "\n";
			}
		}
	}
	else
		cout << "\nTeacher-Dep not opened\n";
	f2.close();

	ofstream f3;
	f3.open("Evaluations.txt", ios::out);
	if (f3)
	{
		for (int i = 0; i < dept_count; i++)
		{
			f3 << dept_list[i]->getdepName() << "\n";//<<dept_list[i]->getCoursesCount() <<"\n";
			/*CourseID,studentCount;
			mid, project, final, weightage[5], grade, gpa, boolWithdraw, totalabs*/
			for (int j = 0; j < dept_list[i]->getCoursesCount(); j++)
			{
				Evaluation** temp = dept_list[i]->getCourseList()[j]->getEvaluationList();
				f3 << dept_list[i]->getCourseList()[j]->getID() << ',' << dept_list[i]->getCourseList()[j]->getStdCount()
					<< ',' << dept_list[i]->getCourseList()[j]->getEvalInitialzier() << ',';
				if (dept_list[i]->getCourseList()[j]->getEvalInitialzier())
				{
					f3 << dept_list[i]->getCourseList()[j]->getEvaluationList()[0]->getWeight(1) << "," << dept_list[i]->getCourseList()[j]->getEvaluationList()[0]->getWeight(2)
						<< "," << dept_list[i]->getCourseList()[j]->getEvaluationList()[0]->getWeight(3) << "," << dept_list[i]->getCourseList()[j]->getEvaluationList()[0]->getWeight(4)
						<< "," << dept_list[i]->getCourseList()[j]->getEvaluationList()[0]->getWeight(5) << '\n';

					for (int k = 0; k < dept_list[i]->getCourseList()[j]->getStdCount(); k++)
					{
						f3 << temp[k]->getRollNo() << ',' << temp[k]->getQuizcount();
						for (int m = 0; m < temp[k]->getQuizcount(); m++)
						{
							f3 << "," << temp[k]->Quizmark(m);
						}
						f3 << "," << temp[k]->getasgCount();
						for (int m = 0; m < temp[k]->getasgCount(); m++)
						{
							f3 << "," << temp[k]->Quizmark(m);
						}
						f3 << "," << temp[k]->getotherMark(1) << "," << temp[k]->getotherMark(2) << "," << temp[k]->getotherMark(3)
							<< "," << temp[k]->getotherMark(4) << "," << temp[k]->getotherMark(5) << "," << temp[k]->getGrade() << "," << temp[k]->getWithdraw() << '\n';
						/*							f3 << "," << temp[k]->getotherMark(1) << "," << temp[k]->getotherMark(2) << "," << temp[k]->getotherMark(3)
														<< "," << temp[k]->getotherMark(4) << "," << temp[k]->getotherMark(5) << "," << temp[k]->getWeight(1)
														<< "," << temp[k]->getWeight(2) << "," << temp[k]->getWeight(3) << "," << temp[k]->getWeight(4)
														<< "," << temp[k]->getWeight(5) << "," << temp[k]->getGrade() << "," << temp[k]->getWithdraw() << '\n';
						*/
					}
				}
				
			}
		}
	}
	else
		cout << "Evaluation did not open\n";
	f3.close();

	
	f3.open("TAMasterList.txt", ios::out);
	if (f3)
	{
		//Name, username, pw, TACID,depname, rollno, empID
		TAssistant** ptr = getTAMasterList();
		f3 << TA_MasterCount << '\n';
		for (int i = 0; i < TA_MasterCount; i++)
		{
			f3 << ptr[i]->getName() << "," << ptr[i]->getuser() << "," << ptr[i]->getpw() << ","
				<< ptr[i]->getPrimaryDep()->getdepName() << "," << ptr[i]->getTACID() << "," <<
				ptr[i]->getRollNo() << "," << ptr[i]->getEmpID() << '\n';
		} 
	}
	else
		cout << "TAMasterList could not be opened\n";
	f3.close();

	cout << "\n\t\tData Saved\n";

	
}

//void University::loadData(University* uni, Department** dept, Teacher** tch, Students** std, Courses** crs, TAssistant** TAs, ManagerIT** mgr, HOD** HD)

//{
//	ifstream fin;
//	fin.open("University.txt", ios::in);
//	while(!fin.eof())
//	{
//		int dcount, scount, fcount,tcount,mcount,hcount;
//		char n[30];
//
//		fin.get(name, ',');
//		fin.ignore();
//		fin >> dcount;
//		fin.ignore();
//		//for (int i = 0; i < dcount; i++)
//		//{
//			//fin.get(n, ',');
//			//fin.ignore();
//			fin >> scount;
//			//fin.ignore();
//			fin >> fcount;
//			fin >> tcount;
//			fin >> mcount;
//			fin >> hcount;
//
//			//dept[i]->setDepName(n);
//			uni.setCounts(dcount,scount, fcount,tcount,mcount,hcount);
//
//			cout << uni->getName() << uni.getStudentCount() << uni.getFacultyCount()<<"\n";
//		//}
//	
//	}
//}