#pragma once
#include"Person.h"

class Registration;

class Student :public Person
{
private:
    char* password;
	Registration** ListOfRegistration;
	int regis_C;

	/*friend ostream& operator<<(ostream& _cout, const Student& obj);
	friend istream& operator>>(istream& _cin, Student& obj);*/


public:


	Student();

	Student(const char* a, const char* name);

	bool Change_Password();

	void Set_PStudent(const char* ps);

	bool ChangeIT_UN();

	void Set_ITUN(const char* ps);

	void print();

	char* GetS_Password();

	char* GetS_Code();

	char* GetS_Name();

	bool Register_Course(const char* name, const char* code);

	bool Unregister_course(const char* code);

	//bool WithDraw_course(const char* code);

	bool Add_Attendence(int c, bool attendence, int y, int m, int d);

	int Get_Regis_courses_count();

	void Set_Student_N(const char* name);

	void Set_Student_C(const char* code);

	char* Get_Assign_courses_SC(int c);

	char* Get_Assign_courses_SN(int c);

	void Set_Date(int r, int y, int m, int d, int lecture);

	//void Set_lecture_Attendence_count(int r, int count);

	bool* Get_Attendence(int r);

	char* Get_Date(int r, int lecture);

	int Get_Lecture_count(int r);

	int Get_Attendence_count(int r);

	void View_Attendence(int r);

	//int* Total_Lecture(int r);

	int* Get_TotalQuizes(int r);

	int* Get_TotalAssignments(int r);

	int Get_Assign_capacity(int r);

	int Get_Quiz_capacity(int r);

	void Set_Assign_capacity(int r,int s);

	void Set_Quiz_capacity(int r, int s);

	bool Add_Assignments(int r, int number);

	bool Add_Quizes(int r, int number);

	int Get_AssignCount(int r);

	int Get_QuizCount(int r);

	int Get_Mid(int r);

	void Set_Mid(int r, int mid);

	int Get_Final(int r);

	void Set_Final(int r, int final);

	void Set_Y(int r, int y);

	void Set_M(int r, int m);

	void Set_D(int r, int d);

	int Get_Y(int r);

	int Get_M(int r);

	int Get_D(int r);

	bool Add_Assignment_weightage(int r, int number);

	bool Add_Quiz_weightage(int r, int number);

	bool Add_Mid_weightage(int r, int number);

	bool Add_Final_weightage(int r, int number);

	bool Add_T_Marks_Assignments(int r, int number);

	bool Add_T_Marks_Quizes(int r, int number);

	bool Add_T_Marks_Mid(int r, int number);

	bool Add_T_Marks_Final(int r, int number);

	int* Get_Assignment_weightage(int r);

	int* Get_Quiz_weightage(int r);

	int Get_Mid_weightage(int r);

	int Get_Final_weightage(int r);

	int* Get_T_Marks_Assignment(int r);

	int* Get_T_Marks_Quizes(int r);

	int Get_T_Marks_Mid(int r);

	int Get_T_Marks_Final(int r);

	int Get_Weightage_Assign_count(int r);

	int Get_Weightage_Quiz_count(int r);

	int Get_T_Marks_Assign_count(int r);

	int Get_T_Marks_Quiz_count(int r);

	bool Assign_Grade(int r, const char* g);

	char* Get_Grade(int r);

	virtual ~Student();

};