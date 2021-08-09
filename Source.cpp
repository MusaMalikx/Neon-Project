#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include"Registration.h"
#include"Person.h"
#include"Student.h"
#include"University.h"
#include"Course.h"
#include"Teacher.h"
#include"Department.h"
#include"Employee.h"
#include"ITManager.h"
#include"TA.h"


using namespace std;


University* file(char filename[])
{

	University* u = new University[1];
	int U_count = 1;
	//depart = new Department * [10];
	//person = new Employee * [10];
	//course = new Course * [10];
	//student = new Student * [10];

	//D_count = 0;
	//P_count = 0;
	//C_count = 0;

	//int de;
	char name1[100];
	int departments;
	int number;
	char code[200];
	char name[200];
	//char departinfocp[100];
	//int count;

	

	ifstream fin;
	fin.open("Data.txt");

	if (fin.fail()) {
		cout << "Error in Opening File" << endl;
	}
	else {
		cout << "File Opened" << endl << endl;

		
		fin.getline(name, 100);

		u = new University(name);
		fin >> departments;
		
		for (int i = 0; i < departments; i++) {
			if (i == 0) {
				fin.get();
			}
			

			fin.getline(name1, 200);

			u->AddDepart(name1);

			fin >> number;

			for (int j = 0; j < number; j++) {
				if (j == 0) {
					fin.get();
				}

				fin.getline(code, 200, ',');

				fin.get();
				fin.getline(name, 200);

				u->AddCourse(name, code, i);
			}

			fin >> number;

			for (int k = 0; k < number; k++) {
				if (k == 0) {
					fin.get();
				}

				fin.getline(code, 200, ',');

				fin.get();
				fin.getline(name, 200, '\n');

				

				u->AddTeacher(name, code, i);
				

			}

			fin >> number;

			for (int l = 0; l < number; l++) {

				if (l == 0) {
					fin.get();
				}
				fin.getline(code, 200, ',');

				fin.get();
				fin.getline(name, 200, '\n');

				u->AddITManager(name, code, i);
			}

			fin >> number;

			for (int m = 0; m < number; m++) {

				if (m == 0) {
					fin.get();
				}
				fin.getline(code, 200, ',');

				fin.get();
				fin.getline(name, 200, '\n');

				u->AddStudent(name, code, i);
				
				//fin.get();
				
			}
		}

	}
	fin.close();

	return u;

}

bool Ofile(char fname[], University* u)
{

	ofstream fout;
	fout.open(fname);
	if (fout.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{
		fout << u->GetUName() << endl;
		fout << u->GetDepartmentCount() << endl;
		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			fout << u->GetDepartmentName(i) << endl;
			fout << u->GetCourseCount(i) << endl;

			for (int j = 0; j < u->GetCourseCount(i); j++)
			{
				fout << u->GetCourseCode(i,j) << ", " << u->GetCourseName(i,j) << endl;
			}

			fout << u->GetTeacherCount(i) << endl;

			//fout << u->GetHODCode(i) << ", " << u->GetHODName(i) << endl;

			for (int j = 0; j < u->GetTeacherCount(i); j++)
			{

				fout << u->GetTeacherCode(i, j) << ", " << u->GetTeacherName(i, j) << endl;

			}

			fout << "1" << endl;
			fout << u->GetITCode(i) << ", " << u->GetITName(i) << endl;

			fout << u->GetStudentCount(i) << endl;
			for (int j = 0; j < u->GetStudentCount(i); j++)
			{
				fout << u->GetStudentCode(i,j) << ", " << u->GetStudentName(i,j) << endl;

				/*if (j == u->GetStudentCount(i) - 1)
				{
					fout << u->GetStudentCode(i, j) << ", " << u->GetStudentName(i, j);
				}*/
			}

		}
		return true;
	}
	fout.close();
}

bool P_s_fileSave(char p_sname[], University* u) {
	ofstream ps;
	ps.open(p_sname);

	if (ps.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{

			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				ps << u->GetSPass(i, j) << endl;

			}
		}

		return true;

	}

	ps.close();

}

bool P_s_fileRead(char p_sname[], University* u) {
	
	ifstream pi;
	pi.open(p_sname);

	char p[20];

	if (pi.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{

			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				pi.getline(p, 20);

				u->Set_Ps(p, i, j);

			}
		}

		return true;

	}
	pi.close();
}

void Changing_Student_p(char* pname, University* U) {

	bool PassReading = P_s_fileRead(pname, U);

	int a;
	cout << "Enter Department No: ";
	cin >> a;
	int b;
	cout << "Enter Student No: ";
	cin >> b;

	for (int i = 0; i < U->GetDepartmentCount(); i++)
	{
		if (i == a - 1) {
			for (int j = 0; j < U->GetStudentCount(i); j++)
			{
				if (j == b - 1)
				{
					U->ChangePassword(i, j);
				}

			}
		}

	}

	bool PassSaving = P_s_fileSave(pname, U);
}

bool P_T_fileSave(char p_tname[], University* u) {
	ofstream ps;
	ps.open(p_tname);

	if (ps.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{

			for (int j = 0; j < u->GetTeacherCount(i); j++)
			{

				ps << u->GetT_Password(i, j) << endl;

			}
		}

		return true;

	}

	ps.close();

}

bool P_T_fileRead(char p_tname[], University* u) {
	ifstream pt;
	pt.open(p_tname);

	char p[20];

	if (pt.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++){
		
			for (int j = 0; j < u->GetTeacherCount(i); j++)
			{

				pt.getline(p, 20);

				u->Set_TP(p, i, j);

			}
			
		}

		return true;

	}
	pt.close();

}

bool P_it_fileRead(char p_itname[], University* u) {

	ifstream pit;
	pit.open(p_itname);

	char p[20];

	if (pit.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			pit.getline(p, 20);
			u->Set_PIT(p, i);
		}

			return true;

	}
	pit.close();

}

bool P_it_fileSave(char p_itname[], University* u) {
	
	ofstream pit;
	pit.open(p_itname);

	if (pit.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			
			pit << u->GetIT_Password(i) << endl;

		}

		return true;

	}
	pit.close();
}

bool C_T_fileSave(char c_tname[], University* u) {
	ofstream ct;
	ct.open(c_tname);

	if (ct.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{
		//ct << u->GetDepartmentCount() << endl;
		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			//ct << u->GetTeacherCount(i) << endl;
			for (int j = 0; j < u->GetTeacherCount(i); j++)
			{
				//ct << u->GetTeacherCode(i, j) << ",";

				ct << u->Get_Assign_Courses_Count(i, j) << ",";

				for (int k = 0; k < u->Get_Assign_Courses_Count(i, j); k++) {
					ct << u->Get_Assign_courses_TC(i, j, k) << "," << u->Get_Assign_Courses_TN(i, j, k) << ",";
				}
				ct << endl;

			}
		}

		return true;

	}
	ct.close();
}

bool C_T_fileRead(char c_tname[], University* u) {
	ifstream ct;
	ct.open(c_tname);

	if (ct.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{
		char name[50];
		char code[50];
//		int d = 0, t = 0, c = 0;
////		ct.get();
//		ct >> d;
		int n = 0;
		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			
			for (int j = 0; j < u->GetTeacherCount(i); j++)
			{
				//cin.get();
				//ct.ignore(2);
				ct >> n;
				ct.ignore();

				for (int k = 0; k < n; k++) {
					
					ct.getline(code, 50, ',');
					ct.getline(name, 50, ',');

					u->Assign_Courses_to_Teacher(i, j, name, code);

				}

			}
		}

		return true;

	}
	ct.close();
}

bool C_S_fileSave(char c_sname[], University* u) {
	ofstream cs;
	cs.open(c_sname);

	if (cs.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{
		
		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				cs << u->Get_Registration_courses_count(i, j) << ",";

				for (int k = 0; k < u->Get_Registration_courses_count(i, j); k++) {
					cs << u->Get_Assign_courses_SC(i, j, k) << "," << u->Get_Assign_courses_SN(i, j, k) << ",";
				}
				cs << endl;

			}
		}

		return true;

	}
	cs.close();
}

bool C_S_fileRead(char c_sname[], University* u) {
	ifstream cs;
	cs.open(c_sname);

	if (cs.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{
		char name[50];
		char code[50];
		//		int d = 0, t = 0, c = 0;
		////		ct.get();
		//		ct >> d;
		int n = 0;
		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{

			for (int j = 0; j < u->GetStudentCount(i); j++)
			{
				//cin.get();
				//ct.ignore(2);
				cs >> n;
				cs.ignore();

				for (int k = 0; k < n; k++) {

					cs.getline(code, 50, ',');
					cs.getline(name, 50, ',');

					u->Register_Course_for_Students(i, j, name, code);

				}

			}
		}

		return true;

	}
	cs.close();
}

bool Attendence_S_fileSave(char c_sname[], University* u) {
	ofstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa << u->Get_Registration_courses_count(i, j) << ",";

				for (int k = 0; k < u->Get_Registration_courses_count(i, j); k++) {
					
					csa << u->Get_Attendence_count(i, j, k) << ",";

					for (int a = 0; a < u->Get_Attendence_count(i, j, k); a++) {
						csa << u->Get_Attendence(i, j, k)[a] << ",";
						csa << u->Get_Y(i, j, k) << ",";
						csa << u->Get_M(i, j, k) << ",";
						csa << u->Get_D(i, j, k) << ",";
					}

				}
				csa << endl;

			}
		}

		return true;

	}
	csa.close();
}

