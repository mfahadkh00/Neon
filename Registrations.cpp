#include "Registrations.h"
#include<iostream>

Registrations::Registrations()
{
	rollno = 0;
	courseID[0] = 0;
	
}
Registrations::Registrations(const int& rn,char ID[])
{
	rollno = rn;
	for (int i = 0; i < 7; i++)
	{
		courseID[i] = ID[i];
	}
	//regID = ++regCount;
	std::cout << "Course "<<ID<<" Successfully Registered for Student "<<rn<<"\n";
}
//int Registrations::regCount = 0;

