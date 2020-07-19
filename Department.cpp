#include "Department.h"

Department::Department()
{
	deptName[0] = '\0';
	manager = 0;
	deptHead = 0;
	activeUser = 0;
	staff_list = new Teacher*[100];
	coursesoffered = new Courses*[50];
	student_list = new Students*[500];
	list_Registrations = new Registrations * [2000];
}
Department::Department( const char name[])
{
	activeUser = 0;
	manager = 0;
	deptHead = 0;
	staff_list = new Teacher * [100];
	coursesoffered = new Courses * [50];
	student_list = new Students * [500];
	list_Registrations = new Registrations * [2000];
	noOfCourses = 0;
	std_count = 0;
	facultyCount = 0;
	registrationsCount = 0;

	//if (strlen(name) == 2)
	//{
		deptName[0]= name[0];
		deptName[1]= name[1] ;
		deptName[2] = name[2];
	//}
	/*else
	{
		std::cout << "Invalid Length of Dept Name. Must be 2 characters only (EE,CS,MM)\n";
		char temp[3];
		std::cin >> temp;
		deptName[0] = name[0];
		deptName[1] = name[1];
		deptName[2] = name[2];
	}*/
}
Department::Department(const char name[], int ccount, int scount, int fcount, int rgcount, ManagerIT* mgr, HOD* HD)
{

		deptName[0] = name[0];
		deptName[1] = name[1];
		deptName[2] = name[2];
		noOfCourses = ccount;
		std_count = scount;
		facultyCount = fcount;
		rgcount = registrationsCount;
		manager = mgr;
		deptHead = HD;
		staff_list = new Teacher * [100];
		coursesoffered = new Courses * [50];
		student_list = new Students * [500];
		list_Registrations = new Registrations * [2000];
	

}

void Department::registerCourse()
{
	int x = 0;
	std::cout << "Enter the current week of the academic semester\n";
	std::cin >> x;
	if (x < 3) //Can only register courses in first 2 weeks of academic semester
	{
		//activeUser = std;
		if (activeUser->getCourseCount() < 5)
		{
			std::cout << "Enter the 6 character Course ID for which you want to get registered\n";
			char temp[7];
			std::cin.ignore();
			std::cin.getline(temp, 7);

			//Check for Existing Registration
			if (RegistrationExists(activeUser->getRollNo(),temp) == 0)
			{
				//Compare CourseID with that being offered by Department
				bool flag = false;
				for (int i = 0; i < noOfCourses; i++)
				{
					if (strcmp(coursesoffered[i]->getID(), temp) == 0)
					{
						if (coursesoffered[i]->getStudentcount() < 50)
						{
							//Registration Successful
							list_Registrations[registrationsCount] = new Registrations(activeUser->getRollNo(), temp);
							activeUser->registercourse(list_Registrations[registrationsCount]);
							coursesoffered[i]->registerStudent(list_Registrations[registrationsCount]);
							registrationsCount++;
							//std::cout << "Course count in Department RGS" << coursesoffered[0]->getStdCount();
						}
						else
							std::cout << "Maximum Capacity of 50 in Course reached ! Failed to register course" << temp << "\n";

						//Terminate loop once match found even if registration unsuccessful

						flag = true;
						i = noOfCourses;

					}
				}
				if (!flag)
					std::cout << temp << " course not being offered by Department " << deptName << "\nEnter a Valid Course\n";
			}
			else
			{
				cout << "\nRegistration for this course already exists\n";
			}
		}
		else
		{
			std::cout << "Max Workload of 5 courses Achieved ! Cannot Register a New Course !\n";
		}
	}
	else
		std::cout << "Window to register new courses has closed ! Course Registration exists during first 2 weeks of the academic semester only !!\n";
	//return coursesoffered[0]->getStdCount();
}

