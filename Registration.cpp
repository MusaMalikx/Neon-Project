#include"Registration.h"
#include<iostream>
#include"Course.h"
#include"Student.h"

using namespace std;



Registration::Registration() {
	this->c = new Course;
	this->s = new Student;
	this->Final = 0;
	this->Mid = 0;
	//this->Total_Lectures = nullptr;
	this->Total_Assigments = new int[10];
	this->Total_Quizes = new int[10];
	this->date = new char* [10];
	this->Attendence = new bool[10];
	this->weightage_assignments = new int[10];
	this->weightage_quizes = new int[10];
	this->weightage_mid = 0;
	this->weightage_final = 0;
	this->T_Marks_assignments = new int[10];
	this->T_Marks_quizes = new int[10];
	this->T_Marks_mid = 0;
	this->T_Marks_final = 0;
	this->capacity = 10;
	this->Date_count = 0;
	this->Attendence_count = 0;
	this->Quizes_Count = 0;
	//this->Lectures_Count = 0;
	this->Grade = 0;
	this->Assignment_Count = 0;
	this->Assign_capacity = 0;
	this->Quiz_capacity = 0;
	//this->lecture = 0;
	this->y = 0;
	this->m = 0;
	this->d = 0;
	this->w_assign_count = 0;
	this->w_quiz_count = 0;
	this->t_marks_assign_count = 0;
	this->t_marks_quiz_count = 0;
}

Registration::Registration(Course* c) {
	this->c = new Course;
	this->c->Set_CourseName(c->GetCourseName());
	this->c->Set_CourseCode(c->GetCourseCode());
	//this->c = c;
	this->s = nullptr;
	this->Final = 0;
	this->Mid = 0;
	//this->Total_Lectures = nullptr;
	this->Total_Assigments = new int[10];
	this->Total_Quizes = new int[10];
	this->date = new char* [10];
	this->Attendence = new bool[10];
	this->weightage_assignments = new int[10];
	this->weightage_quizes = new int[10];
	this->weightage_mid = 0;
	this->weightage_final = 0;
	this->T_Marks_assignments = new int[10];
	this->T_Marks_quizes = new int[10];
	this->T_Marks_mid = 0;
	this->T_Marks_final = 0;
	this->capacity = 10;
	this->Assignment_Count = 0;
	this->Quizes_Count = 0;
	this->Attendence_count = 0;
	this->Date_count = 0;
	//this->Lectures_Count = 0;
	this->Grade = 0;
	this->Assign_capacity = 0;
	this->Quiz_capacity = 0;
	//this->lecture = 0;
	this->y = 0;
	this->m = 0;
	this->d = 0;
	this->w_assign_count = 0;
	this->w_quiz_count = 0;
	this->t_marks_assign_count = 0;
	this->t_marks_quiz_count = 0;
}

Registration::Registration(Student* s) {

	this->c = new Course;
	this->s = new Student;
	this->s->Set_Student_N(s->GetS_Name());
	this->s->Set_Student_C(s->GetS_Code());
	this->Final = 0;
	this->Mid = 0;
	//this->Total_Lectures = nullptr;
	this->Total_Assigments = new int[10];
	this->Total_Quizes = new int[10];
	this->date = new char* [10];
	this->Attendence = new bool[10];
	this->weightage_assignments = new int[10];
	this->weightage_quizes = new int[10];
	this->weightage_mid = 0;
	this->weightage_final = 0;
	this->T_Marks_assignments = new int[10];
	this->T_Marks_quizes = new int[10];
	this->T_Marks_mid = 0;
	this->T_Marks_final = 0;
	this->capacity = 10;
	this->Assignment_Count = 0;
	this->Quizes_Count = 0;
	this->Attendence_count = 0;
	//this->Lectures_Count = 0;
	this->Date_count = 0;
	this->Assign_capacity = 0;
	this->Quiz_capacity = 0;
	this->Grade = 0;
	//this->lecture = 0;
	this->y = 0;
	this->m = 0;
	this->d = 0;
	this->w_assign_count = 0;
	this->w_quiz_count = 0;
	this->t_marks_assign_count = 0;
	this->t_marks_quiz_count = 0;
}

/*Registration(const Registration& obj) {
	this->c = new Course;
	this->s = new Student;
	this->c = obj.c;
	this->s = obj.s;
}*/

bool Registration::Assign_Student(const char* name, const char* code) {
	return this->s = new Student(code, name);
}

bool Registration::Assign_Course(const char* name, const char* code) {
	return this->c = new Course(name, code);
}

Course* Registration::Get_Course() {
	return this->c;
}

void Registration::Set_Course(Course* c) {
	this->c = c;
}

char* Registration::Get_Assigned_Course_N() {
	return this->c->GetCourseName();
}

char* Registration::Get_Assigned_course_C() {
	return this->c->GetCourseCode();
}

char* Registration::Get_Assigned_Student_N() {
	return this->s->GetS_Name();
}

