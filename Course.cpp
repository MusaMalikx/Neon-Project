#include<iostream>
#include"Course.h"
#include"Registration.h"

using namespace std;

Course::Course()
{
	this->code = nullptr;
	this->name = nullptr;
	this->r_count = 0;
	this->r = new Registration* [10];
	/*this->Final = 0;
	this->Mid = 0;
	this->Total_Assigments = nullptr;
	this->Total_Lectures = nullptr;
	this->Total_Quizes = nullptr;
	this->date = nullptr;
	this->Attendence = nullptr;
	this->capacity = 0;*/
}

Course::Course(const char* name, const char* code)
{
	int len1 = strlen(name);
	this->name = new char[len1 + 1];

	for (int i = 0; i < len1; i++)
	{
		this->name[i] = name[i];
	}
	this->name[len1] = '\0';

	int len2 = strlen(code);
	this->code = new char[len2 + 1];

	for (int i = 0; i < len2; i++)
	{
		this->code[i] = code[i];
	}
	this->code[len2] = '\0';

	this->r_count = 0;
	this->r = new Registration * [10];
	/*this->Attendence = nullptr;
	this->Final = 0;
	this->Mid = 0;
	this->Total_Assigments = nullptr;
	this->Total_Lectures = nullptr;
	this->Total_Quizes = nullptr;
	this->date = nullptr;
	this->capacity = 0;*/
	
}

bool Course::AssignStudents(const char* name, const char* code) {
	if (this->r_count == 50) {
		return false;
	}

	this->r[r_count] = new Registration;

	this->r[r_count++]->Assign_Student(code, name);
	return true;

}

int Course::Get_Student_count() {
	return this->r_count;
}

char* Course::Get_Assign_Student_CC(int c) {
	return this->r[c]->Get_Assigned_Student_C();
}

char* Course::Get_Assign_Student_CN(int c) {
	return this->r[c]->Get_Assigned_Student_N();
}

char* Course::GetCourseCode()
{
	return this->code;
}

char* Course::GetCourseName()
{
	return this->name;
}

void Course::Set_CourseName(const char* name) {
	int len1 = strlen(name);
	this->name = new char[len1 + 1];

	for (int i = 0; i < len1; i++)
	{
		this->name[i] = name[i];
	}
	this->name[len1] = '\0';
}

void Course::Set_CourseCode(const char* code) {
	int len2 = strlen(code);
	this->code = new char[len2 + 1];

	for (int i = 0; i < len2; i++)
	{
		this->code[i] = code[i];
	}
	this->code[len2] = '\0';
}

