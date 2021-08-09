#pragma once
#include<iostream>
#include"Course.h"
#include"Teacher.h"
#include"ITManager.h"
#include"Student.h"
#include"HOD.h"

using namespace std;

class Department {

	char* name;
	Course** ListOFCourses;
	Teacher** ListOfTeachers;
	ITManager* t;
	Student** ListOfStudents;
	Teacher* hod;
	int C_count;
	int T_count;
	int S_count;
	int capacity_S;
	int capacity_T;
	int capacity_C;

public:


	Department();

	Department(const char* name);

	void print();

	~Department();

	bool AddTeacher(const char* name, const char* code);

	bool RemoveTeacher(const char* code);

	bool AddCourse(const char* name, const char* code);

	bool AddITManager(const char* name, const char* code);
	
	bool AddHOD(const char* name, const char* code);

	bool AddStudent(const char* name, const char* code);

	bool RemoveStudent(const char* code);

	int GetStudentCount();

	char* GetStudentName(int s_n);

	char* GetStudentCode(int s_c);

	void Grow(Student**& arr);

	void Grow(Course**& arr);

	void Grow(Teacher**& arr);

	char* GetStudentPassword(int s_n);
	
	bool ChangePassword(int s_c);

	void Set_Ps(const char* ps, int s_n);

	bool Register_Course_for_Students(int s ,const char* name, const char* code);

	bool UnRegister_Course_for_Students(int s, const char* code);

	int Get_Registration_courses_count(int s);

	char* Get_Assign_courses_SC(int s, int c);

	char* Get_Assign_courses_SN(int s,int c);

	bool Add_Attendence(int s, int c, bool a, int y, int m, int d);

	bool* Get_Attendence(int s, int c);

	int Get_Attendence_count(int s, int r);

	void View_Attendence(int s, int r);

	char* Get_Date(int s, int r, int lecture);

	//int* Total_Lecture(int s, int r);

	int GetTeacherCount();

	char* GetTeacherName(int teacher_n);

	char* GetTeacherCode(int teacher_c);

	bool ChangeT_Password(int t_c);

	void Set_TP(const char* ps,int t_c);

	bool ChangeT_UN(int t_c);

	void Set_TUN(const char* ps, int t_c);

	char* GetT_Password(int t_c);

	int Get_Assign_Courses_Count(int t_);

	char* Get_Assign_courses_TC(int t, int c);

	char* Get_Assign_Courses_TN(int t, int c);

	bool Assign_Courses_to_Teacher(int t, const char* name, const char* code);

	char* GetCourseName(int course_n);

	char* GetCourseCode(int course_c);

	char* GetITName();

	char* GetITCode();

	bool ChangeIT_Password();

	void Set_PIT(const char* ps);

	bool ChangeIT_UN();

	void Set_ITUN(const char* ps);

	char* GetIT_Password();

	char* GetDepartName();

	int GetCourseCount();

	//void Set_lecture_Attendence_count_in_course(int s,int c, int count);

	int Get_lectures_count(int s, int c);

	bool Assign_Students_for_courses(int c, const char* name, const char* code);

	int Get_Student_count_in_courses(int c);

	char* Get_Assign_Student_CC(int d, int C);

	char* Get_Assign_Student_CN(int d, int C);

	int find_Student_Index(const char* code);

	int find_1S_Course(const char* code);

	int* find_Student_Courses_Index(const char* code);

	int find_Course_Index(const char* code);

	int find_Teacher_Index(const char* code);

	int find_Teacher_Courses_Index(const char* code);

	char* GetHODName();

	char* GetHODCode();

	char* GetHODPassword();

	void Set_HOD_P(const char* p);

	bool Change_HOD_P();

	int* Get_TotalQuizes(int s, int r);

	int* Get_TotalAssignments(int s, int r);

	int Get_Assign_capacity(int s, int r);

	int Get_Quiz_capacity(int s, int r);

	void Set_Assign_capacity(int s,int r, int se);

	void Set_Quiz_capacity(int s, int r, int se);

	bool Add_Assignments(int s, int r, int number);

	bool Add_Quizes(int s, int r, int number);

	int Get_AssignCount(int s, int r);

	int Get_QuizCount(int s, int r);

	int Get_Mid(int s, int r);

	void Set_Mid(int s, int r, int mid);

	int Get_Final(int s, int r);

	void Set_Final(int s, int r, int final);

	void Set_Y(int s, int r, int y);