char* Registration::Get_Assigned_Student_C() {
	return this->s->GetS_Code();
}

int Registration::Get_Mid() {
	return this->Mid;
}

void Registration::Set_Mid(int mid) {
	this->Mid = mid;
}

int Registration::Get_Final() {
	return this->Final;
}

void Registration::Set_Final(int final) {
	this->Final = final;
}

int Registration::Get_lectures_count() {
	return this->capacity;
}

bool Registration::Add_Attendence(bool attendence, int y, int m, int d) {
	//this->lecture = lecture;
	if (this->Attendence_count < this->capacity) {
		this->Attendence[this->Attendence_count] = attendence;
		
		Set_Date(y, m, d, this->Attendence_count);

		this->Attendence_count++;

		return true;
	}
	return false;
}

int Registration::Get_Attendence_count() {
	return this->Attendence_count;
}

void Registration::View_Attendence() {
	for (int i = 0; i < this->Attendence_count; i++) {
		if (Get_Attendence()[i] == 1) {
			cout << "   " << Get_Date(i) << "   " << "Present" << endl;
		}
		else if (Get_Attendence()[i] == 0) {
			cout << "   " << Get_Date(i) << "   " << "Absent" << endl;
		}
	}
}

//int* Registration::Total_Lecture() {
//	return this->Total_Lectures;
//}

bool Registration::Add_Assignments( int number) {
	//this->lecture = lecture;
	if (this->Assignment_Count < this->Assign_capacity) {
		this->Total_Assigments[this->Assignment_Count++] = number;
		
		return true;
	}
	return false;
}

bool Registration::Add_Quizes(int number) {
	if (this->Quizes_Count < this->Quiz_capacity) {
		this->Total_Quizes[this->Quizes_Count++] = number;
		
		return true;
	}
	return false;
}

//void Registration::Set_lecture_Attendence_count(int count) {
//
//    this->capacity = count;
//	//this->Total_Lectures = new int[this->capacity];
//	this->Attendence = new bool[this->capacity];
//	this->date = new char* [this->capacity + 1];
//}

int* Registration::Get_TotalQuizes() {
	return this->Total_Quizes;
}

int* Registration::Get_TotalAssignments() {
	return this->Total_Assigments;
}

int Registration::Get_Assign_capacity() {
	return this->Assign_capacity;
}

int Registration::Get_Quiz_capacity() {
	return this->Quiz_capacity;
}

void Registration::Set_Assign_capacity(int a) {
	this->Assign_capacity = a;
	//this->Total_Assigments = new int[this->Assign_capacity];
}

void Registration::Set_Quiz_capacity(int q) {
	this->Quiz_capacity = q;
	//this->Total_Quizes = new int[this->Quiz_capacity];
}

int Registration::Get_AssignCount() {
	return this->Assignment_Count;
}

int Registration::Get_QuizCount() {
	return this->Quizes_Count;
}

void Registration::Set_Date(int y, int m, int d, int index) {
	this->y = y;
	this->m = m;
	this->d = d;
	this->date[this->Date_count++] = SD(this->y, this->m, this->d);
	/*this->Date_count++;*/
}

void Registration::Set_Y(int y) {
	this->y = y;
}

void Registration::Set_M(int m) {
	this->m = m;
}

void Registration::Set_D(int d) {
	this->d = d;
}

int Registration::Get_Y() {
	return this->y;
}

int Registration::Get_M() {
	return this->m;
}

int Registration::Get_D() {
	return this->d;
}

char* Registration::SD(int y, int m, int d)
{

	int yc = y;
	int y1[4];
	for (int i = 0; i < 4; i++)
	{
		y1[i] = yc % 10;
		yc = yc / 10;
	}


	char* date = new char[50];
	/*char* str;
	const int x = getDayOfWeek(y, m - 1, d);
	str = new char[10];*/
	char* strm = new char[10];

	/*for (int i = 0; i < strlen(STR_DAYS[x]); i++)
	{
		str[i] = STR_DAYS[x][i];
	}
	str[strlen(STR_DAYS[x])] = '\0';*/

	//int len = strlen(str);

	for (int i = 0; i < strlen(STR_MONTHS[m-1]); i++)
	{
		strm[i] = STR_MONTHS[m - 1][i];
	}
	strm[strlen(STR_MONTHS[m - 1])] = '\0';

	int lenm = strlen(strm);

	//Default Constructor set Date to Default value : Sunday, 1 Jan 2017
	int i = 0;
	//for (i = 0; i < len; i++)
	//{
	//	date[i] = str[i];

	//}
	//date[i] = ',';
	//i++;
	//date[i] = ' ';
	//i++;
	////int j = 48;
	if (d >= 0 && d <= 9) {
		date[i] = (char)48 + d;
		i++;
	}
	else {
		int d1[2];
		int d2 = d;
		int j;
		for (j = 0; j < 2; j++) {
			d1[j] = d2 % 10;
			d2 = d2 / 10;
		}

		for (j = 2; j > 0; j--) {
			date[i] = (char)48 + d1[j - 1];
			i++;
		}

	}

	date[i] = ' ';
	i++;
	for (int j = 0; j < lenm; j++)
	{
		date[i] = strm[j];
		i++;
	}
	date[i] = ' ';
	i++;

	for (int k = 3; k >= 0; k--) {
		date[i] = (char)(y1[k] + 48);
		i++;
	}

	date[i] = '\0';

	return date;
}

