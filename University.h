#pragma once
#include<iostream>
#include"Department.h"

using namespace std;

class University {

	Department** ListOfDepartments;
	char* name;
	int D_count;
	
public:

	University();

	University(const char* name);

	void print();

	bool AddDepart(const char* name);

	bool AddTeacher(const char* name, const char* code, int d_c);

	bool RemoveTeacher(const char* code, int d_c);

	bool AddCourse(const char* name, const char* code, int d_c);

	bool AddITManager(const char* name, const char* code, int d_c);

	bool AddHOD(const char* name, const char* code, int d_c);

	bool AddStudent(const char* name, const char* code, int d_c);

	bool RemoveStudent(const char* code, int d_c);

	int GetDepartmentCount();

	bool checkDC();

	char* GetDepartmentName(int d_n);

	char* GetCourseName(int d_c, int course_n);

	char* GetCourseCode(int d_c, int course_c);

	//void Set_lecture_Attendence_count_in_course(int d, int s, int c, int count);

	int Get_lectures_count(int d, int s, int c);
	
	bool Assign_Students_for_courses(int d, int c, const char* name, const char* code);

	int Get_Student_count_in_courses(int d, int c);

	char* Get_Assign_Student_CC(int u, int d, int C);

	char* Get_Assign_Student_CN(int u, int d, int C);

	int find_Student_Index(int d, const char* code);

	int find_Course_Index(int d, const char* code);

	int* find_Student_Courses_Index(int d, const char* code);

	int find_Teacher_Index(int d, const char* code);

	int find_Teacher_Courses_Index(int d, const char* code);

	int find_1S_Course(int d, const char* code);

	int GetCourseCount(int d_c);

	int GetTeacherCount(int d_c);

	char* GetTeacherName(int d_c,int teacher_n);

	char* GetTeacherCode(int d_c,int teacher_c);

	bool ChangeT_Password(int d_c,int t_c);

	void Set_TP(const char* ps,int d_c, int t_c);

	bool ChangeT_UN(int d_c, int t_c);

	void Set_TUN(const char* ps,int d_c, int t_c);

	char* GetT_Password(int d_c,int t_c);

	int GetStudentCount(int d_c);

	char* GetStudentName(int d_C,int s_n);

	char* GetStudentCode(int d_c,int s_c);

	char* GetSPass(int d_c, int s_c);

	bool ChangePassword(int d_c, int s_c);

	void Set_Ps(const char* ps, int d_c, int s_c);

	bool Register_Course_for_Students(int d, int s, const char* name, const char* code);

	bool UnRegister_Course_for_Students(int d, int s, const char* code);

	int Get_Registration_courses_count(int d, int s);

	char* Get_Assign_courses_SC(int d, int s, int c);

	char* Get_Assign_courses_SN(int d, int s, int c);

	bool Add_Attendence(int d, int s, int c, bool a, int y, int m, int de);

	bool* Get_Attendence(int d, int s, int c);

	int Get_Attendence_count(int d, int s, int r);

	void View_Attendence(int d, int s, int r);

	//int* Total_Lecture(int d, int s, int r);

	char* GetITName(int d_c);

	char* GetITCode(int d_c);

	bool ChangeIT_Password(int d_c);

	void Set_PIT(const char* ps,int d_c);

	bool ChangeIT_UN(int d_c);

	void Set_ITUN(const char* ps,int d_c);

	char* GetIT_Password(int d_c);

	char* GetUName();

	char* GetHODName(int d_c);

	char* GetHODCode(int d_c);

	char* GetHODPassword(int d_c);

	void Set_HOD_P(int d_c, const char* p);

	bool Change_HOD_P(int d_c);

	int Get_Assign_Courses_Count(int d, int t_);

	char* Get_Assign_courses_TC(int d, int t, int c);

	char* Get_Assign_Courses_TN(int d, int t, int c);

	bool Assign_Courses_to_Teacher(int d, int t, const char* name, const char* code);

	int* Get_TotalQuizes(int d, int s, int r);

	int* Get_TotalAssignments(int d, int s, int r);

	int Get_Assign_capacity(int d, int s, int r);

	int Get_Quiz_capacity(int d, int s, int r);

