#include"Students.h"
#include"Department.h"

Students::Students()

{
	//rollno[0] = 0;
	rollno = 0;
	course_count = 0;
	course_reg = 0;
}
Students::Students(const char n[], int roll) :Person(n) //const char roll[]
{
	//RollNo validation
	int len, temp = roll;
	for (len = 0; temp > 0; len++)
	{
		temp = temp / 10;
	}

	if (len == 6)
	{
		rollno = roll;
		//course_count = ccount;
	}
	else
	{
		std::cout << "Invalid Roll#, must be 6 digits and in the format YYNNNN --> 191244\n";
		std::cin >> temp;
		rollno = temp;
		//course_count = ccount;
	}
	course_reg = new Registrations * [50];
	//std::cout << "Student constructor\n";
}
Students::Students(const char n[], const char uname[], const char pw[], int roll):Person(n)
{
	Person::setuser(uname);
	Person::setpw(pw);
	rollno = roll;
	course_count = 0;
	course_reg = new Registrations * [50];

}

void Students::viewAttendance(Courses* obj)
{
	bool m2 = false;
	//Match existing registration in Student
	for (int i = 0; i < course_count; i++)
	{
		if (strcmp(obj->getID(), course_reg[i]->getCourseID()) == 0)
		{
			m2 = true; //matching registration found
			obj->viewAttendance(rollno);
		}
	}
	if (!m2)
		std::cout << "Course Not Found in Student Registrations. Invalid Course ID entered\n";

	/*std::cout << "Enter the 6 character Course ID for which you want to get unregistered\n";
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
		//Match existing registration in Student
		for (int i = 0; i < course_count; i++)
		{
			if (strcmp(temp, course_reg[i]->getCourseID()) == 0)
			{
				m2 = true; //matching registration found

				//Match registration to course list
				for (int j = 0; j < dept->getCoursesCount(); j++)
				{
					if (strcmp(temp, dept->getCourse(j).getID()) == 0)
					{
						flag = true;
						//if(choice==1)
							dept->getCourse(j).viewAttendance(rollno);
						//else
							//dept->getCourse(j).viewMark(course_reg[i]->getRollNo());

					}
				}
			}
		}
		if (!flag)
			std::cout << "Course Not Found. Invalid Course ID entered\n";
	/*}
	else
		std::cout << "Invalid Choice\n";*/

}

void Students::viewMarks(Courses*obj)
{
	bool m2 = false;
	//Match existing registration in Student
	for (int i = 0; i < course_count; i++)
	{
		if (strcmp(obj->getID(), course_reg[i]->getCourseID()) == 0)
		{
			m2 = true; //matching registration found
			obj->viewEvaluation(rollno);
		}
	}
	if (!m2)
		std::cout << "Course Not Found in Student Registrations. Invalid Course ID entered\n";
	/*std::cout << "Enter the 6 character Course ID for which you want to get unregistered\n";
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
	//Match existing registration in Student
	for (int i = 0; i < course_count; i++)
	{
		if (strcmp(temp, course_reg[i]->getCourseID()) == 0)
		{
			m2 = true; //matching registration found

			//Match registration to course list
			for (int j = 0; j < dept->getCoursesCount(); j++)
			{
				if (strcmp(temp, dept->getCourse(j).getID()) == 0)
				{
					flag = true;
					//if(choice==1)
					//dept->getCourse(j).viewAttendance(course_reg[i]->getRollNo());
					//else
					dept->getCourse(i).viewEvaluation(rollno);

				}
			}
		}
	}
	if (!flag)
		std::cout << "Course Not Found. Invalid Course ID entered\n";
		*/
}

void Students::registercourse(Registrations*ptr)
{
	//Registration Successful
	course_reg[course_count] = ptr;
	course_count++;
	std::cout << "New Course Count of "<<name<<"( "<<rollno<<" ) is " << course_count<<"\n";
	
	//course_reg[course_count] = new Registrations(rollno, obj->getID());
	//obj->registerStudent(course_reg[course_count]);
	
	
/*
	int x = 0;
	std::cout << "Enter the current week of the academic semester\n";
	std::cin >> x;
	if (x < 3) //Can only register courses in first 2 weeks of academic semester
	{
		if (course_count < 5)
		{
			std::cout << "Enter the 6 character Course ID for which you want to get registered\n";
			char temp[7];
			std::cin.ignore();
			std::cin.getline(temp, 7);

			//Compare CourseID with that being offered by Department
			bool flag = false;
			for (int i = 0; i < dept->getCoursesCount(); i++)
			{
				if (strcmp(dept->getCourse(i).getID(), temp) == 0)
				{
					if (dept->getCourse(i).getStudentcount() < 50)
					{
						//Registration Successful
						course_reg[course_count] = new Registrations(rollno, temp);
						dept->getCourse(i).registerStudent(course_reg[course_count]);
						course_count++;
						std::cout << "New Course Count " << course_count;
					}
					else
						std::cout << "Maximum Capacity of 50 in Course reached ! Failed to register course" << temp << "\n";

					//Terminate loop once match found even if registration unsuccessful
					flag = true;
					i = dept->getCoursesCount();
				}
			}
			if (!flag)
				std::cout << temp << " course not being offered by Department " << dept->getdepName() << "\nEnter a Valid Course\n";
		}
		else
		{
			std::cout << "Max Workload of 5 courses Achieved ! Cannot Register a New Course !\n";
		}
	}
	else
		std::cout << "Window to register new courses has closed ! Course Registration exists during first 2 weeks of the academic semester only !!\n";
*/
}

