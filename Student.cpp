#include<iostream>
#include"Student.h"
#include"Registration.h"

using namespace std;

//ostream& operator<<(ostream& _cout, const Student& obj) {
//
//	cout << Person::GetName() << "/" << Person::GetCode() << endl;
//	return _cout;
//}

//istream& operator>>(istream& _cin, Student& obj) {
//
//	return _cin;
//}



Student::Student() :Person()
{
	char p[] = { "!@#123456!@#" };
	int len = strlen(p);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = p[i];
	}
	this->password[len] = '\0';

	this->ListOfRegistration = new Registration * [10];

	this->regis_C = 0;

	/*register_Course = new Registration*[10];
	regis_C = 0;*/

}

Student::Student(const char* a, const char* name) :Person(a, name)
{
	char p[] = { "!@#123456!@#" };
	int len = strlen(p);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = p[i];
	}
	this->password[len] = '\0';

	this->ListOfRegistration = new Registration * [10];

	this->regis_C = 0;
	/*register_Course = new Registration[10];
	regis_C = 0;*/


}

bool Student::Change_Password()
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

void Student::Set_PStudent(const char* ps)
{
	int len = strlen(ps);
	this->password = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->password[i] = ps[i];
	}
	this->password[len] = '\0';
}

bool Student::ChangeIT_UN()
{
	Person::Change_UN();
	return true;
}

void Student::Set_ITUN(const char* ps)
{
	Person::Set_UN(ps);
}

void Student::print()
{
	cout << "-----------------Student Information-----------------" << endl;
	Person::print();
	cout << "Roll Number : " << this->GetCode() << endl;
	cout << "Courses : " << endl;
	for (int i = 0; i < this->regis_C; i++) {
		cout << this->ListOfRegistration[i]->Get_Assigned_course_C() << "  " << this->ListOfRegistration[i]->Get_Assigned_Course_N() << endl;
	}
}

char* Student::GetS_Password()
{
	return this->password;
}

char* Student::GetS_Code()
{
	return Person::GetCode();
}

char* Student::GetS_Name()
{
	return Person::GetName();
}

bool Student::Register_Course(const char* name, const char* code) {

	
	
	if (this->regis_C == 5) {
		return false;
	}

	int count;

	for (int i = 0; i < this->regis_C; ++i) {

		count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfRegistration[i]->Get_Assigned_course_C()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfRegistration[i]->Get_Assigned_course_C())) {
			return false;
		}
	}

	this->ListOfRegistration[this->regis_C] = new Registration;

	this->ListOfRegistration[this->regis_C]->Assign_Course(name, code);

	this->regis_C++;

	return true;
}

bool Student::Unregister_course(const char* code)
{
	int count;

	for (int i = 0; i < this->regis_C; ++i) {

		 count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfRegistration[i]->Get_Assigned_course_C()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfRegistration[i]->Get_Assigned_course_C())) {
			delete this->ListOfRegistration[i];

			for (int j = i; j < this->regis_C - 1; ++j) {
				this->ListOfRegistration[j] = this->ListOfRegistration[j + 1];
			}
			this->ListOfRegistration[--this->regis_C] = 0;
			return true;
		}
	}
	return false;
}

int Student::Get_Regis_courses_count() {
	return this->regis_C;
}

void Student::Set_Student_N(const char* name) {
	Person::Set_UN(name);
}

void Student::Set_Student_C(const char* code) {
	Person::Set_C(code);
}

char* Student::Get_Assign_courses_SC(int Course_c) {
	return this->ListOfRegistration[Course_c]->Get_Assigned_course_C();
}

char* Student::Get_Assign_courses_SN(int Course_c) {
	return this->ListOfRegistration[Course_c]->Get_Assigned_Course_N();
}

bool Student::Add_Attendence(int c, bool attendence, int y, int m, int d) {
	return this->ListOfRegistration[c]->Add_Attendence(attendence, y, m, d);
}

void Student::Set_Date(int r, int y, int m, int d, int lecture) {
	this->ListOfRegistration[r]->Set_Date(y, m, d, lecture);
}

//void Student::Set_lecture_Attendence_count(int r, int count) {
//	this->ListOfRegistration[r]->Set_lecture_Attendence_count(count);
//}

bool* Student::Get_Attendence(int r) {
	return this->ListOfRegistration[r]->Get_Attendence();
}

int Student::Get_Attendence_count(int r) {
	return this->ListOfRegistration[r]->Get_Attendence_count();
}

void Student::View_Attendence(int r) {
	this->ListOfRegistration[r]->View_Attendence();
}

//int* Student::Total_Lecture(int r) {
//	return this->ListOfRegistration[r]->Total_Lecture();
//
//}

char* Student::Get_Date(int r,int lecture) {
	return this->ListOfRegistration[r]->Get_Date(lecture);
}

int Student::Get_Lecture_count(int r) {
	return this->ListOfRegistration[r]->Get_lectures_count();
}

int* Student::Get_TotalQuizes(int r) {
	return this->ListOfRegistration[r]->Get_TotalQuizes();
}

int* Student::Get_TotalAssignments(int r) {
	return this->ListOfRegistration[r]->Get_TotalAssignments();
}

int Student::Get_Assign_capacity(int r) {
	return this->ListOfRegistration[r]->Get_Assign_capacity();
}