	void Set_M(int s, int r, int m);

	void Set_D(int s, int r, int d);

	int Get_Y(int s, int r);

	int Get_M(int s, int r);

	int Get_D(int s, int r);

	bool Add_Assignment_weightage(int s, int r, int number);

	bool Add_Quiz_weightage(int s, int r, int number);

	bool Add_Mid_weightage(int s, int r, int number);

	bool Add_Final_weightage(int s, int r, int number);

	bool Add_T_Marks_Assignments(int s, int r, int number);

	bool Add_T_Marks_Quizes(int s, int r, int number);

	bool Add_T_Marks_Mid(int s, int r, int number);

	bool Add_T_Marks_Final(int s, int r, int number);

	int* Get_Assignment_weightage(int s, int r);

	int* Get_Quiz_weightage(int s, int r);

	int Get_Mid_weightage(int s, int r);

	int Get_Final_weightage(int s, int r);

	int* Get_T_Marks_Assignment(int s, int r);

	int* Get_T_Marks_Quizes(int s, int r);

	int Get_T_Marks_Mid(int s, int r);

	int Get_T_Marks_Final(int s, int r);

	int Get_Weightage_Assign_count(int s, int r);

	int Get_Weightage_Quiz_count(int s, int r);

	int Get_T_Marks_Assign_count(int s, int r);

	int Get_T_Marks_Quiz_count(int s, int r);

	bool Assign_Grade(int s, int r, const char* g);

	char* Get_Grade(int s, int r);

	template<class Type>
	bool Grw(Type**& arr);


};

Department::Department()
{
	this->C_count = 0;
	this->T_count = 0;
	this->t = nullptr;
	this->name = nullptr;
	this->hod = nullptr;
	this->capacity_C = 10;
	this->capacity_S = 10;
	this->capacity_T = 10;
	this->ListOFCourses = new Course * [this->capacity_S];
	this->ListOfTeachers = new Teacher * [this->capacity_T];
	this->ListOfStudents = new Student * [this->capacity_S];
	this->S_count = 0;

}

Department::Department(const char* name)
{
	this->C_count = 0;
	this->T_count = 0;
	this->hod = nullptr;
	this->t = nullptr;
	this->capacity_C = 10;
	this->capacity_S = 10;
	this->capacity_T = 10;
	this->ListOFCourses = new Course * [10];
	this->ListOfTeachers = new Teacher * [10];
	this->ListOfStudents = new Student * [10];
	this->S_count = 0;
	
	int len = strlen(name);
	this->name = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		this->name[i] = name[i];
	}
	this->name[len] = '\0';
}

char* Department::GetCourseName(int course_n)
{
	return this->ListOFCourses[course_n]->GetCourseName();
}

char* Department::GetCourseCode(int course_c)
{
	return this->ListOFCourses[course_c]->GetCourseCode();
}

//void Department::Set_lecture_Attendence_count_in_course(int s, int c, int count) {
//	this->ListOfStudents[s]->Set_lecture_Attendence_count(c,count);
//}

char* Department::Get_Date(int s, int r, int lecture) {
	return this->ListOfStudents[s]->Get_Date(r, lecture);
}

int Department::Get_lectures_count(int s , int c) {
	return this->ListOfStudents[s]->Get_Lecture_count(c);
}

bool Department::Assign_Students_for_courses(int c, const char* name, const char* code) {
	return this->ListOFCourses[c]->AssignStudents(name, code);
}

int Department::Get_Student_count_in_courses(int c) {
	return this->ListOFCourses[c]->Get_Student_count();
}

char* Department::Get_Assign_Student_CC(int d, int C) {
	return this->ListOFCourses[d]->Get_Assign_Student_CC(C);
}

char* Department::Get_Assign_Student_CN(int d, int C) {
	return this->ListOFCourses[d]->Get_Assign_Student_CN(C);
}

bool Department::Add_Attendence(int s, int r, bool a, int y, int m, int d) {
	return this->ListOfStudents[s]->Add_Attendence(r, a, y, m, d);
}

bool* Department::Get_Attendence(int s, int c) {
	return this->ListOfStudents[s]->Get_Attendence(c);
}

int Department::Get_Attendence_count(int s, int r) {
	return this->ListOfStudents[s]->Get_Attendence_count(r);
}

void Department::View_Attendence(int s, int r) {
	this->ListOfStudents[s]->View_Attendence(r);
}

