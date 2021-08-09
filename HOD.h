#pragma once
#include<iostream>
#include"Teacher.h"

using namespace std;

class HOD :public Teacher
{

public:
	
	HOD();

	HOD(const char* name, const char* code);


};

HOD::HOD() :Teacher()
{

}

HOD::HOD(const char* name, const char* code) : Teacher(code, name)
{

}

