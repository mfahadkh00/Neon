#include"Courses.h"
#include<iostream>
using namespace std;
#pragma once

Courses::Courses()
{
	courseID[0] = 0;
	courseName[0] = 0;
	//std_count = 0;
	course_instructor = 0;
	TA = 0;
	//student_list = new Students * [50];
	std_list = new Registrations * [50];
	//dept = 0;
	attendance = 0;
	total_lec = 0;
	eval = 0;
	attendInitialize = false;
}
Courses::Courses(const char ID[],const char name[])
{
	//Courses::Courses(char ID[], Teacher* t, TAssistant* x)
	for (int i = 0; i < 7; i++) //CS117A
	{
		courseID[i] = ID[i];
	}

	for (int i = 0; i < strlen(name); i++)
	{
		courseName[i] = name[i];
	}
	//student_list = new Students * [50];
	std_list = new Registrations * [50];
	//std_count = 0;
	eval = new Evaluation * [50];
	course_instructor = 0;
	TA = 0;
	//dept = d;
	total_lec = 0;
	//eval = 0;
	evalInitialize = false;
	instructor = false;
	attendInitialize = false;


}
Courses::Courses(const char ID[], const char name[],Teacher* ttemp)
{
	for (int i = 0; i < 7; i++) //CS117A
	{
		courseID[i] = ID[i];
	}

	for (int i = 0; i < strlen(name); i++)
	{
		courseName[i] = name[i];
	}
	std_list = new Registrations * [50];
	eval = new Evaluation * [50];
	course_instructor = ttemp;
	TA = 0;
	total_lec = 0;
	std_count = 0;
	evalInitialize = false;
	instructor = false;
	attendInitialize = false;

}

void Courses::registerStudent(Registrations* std)
{
	std_list[std_count] = std;
	std_count++;
	//std::cout << "Student registered\nNew Student Count: " << std_count << "\n";
	//std::cout << "\nStudent Count in Courses RGS STUDENT: " << std_count << "\n";

	/*std_list[std_count] = new Registrations;
	std_list[std_count]->setCourseID(std->getCourseID());
	std_list[std_count]->setRollNo(std->getRollNo());*/

}

bool Courses::unRegisterStudent(Registrations* std) //incase of withdrawing course
{
	bool stat = false;

	for (int i = 0; i < std_count; i++)
	{
		if (std->getRollNo() == std_list[i]->getRollNo()) //match found
		{
			for (int j = i; j < std_count - 1; j++) //re-order student list
				std_list[j] = std_list[j + 1];

			//Reset last index of Registration
			//std::cout << "BEFORE DELETESTD in Courses-URS" << std_count << "\n";

			//delete std_list[std_count - 1];
			std_list[std_count - 1] = 0;
			//std::cout << "BEFORE EVAL in Courses-URS" << std_count << "\n";

			if (evalInitialize)
			{
				//cout << "Eval Unregistered in Courses\n";
				for (int j = i; j < std_count - 1; j++) //re-order Evaluations list
					eval[j] = eval[j + 1];

				//Reset last index of Evaluations
				delete eval[std_count - 1];
				eval[std_count - 1] = 0;
			}
			//std::cout << "AFTER EVAL in Courses-URS" << std_count << "\n";


			std_count--;
			std::cout << "Student unregistered from "<<courseID<<"\tNew Student Count: " << std_count << "\n";
			stat = true;
		}
	}

	return stat;
}

bool Courses::withdrawCourse(Registrations* std)
{
	bool stat = false;
	if (std_count == 0)
	{
		std::cout << "No student registered in this course ! Register a student first !!!\n";
		stat = false;
	}
	else
	{
		for (int i = 0; i < std_count; i++)
		{
			if (std->getRollNo() == std_list[i]->getRollNo()) //match found
			{
				if (evalInitialize)
				{
					eval[i]->withdrawCourse();
					std::cout << "Course withdrawn\n";
					stat = true;
				}
				
			}
		}
	}
	return stat;
}

void Courses::initializeAttendance() //to be called when students registered and classes started
{
	attendInitialize = true;

	attendance = new int* [std_count];
	for (int i = 0; i < std_count; i++)
	{
			attendance[i] = new int[30];
	}
	//attendance = new int [std_count][30];
	
	for (int i = 0; i < std_count; i++)
	{
		attendance[i][0] = std_list[i]->getRollNo();
	}
	for (int i = 0; i < std_count; i++)
	{
		for (int j = 1; j < 30; j++)
		{
			attendance[i][j] = -1;
		}
	}
	std::cout << "Attendance Register for the Course " << courseID << " has been initialized\n";
}