char* Registration::Get_Date(int lecture) {
	return this->date[lecture];
}

int Registration::getDayOfWeek(int y, int m, int d)
{
	int centuryTable[] = { 4, 2, 0, 6, 4, 2, 0, 6 }; // 17xx, 18xx, ...
	int MonthTable[] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
	int MonthLeapYearTable[] = { 6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };

	int century = y / 100;
	int twoDigitYear = y % 100;
	int centuryTableIndex = (century - 17) % 8;
	//Date before 17xx are not valid, but needed to prevent negative index
	if (centuryTableIndex < 0)
	{
		centuryTableIndex += 8;
	}
	int sum = centuryTable[centuryTableIndex] + twoDigitYear + twoDigitYear / 4;
	if (isLeapYear(y))
	{
		sum += MonthLeapYearTable[m - 1];
	}
	else
	{
		sum += MonthTable[m - 1];
	}
	sum += d;
	return sum % 7;
}

bool Registration::isLeapYear(int y)
{
	if ((y % 100 != 0 && y % 4 == 0) || (y % 100 == 0 && y % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

bool* Registration::Get_Attendence() {
	return this->Attendence;
}

bool Registration::Assign_Grade(const char* g) {
	
	int len = strlen(g);

 	this->Grade = new char[len + 1];

	for (int i = 0; i < len; i++) {
		this->Grade[i] = g[i];
	}
	this->Grade[len] = '\0';

	return true;

}

char* Registration::Get_Grade() {
	return this->Grade;
}

bool Registration::Add_Assignment_weightage(int number) {
	if (this->w_assign_count < this->Assign_capacity) {
		this->weightage_assignments[this->w_assign_count++] = number;
		return true;
	}
	return false;
}

bool Registration::Add_Quiz_weightage(int number) {
	if (this->w_quiz_count < this->Quiz_capacity) {
		this->weightage_quizes[this->w_quiz_count++] = number;
		return true;
	}
	return false;
}

bool Registration::Add_Mid_weightage(int number) {

	return this->weightage_mid = number;

}

bool Registration::Add_Final_weightage(int number) {

	return this->weightage_final = number;

}

bool Registration::Add_T_Marks_Assignments(int number) {
	if (this->t_marks_assign_count < this->Assign_capacity) {
		this->T_Marks_assignments[t_marks_assign_count++] = number;
		return true;
	}
	return false;
}

bool Registration::Add_T_Marks_Quizes(int number) {
	if (this->t_marks_quiz_count < this->Quiz_capacity) {
		this->T_Marks_quizes[this->t_marks_quiz_count++] = number;
		return true;
	}
	return false;
}

bool Registration::Add_T_Marks_Mid(int number) {
	return this->T_Marks_mid = number;
}

bool Registration::Add_T_Marks_Final(int number) {
	return this->T_Marks_final = number;
}

int* Registration::Get_Assignment_weightage() {
	return this->weightage_assignments;
}

int* Registration::Get_Quiz_weightage() {
	return this->weightage_quizes;
}

int Registration::Get_Mid_weightage() {
	return this->weightage_mid;
}

int Registration::Get_Final_weightage() {
	return this->weightage_final;
}

int* Registration::Get_T_Marks_Assignment() {
	return this->T_Marks_assignments;
}

int* Registration::Get_T_Marks_Quizes() {
	return this->T_Marks_quizes;
}

int Registration::Get_T_Marks_Mid() {
	return this->T_Marks_mid;
}

int Registration::Get_T_Marks_Final() {
	return this->T_Marks_final;
}

int Registration::Get_Weightage_Assign_count() {
	return this->w_assign_count;
}

int Registration::Get_Weightage_Quiz_count() {
	return this->w_quiz_count;
}

int Registration::Get_T_Marks_Assign_count() {
	return this->t_marks_assign_count;
}

int Registration::Get_T_Marks_Quiz_count() {
	return this->t_marks_quiz_count;
}

Registration::~Registration() {
	delete[]this->c;
	delete[]this->s;
	delete[]this->Attendence;
	delete[]this->date;
	delete[]this->Total_Assigments;
	delete[]this->Grade;
	delete[]this->Total_Quizes;
	delete[]this->weightage_assignments;
	delete[]this->weightage_quizes;
	delete[]this->T_Marks_assignments;
	delete[]this->T_Marks_quizes;
}


const char Registration::STR_MONTHS[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

const int Registration::DAYS_IN_MONTHS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const char Registration::STR_DAYS[12][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