void Department::unregisterCourse()
{
	//activeUser = std;
	int x = 0;
	std::cout << "Enter the current week of the academic semester\n";
	std::cin >> x;
	if (x < 3) //Can only unregister courses in first 2 weeks of academic semester
	{
		if (activeUser->getCourseCount() > 0 )
		{
			std::cout << "Enter the 6 character Course ID for which you want to unregister\n";
			char temp[7];
			std::cin.ignore();
			std::cin.getline(temp, 7);

			//Compare CourseID with that being offered by Department
			bool flag = false,match=false;
			for (int i = 0; i < noOfCourses; i++)
			{
				if (strcmp(coursesoffered[i]->getID(), temp) == 0)
				{
					match = true;
					if (coursesoffered[i]->getStudentcount() > 0)
					{
						//Match registration in master list
						for (int j = 0; j < registrationsCount; j++)
						{
							//RollNo matched
							//if(RegistrationExists(activeUser->getRollNo(),temp)==0)

							if (list_Registrations[j]->getRollNo() == activeUser->getRollNo())
							{
								//Registrations* rtemp = getStdRegistration(activeUser->getRollNo(), temp);
								if (strcmp(list_Registrations[j]->getCourseID(),temp)==0)
								{
									bool check=activeUser->unregistercourse(list_Registrations[j]);
									if (check)
									{
										coursesoffered[i]->unRegisterStudent(list_Registrations[j]);

										delete list_Registrations[j];

										//Rearrange master registrations array
										for (int k = j; k < registrationsCount - 1; k++)
											list_Registrations[k] = list_Registrations[k + 1];

										list_Registrations[registrationsCount - 1] = 0;
										registrationsCount--;

										std::cout << "Registration removed from Master List\n";
									}
									//Loop terminators
									j = registrationsCount;
								}
							}
							//else
							//	cout << "\nRegistration for this course does not exist\n";

						}
					}					
				}
			}
			if (!match)
				std::cout << temp << " course not being offered by Department " << deptName << "\nEnter a Valid Course\n";
		}
		else
		{
			std::cout << "Register atleast 1 course to be able to unregister a course!\n";
		}
	}
	else
		std::cout << "Window to register/unregister courses has closed ! Course Registration exists during first 2 weeks of the academic semester only !!\n";
}

void Department::withdrawCourse()

{
	int x = 0;
	std::cout << "Enter the current week of the academic semester\n";
	std::cin >> x;
	if (x == 12 || x == 13 || x == 14) //Can only withdraw courses between week 12 and 14 of academic semester
	{
		//activeUser = std;
		if (activeUser->getCourseCount() > 0)
		{
			std::cout << "Enter the 6 character Course ID you want to withdraw\n";
			char temp[7];
			std::cin.ignore();
			std::cin.getline(temp, 7);

			//Compare CourseID with that being offered by Department
			bool flag = false, m2 = false;
			for (int i = 0; i < noOfCourses; i++)
			{
				if (strcmp(coursesoffered[i]->getID(), temp) == 0) //Match found
				{
					flag = true;

					//Send over to Student withdrawcourse function
					m2=activeUser->withdrawcourse(coursesoffered[i]);
				}
				
			}
			if (!flag)
				std::cout << temp << " course not being offered by Department " << deptName << "\nEnter a Valid Course\n";
			if (!m2)
				std::cout << "Could not withdraw course\n";
		}
		else
		{
			std::cout << "No courses registered! Cannot withdraw course\n";
		}
	}
	else
		std::cout << "Window to withdraw courses is not open ! Can only withdraw courses between week 12 and 14 of academic semester !!\n";
}

void Department::viewAttendance()
{
	std::cout << "Enter the 6 character Course ID for which you want to view Attendance\n";
	char temp[7];
	std::cin.ignore();
	std::cin.getline(temp, 7);
	if (strlen(temp) != 6)
	{
		std::cout << "Invalid Input! Try again\nEnter the 6 character Course ID for which you want to view Attendance\n";
		std::cin.ignore();
		std::cin.getline(temp, 7);
	}

	bool m2 = false, flag = false;

	//Match entered course to course list
	for (int j = 0; j < noOfCourses; j++)
	{
		if (strcmp(temp, coursesoffered[j]->getID()) == 0)
		{
			flag = true;

			if (coursesoffered[j]->getAttendInitialize() == 1)
			{
				activeUser->viewAttendance(coursesoffered[j]);
				//coursesoffered[j]->viewAttendance(rollno);
			}
			else
				cout << "Attendance not initialized by Instructor yet\n";
			
		}
	}
	if (!flag)
		std::cout << "Course Not Found. Invalid Course ID entered\n";

}

void Department::viewMarks() 
{
	std::cout << "Enter the 6 character Course ID for which you want to view Marks\n";
	char temp[7];
	std::cin.ignore();
	std::cin.getline(temp, 7);
	if (strlen(temp) != 6)
	{
		std::cout << "Invalid Input! Try again\nEnter the 6 character Course ID for which you want to get unregistered\n";
		std::cin.ignore();
		std::cin.getline(temp, 7);
	}

	bool m2 = false, flag = false;

	//Match entered course to course list
	for (int j = 0; j < noOfCourses; j++)
	{
		if (strcmp(temp, coursesoffered[j]->getID()) == 0)
		{
			flag = true;
			activeUser->viewMarks(coursesoffered[j]);
			//coursesoffered[j]->viewAttendance(rollno);

		}
	}
	if (!flag)
		std::cout << "Course Not Found. Invalid Course ID entered\n";
}

