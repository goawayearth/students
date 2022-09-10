#include<iostream>
#include<fstream>
using namespace std;
#include"operat.h"
#include"stud.h"

//class stud;
void operat::show_menu() {
	cout << "******************************************************" << endl;
	cout << "----------------欢迎使用学生成绩管理系统---------------" << endl;
	cout << "    *          【1】新增学生信息                  *    " << endl;
	cout << "    *          【2】查找学生信息                  *    " << endl;
	cout << "    *          【3】修改学生信息                  *    " << endl;
	cout << "    *          【4】修改学生成绩                  *    " << endl;
	cout << "    *          【5】删除学生成绩                  *    " << endl;
	cout << "    *          【6】插入学生成绩                  *    " << endl;
	cout << "    *          【7】按平均分排列                  *    " << endl;
	cout << "    *          【8】显示学生成绩                  *    " << endl;
	cout << "    *          【0】退出管理系统                  *    " << endl;
	cout << "******************************************************" << endl;
	cout << "请输入您想要执行的操作: ";
}

int operat::get_choice() {
	int choice;
	cin >> choice;
	return choice;
}


void operat::input_data(stud students[]) {
	//输入学生信息
	int n;
	cout << "请输入新增学生的个数: ";
	cin >> n;
	int m = students[0].show_n();
	string NAME,NUM;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入学生"<<i+1<<"的姓名和学号" << ":";
		cin >> NAME >> NUM;
		students[m].set_name(NAME);
		students[m].set_num(NUM);
		students[m].setCourse();
		students[m].set_sum();
		students[m].set_aver();
		m++;
	}
	students[0].set_n(m);
	
}
void operat::search(stud students[]) {
	//查找学生信息
	string NAME;
	int n = students[0].show_n();
	cout << "请输入要查找的学生姓名或学号:";
	cin >> NAME;
	for (int i = 0; i < n; i++)
	{
		if (students[i].show_name() == NAME||students[i].show_num()==NAME) {
			cout << NAME << " 信息如下："<< endl;
			cout << "姓名\t\t学号\t\t";
			int n = students[0].courses[0].showCourse_n();
			for (int j = 0; j < n; j++) {
				cout << students[i].courses[j].show_course_name() << "\t\t";
			}
			cout << endl;
			cout << students[i].show_name() << "\t\t" << students[i].show_num() << "\t\t";
			for (int j = 0; j < n; j++) {
				cout << students[i].courses[j].show_course_grade() << "\t\t";
			}
			cout << endl<<endl<<endl;
			return;
		}
	}
	cout << "查无此人\n\n\n";
}
void operat::end(stud* students) {
	cout << "感谢使用，再见！" << endl;
	//cout << students[1].courses[0].show_course_name() << endl;
	operat::writeFile(students);
	exit(0);
}
void operat::readFile(stud students[]) {
	ifstream infile("student.txt", ios::in);
	if (!infile) {
		cerr << "打开失败" << endl; exit(1);
	}
	int n;
	infile >> n;
	students[0].set_n(n);
	string Name; string Num; int num;
	for(int i=0;i<n;i++) {
		infile >> Name >> Num>>num; 
		int mmp = num;
		students[i].set_name(Name);
		 students[i].set_num(Num);
		 students[i].courses[0].setCourse_n(num);
		 double numm;
		 for (int j = 0; j < mmp; j++) {
			 infile >> Name >> Num >> numm;
			 students[i].courses[j].set_course_name(Name);
			 students[i].courses[j].set_course_number(Num);
			 students[i].courses[j].set_course_grade(numm);
		 }
		 students[i].set_sum();
		 students[i].set_aver();
	}
	infile.close();
}
void operat::writeFile(stud students[]) {
	ofstream outfile("student.txt", ios::out);
	if (!outfile) {
		cerr << "打开失败" << endl; exit(1);
	}
	outfile << students[0].show_n()<<endl;
	for (int i = 0; i < students[0].show_n(); i++) {
		outfile << students[i].show_name()<<" ";
		outfile<< students[i].show_num() <<" ";
		outfile << students[i].courses[0].showCourse_n() << " ";
		for (int j = 0; j < students[i].courses[0].showCourse_n(); j++) {
			outfile << students[i].courses[j].show_course_name()<<" ";
			//cout << students[i].courses[i].show_course_name() << " ";
			outfile << students[i].courses[j].show_course_number() << " ";
			outfile << students[i].courses[j].show_course_grade ()<< " ";
		}
		outfile << endl;
	}
	outfile.close();
}

void operat::modif(stud students[]) {
	//根据学号或姓名修改学生信息
	cout << "请输入需要修改的学生姓名或学号：";
	string temp;
	cin >> temp;
	for (int i = 0; i < students[0].show_n(); i++) {
		if (students[i].show_name() == temp || students[i].show_num() == temp) {
			cout << "请重新输入学生姓名与学号：";
			string NAME, NUM;
			cin >> NAME >> NUM;
			students[i].set_name(NAME);
			students[i].set_num(NUM);
			students[i].setCourse();
			break;
		}
	}
}

void operat::gradeShow(stud students[]) {
	int n = students[0].show_n();
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (students[j].show_aver() < students[j + 1].show_aver()) {
				stud temp;
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}students[0].set_n(n);
	cout << "姓名\t\t" << "学号\t\t" << "总成绩\t\t" << "平均成绩" << endl;
	for (int i = 0; i < n; i++) {
		cout << students[i].show_name() << "\t\t" << students[i].show_num() << "\t\t" << students[i].show_sum() << "\t\t" << students[i].show_aver()<<endl;
	}
	cout << endl << endl << endl;
}
