#pragma once
using namespace std;

class Registration;

class Course {

	char* name;
	char* code;
	/*int capacity;
	char** date;
	bool* Attendence;
	int Attendence_count;
	int* Total_Lectures;
	int Lectures_Count;
	int* Total_Assigments;
	int Assignment_Count;
	int* Total_Quizes;
	int Quizes_Count;
	int Mid;
	int Final;*/
	Registration** r;
	//int assign_count;
	int r_count;

	/*const static char STR_MONTHS[12][4];
	const static char STR_DAYS[12][10];*/
	
public:

	Course();

	Course(const char* name, const char* code);

	void Set_CourseName(const char* name);

	void Set_CourseCode(const char* code);

	void print();

	char* GetCourseName();

	char* GetCourseCode();

	bool AssignStudents(const char* name, const char* code);

	char* Get_Assign_Student_CC(int C);

	char* Get_Assign_Student_CN(int C);

	int Get_Student_count();
	
	//int Get_Mid();

	//void Set_Mid(int mid);

	//int Get_Final();

	//void Set_Final(int final);

	//bool Add_Attendence(bool attendence, int lecture);

	//bool Add_Assignments(int lecture, int number);

	//bool Add_Quizes(int lecture, int number);

	////void Add_Date(const char* attendance, int lecture);

	//void Set_Date(int y, int m, int d, int index);

	//char* Get_Date(int lecture);

	//void Set_lecture_Attendence_count(int count);

	//int Get_lectures_count();

	//char* SD(int y, int m, int d);

	//int getDayOfWeek(int y, int m, int d);

	//bool isLeapYear(int y);

	virtual ~Course();

};