	void Set_Assign_capacity(int d, int s, int r, int se);

	void Set_Quiz_capacity(int d, int s, int r, int se);

	bool Add_Assignments(int d, int s, int r, int number);

	bool Add_Quizes(int d, int s, int r, int number);

	int Get_AssignCount(int d, int s, int r);

	int Get_QuizCount(int d, int s, int r);

	int Get_Mid(int d, int s, int r);

	void Set_Mid(int d, int s, int r, int mid);

	int Get_Final(int d, int s, int r);

	void Set_Final(int d, int s, int r, int final);

	char* Get_Date(int d, int s, int r, int lecture);

	void Set_Y(int d, int s, int r, int y);

	void Set_M(int d, int s, int r, int m);

	void Set_D(int d, int s, int r, int de);

	int Get_Y(int d, int s, int r);

	int Get_M(int d, int s, int r);

	int Get_D(int d, int s, int r);

	bool Add_Assignment_weightage(int d, int s, int r, int number);

	bool Add_Quiz_weightage(int d, int s, int r, int number);

	bool Add_Mid_weightage(int d, int s, int r, int number);

	bool Add_Final_weightage(int d, int s, int r, int number);

	bool Add_T_Marks_Assignments(int d, int s, int r, int number);

	bool Add_T_Marks_Quizes(int d, int s, int r, int number);

	bool Add_T_Marks_Mid(int d, int s, int r, int number);

	bool Add_T_Marks_Final(int d, int s, int r, int number);

	int* Get_Assignment_weightage(int d, int s, int r);

	int* Get_Quiz_weightage(int d, int s, int r);

	int Get_Mid_weightage(int d, int s, int r);

	int Get_Final_weightage(int d, int s, int r);

	int* Get_T_Marks_Assignment(int d, int s, int r);

	int* Get_T_Marks_Quizes(int d, int s, int r);

	int Get_T_Marks_Mid(int d, int s, int r);

	int Get_T_Marks_Final(int d, int s, int r);

	int Get_Weightage_Assign_count(int d, int s, int r);

	int Get_Weightage_Quiz_count(int d, int s, int r);

	int Get_T_Marks_Assign_count(int d, int s, int r);

	int Get_T_Marks_Quiz_count(int d, int s, int r);

	bool Assign_Grade(int d, int s, int r, const char* g);

	char* Get_Grade(int d, int s, int r);

	~University();

};

University::University()
{
	this->name = nullptr;
	this->D_count = 0;
	this->ListOfDepartments = new Department * [10];
}

University::University(const char* name)
{
	this->D_count = 0;
	this->ListOfDepartments = new Department * [10];
	int len = strlen(name);
	this->name = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		this->name[i] = name[i];
	}
	this->name[len] = '\0';
}

void University::print()
{
	cout << "-----------------University Information-----------------" << endl;
	cout << "Name : " << this->name << endl;
}

bool University::AddDepart(const char* name)
{
	if (D_count == 10)
	{
		return false;
	}

	Department* newDepartment = new Department(name);
	this->ListOfDepartments[D_count++] = newDepartment;
	return true;
}

bool University::AddCourse(const char* name, const char* code, int d_c)
{
	return this->ListOfDepartments[d_c]->AddCourse(name, code);
}

bool University::AddTeacher(const char* name, const char* code,int d_c)
{
	return this->ListOfDepartments[d_c]->AddTeacher(name, code);
}

bool University::RemoveTeacher(const char* code, int d_c) {
	return this->ListOfDepartments[d_c]->RemoveTeacher(code);
}

bool University::AddITManager(const char* name, const char* code,int d_c)
{
	return this->ListOfDepartments[d_c]->AddITManager(name, code);
}

bool University::AddHOD(const char* name, const char* code, int d_c)
{
	return this->ListOfDepartments[d_c]->AddHOD(name, code);
}

bool University::AddStudent(const char* name, const char* code,int d_c)
{
	return this->ListOfDepartments[d_c]->AddStudent(name, code);
}

bool University::RemoveStudent(const char* code, int d_c)
{
	return this->ListOfDepartments[d_c]->RemoveStudent(code);
}

int University::GetDepartmentCount()
{
	return this->D_count;
}

