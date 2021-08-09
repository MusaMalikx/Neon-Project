#pragma once
#include<iostream>

using namespace std;

class Person {

	char* a;
	char* name;
public:

	//friend ostream& operator<<(ostream& _cout, const Person& obj);
	//friend istream& operator>>(istream& _cin, Person& obj);



	Person()
	{
		this->a = nullptr;
		this->name = nullptr;
	}

	Person(const char* a, const char* name)
	{
		int l = strlen(a);

		this->a = new char[l + 1];

		for (int i = 0; i < l; i++) {
			this->a[i] = a[i];
		}
		this->a[l] = '\0';
		int len = strlen(name);

		this->name = new char[len + 1];

		for (int i = 0; i < len; i++) {
			this->name[i] = name[i];
		}
		this->name[len] = '\0';
	}

	bool Change_UN()
	{
		char ps[50];
		cout << "Enter the New User_Name : ";
		cin >> ps;
		int len = strlen(ps);
		this->name = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			this->name[i] = ps[i];
		}
		this->name[len] = '\0';

		return true;
	}

	void Set_UN(const char* ps)
	{
		int len = strlen(ps);
		this->name = new char[len + 1];
		for (int i = 0; i < len; i++)
		{
			this->name[i] = ps[i];
		}
		this->name[len] = '\0';
	}

	void Set_C(const char* a) {
		int l = strlen(a);

		this->a = new char[l + 1];

		for (int i = 0; i < l; i++) {
			this->a[i] = a[i];
		}
		this->a[l] = '\0';
	}

	char* GetCode()
	{
		return this->a;

	}

	char* GetName()
	{
		return this->name;
	}

	virtual void print()
	{
		cout << "Name : " << this->name << endl;
	}

	virtual ~Person()
	{
		delete[]this->name;
		delete[]this->a;
	}

};

//ostream& Person::operator<<(ostream& _cout, const Person& obj)
//{
//	cout << "Name : " << obj.name << endl;
//	cout << "Code : " << obj.a << endl;
//	return _cout;
//}
//
//
//istream& Person::operator>>(istream& _cin, Person& obj) {
//	
//	char n[50];
//	char c[50];
//	cout << "Name : ";
//	cin.getline(n, 50);
//	cout << endl;
//
//	int len = strlen(n);
//
//	obj.name = new char[len + 1];
//
//	for (int i = 0; i < len; i++) {
//		obj.name[i] = n[i];
//	}
//	obj.name[len] = '\0';
//
//
//
//	cout << "code : ";
//	cin.getline(c, 50);
//	cout << endl;
//
//	int l = strlen(c);
//
//	obj.a = new char[l + 1];
//
//	for (int i = 0; i < l; i++) {
//		obj.a[i] = c[i];
//	}
//	obj.a[l] = '\0';
//
//	return _cin;
//
//}