//int* Department::Total_Lecture(int s, int r) {
//	return this->ListOfStudents[s]->Total_Lecture(r);
//}

int* Department::Get_TotalQuizes(int s, int r) {
	return this->ListOfStudents[s]->Get_TotalQuizes(r);
}

int* Department::Get_TotalAssignments(int s, int r) {
	return this->ListOfStudents[s]->Get_TotalAssignments(r);
}

int Department::Get_Assign_capacity(int s, int r) {
	return this->ListOfStudents[s]->Get_Assign_capacity(r);
}

int Department::Get_Quiz_capacity(int s, int r) {
	return this->ListOfStudents[s]->Get_Quiz_capacity(r);
}

void Department::Set_Assign_capacity(int s, int r, int se) {
	this->ListOfStudents[s]->Set_Assign_capacity(r, se);
}

void Department::Set_Quiz_capacity(int s, int r, int se) {
	this->ListOfStudents[s]->Set_Quiz_capacity(r, se);
}

bool Department::Add_Assignments(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_Assignments(r, number);
}

bool Department::Add_Quizes(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_Quizes(r, number);
}

int Department::Get_AssignCount(int s, int r) {
	return this->ListOfStudents[s]->Get_AssignCount(r);
}

int Department::Get_QuizCount(int s, int r) {
	return this->ListOfStudents[s]->Get_QuizCount(r);
}

int Department::Get_Mid(int s, int r) {
	return this->ListOfStudents[s]->Get_Mid(r);
}

void Department::Set_Mid(int s, int r, int mid) {
	this->ListOfStudents[s]->Set_Mid(r, mid);
}

int Department::Get_Final(int s, int r) {
	return this->ListOfStudents[s]->Get_Final(r);
}

void Department::Set_Final(int s, int r, int final) {
	this->ListOfStudents[s]->Set_Final(r, final);
}

int Department::find_Student_Index(const char* code) {
	int index = 0;
	int count = 0;

	for (int i = 0; i < this->S_count; ++i) {

		count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfStudents[i]->GetS_Code()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfStudents[i]->GetS_Code())) {
			index = i;
		}
	}

	return index;


}

int Department::find_Course_Index(const char* code) {
	int index = 0;
	int count = 0;

	for (int i = 0; i < this->C_count; ++i) {

		count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOFCourses[i]->GetCourseCode()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOFCourses[i]->GetCourseCode())) {
			index = i;
		}
	}

	return index;
}

int Department::find_Teacher_Index(const char* code) {
	int index = 0;
	int count = 0;

	for (int i = 0; i < this->T_count; ++i) {

		count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfTeachers[i]->GetT_Code()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfTeachers[i]->GetT_Code())) {
			index = i;
		}
	}

	return index;
}

int* Department::find_Student_Courses_Index(const char* code) {
	int* index = new int [S_count];
	int count = 0;
	int a = 1;
	int in = 0;

	for (int i = 0; i < this->S_count; ++i) {

		count = 0;
		

		
		for (int j = 0; j < this->ListOfStudents[i]->Get_Regis_courses_count(); j++) {
			count = 0;
			for (int k = 0; k < strlen(code); k++)
			{
				if (code[k] == this->ListOfStudents[i]->Get_Assign_courses_SC(j)[k])
				{
					count++;
					if (count == strlen(this->ListOfStudents[i]->Get_Assign_courses_SC(j))) {
						in = j;
					}
				}
			}
			
			if (count == strlen(this->ListOfStudents[i]->Get_Assign_courses_SC(j))) {
				index[a] = i;
				a++;
			}

		}

		

	}

	index[0] = a;

	return index;
}

int Department::find_1S_Course(const char* code) {
	int index = 0;
	int count = 0;

	for (int i = 0; i < this->S_count; ++i) {

		count = 0;


		for (int j = 0; j < this->ListOfStudents[i]->Get_Regis_courses_count(); j++) {
			count = 0;
			for (int k = 0; k < strlen(code); k++)
			{
				if (code[k] == this->ListOfStudents[i]->Get_Assign_courses_SC(j)[k])
				{
					count++;
				}
			}

			if (count == strlen(this->ListOfStudents[i]->Get_Assign_courses_SC(j))) {
				index = j;
			}
		}
	}

	return index;

}

