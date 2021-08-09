#pragma once
#include<iostream>
#include"Teacher.h"

using namespace std;

class TA :public Teacher, public Student
{



public:

	TA();

	TA(const char* n, const char* name);

	void print();

};

TA::TA():Student(),Teacher()
{

}

TA::TA(const char* n, const char* name) : Student(n, name), Teacher(n, name) 
{

}

void TA::print() 
{
	cout << "-----------------TA Information-----------------" << endl;
	Student::print();
}