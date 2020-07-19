#pragma once
#ifndef Registrations_H
#define Registration_H

class Registrations
{
	//CAN ONLY REGISTER COURSES IN FIRST 2 WEEKS OF ACADEMIC SEMESTER
	//static int regCount; //random int
	//int regID;//unique ID for this specific registration
	int rollno;//rollno only to match with Student class
	char courseID[7];//courseIDs only to match with Courses class
public:
	Registrations();
	Registrations(const int &rn,char ID[]);

	int getRollNo()
	{
		return rollno;
	}
	char* getCourseID()
	{
		return courseID;
	}
	void setRollNo(int rn)
	{
		rollno = rn;
	}
	void setCourseID(char ID[])
	{
		for (int i = 0; i < 7; i++)
			courseID[i] = ID[i];
	}
	
};
#endif // !Registrations_H



