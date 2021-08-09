#pragma once
#include<iostream>
#include"Person.h"

using namespace std;

class Employee:protected Person
{

public:

	Employee();

	Employee(const char* a, const char* n);

	bool Change_N();

	void Set_N(const char* ps);

	char* GetE_Code();
	
	char* GetE_Name();

	void print();

};

Employee::Employee() :Person() 
{

}

Employee::Employee(const char* a, const char* n) : Person(a, n) 
{

}

bool Employee::Change_N()
{
	return Person::Change_UN();
}

void Employee::Set_N(const char* ps)
{
	Person::Set_UN(ps);
}

char* Employee::GetE_Code()
{
	return Person::GetCode();
}

char* Employee::GetE_Name()
{
	return Person::GetName();
}


void Employee::print()
{
	Person::print();
	cout << endl;
}