void Courses::manageAttendance()
{
	int x = 0;
	std::cout << "Managing Attendance of Course "<<courseID<<"\nChoose the required option:\n1: Record Attendance\n2: View Attendance\n3:Modify Attendance\n";
	std::cin >> x;

	if (x == 1) //Record Attendance
	{
		if (total_lec < 30)
		{
			total_lec++; //INCREMENT FIRST CUZ RollNo STORED AT COL 0
			std::cout << "Recording Attendance for Lec# " << total_lec << "\nInput 1 for Present and 0 for Absent";

			for (int i = 0, x = 0; i < std_count; i++)
			{
				std::cout << "\nStudent " << attendance[i][0] << "\nEnter Attendance";
				std::cin >> x;

				if (x == 0 || x == 1)
					attendance[i][total_lec] = x;
				else
				{
					std::cout << "Invalid Entry ! Input 1 for Present and 0 for Absent ";
					std::cin >> x;
					attendance[i][total_lec] = x;
				}
			}

			int present = 0;
			for (int i = 0; i < std_count; i++)
			{
				if (attendance[i][total_lec] == 1)
					present++;
			}
			std::cout << "Number of Students Present Today:\t" << present<<"\n";
		}
		else
			std::cout << "Maximum No of Lectures Reached ! End of Academic Semester";
	}
	else if (x == 2) //View Attendance
	{
		if (total_lec == 0)
		{
			cout << "No Attendance Record Available\n";
		}
		else
		{
			int y = 0;
			std::cout << "Enter Student Roll No to view attendance";
			std::cin >> y;
			viewAttendance(y);
		}
	}
	else if (x == 3) //Modify Attendance of a Specific Lecture
	{
		int y = 0, z = 0;
		std::cout << "Enter Lecture# to modify attendance";
		std::cin >> y;
		if (y > total_lec || y < 1)
		{
			std::cout << "Invalid Lec No !Enter a Number between 1 and " << total_lec;
			std::cin >> y;
		}
		std::cout << "Enter Student Roll No";
		std::cin >> z;

		for (int i = 0; i < std_count; i++)
		{
			if (attendance[i][0] == z) //Match Found
			{
				std::cout << "Current Status of Attendance of Lec#\t" << y;
				if (attendance[i][y] == 1)
					std::cout << "\tPresent\n";
				else
					std::cout << "\tAbsent\n";

				std::cout << "If you wish to change the status press 1, else press any number\n";
				int a = 0;
				std::cin >> a;

				if (a == 1)
				{
					if (attendance[i][y] == 1)
						attendance[i][y] = 0;
					else
						attendance[i][y] = 1;
				}

				std::cout << "Attendance Updated Successfully!\n";
				viewAttendance(z);
			}
		}

	}

}

void Courses::viewAttendance(int rn)
{
	bool check = false;
	for (int i = 0; i < std_count; i++)
	{
		if (attendance[i][0] == rn)
		{
			check = true;
			std::cout << "Student " << rn << " Attendance for Course " << courseID << "\n";
			int p = 0;
			for (int j = 1; j < total_lec+1; j++)
			{
				std::cout << "Lecture " << j << "\t";
				if (attendance[i][j] == 1)
				{
					std::cout << "Present\n";
					p++;
				}
				else
					std::cout << "Absent\n";
			}
			std::cout << "Number of Lectures Attended\t" << p << "\nAttendance Percentage\t" << (p / total_lec) * 100 << "%\n";
		}

	}
	if(!check)
		std::cout << "Invalid Roll No\n";

}

void Courses::initializeEvaluation()
{
	cout << "Student count in Course IEVA\t" << std_count<<"\n";
	cout << "Enter the weightage of Evaluations in the following order: Quiz, Assignment, MidTerm, Project, Final\n";
	float temp[5];
	float check = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the weightage\t";
		cin >> temp[i];
		check += temp[i]; //to ensure weightage = 100
	}
	while (check != 100)//to ensure weightage = 100
	{
		std::cout << "Invalid Weightage entered ! Must add upto 100 Abs\nTry Again\n";
		check = 0;
		for (int i = 0; i < 5; i++)
		{
			cout << "Enter the weightage of Evaluations in the following order: Quiz, Assignment, MidTerm, Project, Final\n";
			cout << "Enter the weightage\t";
			cin >> temp[i];
			check += temp[i]; //to ensure weightage = 100
		}
	}
	//Set RollNo in Eval according to Student Registration List
	cout << "After weightage input student count"<<std_count<<"\n";
	for (int i = 0; i < std_count; i++)
	{
		eval[i]= new Evaluation(temp[0], temp[1], temp[2], temp[3], temp[4], std_list[i]->getRollNo());
		//eval[i] = new Evaluation;
		//eval[i]->initializeWeightage(temp[0], temp[1], temp[2], temp[3], temp[4], std_list[i]->getRollNo());
		//cout << "Inside Eval loop\n";

		eval[i]->initializeEval();
		evalInitialize = true;
	}
	
}

