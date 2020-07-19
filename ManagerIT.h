#pragma once
#include"Employee.h"
//#include"Department.h"
#include"Students.h"
#include<iostream>
#ifndef IT_H
#define IT_H

class ManagerIT :
    public  Employee
{
   public:
    ManagerIT()
    {
    }
    ManagerIT(const char name[], int ID, const char u_name[], const char pw[]) :Person(name),Employee(name,ID)
    {
        //Username Check
        if (strlen(u_name) != 9)
        {
            std::cout << "Invalid Username! Must be 9 characters\n";
            char temp[10];
            std::cout << "Enter 9 character username to be set:\t";
            std::cin >> temp;
            for (int i = 0; i < 10; i++)
            {
                username[i] = temp[i];
            }
        }
        for (int i = 0; i < 10; i++)
        {
            username[i] = u_name[i];
        }

        //Password Check
        if (strlen(pw) != 6)
        {
            std::cout << "Invalid Password! Must be 6 characters\n";
            char temp[7];
            std::cout << "Enter 6 character Password to be set:\t";
            std::cin >> temp;
            for (int i = 0; i < 7; i++)
            {
                password[i] = temp[i];
            }
        }
        for (int i = 0; i < 7; i++)
        {
            password[i] = pw[i];
        }
    }
    ManagerIT(const char name[], int ID) :Person(name), Employee(name, ID)
    {}
    //void createAcc(Students* std1)
    template<class Type>
    void createAcc(Type* p1)
    {
        char temp[10];
        std::cout << "Enter 9 character username to be set:\t";
        std::cin >> temp;
        if (strlen(temp) != 9)
        {
            std::cout << "Invalid Username! Must be 9 characters";
        }
        //std1->setuser(temp);
        p1->setuser(temp);

        char temp2[10];
        std::cout << "Enter 6 character password to be set:\t";
        std::cin >> temp2;
        if (strlen(temp2) != 6)
        {
            std::cout << "Invalid Password! Must be 9 characters";
        }
        //std1->setpw(temp2);
        p1->setpw(temp2);
        std::cout << "Account created successfully\n";
    }

    template<class Type>
    void deleteAcc()
    {    }

    template<class Type>
    void changeusername(Type* p1)
    {
        char temp[10];
        std::cout << "Enter 9 character username to be set:\t";
        std::cin >> temp;
        if (strlen(temp) != 9)
        {
            std::cout << "Invalid Username! Must be 9 characters";
        }
        //std1->setuser(temp);
        p1->setuser(temp);
    }
    
    template<class Type>
    void changepw(Type* p1)
    {
        char temp2[7];
        std::cout << "Enter 6 character password to be set:\t";
        std::cin >> temp2;
        if (strlen(temp2) == 6)
        {
            p1->setpw(temp2);
            std::cout << "Password Changed\n";
        }
        else
            std::cout << "Invalid Password! Must be 9 characters";

    }

    void print()
    {
        Employee::print();
    }
    ~ManagerIT()
    {

    }
};

#endif