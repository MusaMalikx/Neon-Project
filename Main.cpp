//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//int strlength(char name[]) {
//	int i = 0;
//	while (name[i++] != '\0');
//	return i;
//}
//
//void main() {
//
//	char name[100];
//	int departments;
//	char infodepart1[100];
//	int departcourse1;
//	char departcourses1[100];
//	char departcoursecodecode1[30];
//	char departcourses2[100];
//	char departcoursecodecode2[30];
//	char departcourses3[100];
//	char departcoursecodecode3[30];
//	int facultynoOfDepart1;
//	int employeeid1;
//	int employeeid2;
//	char employeename1[20];
//	char employeename2[20];
//	int itM;
//	int itemployeeid1;
//	char itemployeename1[20];
//	int noOfS;
//	int roll1;
//	int roll2;
//	int roll3;
//	int roll4;
//	int roll5;
//	int roll6;
//	char Sname1[30];
//	char Sname2[30];
//	char Sname3[30];
//	char Sname4[30];
//	char Sname5[30];
//	char Sname6[30];
//
//	char infodepart1_[100];
//	int departcourse1_;
//	char departcourses1_[100];
//	char departcoursecodecode1_[30];
//	char departcourses2_[100];
//	char departcoursecodecode2_[30];
//	int facultynoOfDepart1_;
//	int employeeid1_;
//	int employeeid2_;
//	char employeename1_[20];
//	char employeename2_[20];
//	int itM_;
//	int itemployeeid1_;
//	char itemployeename1_[20];
//	int noOfS_;
//	int roll1_;
//	int roll2_;
//	int roll3_;
//	int roll4_;
//	char Sname1_[30];
//	char Sname2_[30];
//	char Sname3_[30];
//	char Sname4_[30];
//
//	ifstream fin;
//	fin.open("Data.txt");
//
//	if (fin.fail()) {
//		cout << "Error in Opening File" << endl;
//	}
//	else {
//		cout << "File Opened" << endl << endl;
//		
//
//		fin.getline(name, 100);
//		//fin.ignore(200, '\n');
//
//		fin >> departments;
//		fin.ignore(200, '\n');
//
//		fin.getline(infodepart1, 100);
//		
//
//		fin >> departcourse1;
//
//		
//		fin.getline(departcoursecodecode1, 30, ',');
//		fin.getline(departcourses1, 100);
//		
//
//		fin.getline(departcoursecodecode2, 30, ',');
//		fin.getline(departcourses2, 100);
//		
//
//		fin.getline(departcoursecodecode3, 30, ',');
//		fin.getline(departcourses3, 100);
//
//		fin >> facultynoOfDepart1;
//		
//		fin >> employeeid1;
//		fin.ignore();
//		fin.getline(employeename1, 30);
//		
//		fin >> employeeid2;
//		fin.ignore();
//		fin.getline(employeename2, 30);
//
//		fin >> itM;
//
//		fin >> itemployeeid1;
//		fin.ignore();
//		fin.getline(itemployeename1, 30);
//
//		fin >> noOfS;
//		fin >> roll1;
//		fin.getline(Sname1, 30);
//
//		fin >> roll2;
//		fin.getline(Sname2, 30);
//
//		fin >> roll3;
//		fin.getline(Sname3, 30);
//
//		fin >> roll4;
//		fin.getline(Sname4, 30);
//
//		fin >> roll5;
//		fin.getline(Sname5, 30);
//
//		fin >> roll6;
//		fin.getline(Sname6, 30);
//
//		fin.getline(infodepart1_, 500);
//
//
//		fin >> departcourse1_;
//
//
//		fin.getline(departcoursecodecode1_, 30, ',');
//		fin.getline(departcourses1_, 100);
//
//
//		fin.getline(departcoursecodecode2_, 30, ',');
//		fin.getline(departcourses2_, 100);
//
//
//		fin >> facultynoOfDepart1_;
//
//		fin >> employeeid1_;
//		fin.ignore();
//		fin.getline(employeename1_, 30);
//
//		fin >> employeeid2_;
//		fin.ignore();
//		fin.getline(employeename2_, 30);
//
//		fin >> itM_;
//
//		fin >> itemployeeid1_;
//		fin.ignore();
//		fin.getline(itemployeename1_, 30);
//
//		fin >> noOfS_;
//		fin >> roll1_;
//		/*fin.ignore(',');*/
//		fin.getline(Sname1_, 30);
//
//		fin >> roll2_;
//		fin.getline(Sname2_, 30);
//
//		fin >> roll3_;
//		fin.getline(Sname3_, 30);
//
//		fin >> roll4_;
//		fin.getline(Sname4_, 30);
//
//	}
//	fin.close();
//	cout << "University Name : ";
//	for (int i = 0; i < strlength(name); i++) {
//		 cout << name[i];
//	}
//	cout << endl;
//
//	cout << "Departments : " << departments << endl;
//	cout << "1. ";
//	for (int i = 0; i < strlength(infodepart1); i++) {
//		cout << infodepart1[i];
//	}
//	cout << endl;
//
//	cout << "Department Courses : " << departcourse1 << endl;
//
//	cout << "Courses : " ;
//	cout << departcoursecodecode1 << " , " << departcourses1 << endl;
//	cout << departcoursecodecode2 << " , " << departcourses2 << endl;
//	cout << departcoursecodecode3 << " , " << departcourses3 << endl;
//	cout << endl << endl;
//
//	cout << "Faculty Members : " << facultynoOfDepart1 << endl;
//	cout << employeeid1 << " , " << employeename1 << endl;
//	cout << employeeid2 << " , " << employeename2 << endl;
//	cout << endl << endl;
//
//	cout << "IT Managers : " << itM << endl;
//	cout << itemployeeid1 << " , " << itemployeename1 << endl;
//	cout << endl << endl;
//	
//	cout << "Students : " << noOfS << endl;
//	cout << roll1 << ' , ' << Sname1 << endl;
//	cout << roll2 << ' , ' << Sname2 << endl;
//	cout << roll3 << ' , ' << Sname3 << endl;
//	cout << roll4 << ' , ' << Sname4 << endl;
//	cout << roll5 << ' , ' << Sname5 << endl;
//	cout << roll6 << ' , ' << Sname6 << endl;
//	cout << endl << endl;
//	
//	cout << "2. ";
//	for (int i = 0; i < strlength(infodepart1_); i++) {
//		cout << infodepart1_[i];
//	}
//	cout << endl;
//
//	cout << "Department Courses : " << departcourse1_ << endl;
//
//	cout << "Courses : ";
//	cout << departcoursecodecode1_ << " , " << departcourses1_ << endl;
//	cout << departcoursecodecode2_ << " , " << departcourses2_ << endl;
//	cout << endl << endl;
//
//	cout << "Faculty Members : " << facultynoOfDepart1_ << endl;
//	cout << employeeid1_ << " , " << employeename1_ << endl;
//	cout << employeeid2_ << " , " << employeename2_ << endl;
//	cout << endl << endl;
//
//	cout << "IT Managers : " << itM_ << endl;
//	cout << itemployeeid1_ << " , " << itemployeename1_ << endl;
//	cout << endl << endl;
//
//	cout << "Students : " << noOfS_ << endl;
//	cout << roll1_ << ' , ' << Sname1_ << endl;
//	cout << roll2_ << ' , ' << Sname2_ << endl;
//	cout << roll3_ << ' , ' << Sname3_ << endl;
//	cout << roll4_ << ' , ' << Sname4_ << endl;	
//}