void Department::HODviewGrades()

{
	std::cout << "Enter the 6 character Course ID for which you want to view Marks\n";
	char temp[7];
	std::cin.ignore();
	std::cin.getline(temp, 7);
	if (strlen(temp) != 6)
	{
		std::cout << "Invalid Input! Try again\nEnter the 6 character Course ID for which you want to get unregistered\n";
		std::cin.ignore();
		std::cin.getline(temp, 7);
	}

	bool m2 = false, flag = false;

	//Match entered course to course list
	for (int j = 0; j < noOfCourses; j++)
	{
		if (strcmp(temp, coursesoffered[j]->getID()) == 0)
		{
			flag = true;
			coursesoffered[j]->HOD_Grades();

			//std::cout << "Enter Student Roll No to delete account. This will delete all related data as well\n";
			//int rn = 0;
			//std::cin >> rn;
			//if (studentExists(rn))
			//{
			//	Students* temp = getStudent(rn);
			//	{
			//		temp->viewMarks(coursesoffered[j]);
			//	}
				//coursesoffered[j]->viewAttendance(rollno);
		}
	}
	if (!flag)
		std::cout << "Course Not Found. Invalid Course ID entered\n";

}

void Department::changeStdPassword()
{
	manager->changepw(activeUser);
}

Courses* Department::addCourse(Courses* obj)
{
	try
	{
		for (int i = 0; i < noOfCourses; i++)
		{
			if (strcmp(obj->getID(), coursesoffered[i]->getID()) == 0)
			{
				throw i;
			}
		}
		coursesoffered[noOfCourses] = new Courses(obj->getID(),obj->getName());
		//coursesoffered[noOfCourses] = obj;
		std::cout<<"Course "<< coursesoffered[noOfCourses++]->getID()<<" added successfully\n";
		return coursesoffered[noOfCourses - 1];
	}
	catch (int x)
	{
		std::cout << "Course already exists !\n";
	}
	catch (...)
	{
		std::cout << "Default Error while Adding Course\n";
	}
}

Courses* Department::addCoursefromFile(Courses* obj)
{
	try
	{
		for (int i = 0; i < noOfCourses; i++)
		{
			if (strcmp(obj->getID(), coursesoffered[i]->getID()) == 0)
			{
				throw i;
			}
		}
		coursesoffered[noOfCourses] = new Courses(obj->getID(),obj->getName(),obj->getTeacher());
		//coursesoffered[noOfCourses] = obj;
		std::cout << "Course " << coursesoffered[noOfCourses++]->getID() << " added successfully\n";
		return coursesoffered[noOfCourses - 1];

	}
	catch (int x)
	{
		std::cout << "Course already exists !\n";
	}
	catch (...)
	{
		std::cout << "Default Error while Adding Course\n";
	}
}

void Department::registerCoursefromFile(Students*std,char temp[])
{
	setActiveUser(std);
	if (activeUser->getCourseCount() < 5)
	{
		//Compare CourseID with that being offered by Department
		bool flag = false;
		for (int i = 0; i < noOfCourses; i++)
		{
			if (strcmp(coursesoffered[i]->getID(), temp) == 0)
			{
				if (coursesoffered[i]->getStudentcount() < 50)
				{
					//Registration Successful
					list_Registrations[registrationsCount] = new Registrations(activeUser->getRollNo(), temp);
					activeUser->registercourse(list_Registrations[registrationsCount]);
					coursesoffered[i]->registerStudent(list_Registrations[registrationsCount]);
					registrationsCount++;
					std::cout << "Course " << coursesoffered[i]->getName() << "\tRegistered for " << std->getRollNo()<<"\n";
				}
				else
					std::cout << "Maximum Capacity of 50 in Course reached ! Failed to register course" << temp << "\n";

				//Terminate loop once match found even if registration unsuccessful

				flag = true;
				i = noOfCourses;

			}
		}
		if (!flag)
			std::cout << temp << " course not being offered by Department " << deptName << "\nEnter a Valid Course\n";
	}
	else
	{
		std::cout << "Max Workload of 5 courses Achieved ! Cannot Register a New Course !\n";
	}

	
}