bool University::checkDC()
{
	this->D_count = this->D_count - 1;
	return true;
}

char* University::GetDepartmentName(int d_n)
{
	return this->ListOfDepartments[d_n]->GetDepartName();
}

char* University::GetCourseName(int d_c, int course_n)
{
	return this->ListOfDepartments[d_c]->GetCourseName(course_n);
}

char* University::GetCourseCode(int d_c, int course_c)
{
	return this->ListOfDepartments[d_c]->GetCourseCode(course_c);
}

int University::GetCourseCount(int d_c)
{
	return this->ListOfDepartments[d_c]->GetCourseCount();
}

//void University::Set_lecture_Attendence_count_in_course(int d,int s, int c, int count) {
//	this->ListOfDepartments[d]->Set_lecture_Attendence_count_in_course(s, c, count);
//}

int University::Get_lectures_count(int d, int s, int c) {
	return this->ListOfDepartments[d]->Get_lectures_count(s, c);
}

bool University::Assign_Students_for_courses(int d, int c, const char* name, const char* code) {
	return this->ListOfDepartments[d]->Assign_Students_for_courses(c, name, code);
}

int University::Get_Student_count_in_courses(int d, int c) {
	return this->ListOfDepartments[d]->Get_Student_count_in_courses(c);
}

char* University::Get_Assign_Student_CC(int u, int d, int C) {
	return this->ListOfDepartments[u]->Get_Assign_Student_CC(d, C);
}

char* University::Get_Assign_Student_CN(int u, int d, int C) {
	return this->ListOfDepartments[u]->Get_Assign_Student_CN(d, C);
}

bool University::Add_Attendence(int d, int s, int c, bool a, int y, int m, int de) {
	return this->ListOfDepartments[d]->Add_Attendence(s, c, a, y, m, de);
}

bool* University::Get_Attendence(int d, int s, int c) {
	return this->ListOfDepartments[d]->Get_Attendence(s, c);
}

int University::Get_Attendence_count(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Attendence_count(s, r);
}

void University::View_Attendence(int d, int s, int r) {
	return this->ListOfDepartments[d]->View_Attendence(s, r);
}

char* University::Get_Date(int d, int s, int r, int lecture) {
	return this->ListOfDepartments[d]->Get_Date(s, r, lecture);
}

//int* University::Total_Lecture(int d, int s, int r) {
//	return this->ListOfDepartments[d]->Total_Lecture(s, r);
//}

int* University::Get_TotalQuizes(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_TotalQuizes(s, r);
}

int* University::Get_TotalAssignments(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_TotalAssignments(s, r);
}

int University::Get_Assign_capacity(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Assign_capacity(s, r);
}

int University::Get_Quiz_capacity(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Quiz_capacity(s, r);
}

void University::Set_Assign_capacity(int d, int s, int r, int se) {
	this->ListOfDepartments[d]->Set_Assign_capacity(s, r, se);
}

void University::Set_Quiz_capacity(int d, int s, int r, int se) {
	this->ListOfDepartments[d]->Set_Quiz_capacity(s, r, se);
}

bool University::Add_Assignments(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_Assignments(s, r, number);
}

bool University::Add_Quizes(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_Quizes(s, r, number);
}

int University::Get_AssignCount(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_AssignCount(s, r);
}

int University::Get_QuizCount(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_QuizCount(s, r);
}

int University::Get_Mid(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Mid(s, r);
}

void University::Set_Mid(int d, int s, int r, int mid) {
	this->ListOfDepartments[d]->Set_Mid(s, r, mid);
}

int University::Get_Final(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Final(s, r);
}

void University::Set_Final(int d, int s, int r, int final) {
	return this->ListOfDepartments[d]->Set_Final(s, r, final);
}

int University::find_Student_Index(int d, const char* code) {
	return this->ListOfDepartments[d]->find_Student_Index(code);
}

int University::find_Course_Index(int d, const char* code) {
	return this->ListOfDepartments[d]->find_Course_Index(code);
}

int* University::find_Student_Courses_Index(int d, const char* code) {
	return this->ListOfDepartments[d]->find_Student_Courses_Index(code);
}

int University::find_1S_Course(int d, const char* code) {
	return this->ListOfDepartments[d]->find_1S_Course(code);
}