bool Attendence_S_fileRead(char c_sname[], University* u) {
	ifstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{

		int r;
		int attend_C;
		int attend;
		int y;
		int m;
		int d;

		

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{

			
			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa >> r;
				csa.ignore();

				for (int k = 0; k < r; k++) {

					
					csa >> attend_C;
					csa.ignore();

					for (int a = 0; a < attend_C; a++) {
						
						csa >> attend;
						csa.ignore();
						csa >> y;
						csa.ignore();
						csa >> m;
						csa.ignore();
						csa >> d;
						csa.ignore();
						u->Add_Attendence(i, j, k, attend, y, m, d);
					}

				}
				//csa.ignore('\n');

			}
			//csa.ignore('\n');
		}

		return true;

	}
	csa.close();
}

bool Assignment_S_fileSave(char c_sname[], University* u) {
	ofstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa << u->Get_Registration_courses_count(i, j) << ",";

				for (int k = 0; k < u->Get_Registration_courses_count(i, j); k++) {

					csa << u->Get_AssignCount(i, j, k) << ",";
					csa << u->Get_Assign_capacity(i, j, k) << ",";

					for (int a = 0; a < u->Get_AssignCount(i, j, k); a++) {
						csa << u->Get_TotalAssignments(i, j, k)[a] << ",";
						csa << u->Get_T_Marks_Assignment(i, j, k)[a] << ",";
						csa << u->Get_Assignment_weightage(i, j, k)[a] << ",";
					}

				}
				csa << endl;

			}
		}

		return true;

	}
	csa.close();
}

bool Assignment_S_fileRead(char c_sname[], University* u) {
	ifstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{

		int r;
		int ac;
		int cp;
		int o;
		int t;
		int w;
		



		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{


			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa >> r;
				csa.ignore();

				for (int k = 0; k < r; k++) {


					csa >> ac;
					csa.ignore();
					csa >> cp;
					csa.ignore();

					u->Set_Assign_capacity(i, j, k, cp);

					for (int a = 0; a < ac; a++) {

						csa >> o;
						csa.ignore();
						csa >> t;
						csa.ignore();
						csa >> w;
						csa.ignore();
					
						u->Add_Assignments(i, j, k, o);
						u->Add_T_Marks_Assignments(i, j, k, t);
						u->Add_Assignment_weightage(i, j, k, w);
					}

				}
				//csa.ignore('\n');

			}
			//csa.ignore('\n');
		}

		return true;

	}
	csa.close();
}

bool Quiz_S_fileSave(char c_sname[], University* u) {
	ofstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa << u->Get_Registration_courses_count(i, j) << ",";

				for (int k = 0; k < u->Get_Registration_courses_count(i, j); k++) {

					csa << u->Get_QuizCount(i, j, k) << ",";
					csa << u->Get_Quiz_capacity(i, j, k) << ",";

					for (int a = 0; a < u->Get_QuizCount(i, j, k); a++) {
						csa << u->Get_TotalQuizes(i, j, k)[a] << ",";
						csa << u->Get_T_Marks_Quizes(i, j, k)[a] << ",";
						csa << u->Get_Quiz_weightage(i, j, k)[a] << ",";
					}

				}
				csa << endl;

			}
		}

		return true;

	}
	csa.close();
}

bool Quiz_S_fileRead(char c_sname[], University* u) {
	ifstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{

		int r;
		int ac;
		int cp;
		int o;
		int t;
		int w;




		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{


			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa >> r;
				csa.ignore();

				for (int k = 0; k < r; k++) {


					csa >> ac;
					csa.ignore();
					csa >> cp;
					csa.ignore();

					u->Set_Quiz_capacity(i, j, k, cp);

					for (int a = 0; a < ac; a++) {

						csa >> o;
						csa.ignore();
						csa >> t;
						csa.ignore();
						csa >> w;
						csa.ignore();

						u->Add_Quizes(i, j, k, o);
						u->Add_T_Marks_Quizes(i, j, k, t);
						u->Add_Quiz_weightage(i, j, k, w);
					}

				}
				//csa.ignore('\n');

			}
			//csa.ignore('\n');
		}

		return true;

	}
	csa.close();
}

bool Mid_S_fileSave(char c_sname[], University* u) {
	ofstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa << u->Get_Registration_courses_count(i, j) << ",";

				for (int k = 0; k < u->Get_Registration_courses_count(i, j); k++) {

					csa << u->Get_Mid(i, j, k) << ",";
					csa << u->Get_T_Marks_Mid(i, j, k) << ",";
					csa << u->Get_Mid_weightage(i, j, k) << ",";

				}
				csa << endl;

			}
		}

		return true;

	}
	csa.close();
}

bool Mid_S_fileRead(char c_sname[], University* u) {
	ifstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{

		int r;
		int o;
		int t;
		int w;




		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{


			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa >> r;
				csa.ignore();

				for (int k = 0; k < r; k++) {


					csa >> o;
					csa.ignore();
					csa >> t;
					csa.ignore();
					csa >> w;
					csa.ignore();

					u->Set_Mid(i, j, k, o);
					u->Add_T_Marks_Mid(i, j, k, t);
					u->Add_Mid_weightage(i, j, k, w);

					

				}
				//csa.ignore('\n');

			}
			//csa.ignore('\n');
		}

		return true;

	}
	csa.close();
}

bool Final_S_fileSave(char c_sname[], University* u) {
	ofstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa << u->Get_Registration_courses_count(i, j) << ",";

				for (int k = 0; k < u->Get_Registration_courses_count(i, j); k++) {

					csa << u->Get_Final(i, j, k) << ",";
					csa << u->Get_T_Marks_Final(i, j, k) << ",";
					csa << u->Get_Final_weightage(i, j, k) << ",";

				}
				csa << endl;

			}
		}

		return true;

	}
	csa.close();
}

bool Final_S_fileRead(char c_sname[], University* u) {
	ifstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{

		int r;
		int o;
		int t;
		int w;




		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{


			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa >> r;
				csa.ignore();

				for (int k = 0; k < r; k++) {


					csa >> o;
					csa.ignore();
					csa >> t;
					csa.ignore();
					csa >> w;
					csa.ignore();

					u->Set_Final(i, j, k, o);
					u->Add_T_Marks_Final(i, j, k, t);
					u->Add_Final_weightage(i, j, k, w);



				}
				//csa.ignore('\n');

			}
			//csa.ignore('\n');
		}

		return true;

	}
	csa.close();
}

bool Grades_S_fileSave(char c_sname[], University* u) {
	ofstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Saving the file" << endl;
		return false;
	}
	else
	{

		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{
			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa << u->Get_Registration_courses_count(i, j) << ",";

				for (int k = 0; k < u->Get_Registration_courses_count(i, j); k++) {

					if (u->Get_Grade(i, j, k) == nullptr) {
						csa << 0 << ",";
					}
					else {
						csa << u->Get_Grade(i, j, k) << ",";
					}

				}
				csa << endl;

			}
		}

		return true;

	}
	csa.close();
}

bool Grades_S_fileRead(char c_sname[], University* u) {
	ifstream csa;
	csa.open(c_sname);

	if (csa.fail())
	{
		cout << "Error in Reading the file" << endl;
		return false;
	}
	else
	{

		char str[10];
		int r = 0;



		for (int i = 0; i < u->GetDepartmentCount(); i++)
		{


			for (int j = 0; j < u->GetStudentCount(i); j++)
			{

				csa >> r;
				csa.ignore();

				for (int k = 0; k < r; k++) {


					csa.getline(str, 10, ',');
					if (str[0] != '0') {
						u->Assign_Grade(i, j, k, str);
					}


				}
				//csa.ignore('\n');

			}
			//csa.ignore('\n');
		}

		return true;

	}
	csa.close();
}

