#pragma once
#include<iostream>
using namespace std;
#ifndef Person_H
#define Person_H
class Person
{
	
	//char username[10]; //9 character username + null
	//char password[7]; //6 character pw + null
	//friend class ManagerIT;

protected:
	char username[10]; //9 character username + null
	char password[7]; //6 character pw + null
	char name[30];
	//Accounts credentials;
public:
	Person()
	{

	}
	Person(const char n[])
	{
		for (int i = 0; i < strlen(n); i++)
			name[i] = n[i];
		name[strlen(n)] = '\0';
		//std::cout << "Person constructor\n";

	}

	char* getName()
	{
		return name;
	}
	
	
	void setuser(const char x[])
	{
		//if (strlen(x) == 9)
		//{
			for (int i = 0; i < 10; i++)
			{
				username[i] = x[i];
			}
		//}
	}
	void setpw(const char x[])
	{
		//if (strlen(x) == 6)
		//{
			for (int i = 0; i < 7; i++)
			{
				password[i] = x[i];
			}
		//}
	}
	char* getuser()
	{
		return username;
	}
	char* getpw()
	{
		return password;
	}
	void print()
	{
		cout << name<<"\t";
		printcredentials();
	}
	void printcredentials()
	{
		std::cout << username << "\t" << password;
	}
};

#endif