//int Course::Get_Mid() {
//	return this->Mid;
//}
//
//void Course::Set_Mid(int mid) {
//	this->Mid = mid;
//}
//
//int Course::Get_Final() {
//	return this->Final;
//}
//
//void Course::Set_Final(int final) {
//	this->Final = final;
//}
//
//int Course::Get_lectures_count() {
//	return this->capacity;
//}
//
//bool Course::Add_Attendence(bool attendence, int lecture) {
//	if (this->Attendence_count < this->capacity) {
//		this->Attendence[lecture] = attendence;
//		this->Attendence_count++;
//		return true;
//	}
//	return false;
//}
//
//bool Course::Add_Assignments(int lecture, int number) {
//	if (this->Assignment_Count < this->capacity) {
//		this->Total_Assigments[lecture] = number;
//		this->Assignment_Count++;
//		return true;
//	}
//	return false;
//}
//
//bool Course::Add_Quizes(int lecture, int number) {
//	if (this->Quizes_Count < this->capacity) {
//		this->Total_Quizes[lecture] = number;
//		this->Quizes_Count++;
//		return true;
//	}
//	return false;
//}
//
//void Course::Set_lecture_Attendence_count(int count) {
//	this->capacity = count;
//	this->Total_Lectures = new int[this->capacity + 1];
//	this->Attendence = new bool [this->capacity + 1];
//	this->date = new char* [this->capacity + 1];
//}
//
//void Course::Set_Date(int y, int m, int d, int index) {
//	this->date[index] = SD(y, m, d);
//}
//
//char* Course::SD(int y, int m, int d)
//{
//
//	int yc = y;
//	int y1[4];
//	for (int i = 0; i < 4; i++)
//	{
//		y1[i] = yc % 10;
//		yc = yc / 10;
//	}
//
//
//	char* date = new char[50];
//	char* str;
//	const int x = getDayOfWeek(y, m, d);
//	str = new char[10];
//	char* strm = new char[10];
//
//	for (int i = 0; i < strlen(STR_DAYS[x]); i++)
//	{
//		str[i] = STR_DAYS[x][i];
//	}
//	str[strlen(STR_DAYS[x])] = '\0';
//
//	int len = strlen(str);
//
//	for (int i = 0; i < strlen(STR_MONTHS[m]); i++)
//	{
//		strm[i] = STR_MONTHS[m][i];
//	}
//	strm[strlen(STR_MONTHS[m])] = '\0';
//
//	int lenm = strlen(strm);
//
//	//Default Constructor set Date to Default value : Sunday, 1 Jan 2017
//	int i;
//	for (i = 0; i < len; i++)
//	{
//		date[i] = str[i];
//		
//	}
//	date[i] = ',';
//	i++;
//	date[i] = ' ';
//	i++;
//	//int j = 48;
//	if (d >= 0 && d <= 9) {
//		date[i] = (char)48 + d;
//		i++;
//	}
//	else {
//		int d1[2];
//		int d2 = d;
//		int j;
//		for ( j = 0; j < 2; j++) {
//			d1[j] = d2 % 10;
//			d2 = d2 / 10;
//		}
//
//		for (j = 2; j > 0; j--) {
//			date[i] = (char)48 + d1[j - 1];
//			i++;
//		}
//		
//	}
//
//	date[i] = ' ';
//	i++;
//	for (int j = 0; j < lenm; j++)
//	{
//		date[i] = strm[j];
//		i++;
//	}
//	date[i] = ' ';
//	i++;
//
//	for (int k = 3; k >= 0; k--) {
//		date[i] = (char)(y1[k] + 48);
//		i++;
//	}
//
//	date[i] = '\0';
//
//	return date;
//}
//
//char* Course::Get_Date(int lecture) {
//	return this->date[lecture];
//}
//
//const char Course::STR_MONTHS[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
//
////const int Course::DAYS_IN_MONTHS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//const char Course::STR_DAYS[12][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
//
//int Course::getDayOfWeek(int y, int m, int d)
//{
//	int centuryTable[] = { 4, 2, 0, 6, 4, 2, 0, 6 }; // 17xx, 18xx, ...
//	int MonthTable[] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
//	int MonthLeapYearTable[] = { 6, 2, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
//
//	int century = y / 100;
//	int twoDigitYear = y % 100;
//	int centuryTableIndex = (century - 17) % 8;
//	//Date before 17xx are not valid, but needed to prevent negative index
//	if (centuryTableIndex < 0)
//	{
//		centuryTableIndex += 8;
//	}
//	int sum = centuryTable[centuryTableIndex] + twoDigitYear + twoDigitYear / 4;
//	if (isLeapYear(y))
//	{
//		sum += MonthLeapYearTable[m - 1];
//	}
//	else
//	{
//		sum += MonthTable[m - 1];
//	}
//	sum += d;
//	return sum % 7;
//}
//
//bool Course::isLeapYear(int y)
//{
//	if ((y % 100 != 0 && y % 4 == 0) || (y % 100 == 0 && y % 400 == 0)) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

void Course::print()
{
	cout << "-----------------Course Information-----------------" << endl;
	cout << "Course Name : " << this->name << endl;
	cout << "Course Code : " << this->code << endl;
}

Course::~Course()
{
	
	for (int i = 0; i < this->r_count; i++) {
		if (r[i] != nullptr) {
			delete this->r[i];
		}
	}
	if(r!=nullptr)
	delete[]this->r;

	if(name!=nullptr)
	delete[]this->name;

	if(code!=nullptr)
	delete[]this->code;

	/*delete[]this->Attendence;
	delete[]this->date;*/
}