int Department::find_Teacher_Courses_Index(const char* code) {
	int index = 0;
	int count = 0;

	for (int i = 0; i < this->T_count; ++i) {

		count = 0;

		for (int j = 0; j < this->ListOfTeachers[i]->Get_Assign_Courses_Count(); j++) {

			for (int k = 0; k < strlen(code); k++)
			{
				if (code[k] == this->ListOfTeachers[i]->Get_Assign_courses_TC(j)[k])
				{
					count++;
				}
			}

			if (count == strlen(this->ListOfTeachers[i]->Get_Assign_courses_TC(j))) {
				index = j;
			}
		}
	}

	return index;
}

char* Department::GetTeacherName(int teacher_n)
{
	return this->ListOfTeachers[teacher_n]->GetT_Name();
}

char* Department::GetTeacherCode(int teacher_c)
{
	return this->ListOfTeachers[teacher_c]->GetT_Code();
}

bool Department::ChangeT_Password(int t_c)
{
	return this->ListOfTeachers[t_c]->ChangeT_Password();
}

void Department::Set_TP(const char* ps, int t_c)
{
	this->ListOfTeachers[t_c]->Set_TP(ps);
}

bool Department::ChangeT_UN(int t_c)
{
	return this->ListOfTeachers[t_c]->ChangeT_UN();
}

void Department::Set_TUN(const char* ps, int t_c)
{
	this->ListOfTeachers[t_c]->Set_TUN(ps);
}

char* Department::GetT_Password(int t_c)
{
	return this->ListOfTeachers[t_c]->GetT_Password();
}

int Department::Get_Assign_Courses_Count(int t_c) {
	return this->ListOfTeachers[t_c]->Get_Assign_Courses_Count();
}

char* Department::Get_Assign_courses_TC(int t, int c) {
	return this->ListOfTeachers[t]->Get_Assign_courses_TC(c);
}

char* Department::Get_Assign_Courses_TN(int t, int Course_c) {
	return this->ListOfTeachers[t]->Get_Assign_Courses_TN(Course_c);
}

bool Department::Assign_Courses_to_Teacher(int t, const char* name, const char* code) {
	return this->ListOfTeachers[t]->Assign_Courses(name, code);
}

bool Department::ChangeIT_Password()
{
	return this->t->ChangeIT_Password();
}

void Department::Set_PIT(const char* ps)
{
	this->t->Set_PIT(ps);
}

bool Department::ChangeIT_UN()
{
	return this->t->ChangeIT_UN();
}

void Department::Set_ITUN(const char* ps)
{
	this->t->Set_ITUN(ps);
}

char* Department::GetIT_Password()
{
	return this->t->GetIT_Password();
}

int Department::GetCourseCount()
{
	return this->C_count;
}

int Department::GetTeacherCount()
{
	return this->T_count;
}

char* Department::GetITName()
{
	return this->t->GetIT_Name();
}

char* Department::GetITCode()
{
	return this->t->GetIT_Code();
}

char* Department::GetStudentName(int s_n)
{
	return this->ListOfStudents[s_n]->GetS_Name();
}

char* Department::GetStudentCode(int s_c)
{
	return this->ListOfStudents[s_c]->GetS_Code();
}

char* Department::GetStudentPassword(int s_n)
{
	return this->ListOfStudents[s_n]->GetS_Password();
}

bool Department::ChangePassword(int s_n)
{
	this->ListOfStudents[s_n]->Change_Password();
	return true;
}

void Department::Set_Ps(const char* ps, int s_n)
{
	this->ListOfStudents[s_n]->Set_PStudent(ps);
}

int Department::GetStudentCount()
{
	return this->S_count;
}

bool Department::Register_Course_for_Students(int s, const char* name, const char* code) {
	return this->ListOfStudents[s]->Register_Course(name, code);
}

bool Department::UnRegister_Course_for_Students(int s, const char* code) {
	return this->ListOfStudents[s]->Unregister_course(code);
}

int Department::Get_Registration_courses_count(int s) {
	return this->ListOfStudents[s]->Get_Regis_courses_count();
}

char* Department::Get_Assign_courses_SC(int s, int c) {
	return this->ListOfStudents[s]->Get_Assign_courses_SC(c);
}

char* Department::Get_Assign_courses_SN(int s, int c) {
	return this->ListOfStudents[s]->Get_Assign_courses_SN(c);
}

char* Department::GetHODName()
{
	return this->hod->GetT_Name();
}

char* Department::GetHODCode()
{
	return this->hod->GetT_Code();
}

char* Department::GetHODPassword() {
	return this->hod->GetT_Password();
}

