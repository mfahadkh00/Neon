#pragma once
#include "Person.h"
#include<iostream>
#ifndef Emp_H
#define Emp_H
class Employee :
	public virtual Person
{
	int emp_ID;

public:
	Employee(){}
	Employee(const char n[], int ID):Person(n)
	{
		emp_ID = ID;
		//std::cout << "Employee constructor\n";
	}

	int getEmpID()
	{
		return emp_ID;
	}
	void setEmpID(int x)
	{
		emp_ID = x;
	}
	void print()
	{
		Person::print();
		cout << '\t' << emp_ID;

	}
};

#endif