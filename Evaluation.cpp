#include "Evaluation.h"
using namespace std;

Evaluation::Evaluation()
{
	rollno = 0;
	quiz = new float*[10];
	asg = new float*[10];
	mid = 0;
	project = 0;
	final = 0;
	weightage[0] = 0;
	quizcount = 0;
	asgcount = 0;
	totalabs = 0;
	grade[0] = 'x';
	gpa = 0;
	withdraw = false;
}
Evaluation::Evaluation(float q, float a, float m, float p, float f, int rn) //pass in weightage
{
	rollno = rn;
	quiz = new float* [10];
	asg = new float* [10];
	mid= 0;
	project = 0;
	final = 0;
	quizcount = 0;
	asgcount = 0;
	totalabs = 0;
	gpa = 0;

	weightage[0] = q;
	weightage[1] = a;
	weightage[2] = m;
	weightage[3] = p;
	weightage[4] = f;

	grade[0] = 'x';
	withdraw = false;

	std::cout << "Course Evaluation Initialized\n";
}

//void Evaluation::initializeWeightage(float q, float a, float m, float p, float f, int rn)
//{
//	rollno = rn;
//	quiz = new int* [10];
//	asg = new int* [10];
//	mid = 0;
//	project = 0;
//	final = 0;
//	quizcount = 0;
//	asgcount = 0;
//	totalabs = 0;
//	gpa = 0;
//
//	weightage[0] = q;
//	weightage[1] = a;
//	weightage[2] = m;
//	weightage[3] = p;
//	weightage[4] = f;
//
//	grade[0] = 'x';
//	withdraw = false;
//
//	std::cout << "Course Evaluation Initialized\n";
//}
//void Evaluation::addQuiz() //If quizzes >3
//{
//	if (quizcount >= 3)
//	{
//		quizcount++;
//		/*int* temp = new int[quizcount];
//		for (int i = 0; i < quizcount - 1; i++)
//		{
//			temp[i] = quiz[i];
//		}
//		delete[]quiz;
//		quiz = temp;
//		temp = 0;*/
//		std::cout << "No of Quizzes updated to: " << quizcount << "\n";
//	}
//	else
//		std::cout << "Conduct 3 quizzes to add a new quiz\n";
//	
//}
//void Evaluation::addAsg() //If assignments >3
//{
//	if (asgcount >= 3)
//	{
//		asgcount++;
//		/*int* temp = new int[asgcount];
//		for (int i = 0; i < asgcount - 1; i++)
//		{
//			temp[i] = asg[i];
//		}
//		delete[]asg;
//		asg = temp;
//		temp = 0;*/
//		std::cout << "No of Assignments updated to: " << asgcount << "\n";
//	}
//	else
//		std::cout << "Must have assigned 3 assignments to add more\n";
//	
//}
void Evaluation::evaluationEntry()
{
	std::cout << "Enter 1 for Quiz, 2 for Assignments, 3 for Midterms, 4 for Project, 5 for Final\n";
	int x = 0;
	std::cin>>x;

	switch (x)
	{
	case(1):
		{
		std::cout << "Enter the Mark for Quiz " << quizcount + 1<<"\t";
		float y = 0;
		cin >> y;
		if (y < 0 || y>10)
			cout << "Invalid Entry, Quiz marks must be out of 10\n";
		else
		{
			quiz[quizcount++] = new float(y);
		}
		break;

		}
	case(2):
	{
		std::cout << "Enter the Mark for Assignment " << asgcount + 1<<"\t";
		float y = 0;
		cin >> y;
		if (y < 0 || y>50)
			cout << "Invalid Entry, Assignment marks must be out of 50\n";
		else 
		{
			asg[asgcount++] = new float(y);
			break;
		}
		break;

	}
	case(3):
	{
		std::cout << "Enter Midterm Marks\t";
		float y = 0;
		cin >> y;
		if (y < 0 || y>30)
			cout << "Invalid Entry, Midterm marks must be out of 30\n";
		else
		{
			mid = y;
			break;
		}
		break;
	}
	case(4):
	{
		std::cout << "Enter Project Marks\t";
		float y = 0;
		cin >> y;
		if (y < 0 || y>100)
			cout << "Invalid Entry, Project marks must be out of 100\n";
		else
		{
			project = y;
			
		}
		break;
	}
	case(5):
	{
		std::cout << "Enter Final Marks\t";
		float y = 0;
		cin >> y;
		if (y < 0 || y>100)
			cout << "Invalid Entry, Final marks must be out of 100\n";
		else
		{
			final = y;
			break;
		}
		break;

	}
	default:
	{
		cout << "Invalid Entry\n";
		break;
	}
	}


}
void Evaluation::calculategrade()
{
	if (!withdraw)
	{
		cout << "\n\nThe student has achieved " << totalabs << " absolutes\nEnter the grade you wish to award:";
		cin >> grade;

		cout << "\nEnter GPA for " << grade << '\t';
		cin >> gpa;
		/*int t2 = 0, totalabs = 0;
		for (int i = 0; i < quizcount; i++)
		{
			t2 += *quiz[i];
		}
		totalabs += (t2 / (10 * quizcount)) * weightage[0];

		t2 = 0;
		for (int i = 0; i < asgcount; i++)
		{
			t2 += *asg[i];
		}
		totalabs += (t2 / (50  * asgcount)) * weightage[1];

		t2 = 0;
		totalabs += (mid / 30) * weightage[2];
		totalabs += (project / 100) * weightage[3];
		totalabs += (final / 100) * weightage[4];

		cout << "The student has achieved " << totalabs << " absolutes\nEnter the grade you wish to award:";
		cin >> grade;

		cout << "\nEnter GPA for " << grade<<'\t';
		cin >> gpa;*/
	}
	else
	{
		std::cout << "This course has been withdrawn. W grade will be awarded\n";
		grade[0] = 'W';
	}


}
void Evaluation::evalreport()
{
	if (!withdraw)
	{
		system("CLS");
		float t1 = 0, t2 = 0;
		for (int i = 0; i < quizcount; i++)
		{
			cout << "Marks obtained out of 10 in Quiz " << i + 1 << "\t" << *quiz[i]<<"\n";// << "\t" << quiz[quizcount - 1];
			t2 += *quiz[i];
		}
		//t1 += t2;
		cout << "\nNumber of Quizzes\t" << quizcount << "\nTotal Quiz Marks\t" << quizcount * 10
			<< "\nMarks Obtained\t" << t2 << "\nAbsolutes\t" << ((t2 / (quizcount * 10)) * weightage[0]);
		t1 += ((t2 / (10 * quizcount)) * weightage[0]);
		//cout << "\nT1\t" << t1;


		t2 = 0;
		for (int i = 0; i < asgcount; i++)
		{
			cout << "\n\nMarks obtained out of 50 in Assignment " << i + 1 << "\t" << *asg[i]<<"\n";
			t2 += *asg[i];
		}
		//t1 += t2;
		t1 += ((t2 / (50 * asgcount)) * weightage[1]);
		//cout << "\nT1\t" << t1;
		cout << "\nNumber of Assignments\t" << asgcount << "\nTotal Assignment Marks " << asgcount * 50
			<< "\nMarks Obtained\t" << t2 << "\nAbsolutes\t" << ((t2 / (asgcount * 50)) * weightage[1])<<"\n\n";

		//t1 += (t2 / (10 * asgcount) * weightage[1]);
		t1 += ((mid / 30) * weightage[2]);
		//cout << "\nT1\t" << t1;

		t1 += ((project / 100) * weightage[3]);
		//cout << "\nT1\t" << t1;

		t1 += ((final / 100) * weightage[4]);
		//cout << "\nT1\t" << t1;


		cout << "Midterm Marks Obtained\t" << mid << "/30\nAbsolutes\t" << (mid / 30) * weightage[2];
		cout << "\n\nProject Marks Obtained\t" << project << "/100\nAbsolutes\t" << ((project / 100) * weightage[3]);
		cout << "\n\nFinal Marks Obtained\t" << final << "/100\nAbsolutes\t" << ((final / 100) * weightage[4]);
		
		totalabs = t1;
		cout << "\n\nTotal Absolutes\t" << t1 << "\n";
	}
	else
		std::cout << "Course has been withdrawn. W grade will be awarded\n";
}

Evaluation::~Evaluation()
{
	for (int i = 0; i < quizcount; i++)
		delete quiz[i];
	delete[]quiz;
	quiz = 0;

	for (int i = 0; i < asgcount; i++)
		delete asg[i];
	delete[]asg;
	asg = 0;

}