void Department::createHOD(Teacher* obj)
{
	deptHead = (HOD*)obj;

}

void Department::HODassignCourse(Teacher* obj, Courses* crs)
//Accessible to HOD only
{
	if (obj->getCourseCount() < 3)
	{

		if ( TeacherCourseExists(crs,obj)== 0)
		{
			crs->SetTeacher(obj);
			obj->addCourse(crs);
			std::cout << "Teacher " << obj->getName() << obj->getEmpID() << " has been assigned to " << crs->getID() << "\n";
		}
		else
			std::cout << obj->getName()<<" - "<< obj->getEmpID()<<" already assigned to " << crs->getID() << '\n';

	}
	else
		std::cout << "Instructor is already teaching 3 courses. Cannot Assign a new course\n";

}

void Department::HODregistration()
{
	int x = 0;
	std::cout << "Enter the current week of the academic semester\n";
	std::cin >> x;
	if (x < 3) //Can only register courses in first 2 weeks of academic semester
	{
		int rn = 0;
		std::cout << "Enter the Student Roll No\n";
		std::cin >> rn;

		for (int i = 0; i < std_count; i++)
		{
			if (rn == student_list[i]->getRollNo()) //Match found in Student List
			{

					if (student_list[i]->getCourseCount() < 5)
					{
						std::cout << "Enter the 6 character Course ID for which you want to get registered\n";
						char temp[7];
						std::cin.ignore();
						std::cin.getline(temp, 7);

						if (RegistrationExists(activeUser->getRollNo(), temp) == 0)
						{
							//Compare CourseID with that being offered by Department
							bool flag = false;
							for (int j = 0; j < noOfCourses; j++)
							{
								if (strcmp(coursesoffered[j]->getID(), temp) == 0)
								{
									if (coursesoffered[j]->getStudentcount() < 50)
									{
										//Registration Successful
										list_Registrations[registrationsCount] = new Registrations(student_list[i]->getRollNo(), temp);
										student_list[i]->registercourse(list_Registrations[registrationsCount]);
										coursesoffered[i]->registerStudent(list_Registrations[registrationsCount]);
										registrationsCount++;
									}
									else
										std::cout << "Maximum Capacity of 50 in Course reached ! Failed to register course" << temp << "\n";

									//Terminate loop once match found even if registration unsuccessful
									flag = true;
									j = noOfCourses;
								}
							}
							if (!flag)
							{
								std::cout << temp << " course not being offered by Department " << deptName << "\nEnter a Valid Course\n";
								i = std_count;
							}
						}
						else
							std::cout << "Student already registered in " << temp << "\n";
					}
					else
					{
						std::cout << "Max Workload of 5 courses Achieved ! Cannot Register a New Course !\n";
						i = std_count;
					}
				
			}
		}
		
	}
	else
		std::cout << "Window to register new courses has closed ! Course Registration exists during first 2 weeks of the academic semester only !!\n";
}

void Department::HODunRegister()

{
	//activeUser = std;
	int x = 0;
	std::cout << "Enter the current week of the academic semester\n";
	std::cin >> x;
	if (x < 3) //Can only unregister courses in first 2 weeks of academic semester
	{
		int rn = 0;
		std::cout << "Enter the Student Roll No\n";
		std::cin >> rn;

		for (int i = 0; i < std_count; i++)
		{
			if (rn == student_list[i]->getRollNo()) //Match found in Student List
			{
				if (student_list[i]->getCourseCount() > 0)
				{
					std::cout << "Enter the 6 character Course ID for which you want to unregister\n";
					char temp[7];
					std::cin.ignore();
					std::cin.getline(temp, 7);

					//Compare CourseID with that being offered by Department
					bool flag = false, match = false;
					for (int i = 0; i < noOfCourses; i++)
					{
						if (strcmp(coursesoffered[i]->getID(), temp) == 0)
						{
							match = true;
							if (coursesoffered[i]->getStudentcount() > 0)
							{
								//Match registration in master list
								for (int j = 0; j < registrationsCount; j++)
								{
									//RollNo matched
									if (list_Registrations[j]->getRollNo() == student_list[i]->getRollNo())
									{
										if (strcmp(list_Registrations[j]->getCourseID(), temp) == 0)
										{
											student_list[i]->unregistercourse(list_Registrations[j]);
											coursesoffered[i]->unRegisterStudent(list_Registrations[j]);

											delete list_Registrations[j];

											//Rearrange master registrations array
											for (int k = j; k < registrationsCount - 1; k++)
												list_Registrations[k] = list_Registrations[k + 1];

											list_Registrations[registrationsCount - 1] = 0;
											registrationsCount--;

											std::cout << "Registration removed from Master List\n";

											//Loop terminators
											j = registrationsCount;


										}
									}
								}
							}
						}
					}
					if (!match)
						std::cout << temp << " course not being offered by Department " << deptName << "\nEnter a Valid Course\n";
				}
				else
				{
					std::cout << "Register atleast 1 course to be able to unregister a course!\n";
				}

			}
		}
	}
	else
		std::cout << "Window to register/unregister courses has closed ! Course Registration exists during first 2 weeks of the academic semester only !!\n";
}

