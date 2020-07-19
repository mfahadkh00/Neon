#pragma once
#include<iostream>
class Evaluation
{
	int rollno;
	bool initialized;

	float** quiz; //x10 by default, out of 10 marks
	float**	 asg; //x10 by default, out of 50 marks
	float mid; //x1, out of 30 marks
	float project; //x1, out of 100 marks
	float final; //x1, out of 100 marks
	float weightage[5];//Q-A-M-P-F
	char grade[2]; //A,B,C,D
	float gpa;

	bool withdraw;
	int quizcount;
	int asgcount;
	float totalabs;

public:
	Evaluation();
	Evaluation(float q, float a, float m, float p, float f, int rn); //pass in weightage

	//void initializeWeightage(float q, float a, float m, float p, float f, int rn);

	//void setweightage();
	//void addQuiz(); //If quizzes >3
	//void addAsg(); //If assignments >3
	void evaluationEntry();
	void calculategrade();
	void evalreport();
	
	void withdrawCourse()
	{
		withdraw = true;
	}
	char* getGrade()
	{
		return grade;
	}
	void setRollNo(int rn)
	{
		rollno = rn;
	}
	void initializeEval()
	{
		initialized = true;
	}
	int getRollNo()
	{
		return rollno;
	}
	bool intializationStatus()
	{
		return initialized;
	}
	int getQuizcount()
	{
		return quizcount;
	}
	//quizcount, q1, q2, q3, asgcount, asg1, asg2, asg3, mid, project, final, weightage[5], grade, gpa, boolWithdraw, totalabs
	float Quizmark(int k)
	{
		return *quiz[k];
	}
	int getasgCount()
	{
		return asgcount;
	}
	float getasgMark(int k)
	{
		return *asg[k];
	}
	float getotherMark(int k)
	{
		switch (k)
		{
		case(1):
			return mid;
		case(2):
			return project;
		case(3):
			return final;
		case(4):
			return totalabs;
		case(5):
			return gpa;
		}
	}
	float getWeight(int k)
	{
		return weightage[k - 1];
	}
	bool getWithdraw()
	{
		return withdraw;
	}
	
	void setQmark(float q)
	{
		quiz[quizcount++] = new float(q);
	}
	void setAmark(float a)
	{
		asg[asgcount++] = new float(a);
	}
	void setotherMark(int k,float m)
	{
		switch (k)
		{
		case(1):
		{
			mid = m;
			break;
		}
		case(2):
		{
			project = m;
			break;
		}
		case(3):
		{
			final = m;
			break;
		}
		case(4):
		{
			totalabs = m;
			break;
		}
		case(5):
		{
			gpa = m;
			break;
		}
		}
	}
	void setWeight(int k,float m)
	{
		weightage[k]=m;
	}
	void setWithdraw(bool k)
	{
		withdraw = k;
	}
	void setGrade(char* k)
	{
		for (int i = 0; i < strlen(k); i++)
			grade[i] = k[i];
	}

	~Evaluation();


};

