#pragma once
#include<iostream>
#include"Employee.h"
#include"Course.h"

using namespace std;

class Teacher:protected Employee 
{

	char* password;
	Course** ListOfCourses;
	int Course_c;

public:

	Teacher();

	Teacher(const char* n, const char* name);

	bool ChangeT_Password();

	void Set_TP(const char* ps);

	bool ChangeT_UN();

	void Set_TUN(const char* ps);

	char* GetT_Password();

	char* GetT_Code();

	char* GetT_Name();

	bool Assign_Courses(const char* name, const char* code);

	bool Unassign_Course(const char* code);

	int Get_Assign_Courses_Count();

	char* Get_Assign_courses_TC(int Course_c);

	char* Get_Assign_Courses_TN(int Course_c);

	void print();

	~Teacher();

};

Teacher::Teacher() :Employee()
{
	char p[] = { "!@#123456!@#" };
	int len = strlen(p);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = p[i];
	}
	this->password[len] = '\0';

	this->ListOfCourses = new Course * [10];

	this->Course_c = 0;

}

Teacher::Teacher(const char* n, const char* name) : Employee(n, name)
{
	char p[] = { "!@#123456!@#" };
	int len = strlen(p);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = p[i];
	}
	this->password[len] = '\0';

	this->ListOfCourses = new Course * [10];

	this->Course_c = 0;

}

char* Teacher::Get_Assign_courses_TC(int Course_c) {
	return this->ListOfCourses[Course_c]->GetCourseCode();
}

char* Teacher::Get_Assign_Courses_TN(int Course_c) {
	return ListOfCourses[Course_c]->GetCourseName();
}

int Teacher::Get_Assign_Courses_Count() 
{
	return this->Course_c;
}

bool Teacher::Assign_Courses(const char* name, const char* code) 
{
	if (Course_c == 10) {
		return false;
	}

	int count;

	for (int i = 0; i < this->Course_c; ++i) {

		count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfCourses[i]->GetCourseCode()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfCourses[i]->GetCourseCode())) {
			return false;
		}

	}

	this->ListOfCourses[Course_c++] = new Course(name, code);
	return true;
}

bool Teacher::Unassign_Course(const char* code)
{
	int count;

	for (int i = 0; i < this->Course_c; ++i) {

		count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfCourses[i]->GetCourseCode()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfCourses[i]->GetCourseCode())) {
			delete this->ListOfCourses[i];

			for (int j = i; j < this->Course_c - 1; ++j) {
				this->ListOfCourses[j] = this->ListOfCourses[j + 1];
			}
			this->ListOfCourses[--this->Course_c] = 0;
			return true;
		}
	}
	return false;
}

bool Teacher::ChangeT_Password()
{
	char ps[20];
	cout << "Enter the New Password : ";
	cin >> ps;
	int len = strlen(ps);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = ps[i];
	}
	this->password[len] = '\0';

	return true;
}

bool Teacher::ChangeT_UN()
{
	Employee::Change_N();
	return true;
}

void Teacher::Set_TP(const char* ps)
{
	int len = strlen(ps);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = ps[i];
	}
	this->password[len] = '\0';
}

void Teacher::Set_TUN(const char* ps)
{
	Employee::Set_N(ps);
}

char* Teacher::GetT_Password()
{
	return this->password;
}

char* Teacher::GetT_Code()
{
	return Employee::GetE_Code();
}

char* Teacher::GetT_Name()
{
	return Employee::GetE_Name();
}

void Teacher::print()
{
	cout << "-----------------Teacher Information-----------------" << endl;
	Employee::print();
	cout << "Code : " << this->GetCode() << endl;
}

Teacher::~Teacher()
{
	for (int i = 0; i < this->Course_c; i++) {
		delete this->ListOfCourses[i];
	}
	delete[]this->ListOfCourses;

	delete[]this->password;
}