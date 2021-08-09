#pragma once
#include<iostream>


using namespace std;

class Course;

class Student;

class Registration
{

	Course* c;
	Student* s;

	int y;
	int m;
	int d;
	char* Grade;
	int capacity;
	char** date;
	bool* Attendence;
	int Attendence_count;
	/*int* Total_Lectures;
	int Lectures_Count;*/
	int* Total_Assigments;
	int Assignment_Count;
	int* Total_Quizes;
	int Quizes_Count;
	int Mid;
	int Final;
	int Date_count;
	int Assign_capacity;
	int Quiz_capacity;
	int* weightage_assignments;
	int* weightage_quizes;
	int weightage_mid;
	int weightage_final;
	int* T_Marks_assignments;
	int* T_Marks_quizes;
	int T_Marks_mid;
	int T_Marks_final;
	int w_assign_count;
	int w_quiz_count;
	int t_marks_assign_count;
	int t_marks_quiz_count;

	const static char STR_MONTHS[12][4];
	const static char STR_DAYS[12][10];
	const static int DAYS_IN_MONTHS[12];

public:

	Registration();

	Registration(Course* c);

	Registration(Student* s);

	/*Registration(const Registration& obj) {
		this->c = new Course;
		this->s = new Student;
		this->c = obj.c;
		this->s = obj.s;
	}*/

	bool Assign_Student(const char* name, const char* code);

	bool Assign_Course(const char* name, const char* code);

	Course* Get_Course();

	void Set_Course(Course* c);

	char* Get_Assigned_Course_N();
		
	char* Get_Assigned_course_C();

	char* Get_Assigned_Student_N();

	char* Get_Assigned_Student_C();

	int Get_Mid();

	void Set_Mid(int mid);

	int Get_Final();

	void Set_Final(int final);

	int Get_lectures_count();

	bool Add_Attendence(bool attendence, int y, int m, int d);

	int Get_Attendence_count();

	void View_Attendence();

	bool Add_Assignments( int number);

	bool Add_Quizes(int number);

	//void Set_lecture_Attendence_count(int count);

	void Set_Date(int y, int m, int d, int index);

	char* SD(int y, int m, int d);

	char* Get_Date(int lecture);

	int getDayOfWeek(int y, int m, int d);

	bool isLeapYear(int y);

	bool* Get_Attendence();

	//int* Total_Lecture();

	bool Assign_Grade(const char* g);

	char* Get_Grade();

	int* Get_TotalQuizes();

	int* Get_TotalAssignments();

	int Get_Assign_capacity();

	int Get_Quiz_capacity();

	void Set_Assign_capacity(int s);

	void Set_Quiz_capacity(int s);

	int Get_AssignCount();

	int Get_QuizCount();

	void Set_Y(int y);

	void Set_M(int m);

	void Set_D(int d);

	int Get_Y();

	int Get_M();

	int Get_D();

	bool Add_Assignment_weightage(int number);

	bool Add_Quiz_weightage(int number);

	bool Add_Mid_weightage(int number);

	bool Add_Final_weightage(int number);

	bool Add_T_Marks_Assignments(int number);

	bool Add_T_Marks_Quizes(int number);

	bool Add_T_Marks_Mid(int number);

	bool Add_T_Marks_Final(int number);

	int* Get_Assignment_weightage();

	int* Get_Quiz_weightage();

	int Get_Mid_weightage();

	int Get_Final_weightage();

	int* Get_T_Marks_Assignment();

	int* Get_T_Marks_Quizes();

	int Get_T_Marks_Mid();

	int Get_T_Marks_Final();

	int Get_Weightage_Assign_count();

	int Get_Weightage_Quiz_count();

	int Get_T_Marks_Assign_count();

	int Get_T_Marks_Quiz_count();

	~Registration();

};