int University::find_Teacher_Index(int d, const char* code) {
	return this->ListOfDepartments[d]->find_Teacher_Index(code);
}

int University::find_Teacher_Courses_Index(int d, const char* code) {
	return this->ListOfDepartments[d]->find_Teacher_Courses_Index(code);
}

char* University::GetTeacherName(int d_c, int teacher_n)
{
	return this->ListOfDepartments[d_c]->GetTeacherName(teacher_n);
}

char* University::GetTeacherCode(int d_c, int teacher_c)
{
	return this->ListOfDepartments[d_c]->GetTeacherCode(teacher_c);
}

int University::GetTeacherCount(int d_c)
{
	return this->ListOfDepartments[d_c]->GetTeacherCount();
}

bool University::ChangeT_Password(int d_c, int t_c)
{
	return this->ListOfDepartments[d_c]->ChangeT_Password(t_c);
}

void University::Set_TP(const char* ps, int d_c, int t_c) 
{
	this->ListOfDepartments[d_c]->Set_TP(ps, t_c);
}

bool University::ChangeT_UN(int d_c, int t_c)
{
	return this->ListOfDepartments[d_c]->ChangeT_UN(t_c);
}

void University::Set_TUN(const char* ps, int d_c, int t_c)
{
	this->ListOfDepartments[d_c]->Set_TUN(ps, t_c);
}

char* University::GetT_Password(int d_c, int t_c)
{
	return this->ListOfDepartments[d_c]->GetT_Password(t_c);
}

char* University::GetStudentName(int d_c, int s_n)
{
	return this->ListOfDepartments[d_c]->GetStudentName(s_n);
}

char* University::GetStudentCode(int d_c, int s_c)
{
	return this->ListOfDepartments[d_c]->GetStudentCode(s_c);
}

int University::GetStudentCount(int d_c)
{
	return this->ListOfDepartments[d_c]->GetStudentCount();
}

char* University::GetSPass(int d_c, int s_c)
{
	return this->ListOfDepartments[d_c]->GetStudentPassword(s_c);
}

bool University::ChangePassword(int d_c, int s_c)
{
	return this->ListOfDepartments[d_c]->ChangePassword(s_c);
}

void University::Set_Ps(const char* ps, int d_c, int s_c)
{
	this->ListOfDepartments[d_c]->Set_Ps(ps, s_c);
}

bool University::Register_Course_for_Students(int d, int s, const char* name, const char* code) {
	return this->ListOfDepartments[d]->Register_Course_for_Students(s, name, code);
}

bool University::UnRegister_Course_for_Students(int d, int s, const char* code) {
	return this->ListOfDepartments[d]->UnRegister_Course_for_Students(s, code);
}

int University::Get_Registration_courses_count(int d, int s) {
	return this->ListOfDepartments[d]->Get_Registration_courses_count(s);
}

char* University::Get_Assign_courses_SC(int d, int s, int c) {
	return this->ListOfDepartments[d]->Get_Assign_courses_SC(s, c);
}

char* University::Get_Assign_courses_SN(int d, int s, int c) {
	return this->ListOfDepartments[d]->Get_Assign_courses_SN(s, c);
}

char* University::GetITName(int d_c) 
{
	return this->ListOfDepartments[d_c]->GetITName();
}

char* University::GetITCode(int d_c)
{
	return this->ListOfDepartments[d_c]->GetITCode();
}

bool University::ChangeIT_Password(int d_c)
{
	return this->ListOfDepartments[d_c]->ChangeIT_Password();
}

void University::Set_PIT(const char* ps, int d_c)
{
	this->ListOfDepartments[d_c]->Set_PIT(ps);
}

bool University::ChangeIT_UN(int d_c)
{
	return this->ListOfDepartments[d_c]->ChangeIT_UN();
}

void University::Set_ITUN(const char* ps, int d_c)
{
	this->ListOfDepartments[d_c]->Set_ITUN(ps);
}

char* University::GetIT_Password(int d_c)
{
	return this->ListOfDepartments[d_c]->GetIT_Password();
}

char* University::GetUName()
{
	return this->name;
}