void Courses::initializeEvaluationfromFile(int a,int b,int c,int d,int e)
{
	for (int i = 0; i < std_count; i++)
	{
		eval[i] = new Evaluation(a,b,c,d,e, std_list[i]->getRollNo());
		//eval[i] = new Evaluation;
		//eval[i]->initializeWeightage(temp[0], temp[1], temp[2], temp[3], temp[4], std_list[i]->getRollNo());

		eval[i]->initializeEval();
		evalInitialize = true;
	}

}

void Courses::manageEvaluation()
{
	cout << "Enter the Student's Roll No manage Evaluation\n";
	int rn = 0;
	cin >> rn;

	int mark = 0,x=1;
	bool flag = false;
	for (int i = 0; i < std_count; i++)
	{
		if (eval[i]->getRollNo() == rn)
		{
			mark = i;
			i = std_count;
			flag = true;
		}
	}
	if (!flag)
		std::cout << "Invalid Roll No entered\n";
	else
	{
		while (x == 1)
		{
			cout << "Select the desired option:\n1. Evaluation Entry\n2.Calculate Grade\n3. View Evaluation Report\n";
			int temp = 0;
			cin >> temp;
			switch (temp)
			{
			case(1):
			{
				eval[mark]->evaluationEntry();
				break;
			}
			case(2):
			{
				eval[mark]->calculategrade();
				break;
			}
			case(3):
			{
				eval[mark]->evalreport();
				break;
			}
			default:
			{
				cout << "Invalid Entry\n";
				break;
			}
			}
			cout << "\nPress 1 to manage evaluation for current student again\n";
			cin >> x;
			system("CLS");
		}
		
	}
}

void Courses::manageTAEvaluation()
{
	cout << "Enter the Student's Roll No manage Evaluation\n";
	int rn = 0;
	cin >> rn;

	int mark = 0, x = 1;
	bool flag = false;
	for (int i = 0; i < std_count; i++)
	{
		if (eval[i]->getRollNo() == rn)
		{
			mark = i;
			i = std_count;
			flag = true;
		}
	}
	if (!flag)
		std::cout << "Invalid Roll No entered\n";
	else
	{
		while (x == 1)
		{
			cout << "Select the desired option:\n1. Evaluation Entry\n2. View Evaluation Report\n";
			int temp = 0;
			cin >> temp;
			switch (temp)
			{
			case(1):
			{
				eval[mark]->evaluationEntry();
				break;
			}
			case(2):
			{
				eval[mark]->evalreport();
				break;
			}
			default:
			{
				cout << "Invalid Entry\n";
				break;
			}
			}
			cout << "\nPress 1 to manage evaluation for current student again\n";
			cin >> x;
			system("CLS");
		}

	}
}

void Courses::viewEvaluation(const int &rn)
{
	int mark = 0;
	bool flag = false;
	for (int i = 0; i < std_count; i++)
	{
		if (eval[i]->getRollNo() == rn)
		{
			mark = i;
			i = std_count;
			flag = true;
		}
	}
	if (!flag)
		std::cout << "Invalid Roll No entered\n";
	else
	{
		eval[mark]->evalreport();
	}
}

void Courses::HOD_Grades()
{
	if (evalInitialize == 1)
	{
		cout << "\t\tCourse:\t" << courseName << " (" << courseID << ")" << "\n\t\tInstuctor:\t" << course_instructor->getName() << " (" << course_instructor->getEmpID() << ")\n\n";
		for (int i = 0; i < std_count; i++)
		{
			cout << std_list[i]->getRollNo() << "\t" << eval[i]->getGrade() << "\n";
		}
	}
	else
		cout << "Evaluations have not been initialized yet\n";
}

Courses::~Courses()
{
	course_instructor = 0;
	TA = 0;
	

	//Delete Attendance
	for (int i = 0; i < std_count; i++)
		delete attendance[i];
	delete[] attendance;
	attendance = 0;

	//Delete Evaluations
	for (int i = 0; i < std_count; i++)
		delete eval[i];
	delete[] eval;
	eval = 0;
}
