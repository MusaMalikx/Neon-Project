#pragma once
#include"Employee.h"

class ITManager :protected Employee
{

	char* password;

public:

	ITManager();

	ITManager(const char* n, const char* name);

	char* GetIT_Code();

	char* GetIT_Name();

	bool ChangeIT_Password();

	void Set_PIT(const char* ps);

	bool ChangeIT_UN();

	void Set_ITUN(const char* ps);

	char* GetIT_Password();

	void print();

	~ITManager();

};

ITManager::ITManager() :Employee()
{
	char p[] = { "!@#123456!@#" };
	int len = strlen(p);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = p[i];
	}
	this->password[len] = '\0';
}

ITManager::ITManager(const char* n, const char* name) : Employee(n, name) 
{
	char p[] = { "!@#123456!@#" };
	int len = strlen(p);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = p[i];
	}
	this->password[len] = '\0';
}

bool ITManager::ChangeIT_Password()
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

void ITManager::Set_PIT(const char* ps)
{
	int len = strlen(ps);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = ps[i];
	}
	this->password[len] = '\0';
}

char* ITManager::GetIT_Code()
{
	return Employee::GetE_Code();
}

char* ITManager::GetIT_Name()
{
	return Employee::GetE_Name();
}

//char* ITManager::GetIT_Password()
//{
//	return this->password;
//}

bool ITManager::ChangeIT_UN()
{
	Person::Change_UN();
	return true;
}

void ITManager::Set_ITUN(const char* ps)
{
	Person::Set_UN(ps);
}

char* ITManager::GetIT_Password()
{
	return this->password;
}

void ITManager::print()
{
	cout << "-----------------IT Manager-----------------" << endl;
	Employee::print();
	cout << "Code : " << this->GetCode() << endl;
}

ITManager::~ITManager()
{
	delete[]this->password;
}