int Student::Get_Quiz_capacity(int r) {
	return this->ListOfRegistration[r]->Get_Quiz_capacity();
}

void Student::Set_Assign_capacity(int r, int s) {
	this->ListOfRegistration[r]->Set_Assign_capacity(s);
}

void Student::Set_Quiz_capacity(int r, int s) {
	this->ListOfRegistration[r]->Set_Quiz_capacity(s);
}

bool Student::Add_Assignments(int r, int number) {
	return this->ListOfRegistration[r]->Add_Assignments(number);
}


bool Student::Add_Quizes(int r, int number) {
	return this->ListOfRegistration[r]->Add_Quizes(number);
}

int Student::Get_AssignCount(int r) {
	return this->ListOfRegistration[r]->Get_AssignCount();
}

int Student::Get_QuizCount(int r) {
	return this->ListOfRegistration[r]->Get_QuizCount();
}

int Student::Get_Mid(int r) {
	return this->ListOfRegistration[r]->Get_Mid();
}

void Student::Set_Mid(int r, int mid) {
	this->ListOfRegistration[r]->Set_Mid(mid);
}

int Student::Get_Final(int r) {
	return this->ListOfRegistration[r]->Get_Final();
}

void Student::Set_Final(int r, int final) {
	this->ListOfRegistration[r]->Set_Final(final);
}

void Student::Set_Y(int r, int y) {
	this->ListOfRegistration[r]->Set_Y(y);
}

void Student::Set_M(int r, int m) {
	this->ListOfRegistration[r]->Set_M(m);
}

void Student::Set_D(int r, int d) {
	this->ListOfRegistration[r]->Set_D(d);
}

int Student::Get_Y(int r) {
	return this->ListOfRegistration[r]->Get_Y();
}

int Student::Get_M(int r) {
	return this->ListOfRegistration[r]->Get_M();
}

int Student::Get_D(int r) {
	return this->ListOfRegistration[r]->Get_D();
}

bool Student::Add_Assignment_weightage(int r, int number) {
	return this->ListOfRegistration[r]->Add_Assignment_weightage(number);
}

bool Student::Add_Quiz_weightage(int r, int number) {
	return this->ListOfRegistration[r]->Add_Quiz_weightage(number);
}

bool Student::Add_Mid_weightage(int r, int number) {
	return this->ListOfRegistration[r]->Add_Mid_weightage(number);
}

bool Student::Add_Final_weightage(int r, int number) {
	return this->ListOfRegistration[r]->Add_Final_weightage(number);
}

bool Student::Add_T_Marks_Assignments(int r, int number) {
	return this->ListOfRegistration[r]->Add_T_Marks_Assignments(number);
}

bool Student::Add_T_Marks_Quizes(int r, int number) {
	return this->ListOfRegistration[r]->Add_T_Marks_Quizes(number);
}

bool Student::Add_T_Marks_Mid(int r, int number) {
	return this->ListOfRegistration[r]->Add_T_Marks_Mid(number);
}

bool Student::Add_T_Marks_Final(int r, int number) {
	return this->ListOfRegistration[r]->Add_T_Marks_Final(number);
}

int* Student::Get_Assignment_weightage(int r) {
	return this->ListOfRegistration[r]->Get_Assignment_weightage();
}

int* Student::Get_Quiz_weightage(int r) {
	return this->ListOfRegistration[r]->Get_Quiz_weightage();
}

int Student::Get_Mid_weightage(int r) {
	return this->ListOfRegistration[r]->Get_Mid_weightage();
}

int Student::Get_Final_weightage(int r) {
	return this->ListOfRegistration[r]->Get_Final_weightage();
}

int* Student::Get_T_Marks_Assignment(int r) {
	return this->ListOfRegistration[r]->Get_T_Marks_Assignment();
}

int* Student::Get_T_Marks_Quizes(int r) {
	return this->ListOfRegistration[r]->Get_T_Marks_Quizes();
}

int Student::Get_T_Marks_Mid(int r) {
	return this->ListOfRegistration[r]->Get_T_Marks_Mid();
}

int Student::Get_T_Marks_Final(int r) {
	return this->ListOfRegistration[r]->Get_T_Marks_Final();
}

int Student::Get_Weightage_Assign_count(int r) {
	return this->ListOfRegistration[r]->Get_Weightage_Assign_count();
}

int Student::Get_Weightage_Quiz_count(int r) {
	return this->ListOfRegistration[r]->Get_Weightage_Quiz_count();
}

int Student::Get_T_Marks_Assign_count(int r) {
	return this->ListOfRegistration[r]->Get_T_Marks_Assign_count();
}

int Student::Get_T_Marks_Quiz_count(int r) {
	return this->ListOfRegistration[r]->Get_T_Marks_Quiz_count();
}

bool Student::Assign_Grade(int r, const char* g) {
	return this->ListOfRegistration[r]->Assign_Grade(g);
}

char* Student::Get_Grade(int r) {
	return this->ListOfRegistration[r]->Get_Grade();
}

Student::~Student()
{
	for (int i = 0; i < this->regis_C; i++) {
		delete this->ListOfRegistration[i];
	}
	delete[]this->ListOfRegistration;
	delete[]this->password;
}