void Department::Set_HOD_P(const char* p) {
	this->hod->Set_TP(p);
}

bool Department::Change_HOD_P() {
	return this->hod->ChangeT_Password();
}

void Department::Grow(Student**& arr) {
	
	Student** temp = new Student * [2 * this->capacity_S];
	for (int i = 0; i < this->capacity_S; i++)
		temp[i] = arr[i];
	delete[]arr;
	arr = temp;
	this->capacity_S = 2 * this->capacity_S;
}

void Department::Grow(Course**& arr) {
	Course** temp = new Course * [2 * this->capacity_C];
	for (int i = 0; i < this->capacity_C; i++)
		temp[i] = arr[i];
	delete[]arr;
	arr = temp;
	this->capacity_C = 2 * this->capacity_C;
}

void Department::Grow(Teacher**& arr) {
	Teacher** temp = new Teacher * [2 * this->capacity_T];
	for (int i = 0; i < this->capacity_T; i++)
		temp[i] = arr[i];
	delete[]arr;
	arr = temp;
	this->capacity_T = 2 * this->capacity_T;
}

bool Department::AddCourse(const char* name, const char* code)
{

	int count;
	for (int i = 0; i < this->C_count; ++i) {

		count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOFCourses[i]->GetCourseCode()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOFCourses[i]->GetCourseCode())) {
			//cout << endl << "  -The Course is Already Assigned-" << endl << endl;
			return false;
		}
	}

	if (this->C_count == this->capacity_C - 1)
	{
		Grow(this->ListOFCourses);
	}

	Course* newCourse = new Course(name, code);
	this->ListOFCourses[C_count++] = newCourse;
	
	
	return true;

}

bool Department::AddTeacher(const char* name, const char* code)
{
	int count;
	for (int i = 0; i < this->T_count; ++i) {

		count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfTeachers[i]->GetT_Code()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfTeachers[i]->GetT_Code())) {
			
			return false;
		}
	}

	if (this->T_count == this->capacity_T - 1)
	{
		Grow(this->ListOfTeachers);
	}

	this->ListOfTeachers[T_count] = new Teacher(code, name);

	if (T_count == 0)
	{
		this->hod = this->ListOfTeachers[0];
	}

	this->T_count++;

	return true;
}

bool Department::RemoveTeacher(const char* code) {
	int count;

	for (int i = 0; i < this->T_count; ++i) {

		 count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfTeachers[i]->GetT_Code()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfTeachers[i]->GetT_Code())) {
			delete this->ListOfTeachers[i];

			for (int j = i; j < this->T_count - 1; ++j) {
				this->ListOfTeachers[j] = this->ListOfTeachers[j + 1];
			}
			this->ListOfTeachers[--this->T_count] = 0;
			return true;
		}
	}
	return false;


}

bool Department::AddStudent(const char* name, const char* code)
{

	int count;
	for (int i = 0; i < this->S_count; ++i) {

		count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfStudents[i]->GetS_Code()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfStudents[i]->GetS_Code())) {
			//cout << endl << "  -The Course is Already Assigned-" << endl << endl;
			return false;
		}
	}

	if (this->S_count == this->capacity_S - 1)
	{
		Grow(this->ListOfStudents);
	}

	this->ListOfStudents[S_count++] = new Student(code, name);
	return true;
}

bool Department::RemoveStudent(const char* code)
{
	int count;

	for (int i = 0; i < this->S_count; ++i) {
		
		 count = 0;

		for (int k = 0; k < strlen(code); k++)
		{
			if (code[k] == this->ListOfStudents[i]->GetS_Code()[k])
			{
				count++;
			}
		}

		if (count == strlen(this->ListOfStudents[i]->GetS_Code())) {
			delete this->ListOfStudents[i];

			for (int j = i; j < this->S_count - 1; ++j) {
				this->ListOfStudents[j] = this->ListOfStudents[j + 1];
			}
			this->ListOfStudents[--this->S_count] = 0;
			return true;
		}
	}
	return false;

}

bool Department::AddITManager(const char* name, const char* code)
{
	t = new ITManager(code, name);
	return true;
}

bool Department::AddHOD(const char* name, const char* code)
{
	hod = new Teacher(name, code);
	return true;
}

char* Department::GetDepartName()
{
	return this->name;
}

void Department::Set_Y(int s, int r, int y) {
	this->ListOfStudents[s]->Set_Y(r, y);
}