char* University::GetHODName(int d_c)
{
	return this->ListOfDepartments[d_c]->GetHODName();
}

char* University::GetHODCode(int d_c)
{
	return this->ListOfDepartments[d_c]->GetHODCode();
}

char* University::GetHODPassword(int d_c) {
	return this->ListOfDepartments[d_c]->GetHODPassword();
}

void University::Set_HOD_P(int d_c,const char* p) {
	this->ListOfDepartments[d_c]->Set_HOD_P(p);
}

bool University::Change_HOD_P(int d_c) {
	return this->ListOfDepartments[d_c]->Change_HOD_P();
}

char* University::Get_Assign_courses_TC(int d,int t, int Course_c) {
	return this->ListOfDepartments[d]->Get_Assign_courses_TC(t, Course_c);
}

char* University::Get_Assign_Courses_TN(int d,int t, int Course_c) {
	return this->ListOfDepartments[d]->Get_Assign_Courses_TN(t, Course_c);
}

bool University::Assign_Courses_to_Teacher(int d, int t, const char* name, const char* code) {
	return this->ListOfDepartments[d]->Assign_Courses_to_Teacher(t, name, code);
}

int University::Get_Assign_Courses_Count(int d_c, int t_c) {
	return this->ListOfDepartments[d_c]->Get_Assign_Courses_Count(t_c);
}

void University::Set_Y(int d, int s, int r, int y) {
	this->ListOfDepartments[d]->Set_Y(s, r, y);
}

void University::Set_M(int d, int s, int r, int m) {
	this->ListOfDepartments[d]->Set_M(s, r, m);
}

void University::Set_D(int d, int s, int r, int de) {
	this->ListOfDepartments[d]->Set_D(s, r, de);
}

int University::Get_Y(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Y(s, r);
}

int University::Get_M(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_M(s, r);
}

int University::Get_D(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_D(s, r);
}

bool University::Add_Assignment_weightage(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_Assignment_weightage(s, r, number);
}

bool University::Add_Quiz_weightage(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_Quiz_weightage(s, r, number);
}

bool University::Add_Mid_weightage(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_Mid_weightage(s, r, number);
}

bool University::Add_Final_weightage(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_Final_weightage(s, r, number);
}

bool University::Add_T_Marks_Assignments(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_T_Marks_Assignments(s, r, number);
}

bool University::Add_T_Marks_Quizes(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_T_Marks_Quizes(s, r, number);
}

bool University::Add_T_Marks_Mid(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_T_Marks_Mid(s, r, number);
}

bool University::Add_T_Marks_Final(int d, int s, int r, int number) {
	return this->ListOfDepartments[d]->Add_T_Marks_Final(s, r, number);
}

int* University::Get_Assignment_weightage(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Assignment_weightage(s, r);
}

int* University::Get_Quiz_weightage(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Quiz_weightage(s, r);
}

int University::Get_Mid_weightage(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Mid_weightage(s, r);
}

int University::Get_Final_weightage(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Final_weightage(s, r);
}

int* University::Get_T_Marks_Assignment(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_T_Marks_Assignment(s, r);
}

int* University::Get_T_Marks_Quizes(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_T_Marks_Quizes(s, r);
}

int University::Get_T_Marks_Mid(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_T_Marks_Mid(s, r);
}

int University::Get_T_Marks_Final(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_T_Marks_Final(s, r);
}

int University::Get_Weightage_Assign_count(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Weightage_Assign_count(s, r);
}

int University::Get_Weightage_Quiz_count(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Weightage_Quiz_count(s, r);
}

int University::Get_T_Marks_Assign_count(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_T_Marks_Assign_count(s, r);
}

int University::Get_T_Marks_Quiz_count(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_T_Marks_Quiz_count(s, r);
}

bool University::Assign_Grade(int d, int s, int r, const char* g) {
	return this->ListOfDepartments[d]->Assign_Grade(s, r, g);
}

char* University::Get_Grade(int d, int s, int r) {
	return this->ListOfDepartments[d]->Get_Grade(s, r);
}

University::~University()
{
	delete[]this->name;

	for (int i = 0; i < this->D_count; i++)
	{
		delete this->ListOfDepartments[i];
	}
	delete[]this->ListOfDepartments;

}