bool Students::unregistercourse(Registrations* ptr)
{
	bool m2 = false;
	for (int j = 0; j < course_count; j++)
	{
		//Find existing registration in Student
		if (strcmp(ptr->getCourseID(), course_reg[j]->getCourseID()) == 0)
		{
			m2 = true;

			//Rearrange student registrations array
			for (int k = j; k < course_count-1; k++)
				course_reg[k] = course_reg[k + 1];

			//Reset last Registration pointer to null
			course_reg[course_count-1] = 0;
			
			j = course_count; //to terminate loop

			course_count--;
			std::cout << "Updated Course Count " << course_count << "\n";
			return true;
			//delete course_reg[course_count-1];
			//obj->unRegisterStudent(course_reg[j]);
		}
	}
	if (!m2)
	{
		std::cout << "Could not find matching course in Student Registrations\n";
		return false;
	}

	

	/*	{
		int x = 0;
		std::cout << "Enter the current week of the academic semester\n";
		std::cin >> x;
		if (x < 3) //Can only unregister courses in first 2 weeks of academic semester
		{
			if (course_count >0)
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

				//Compare CourseID with that being offered by Department
				bool flag = false, match = false, m2=false;
				for (int i = 0; i < dept->getCoursesCount(); i++)
				{
					if (strcmp(dept->getCourse(i).getID(), temp) == 0)
					{
						match = true;
						//UnRegistration Successful
						for (int j = 0; j < course_count; j++)
						{
							//Find existing registration in Student
							if (strcmp(dept->getCourse(i).getID(), course_reg[j]->getCourseID()) == 0)
							{
								m2 = true;
								flag=dept->getCourse(i).unRegisterStudent(course_reg[j]);
								j = course_count;

								//Rearrange student registrations array
								for (int k = i; k < course_count; j++)
									course_reg[k] = course_reg[k + 1];

								//Reset last index of Registration
								delete course_reg[course_count];
								course_reg[course_count]=0;

								course_count--;
								std::cout << "Updated Course Count " << course_count << "\n";
							}
						}
						if (!m2)
							std::cout << "Could not find matching course in Student Registrations\n";

					}
				}
				if (!match)
					std::cout << temp << " course not being offered by Department " << dept->getdepName() << "\nEnter a Valid Course\n";
			}
			else
			{
				std::cout << "Register atleast 1 course to be able to unregister a course!\n";
			}
		}
		else
			std::cout << "Window to register/unregister courses has closed ! Course Registration exists during first 2 weeks of the academic semester only !!\n";
	}
*/
}

bool Students::withdrawcourse(Courses* obj)
{
	bool m2 = false,flag=false;
	for (int j = 0; j < course_count; j++)
	{
		//Find existing registration in Student
		if (strcmp(obj->getID(), course_reg[j]->getCourseID()) == 0)
		{
			m2 = true;
			flag = obj->withdrawCourse(course_reg[j]);
			j = course_count;
						
			std::cout << obj->getID() << " course Withdrawn Successfully\n";
		}
	}
	if (!m2)
		std::cout << "Could not find matching course in Student Registrations\n";
	return flag;
	/*
		int x = 0;
		std::cout << "Enter the current week of the academic semester\n";
		std::cin >> x;
		if (x ==12 ||x==13||x==14) //Can only withdraw courses between week 12 and 14 of academic semester
		{
			if (course_count >0)
			{
				std::cout << "Enter the 6 character Course ID you want to withdraw\n";
				char temp[7];
				std::cin.ignore();
				std::cin.getline(temp, 7);

				//Compare CourseID with that being offered by Department
				bool flag = false,m2=false;
				for (int i = 0; i < dept->getCoursesCount(); i++)
				{
					if (strcmp(dept->getCourse(i).getID(), temp) == 0) //Match found
					{
						flag = true;
						//Withdraw Course

						for (int j = 0; j < course_count; j++)
						{
							//Find existing registration in Student
							if (strcmp(dept->getCourse(i).getID(), course_reg[j]->getCourseID()) == 0)
							{
								m2 = true;
								flag = dept->getCourse(i).withdrawCourse(course_reg[j]);
								j = course_count;

								////Rearrange student registrations array
								//for (int k = i; k < course_count; j++)
								//	course_reg[k] = course_reg[k + 1];

								////Reset last index of Registration
								//delete course_reg[course_count];
								//course_reg[course_count] = 0;

								course_count--;
		std::cout << dept->getCourse(i).getID() << " course Withdrawn Successfully\n";
	}
						}
						if (!m2)
							std::cout << "Could not find matching course in Student Registrations\n";
					}
				}
				if (!flag)
					std::cout << temp << " course not being offered by Department " << dept->getdepName() << "\nEnter a Valid Course\n";
			}
			else
			{
			std::cout << "No courses registered! Cannot withdraw course\n";
			}
		}
		else
		std::cout << "Window to withdraw courses is not open ! Can only withdraw courses between week 12 and 14 of academic semester !!\n";

		*/
}




//copy function basically
//Students Students::operator=(const Students& s1)
//{
//	rollno = s1.rollno;
//	course_count = s1.course_count;
//
//	*dept = s1.dept;
//
//}

Students::~Students()
{
	delete[]course_reg;
	course_reg = 0;
}