void Department::Set_M(int s, int r, int m) {
	this->ListOfStudents[s]->Set_M(r, m);
}

void Department::Set_D(int s, int r, int d) {
	this->ListOfStudents[s]->Set_D(r, d);
}

int Department::Get_Y(int s, int r) {
	return this->ListOfStudents[s]->Get_Y(r);
}

int Department::Get_M(int s, int r) {
	return this->ListOfStudents[s]->Get_M(r);
}

int Department::Get_D(int s, int r) {
	return this->ListOfStudents[s]->Get_D(r);
}

bool Department::Add_Assignment_weightage(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_Assignment_weightage(r, number);
}

bool Department::Add_Quiz_weightage(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_Quiz_weightage(r, number);
}

bool Department::Add_Mid_weightage(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_Mid_weightage(r, number);
}

bool Department::Add_Final_weightage(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_Final_weightage(r, number);
}

bool Department::Add_T_Marks_Assignments(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_T_Marks_Assignments(r, number);
}

bool Department::Add_T_Marks_Quizes(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_T_Marks_Quizes(r, number);
}

bool Department::Add_T_Marks_Mid(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_T_Marks_Mid(r, number);
}

bool Department::Add_T_Marks_Final(int s, int r, int number) {
	return this->ListOfStudents[s]->Add_T_Marks_Final(r, number);
}

int* Department::Get_Assignment_weightage(int s, int r) {
	return this->ListOfStudents[s]->Get_Assignment_weightage(r);
}

int* Department::Get_Quiz_weightage(int s, int r) {
	return this->ListOfStudents[s]->Get_Quiz_weightage(r);
}

int Department::Get_Mid_weightage(int s, int r) {
	return this->ListOfStudents[s]->Get_Mid_weightage(r);
}

int Department::Get_Final_weightage(int s, int r) {
	return this->ListOfStudents[s]->Get_Final_weightage(r);
}

int* Department::Get_T_Marks_Assignment(int s, int r) {
	return this->ListOfStudents[s]->Get_T_Marks_Assignment(r);
}

int* Department::Get_T_Marks_Quizes(int s, int r) {
	return this->ListOfStudents[s]->Get_T_Marks_Quizes(r);
}

int Department::Get_T_Marks_Mid(int s, int r) {
	return this->ListOfStudents[s]->Get_T_Marks_Mid(r);
}

int Department::Get_T_Marks_Final(int s, int r) {
	return this->ListOfStudents[s]->Get_T_Marks_Final(r);
}

int Department::Get_Weightage_Assign_count(int s, int r) {
	return this->ListOfStudents[s]->Get_Weightage_Assign_count(r);
}

int Department::Get_Weightage_Quiz_count(int s, int r){
	return this->ListOfStudents[s]->Get_Weightage_Quiz_count(r);
}

int Department::Get_T_Marks_Assign_count(int s, int r) {
	return this->ListOfStudents[s]->Get_T_Marks_Assign_count(r);
}

int Department::Get_T_Marks_Quiz_count(int s, int r) {
	return this->ListOfStudents[s]->Get_T_Marks_Quiz_count(r);
}

bool Department::Assign_Grade(int s, int r, const char* g) {
	return this->ListOfStudents[s]->Assign_Grade(r, g);
}

char* Department::Get_Grade(int s, int r) {
	return this->ListOfStudents[s]->Get_Grade(r);
}

template<class Type>
bool Department::Grw(Type**& arr) {
	Type** temp = new Type * [2 * this->S_count];
	for (int i = 0; i < this->S_count; i++)
		temp[i] = arr[i];
	delete[]arr;
	arr = temp;
	this->S_count = 2 * this->S_count;
}

void Department::print()
{
	cout << "-----------------Department Information-----------------" << endl;
	cout << "Department Name : " << this->name << endl;
	for (int i = 0; i < C_count; i++)
	{
		this->ListOFCourses[i]->print();
		cout << endl;
	}
}

Department::~Department()
{
	delete[]this->name;

	delete[]this->t;

	for (int i = 0; i < C_count; i++)
	{
		delete this->ListOFCourses[i];
	}
	delete[]this->ListOFCourses;

	for (int i = 0; i < T_count; i++)
	{
		delete this->ListOfTeachers[i];
	}
	delete[]this->ListOfTeachers;

	for (int i = 0; i < S_count; i++)
	{
		delete this->ListOfStudents[i];
	}
	delete[]this->ListOfStudents;
}