void Department::addStudent(Students* std)
{
	try
	{
		for (int i = 0; i < std_count; i++)
		{
			if (std->getRollNo()==student_list[i]->getRollNo())
			{
				throw i;
			}
		}
		student_list[std_count++] = std;
		std::cout << "Student" << std->getRollNo() << " admitted to " << deptName << "\nNew Student Count in Department "<<std_count<<"\n";
		
	}
	catch (int x)
	{
		std::cout << "Student already exists in Department !\n";
	}
}

void Department::addTeacher(Teacher* obj)
{
	try
	{
		for (int i = 0; i < facultyCount; i++)
		{
			if (obj->getEmpID()==staff_list[i]->getEmpID())
			{
				throw i;
			}
		}
		staff_list[facultyCount] = obj;
		facultyCount++;
		std::cout << "Teacher " << obj->getEmpID() << " added to " << deptName << "\n";
	}
	catch (int x)
	{
		std::cout << "Teacher already exists in Department !\n";
	}
}

void Department::createTA()
{
	std::cout << "Enter the 6 character Course ID for which you want to get unregistered\n";
	char temp[7];
	std::cin.ignore();
	std::cin.getline(temp, 7);
	if (strlen(temp) != 6)
	{
		std::cout << "Invalid Input! Try again\nEnter the 6 character Course ID for which you want to get unregistered\n";
		std::cin.ignore();
		std::cin.getline(temp, 7);
	}
	std::cout << "Enter the Student you wish to assign as a Teacher Assistant\n";
	int rn;
	std::cin >> rn;

	if (courseExists(temp))
	{
		if (studentExists(rn))
		{
			Courses* obj = getCoursebyID(temp);
			Students* std = getStudent(rn);

			
			obj->createTA(std);
			cout << "Student "<<rn<<" is now a TA of "<<temp<<"\n";
			//coursesoffered[j]->viewAttendance(rollno);


		}
		else
			std::cout << "Student " << rn << " does not belong to " << deptName << " and so cannot be assigned as TA\n";

	}
	else
		std::cout << "Course " <<temp << " does not belong to " << deptName << "\n";

	


}

Registrations* Department::getStdRegistration(int rn,const char id[])
{
	for (int i = 0; i < registrationsCount; i++)
	{
		if (rn == list_Registrations[i]->getRollNo())
		{
			if(strcmp(id,list_Registrations[i]->getCourseID())==0)
				return list_Registrations[i];

		}
	}
	std::cout << "No matching student registration found\n";
	
}

bool Department::RegistrationExists(int rn, const char id[])
{
	for (int i = 0; i < registrationsCount; i++)
	{
		if (rn == list_Registrations[i]->getRollNo())
		{
			if (strcmp(id, list_Registrations[i]->getCourseID()) == 0)
				return true;

		}
	}
//	cout << "\nRegistration for this course already exists\n";
	return false;
}

Students* Department::getStudent(int rn)
{
	for (int i = 0; i < std_count; i++)
	{
		if (rn == student_list[i]->getRollNo())
			return student_list[i];
	}
	return 0;
	//std::cout << "No matching student found\n";
}

bool Department::studentExists(int rn)
{
	for (int i = 0; i < std_count; i++)
	{
		if (rn == student_list[i]->getRollNo())
			return true;
	}
	return false;
}



//Add this
Department::~Department()
{
	

	//delete master list of registrations
	for (int i = 0; i < registrationsCount; i++)
		delete list_Registrations[i];
	delete[]list_Registrations;
	list_Registrations = 0;

	//delete master list of courses
	for (int i = 0; i < noOfCourses; i++)
		delete coursesoffered[i];
	delete[]coursesoffered;
	coursesoffered = 0;


	delete[]staff_list;
	delete[]student_list;

	manager = 0;
	deptHead = 0;
	staff_list = 0;
	coursesoffered = 0;
}