int main() {

	char filename[] = "Data.txt";

	char fname[] = "D.txt";

	University* U;

	U = file(filename);

	char Pass_S_File[] = "password.txt";

	char Pass_T_File[] = "TeacH_Password.txt";

	char Pass_IT_File[] = "ITM_Password.txt";

	char Courses_T_file[] = "Teach_Course.txt";

	char Registered_Student_Courses[] = "Student_Course.txt";

	char Attendence_S_File[] = "Student_Attendence.txt";

	char Assignments_S_File[] = "Student_Assignments.txt";

	char Quizes_S_File[] = "Student_Quizes.txt";

	char Mid_S_File[] = "Student_Mid.txt";

	char Final_S_File[] = "Student_Final.txt";

	char Grades_S_File[] = "Student_Grades.txt";

	int s_in = 0;
	char password[50];
	int count;
	int d;
	int IT_Check = 0;

	bool IT_Rfile;
	bool IT_Sfile;

	bool T_Rfile;
	bool T_Sfile;

	bool S_Rfile;
	bool S_Sfile;

	bool check = Ofile;

	C_S_fileRead(Registered_Student_Courses, U);
	P_T_fileRead(Pass_T_File, U);
	C_T_fileRead(Courses_T_file, U);
	P_s_fileRead(Pass_S_File, U);
	P_it_fileRead(Pass_IT_File, U);
	Attendence_S_fileRead(Attendence_S_File, U);
	Assignment_S_fileRead(Assignments_S_File, U);
	Quiz_S_fileRead(Quizes_S_File, U);
	Mid_S_fileRead(Mid_S_File, U);
	Final_S_fileRead(Final_S_File, U);
	Grades_S_fileRead(Grades_S_File, U);

	int s = 0;
	for (int i = 0; i < 50; i++) {
		cout << "Select The Department : " << endl << endl;

		for (int j = 0; j < U->GetDepartmentCount(); j++) {
			cout << j + 1 << " --> " << U->GetDepartmentName(j) << endl;
			s = j;
		}
		cout << s + 2 << " --> " << "Exit" << endl;
		cout << endl;

	Try:
		cout << "Enter Your Choice : ";
		cin >> d;

		system("CLS");

		if (d == s + 2) {
			cout << endl << "    -EXIT SUCCESSFULLY-" << endl << endl;
			break;
		}

		if ((d < 1) || (d > U->GetDepartmentCount() + 1))
		{
			cout << endl << "      -You Have Entered Wrong Choice....Please Enter Again-" << endl << endl;
			goto Try;
		}

		cout << endl;


		for (int sign_in = 0; sign_in < 50; sign_in++)
		{
			s_in = 0;
			cout << "Sign in As ; " << endl << endl;
			cout << "  1 --> HOD" << endl;
			cout << "  2 --> IT Manager" << endl;
			cout << "  3 --> Teacher" << endl;
			cout << "  4 --> Student" << endl;
			cout << "  5 --> EXIT" << endl << endl;

		Jump:
			cout << "Enter Your Choice : ";
			cin >> s_in;

			system("CLS");

			if ((s_in < 0) || (s_in > 5)) {
				cout << endl << "      -You Have Entered Wrong Choice....Please Enter Again-" << endl << endl;
				goto Jump;
			}

			if (s_in == 1) {
				cout << "For LOGIN : " << endl;

				cout << endl << "Default Password : " << U->GetHODPassword(d - 1) << endl << endl;

				cout << "Enter the Password :";


				cin.get();

				cin.get(password, 50);

				//T_Rfile = P_T_fileRead(Pass_T_File, U);

				count = 0;

				for (int pass = d - 1; pass < d; pass++) {
					count = 0;
					for (int i = 0; i < strlen(password); i++)
					{
						if (password[i] == U->GetHODPassword(pass)[i])
						{
							count++;
						}
					}


					if ((strlen(password) == strlen(U->GetHODPassword(pass))) && (strlen(password) == count))
					{

						system("CLS");

						cout << endl;
						cout << "----------------- WELCOME " << U->GetHODName(pass) << " -----------------" << endl << endl;

						for (int A = 0; A < 50; A++) {

							int n;
							cout << "Signed IN" << endl << endl;
							cout << "   1 --> Assign Courses to Teachers" << endl;
							cout << "   2 --> Register a Course for a Student" << endl;
							cout << "   3 --> Unregister a Course for a Student" << endl;
							cout << "   4 --> View Grades of a Specific Course" << endl;
							cout << "   5 --> LOG OUT" << endl << endl;
						Again1:
							cout << "Enter your OPtion : ";
							cin >> n;

							system("CLS");

							if ((n < 1) || (n > 5)) {

								system("CLS");

								cout << endl;
								cout << "      -You Have Entered Wrong Choice....Please Enter Again-" << endl << endl;
								goto Again1;
							}

							if (n == 1) {

								system("CLS");

								//C_T_fileRead(Courses_T_file, U);

								/*char code[20];
								char name[20];*/
								int n2;
								int n1;
								//cin.get();

								//cout << endl << U->GetTeacherCount(pass);
								cout << endl;
								for (int k = 0; k < U->GetTeacherCount(pass); k++) {
									cout << "   " << k + 1 << " --> " << U->GetTeacherCode(pass, k) << "   " << U->GetTeacherName(pass, k) << endl;
								}
								cout << endl << "Select Faculty Member : ";
								//cin.get();
							t2:
								cin >> n2;

								if (n2 > U->GetTeacherCount(pass) || n2 < 0) {
									cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
									goto t2;
								}


								cout << endl;
								for (int k = 0; k < U->GetCourseCount(pass); k++) {
									cout << k + 1 << " --> " << U->GetCourseCode(pass, k) << "   " << U->GetCourseName(pass, k) << endl;
								}
								cout << endl;

								cout << "Select Course : ";
							t1:
								cin >> n1;

								if (n2 > U->GetTeacherCount(pass) || n2 < 0) {
									cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
									goto t1;
								}


								/*cout << endl << "Enter the Code OF Course To Assign : ";
								cin.getline(code, 20);
								cout << endl;
								cout << "Enter the Name OF Course To Assign : ";
								cin.getline(name, 20);*/

								if (U->Assign_Courses_to_Teacher(pass, n2 - 1, U->GetCourseName(pass, n1 - 1), U->GetCourseCode(pass, n1 - 1)) == 1) {
									cout << endl << "-The Course is Assigned Successfully-" << endl << endl;
								}
								else if (U->Assign_Courses_to_Teacher(pass, n2 - 1, U->GetCourseName(pass, n1 - 1), U->GetCourseCode(pass, n1 - 1)) == 0) {
									cout << endl << "-This Course was Assigned Already-" << endl << endl;
								}
								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);
							}

							if (n == 2) {

								system("CLS");

								//C_S_fileRead(Registered_Student_Courses, U);

								/*char code[20];
								char name[20];*/
								int n2;
								int n1;
								//cin.get();

								//cout << endl << U->GetTeacherCount(pass);
								cout << endl;
								for (int k = 0; k < U->GetStudentCount(pass); k++) {
									cout << "   " << k + 1 << " --> " << U->GetStudentCode(pass, k) << " , " << U->GetStudentName(pass, k) << endl;
								}
								cout << endl << "Select Student : ";
								//cin.get();
							st2:
								cin >> n2;

								if (n2 > U->GetStudentCount(pass) || n2 < 0) {
									cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
									goto st2;
								}

								cout << endl;

								for (int k = 0; k < U->GetCourseCount(pass); k++) {
									cout << k + 1 << " --> " << U->GetCourseCode(pass, k) << " , " << U->GetCourseName(pass, k) << endl;
								}
								cout << endl;

								cout << "Select Course : ";
							st1:
								cin >> n1;
								if (n2 > U->GetStudentCount(pass) || n2 < 0) {
									cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
									goto st1;
								}

								if (U->Register_Course_for_Students(pass, n2 - 1, U->GetCourseName(pass, n1 - 1), U->GetCourseCode(pass, n1 - 1)) == 1) {
									//U->Assign_Students_for_courses(pass, n1 - 1, U->GetStudentName(pass, n2 - 1), U->GetStudentCode(pass, n2 - 1));
									cout << endl << "-The Course is Registered Successfully-" << endl << endl;
								}
								else {
									cout << endl << "-The Course was Registered Already-" << endl << endl;
								}
								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 3) {

								system("CLS");

								//C_S_fileRead(Registered_Student_Courses, U);

								/*char code[20];
								char name[20];*/
								int n2;
								int n1;
								//cin.get();

								//cout << endl << U->GetTeacherCount(pass);
								cout << endl;
								for (int k = 0; k < U->GetStudentCount(pass); k++) {
									cout << "   " << k + 1 << " --> " << U->GetStudentCode(pass, k) << " , " << U->GetStudentName(pass, k) << endl;
								}
								cout << endl << "Select Student : ";
								//cin.get();
							s2:
								cin >> n2;

								if (n2 > U->GetStudentCount(pass) || n2 < 0) {
									cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
									goto s2;
								}

								cout << endl;

								if (U->Get_Registration_courses_count(pass, n2 - 1) == 0) {
									cout << "-No Course is Registered-" << endl << endl;
								}

								else {
									for (int k = 0; k < U->Get_Registration_courses_count(pass, n2 - 1); k++) {
										cout << k + 1 << " --> " << U->Get_Assign_courses_SC(pass, n2 - 1, k) << " , " << U->Get_Assign_courses_SN(pass, n2 - 1, k) << endl;
									}

									cout << "Select Course : ";
								s1:
									cin >> n1;
									if (n1 > U->Get_Registration_courses_count(pass, n2 - 1) || n1 < 0) {
										cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
										goto s1;
									}

									if (U->UnRegister_Course_for_Students(pass, n2 - 1, U->GetCourseCode(pass, n1 - 1)) == 1){
									cout << endl << "-The Course is Un-Registered Successfully-" << endl << endl;
									}
									else if (U->UnRegister_Course_for_Students(pass, n2 - 1, U->GetCourseCode(pass, n1 - 1)) == 0) {
										cout << endl << "-This Course was not Found-" << endl << endl;
									}

									Ofile(filename, U);
									C_S_fileSave(Registered_Student_Courses, U);
									P_T_fileSave(Pass_T_File, U);
									C_T_fileSave(Courses_T_file, U);
									P_s_fileSave(Pass_S_File, U);
									P_it_fileSave(Pass_IT_File, U);
									Attendence_S_fileSave(Attendence_S_File, U);
									Assignment_S_fileSave(Assignments_S_File, U);
									Quiz_S_fileSave(Quizes_S_File, U);
									Mid_S_fileSave(Mid_S_File, U);
									Final_S_fileSave(Final_S_File, U);
									Grades_S_fileSave(Grades_S_File, U);
								
								}

							}

							if (n == 4) {

								system("CLS");

								int s = 0;
								int c = 0;
								for (int k = 0; k < U->GetStudentCount(pass); k++) {
									cout << "  " << k + 1 << " --> " << U->GetStudentCode(pass, k) << "  " << U->GetStudentName(pass, k) << endl;
								}
								cout << endl << "Select Student : ";
								cin >> s;
								cout << endl;

								if (U->Get_Registration_courses_count(pass, s - 1) == 0) {
									cout << endl << "-No Course is Registered Yet-" << endl << endl;
								}
								else {

									for (int f = 0; f < U->Get_Registration_courses_count(pass, s - 1); f++) {
										cout << "  " << f + 1 << " --> " << U->Get_Assign_courses_SC(pass, s - 1, f) << "    " << U->Get_Assign_courses_SN(pass, s - 1, f) << endl;
									}

									cout << endl << "Select Course : ";
									cin >> c;
									cout << endl;

									if (U->Get_Grade(pass, s - 1, c - 1) == nullptr) {

										cout << "No Grade is Assigned" << endl << endl;

									}

									else {
										cout << "   -The Assigned Grade is : " << U->Get_Grade(pass, s - 1, c - 1) << endl << endl;
									}

									Ofile(filename, U);
									C_S_fileSave(Registered_Student_Courses, U);
									P_T_fileSave(Pass_T_File, U);
									C_T_fileSave(Courses_T_file, U);
									P_s_fileSave(Pass_S_File, U);
									P_it_fileSave(Pass_IT_File, U);
									Attendence_S_fileSave(Attendence_S_File, U);
									Assignment_S_fileSave(Assignments_S_File, U);
									Quiz_S_fileSave(Quizes_S_File, U);
									Mid_S_fileSave(Mid_S_File, U);
									Final_S_fileSave(Final_S_File, U);
									Grades_S_fileSave(Grades_S_File, U);

								}

							}

							if (n == 5) {

								system("CLS");

								cout << endl << "  -Logged Out Successfully-" << endl << endl;

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

								break;
							}
						}
					}
					else
					{
						cout << "-You Have Entered the Wrong Password-" << endl;
					}
				}

			}

			if (s_in == 2)
			{
				cout << "For LOGIN : " << endl;

				cout << endl << "Default Password : " << U->GetIT_Password(d - 1) << endl << endl;

				cout << "Enter the Password :";

				cin.get();
				cin.get(password, 50);

				//IT_Rfile = P_it_fileRead(Pass_IT_File, U);

				count = 0;

				for (int pass = d - 1; pass < d; pass++) {
					count = 0;
					for (int i = 0; i < strlen(password); i++)
					{
						if (password[i] == U->GetIT_Password(pass)[i])
						{
							count++;
						}
					}



					if ((strlen(password) == strlen(U->GetIT_Password(pass))) && (strlen(password) == count))
					{

						system("CLS");

						cout << endl;
						cout << "----------------- WELCOME " << U->GetITName(pass) << " -----------------" << endl << endl;

						for (int A = 0; A < 50; A++) {

							int n;
							cout << "Signed IN" << endl << endl;
							cout << "   1 --> Change IT Account Passord" << endl;
							cout << "   2 --> Change Student Account Passord" << endl;
							cout << "   3 --> Change Teacher Account Passord" << endl;
							cout << "   4 --> Create a NEW Student Account" << endl;
							cout << "   5 --> Create a NEW Teacher Account" << endl;
							cout << "   6 --> Delete a Student's Account" << endl;
							cout << "   7 --> Delete a Teacher's Account" << endl;
							cout << "   8 --> LOG OUT" << endl << endl;
						Again0:
							cout << "Enter your OPtion : ";
							cin >> n;

							system("CLS");

							if ((n < 1) || (n > 8)) {
								cout << endl;
								cout << "      -You Have Entered Wrong Choice....Please Enter Again-" << endl << endl;
								goto Again0;
							}

							if (n == 1) {

								system("CLS");

								//IT_Rfile = P_it_fileRead(Pass_IT_File, U);
								U->ChangeIT_Password(pass);
								cout << endl << "    -PASSWORD CHANGED Successfully" << endl << endl;
								
								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);
							}

							if (n == 2) {

								system("CLS");

								//S_Rfile = P_s_fileRead(Pass_S_File, U);

								int s = 0;
								char c[50];
								int check;

								cout << endl;

								for (int j = 0; j < U->GetStudentCount(pass); j++)
								{

									cout << "   --> " << U->GetStudentCode(pass, j) << "   " << U->GetStudentName(pass, j) << endl;

								}
								cout << endl;
								cin.get();
							IT0:
								cout << "Enter the Student Roll Number : ";
								cin.getline(c, 50);
								cout << endl;
								count = 0;
								for (int j = 0; j < U->GetStudentCount(pass); j++) {
									count = 0;
									for (int i = 0; i < strlen(c); i++) {

										//count = 0;

										if (c[i] == U->GetStudentCode(pass, j)[i]) {
											count++;
										}

									}

									if (count == strlen(c)) {
										s = j;
										check = count;
										break;
									}

								}

								if (strlen(c) == count) {

									U->ChangePassword(pass, s);
									cout << endl << "    -PASSWORD CHANGED Successfully-" << endl << endl;

								}
								else if (strlen(c) != count) {
									cout << endl << "    -You Have Entered Wrong Student Roll Number.....Please Enter Again-" << endl << endl;
									goto IT0;
								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);
							}

							if (n == 3) {

								system("CLS");

								//T_Rfile = P_T_fileRead(Pass_T_File, U);

								int s = 0;
								char c[50];
								int check;

								cout << endl;
								for (int j = 0; j < U->GetTeacherCount(pass); j++)
								{

									cout << "   --> " << U->GetTeacherCode(pass, j) << "   " << U->GetTeacherName(pass, j) << endl;

								}

								cout << endl;
								cin.get();
							IT1:
								cout << "Enter the Faculty Member Code : ";
								cin.getline(c, 50);
								cout << endl;
								count = 0;
								for (int j = 0; j < U->GetTeacherCount(pass); j++) {
									count = 0;
									for (int i = 0; i < strlen(c); i++) {

										//count = 0;

										if (c[i] == U->GetTeacherCode(pass, j)[i]) {
											count++;
										}

									}

									if (count == strlen(c)) {
										s = j;
										check = count;
										break;
									}

								}

								if (strlen(c) == count) {
									system("CLS");
									U->ChangeT_Password(pass, s);
									cout << endl << "    -PASSWORD CHANGED SUCCESSFULLY-" << endl << endl;
								}
								else if (strlen(c) != count) {
									cout << endl << "    -You Have Entered Wrong Student Roll Number.....Please Enter Again-" << endl << endl;
									goto IT1;
								}


								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 4) {

								system("CLS");

								char name[50];
								char code[50];

								cin.get();
								cout << "Enter the NAME of the Student : ";
								cin.getline(name, 50);

								cout << "Enter the ROll NUMBER of the Student : ";
								cin.getline(code, 50);

								system("CLS");
								
								if (U->AddStudent(name, code, pass) == 1) {
									cout << endl << "    -STUDENT ACCOUNT CREATED SUCCESSFULLY-" << endl << endl;
								}
								else if (U->AddStudent(name, code, pass) == 0) {
									cout << endl << "    -STUDENT ACCOUNT WAS CREATED ALREADY WITH THIS ROLL NUMBER-" << endl << endl;
								}
								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 5) {

								system("CLS");

								char name[50];
								char code[50];

								cin.get();
								cout << "Enter the NAME of the Faculty Member : ";
								cin.getline(name, 50);

								cout << "Enter the ROll NUMBER of the Faculty Member : ";
								cin.getline(code, 50);

								system("CLS");
								
								if (U->AddTeacher(name, code, pass) == 1) {
									cout << endl << "    -FACULTY MEMBER ACCOUNT CREATED SUCCESSFULLY-" << endl << endl;
								}
								else if (U->AddTeacher(name, code, pass) == 0) {
									cout << endl << "    -FACULTY MEMBER ACCOUNT IS ALREADY CREATED WITH THIS CODE-" << endl << endl;
								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 6) {

								system("CLS");

								char code[50];

								for (int j = 0; j < U->GetStudentCount(pass); j++)
								{

									cout << U->GetStudentCode(pass, j) << ", " << U->GetStudentName(pass, j) << endl;

								}

								cin.get();
							IT2:
								cout << "Enter the ROll NUMBER of the Student : ";
								cin.getline(code, 50);

								for (int j = 0; j < U->GetStudentCount(pass); j++) {
									count = 0;
									for (int i = 0; i < strlen(code); i++) {

										//count = 0;

										if (code[i] == U->GetStudentCode(pass, j)[i]) {
											count++;
										}

									}

									if (count == strlen(code)) {
										//s = j;
										//check = count;
										break;
									}

								}

								if (strlen(code) == count) {
									system("CLS");
									U->RemoveStudent(code, pass);
									//U->ChangePassword(pass, s);
									cout << endl << "    -STUDENT ACCOUNT REMOVED SUCCESSFULLY-" << endl << endl;

								}
								else if (strlen(code) != count) {
									cout << endl << "    -You Have Entered Wrong Student Roll Number.....Please Enter Again-" << endl << endl;
									goto IT2;
								}



								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 7) {

								system("CLS");

								//T_Rfile = P_T_fileRead(Pass_S_File, U);

								char code[50];

								for (int j = 0; j < U->GetTeacherCount(pass); j++)
								{

									cout << U->GetTeacherCode(pass, j) << ", " << U->GetTeacherName(pass, j) << endl;

								}

								cin.get();
							IT3:
								cout << "Enter the Code of the Teacher : ";
								cin.getline(code, 50);

								count = 0;
								for (int j = 0; j < U->GetTeacherCount(pass); j++) {
									count = 0;
									for (int i = 0; i < strlen(code); i++) {

										//count = 0;

										if (code[i] == U->GetTeacherCode(pass, j)[i]) {
											count++;
										}

									}

									if (count == strlen(code)) {
										//s = j;
										//check = count;
										break;
									}

								}

								if (strlen(code) == count) {
									system("CLS");
									U->RemoveTeacher(code, pass);
									//U->ChangeT_Password(pass, s);
									cout << endl << "    -TEACHER ACCOUNT DELETED SUCCESSFULLY-" << endl << endl;
								}
								else if (strlen(code) != count) {
									cout << endl << "    -You Have Entered Wrong Faculty Member Code.....Please Enter Again-" << endl << endl;
									goto IT3;
								}


								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);
							}

							if (n == 8) {

								system("CLS");

								cout << endl << "    -LOG OUT SUCCESSFULLY-" << endl << endl;

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

								break;

							}

						}

					}

					else
					{
						system("CLS");
						cout << endl << "-You Have Entered the Wrong Password-" << endl << endl;
					}

				}

			}

			if (s_in == 3) {

				system("CLS");

				count = 0;
				int teacher = 0;

				cout << endl;

				for (int i = 0; i < U->GetTeacherCount(d - 1); i++) {
					cout << "   " << i + 1 << " --> " << U->GetTeacherCode(d - 1, i) << "  " << U->GetTeacherName(d - 1, i) << endl;
				}

				cout << endl << "Enter Faculty Member : ";
				cin >> teacher;

				system("CLS");

				cout << "For LOGIN : " << endl;

				cout << endl << "Default Password : " << U->GetT_Password(d - 1, teacher - 1) << endl << endl;

				cout << "Enter the Password :";

				

				cin.get();

				cin.get(password, 50);

				

				for (int i = teacher - 1; i < teacher; i++) {

					for (int j = 0; j < strlen(password); j++)
					{
						if (password[j] == U->GetT_Password(d - 1, i)[j])
						{
							count++;
						}
					}
				}


				
					/*count = 0;
					for (int j = 1; j < U->GetTeacherCount(i); j++) {

						for (int i = 0; i < strlen(password); i++)
						{
							if (password[i] == U->GetT_Password(pass, j)[i])
							{
								count++;
							}
						}

						if (count == strlen(U->GetT_Password(pass, j))) {
							index = j;
							break;
						}

					}*/

				if ((strlen(password) == strlen(U->GetT_Password(d - 1, teacher - 1))) && (strlen(password) == count))
				{

					for (int pass = d - 1; pass < d; pass++) {

						system("CLS");

						cout << endl;
						cout << "----------------- WELCOME " << U->GetTeacherName(pass, teacher - 1) << " -----------------" << endl << endl;

						for (int A = 0; A < 50; A++) {

							int n;
						CR0:
							cout << "Signed IN" << endl << endl;
							cout << "   1 --> Manage Attendance of Students" << endl;
							cout << "   2 --> View Attendance of all Students" << endl;
							cout << "   3 --> Manage Evaluations of Students " << endl;
							cout << "   4 --> View Evaluation Report of a Specific Course Displaying all Evaluations of all the Students of that Course" << endl;
							cout << "   5 --> Assign Grades to Students" << endl;
							cout << "   6 --> LOG OUT" << endl << endl;
						Again2:
							cout << "Enter your OPtion : ";
							cin >> n;

							system("CLS");

							if ((n < 1) || (n > 6)) {

								system("CLS");

								cout << endl;
								cout << "      -You Have Entered Wrong Choice....Please Enter Again-" << endl << endl;
								goto Again2;
							}

							if (n == 1) {

								system("CLS");

								int n = 0, n2 = 0, n3 = 0;
								int* x = 0;
								int x1 = 0;

								for (int k = 0; k < U->Get_Assign_Courses_Count(pass, teacher - 1); k++) {
									cout << k + 1 << "   --> " << U->Get_Assign_courses_TC(pass, teacher - 1, k) << "   " << U->Get_Assign_Courses_TN(pass, teacher - 1, k) << endl;
								}

							A:
								cout << endl << "Select Teacher Course : ";
								cin >> n;

								if (n < 1 || n > U->Get_Assign_Courses_Count(pass, teacher - 1)) {
									cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
									goto A;
								}

								x = U->find_Student_Courses_Index(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));
								x1 = U->find_1S_Course(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));

								if (x[0] == 1) {

									system("CLS");

									cout << endl << "   -No Course is Registered Yet-" << endl << endl;
								}
								else {
									cout << endl;
									for (int k = 1; k < x[0]; k++) {
										cout << k << " --> " << U->GetStudentCode(pass, x[k]) << " , " << U->GetStudentName(pass, x[k]) << endl;
									}
									cout << endl;

									cout << "Select Student : ";
									cin >> n3;

									system("CLS");

									//int x = U->find_Student_Index(pass, U->Get_Assign_Student_CC(pass, n1 - 1, n3 - 1));



										//U->Set_lecture_Attendence_count_in_course(pass, x[n3], x1, n2);

									cout << "    --> Add Attendence" << endl;


									//cout << endl << "Total Lectures are " << U->Get_lectures_count(pass, n3 - 1, n1 - 1) << " in " << U->GetCourseName(pass, n1 - 1) << endl;

									int l1 = 0;
									int y = 0, m = 0, d = 0;
									cout << endl << "Lecture : " << U->Get_Attendence_count(pass, x[n3], x1) + 1 << endl;

									cout << endl << "Press 1(Present) or Press 0(Absent) : ";
									cin >> l1;

									if (l1 == 1) {

										cout << endl << "Enter the Year : ";
										cin >> y;
										cout << endl << "Enter the Month : ";
										cin >> m;
										cout << endl << "Enter the Day : ";
										cin >> d;
										U->Add_Attendence(pass, x[n3], x1, true, y, m, d);


									}
									else if (l1 == 0) {

										cout << endl << "Enter the Year : ";
										cin >> y;
										cout << endl << "Enter the Month : ";
										cin >> m;
										cout << endl << "Enter the Day : ";
										cin >> d;
										U->Add_Attendence(pass, x[n3], x1, false, y, m, d);

									}




								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 2) {

								system("CLS");

								int n = 0, n1 = 0, n2 = 0, n3 = 0;
								int* x = 0;
								int x1 = 0;

								for (int k = 0; k < U->Get_Assign_Courses_Count(pass, teacher - 1); k++) {
									cout << k + 1 << "   --> " << U->Get_Assign_courses_TC(pass, teacher - 1, k) << "   " << U->Get_Assign_Courses_TN(pass, teacher - 1, k) << endl;
								}

							T1:
								cout << endl << "Select Teacher Course : ";
								cin >> n;

								if (n < 1 || n > U->Get_Assign_Courses_Count(pass, teacher - 1)) {
									cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
									goto T1;
								}

								x = U->find_Student_Courses_Index(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));
								x1 = U->find_1S_Course(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));

								for (int k = 1; k < x[0]; k++) {
									cout << k << " --> " << U->GetStudentCode(pass, x[k]) << " , " << U->GetStudentName(pass, x[k]) << endl;
								}

							T:
								cout << endl << "Select Student : ";
								cin >> n3;

								if (n3 < 1 || n3 > x[0]) {
									cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
									goto T;
								}

								system("CLS");

								if (U->Get_Attendence_count(pass, x[n3], x1) == 0) {
									cout << endl << "No Attendence is found" << endl;
									goto CR0;
								}
								else {
									cout << endl << "Attendence of " << U->GetStudentName(pass, x[n3]) << endl;
									U->View_Attendence(pass, x[n3], x1);
								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 3) {

								system("CLS");


								int a = 0, n1 = 0, n2 = 0, n3 = 0;
								int* x = 0;
								int x1 = 0;

								for (int k = 0; k < U->Get_Assign_Courses_Count(pass, teacher - 1); k++) {
									cout << k + 1 << "   --> " << U->Get_Assign_courses_TC(pass, teacher - 1, k) << "   " << U->Get_Assign_Courses_TN(pass, teacher - 1, k) << endl;
								}

							N1:
								cout << endl << "Select Teacher Course : ";
								cin >> n;

								if (n < 1 || n > U->Get_Assign_Courses_Count(pass, teacher - 1)) {
									cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
									goto N1;
								}

								x = U->find_Student_Courses_Index(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));
								x1 = U->find_1S_Course(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));

								if (x[0] == 1) {

									cout << endl << "   -No Student is Registered in this Course-" << endl << endl;

								}

								else {

									for (int k = 1; k < x[0]; k++) {
										cout << k << " --> " << U->GetStudentCode(pass, x[k]) << " , " << U->GetStudentName(pass, x[k]) << endl;
									}

								N:
									cout << endl << "Select Student : ";
									cin >> n3;

									if (n3 < 1 || n3 > x[0]) {
										cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
										goto N;
									}

									system("CLS");

									cout << endl << "   -Manage Evaluation-" << endl << endl;
									cout << "   1 --> Add Assignments" << endl;
									cout << "   2 --> Add Quizes" << endl;
									cout << "   3 --> Add Mid" << endl;
									cout << "   4 --> Add Final" << endl << endl;

								R:
									cout << "Enter Your Choice : ";
									cin >> a;

									if (a < 1 || a > 4) {
										cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
										goto R;
									}

									if (a == 1) {

										int number = 0;
										int number1 = 0;
										int number2 = 0;
										if (U->Get_AssignCount(pass, x[n3], x1) == 0) {
											int m = 0;
											cout << "Enter the Maximun Assignments Number that can be Taken : ";
											cin >> m;
											U->Set_Assign_capacity(pass, x[n3], x1, m);
										}
										cout << endl << "Enter the Numbers of Assignment " << U->Get_AssignCount(pass, x[n3], x1) + 1 << " : ";
										cin >> number;
										cout << "Enter the Total Marks of Assignment " << U->Get_AssignCount(pass, x[n3], x1) + 1 << " : ";
										cin >> number1;
										cout << "Enter the Weightage of Assignment " << U->Get_AssignCount(pass, x[n3], x1) + 1 << " : ";
										cin >> number2;

										U->Add_Assignments(pass, x[n3], x1, number);
										U->Add_Assignment_weightage(pass, x[n3], x1, number2);
										U->Add_T_Marks_Assignments(pass, x[n3], x1, number1);

									}

									if (a == 2) {

										int number = 0;
										int number1 = 0;
										int number2 = 0;
										if (U->Get_QuizCount(pass, x[n3], x1) == 0) {
											int m = 0;
											cout << "Enter the Maximum Quizes Number that can be Taken : ";
											cin >> m;
											U->Set_Quiz_capacity(pass, x[n3], x1, m);
										}
										cout << endl << "Enter the Numbers of Quiz " << U->Get_QuizCount(pass, x[n3], x1) + 1 << " : ";
										cin >> number;
										cout << "Enter the Total Marks of Quiz " << U->Get_QuizCount(pass, x[n3], x1) + 1 << " : ";
										cin >> number1;
										cout << "Enter the Weightage of Quiz " << U->Get_QuizCount(pass, x[n3], x1) + 1 << " : ";
										cin >> number2;

										U->Add_Quizes(pass, x[n3], x1, number);
										U->Add_Quiz_weightage(pass, x[n3], x1, number2);
										U->Add_T_Marks_Quizes(pass, x[n3], x1, number1);

									}

									if (a == 3) {

										int number = 0;
										int number1 = 0;
										int number2 = 0;
										cout << endl << "Enter the Obtained Marks of Mid : ";
										cin >> number;
										cout << "Enter the Total Marks of Mid : ";
										cin >> number1;
										cout << "Enter the Weightage of Mid : ";
										cin >> number2;

										U->Set_Mid(pass, x[n3], x1, number);
										U->Add_Mid_weightage(pass, x[n3], x1, number2);
										U->Add_T_Marks_Mid(pass, x[n3], x1, number1);

									}

									if (a == 4) {

										int number = 0;
										int number1 = 0;
										int number2 = 0;
										cout << endl << "Enter the Obtained Marks of Final : ";
										cin >> number;
										cout << "Enter the Total Marks of Final : ";
										cin >> number1;
										cout << "Enter the Weightage of Final : ";
										cin >> number2;

										U->Set_Final(pass, x[n3], x1, number);
										U->Add_Final_weightage(pass, x[n3], x1, number2);
										U->Add_T_Marks_Final(pass, x[n3], x1, number1);

									}

								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 4) {

								int a = 0, n1 = 0, n2 = 0, n3 = 0;
								int* x = 0;
								int x1 = 0;

								for (int k = 0; k < U->Get_Assign_Courses_Count(pass, teacher - 1); k++) {
									cout << k + 1 << "   --> " << U->Get_Assign_courses_TC(pass, teacher - 1, k) << "   " << U->Get_Assign_Courses_TN(pass, teacher - 1, k) << endl;
								}

							N3:
								cout << endl << "Select Teacher Course : ";
								cin >> n;

								if (n < 1 || n > U->Get_Assign_Courses_Count(pass, teacher - 1)) {
									cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
									goto N3;
								}

								x = U->find_Student_Courses_Index(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));
								x1 = U->find_1S_Course(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));

								if (x[0] == 1) {

									cout << endl << "   -No Student is Registered in this Course-" << endl << endl;

								}

								else {

									for (int k = 1; k < x[0]; k++) {
										cout << k << " --> " << U->GetStudentCode(pass, x[k]) << " , " << U->GetStudentName(pass, x[k]) << endl;
									}

								N0:
									cout << endl << "Select Student : ";
									cin >> n3;

									if (n3 < 1 || n3 > x[0]) {
										cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
										goto N0;
									}

									system("CLS");

									cout << endl << "   -View Evaluation-" << endl << endl;
									cout << "   1 --> View Assignments" << endl;
									cout << "   2 --> View Quizes" << endl;
									cout << "   3 --> View Mid" << endl;
									cout << "   4 --> View Final" << endl << endl;

								R1:
									cout << "Enter Your Choice : ";
									cin >> a;

									if (a < 1 || a > 4) {
										cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
										goto R1;
									}

									if (a == 1) {

										int number = 0;
										if (U->Get_AssignCount(pass, x[n3], x1) == 0) {
											cout << endl << "   -No Assignments Marks Are Found-" << endl;
										}
										else {

											cout << endl << "Number of Assignments Are : " << endl;
											cout << endl << "   Assignments        Obtained Marks        Total Marks        Weightage" << endl << endl;
											for (int k = 0; k < U->Get_AssignCount(pass, x[n3], x1); k++) {

												cout << "     " << k + 1 << "                     " << U->Get_TotalAssignments(pass, x[n3], x1)[k] << "                    " << U->Get_T_Marks_Assignment(pass, x[n3], x1)[k] << "                 " << U->Get_Assignment_weightage(pass, x[n3], x1)[k] << endl;

											}

											cout << endl;

										}

									}

									if (a == 2) {

										int number = 0;
										if (U->Get_QuizCount(pass, x[n3], x1) == 0) {
											cout << endl << "   -No Quizes Marks Are Found-" << endl;
										}
										else {

											cout << endl << "Number of Quizes Are : " << U->Get_QuizCount(pass, x[n3], x1) << endl;
											cout << endl << "   Quizes        Obtained Marks        Total Marks        Weightage" << endl << endl;
											for (int k = 0; k < U->Get_QuizCount(pass, x[n3], x1); k++) {

												cout << "     " << k + 1 << "                 " << U->Get_TotalQuizes(pass, x[n3], x1)[k] << "                    " << U->Get_T_Marks_Quizes(pass, x[n3], x1)[k] << "                 " << U->Get_Quiz_weightage(pass, x[n3], x1)[k] << endl;

											}

											cout << endl;

										}

									}

									if (a == 3) {

										if (U->Get_Mid(pass, x[n3], x1) == 0) {
											cout << endl << "No Marks of Mid is Found : " << endl;
										}
										else {
											//cout << endl << "The Numbers of Mid : " << U->Get_Mid(pass, x[n3], x1) << endl;
											cout << endl << "   Mid        Obtained Marks        Total Marks        Weightage" << endl << endl;
											cout << "   1                 " << U->Get_Mid(pass, x[n3], x1) << "                  " << U->Get_T_Marks_Mid(pass, x[n3], x1) << "               " << U->Get_Mid_weightage(pass, x[n3], x1) << endl;
										}
										cout << endl;

									}

									if (a == 4) {



										if (U->Get_Final(pass, x[n3], x1) == 0) {
											cout << endl << "No Marks of Final is Found : " << endl;
										}
										else {
											//cout << endl << "The Numbers of Finals : " << U->Get_Mid(pass, x[n3], x1) << endl;
											cout << endl << "   Final        Obtained Marks        Total Marks        Weightage" << endl << endl;
											cout << "     1                 " << U->Get_Final(pass, x[n3], x1) << "                  " << U->Get_T_Marks_Final(pass, x[n3], x1) << "               " << U->Get_Final_weightage(pass, x[n3], x1) << endl;
										}
										cout << endl;
									}
								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 5) {

								system("CLS");

								int n = 0, n3 = 0;
								int* x = 0;
								int x1 = 0;

								for (int k = 0; k < U->Get_Assign_Courses_Count(pass, teacher - 1); k++) {
									cout << k + 1 << "   --> " << U->Get_Assign_courses_TC(pass, teacher - 1, k) << "   " << U->Get_Assign_Courses_TN(pass, teacher - 1, k) << endl;
								}

							N4:
								cout << endl << "Select Teacher Course : ";
								cin >> n;

								if (n < 1 || n > U->Get_Assign_Courses_Count(pass, teacher - 1)) {
									cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
									goto N4;
								}

								x = U->find_Student_Courses_Index(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));
								x1 = U->find_1S_Course(pass, U->Get_Assign_courses_TC(pass, teacher - 1, n - 1));

								if (x[0] == 1) {

									cout << endl << "   -No Student is Registered in this Course-" << endl << endl;

								}

								else {

									for (int k = 1; k < x[0]; k++) {
										cout << k << " --> " << U->GetStudentCode(pass, x[k]) << " , " << U->GetStudentName(pass, x[k]) << endl;
									}

								N5:
									cout << endl << "Select Student : ";
									cin >> n3;

									if (n3 < 1 || n3 > x[0]) {
										cout << "   -You Have Entered Wrong Choice......Please Re-Enter- " << endl;
										goto N5;
									}
									char str[10];

									cout << endl << "Enter The Grade To Assign to Student in this Course : ";
									cin >> str;

									if (U->Assign_Grade(pass, x[n3], x1, str) == 1) {
										cout << endl << "-The Grade is Successfully Assigned-" << endl << endl;
									}
									else if (U->Assign_Grade(pass, x[n3], x1, str) == 0) {
										cout << endl << "-The Grade is not Successfully Assigned-" << endl << endl;
									}

								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 6) {

								system("CLS");

								cout << endl << "      -Logged Out Succesfully-" << endl <<endl;

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

								break;
							}

						}
					}
				}
			}

			if (s_in == 4) {

				count = 0;
				int student = 0;

				cout << endl;

				for (int i = 0; i < U->GetStudentCount(d - 1); i++) {
					cout << "   " << i + 1 << " --> " << U->GetStudentCode(d - 1, i) << "  " << U->GetStudentName(d - 1, i) << endl;
				}

				cout << endl << "Enter Student : ";
				cin >> student;

				cout << "For LOGIN : " << endl;

				cout << endl << "Default Password : " << U->GetSPass(d - 1, student - 1) << endl << endl;

				cout << "Enter the Password :";

				cin.get();

				cin.get(password, 50);

				system("CLS");

				for (int i = student - 1; i < student; i++) {
					
					for (int j = 0; j < strlen(password); j++)
					{
						if (password[j] == U->GetSPass(d-1,i)[j])
						{
							count++;
						}
					}
				}

				/*cout << "For LOGIN : " << endl;
				cout << "Enter the Password :";

				cin.get();

				cin.get(password, 50);*/

				//T_Rfile = P_T_fileRead(Pass_T_File, U);

				

				if ((strlen(password) == strlen(U->GetSPass(d - 1, student - 1))) && (strlen(password) == count))
				{

					for (int pass = d - 1; pass < d; pass++) {
						count = 0;



						/*if ((strlen(password) == strlen(U->GetHODPassword(pass))) && (strlen(password) == count))
						{*/

						cout << endl;
						cout << "----------------- WELCOME " << U->GetStudentName(pass, student - 1) << " -----------------" << endl << endl;

						for (int A = 0; A < 50; A++) {

							int n;
							cout << "Signed IN" << endl << endl;
							cout << "   1 --> Register Course" << endl;
							cout << "   2 --> UnRegister Course" << endl;
							cout << "   3 --> WithDraw Course" << endl;
							cout << "   4 --> View Marksheet of A Particular Course" << endl;
							cout << "   5 --> View Attendence of A Particular Course" << endl;
							cout << "   6 --> Change Password" << endl;
							cout << "   7 --> LOG OUT" << endl << endl;
						Again5:
							cout << "Enter your OPtion : ";
							cin >> n;

							if ((n < 1) || (n > 7)) {
								system("CLS");

								cout << endl;
								cout << "      -You Have Entered Wrong Choice....Please Enter Again-" << endl << endl;
								goto Again5;
							}

							if (n == 1) {

								system("CLS");

								//int n2;
								int n1;
								
							//	cout << endl;
							//	for (int k = 0; k < U->GetStudentCount(pass); k++) {
							//		cout << "   " << k + 1 << " --> " << U->GetStudentCode(pass, k) << " , " << U->GetStudentName(pass, k) << endl;
							//	}
							//	cout << endl << "Select Student : ";
							//	
							//st3:
							//	cin >> n2;

							//	if (n2 > U->GetStudentCount(pass) || n2 < 0) {
							//		cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
							//		goto st3;
							//	}

								cout << endl;

								for (int k = 0; k < U->GetCourseCount(pass); k++) {
									cout << k + 1 << " --> " << U->GetCourseCode(pass, k) << " , " << U->GetCourseName(pass, k) << endl;
								}

								cout << "Select Course : ";
							st4:
								cin >> n1;
								if (n1 > U->GetCourseCount(pass) || n1 < 0) {
									cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
									goto st4;
								}

								U->Register_Course_for_Students(pass, student - 1, U->GetCourseName(pass, n1 - 1), U->GetCourseCode(pass, n1 - 1));
								
								cout << endl << "-The Course is Registered Successfully-" << endl << endl;

								C_S_fileSave(Registered_Student_Courses, U);

							}

							if (n == 2) {

								system("CLS");

								//int n2;
								int n1;
								//cin.get();

								//cout << endl << U->GetTeacherCount(pass);
							//	cout << endl;
							//	for (int k = 0; k < U->GetStudentCount(pass); k++) {
							//		cout << "   " << k + 1 << " --> " << U->GetStudentCode(pass, k) << " , " << U->GetStudentName(pass, k) << endl;
							//	}
							//	cout << endl << "Select Student : ";
							//	//cin.get();
							//s4:
							//	cin >> n2;

							//	if (n2 > U->GetStudentCount(pass) || n2 < 0) {
							//		cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
							//		goto s4;
							//	}

								cout << endl;

								if (U->Get_Registration_courses_count(pass, student - 1) == 0) {
									cout << "-No Course is Registered-" << endl << endl;
								}

								else {
									for (int k = 0; k < U->Get_Registration_courses_count(pass, student - 1); k++) {
										cout << k + 1 << " --> " << U->Get_Assign_courses_SC(pass, student - 1, k) << " , " << U->Get_Assign_courses_SN(pass, student - 1, k) << endl <<endl;
									}

									cout << "Select Course : ";
								s3:
									cin >> n1;
									if (n1 > U->Get_Registration_courses_count(pass, student - 1) || n1 < 0) {
										cout << endl << "-You have Entered Wrong Choice....Please Re-Enter Again-" << endl;
										goto s3;
									}

									U->UnRegister_Course_for_Students(pass, student - 1, U->Get_Assign_courses_SC(pass, student - 1, n1 - 1));
									cout << endl << "-The Course is Un-Registered Successfully-" << endl << endl;

									
								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 3) {

								system("CLS");

								int a = 0;

								if (U->Get_Registration_courses_count(pass, student - 1) == 0) {
									cout << endl << "  -No Course is Registered Yet-" << endl << endl;
								}
								else {
									for (int k = 0; k < U->Get_Registration_courses_count(pass, student - 1); k++) {
										if (U->Get_Registration_courses_count(pass, student - 1) == 0) {
											cout << endl << "   -No Course is Registered Yet-" << endl << endl;
											break;
										}
										else {

											cout << "   " << k + 1 << " --> " << U->Get_Assign_courses_SC(pass, student - 1, k) << "   " << U->Get_Assign_courses_SN(pass, student - 1, k) << endl;

										}
									}

									cout << "Select Course : ";
									cin >> a;
									if (U->Get_Attendence_count(pass, student - 1, a - 1) < 10) {
										if (U->UnRegister_Course_for_Students(pass, student - 1, U->Get_Assign_courses_SC(pass, student - 1, a - 1)) == 1) {
											/*char str[] = "W";
											U->Assign_Grade(pass, student - 1, a - 1, str);*/
											cout << endl << "   -The Course is Successfully Withdrawed-" << endl << endl;
										}

										else if (U->UnRegister_Course_for_Students(pass, student - 1, U->Get_Assign_courses_SC(pass, student - 1, a - 1)) == 0) {
											cout << endl << "   -The Course is not Successfully Withdrawed-" << endl << endl;
										}
									}
									else {
										cout << endl << "-The time has ended for withdraw-" << endl << endl;
									}
								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);
							}

							if (n == 4) {

								system("CLS");

								if (U->Get_Registration_courses_count(pass, student - 1) == 0) {
									cout << endl << "   -No Course is Registered-" << endl << endl;
								}
								else {
									for (int k = 0; k < U->Get_Registration_courses_count(pass, student - 1); k++) {

										cout << endl << "    < Course " << U->Get_Assign_courses_SN(pass, student-1, k) << " Record >" << endl << endl;
										/*cout << endl << "   -Attendence- " << endl << endl;
										if (U->Get_Attendence(pass, student - 1, k) == nullptr) {
											cout << endl << "No Record for Attendence is found" << endl << endl;
										}
										else {
											cout << endl;
											for (int attend = 0; attend < U->Get_Attendence_count(pass, student - 1, k); attend++) {

												cout << "   " << U->Get_Attendence(pass, student - 1, k)[attend] << "   " << U->Get_Date(pass, student - 1, k, attend) << endl;

											}
										}*/

										cout << endl << "   -Assignments- " << endl << endl;
										if (U->Get_AssignCount(pass, student-1, k) == 0) {
											cout << endl << "   -No Assignments Marks Are Found-" << endl;
										}
										else {

											cout << endl << "Number of Assignments Are : " << U->Get_AssignCount(pass, student - 1, k) << endl;
											cout << endl << "   Assignments        Obtained Marks        Total Marks        Weightage" << endl << endl;
											for (int sh = 0; sh < U->Get_AssignCount(pass, student - 1, k); sh++) {

												cout << "     " << sh + 1 << "                     " << U->Get_TotalAssignments(pass, student - 1, k)[sh] << "                 " << U->Get_T_Marks_Assignment(pass, student - 1, k)[sh] << "             " << U->Get_Assignment_weightage(pass, student - 1, k)[sh] << endl;

											}

											cout << endl;

										}

										cout << endl << "   -Quizes- " << endl << endl;
										if (U->Get_QuizCount(pass, student - 1, k) == 0) {
											cout << endl << "   -No Quizes Marks Are Found-" << endl;
										}
										else {

											cout << endl << "Number of Quizes Are : " << U->Get_QuizCount(pass, student - 1, k) << endl;
											cout << endl << "   Quizes        Obtained Marks        Total Marks        Weightage" << endl << endl;
											for (int q = 0; q < U->Get_QuizCount(pass, student - 1, k); q++) {

												cout << "     " << q + 1 << "                 " << U->Get_TotalQuizes(pass, student - 1, k)[q] << "                 " << U->Get_T_Marks_Quizes(pass, student - 1, k)[q] << "             " << U->Get_Quiz_weightage(pass, student - 1, k)[q] << endl;

											}

											cout << endl;

										}

										cout << endl << "   -Mid- " << endl << endl;
										if (U->Get_Mid(pass, student - 1, k) == 0) {
											cout << endl << "No Marks of Mid is Found : " << endl;
										}
										else {
											//cout << endl << "The Numbers of Mid : " << U->Get_Mid(pass, x[n3], x1) << endl;
											cout << endl << "   Mid        Obtained Marks        Total Marks        Weightage" << endl << endl;
											cout << "   1                 " << U->Get_Mid(pass, student - 1, k) << "                  " << U->Get_T_Marks_Mid(pass, student - 1, k) << "               " << U->Get_Mid_weightage(pass, student - 1, k) << endl;
										}
										cout << endl;

										cout << endl << "   -Final- " << endl << endl;
										if (U->Get_Final(pass, student - 1, k) == 0) {
											cout << endl << "No Marks of Final is Found : " << endl;
										}
										else {
											//cout << endl << "The Numbers of Finals : " << U->Get_Mid(pass, x[n3], x1) << endl;
											cout << endl << "   Final        Obtained Marks        Total Marks        Weightage" << endl << endl;
											cout << "     1                 " << U->Get_Final(pass, student - 1, k) << "                  " << U->Get_T_Marks_Final(pass, student - 1, k) << "               " << U->Get_Final_weightage(pass, student - 1, k) << endl;
										}
										cout << endl;

									}
								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 5) {

								system("CLS");

								if (U->Get_Registration_courses_count(pass, student - 1) == 0) {
									cout << endl << "   -No Course is Registered Yet-" << endl << endl;
								}
								else {
									for (int k = 0; k < U->Get_Registration_courses_count(pass, student - 1); k++) {

										cout << endl << "    -Course " << U->Get_Assign_courses_SN(pass, student - 1, k) << " Record-" << endl << endl;
										cout << endl << "   -Attendence- " << endl << endl;
										;										if (U->Get_Attendence_count(pass, student - 1, k) == 0) {
											cout << endl << "No Record for Attendence is found" << endl << endl;
										}
										else {
											cout << endl;
											for (int attend = 0; attend < U->Get_Attendence_count(pass, student - 1, k); attend++) {

												cout << "   " << U->Get_Attendence(pass, student - 1, k)[attend] << "   " << U->Get_Date(pass, student - 1, k, attend) << endl;

											}
										}
									}
								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 6) {

								system("CLS");

								if (U->ChangePassword(pass, student - 1) == 1) {
									cout << endl << "   -Password is Successfully Changed-" << endl;
								}
								else if (U->ChangePassword(pass, student - 1) == 0) {
									cout << endl << "   -Password is not Successfully Changed-" << endl;
								}

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

							}

							if (n == 7) {

								system("CLS");

								cout << endl << "   -Logged Out Successfully-" << endl << endl;

								Ofile(filename, U);
								C_S_fileSave(Registered_Student_Courses, U);
								P_T_fileSave(Pass_T_File, U);
								C_T_fileSave(Courses_T_file, U);
								P_s_fileSave(Pass_S_File, U);
								P_it_fileSave(Pass_IT_File, U);
								Attendence_S_fileSave(Attendence_S_File, U);
								Assignment_S_fileSave(Assignments_S_File, U);
								Quiz_S_fileSave(Quizes_S_File, U);
								Mid_S_fileSave(Mid_S_File, U);
								Final_S_fileSave(Final_S_File, U);
								Grades_S_fileSave(Grades_S_File, U);

								break;

							}

						}

					}
				}


			}

			if (s_in == 5)
			{
				system("CLS");
				cout << endl << "    -EXIT SUCCESSFULLY-" << endl << endl;
				break;
			}

		}
	}

	Ofile(filename, U);		
	C_S_fileSave(Registered_Student_Courses, U);
	P_T_fileSave(Pass_T_File, U);
	C_T_fileSave(Courses_T_file, U);
	P_s_fileSave(Pass_S_File, U);
	P_it_fileSave(Pass_IT_File, U);
	Attendence_S_fileSave(Attendence_S_File, U);
	Assignment_S_fileSave(Assignments_S_File, U);
	Quiz_S_fileSave(Quizes_S_File, U);
	Mid_S_fileSave(Mid_S_File, U);
	Final_S_fileSave(Final_S_File, U);
	Grades_S_fileSave(Grades_S_File, U);

	return 0;

}