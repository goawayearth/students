#include<iostream>
#include<fstream>
using namespace std;
#include"operat.h"
#include"stud.h"
#include<Windows.h>
void operat::show_menu() {
	cout << "******************************************************" << endl;
	cout << "----------------欢迎使用学生成绩管理系统---------------" << endl;
	cout << "    *          【1】新增学生信息                  *    " << endl;
	cout << "    *          【2】查找学生信息                  *    " << endl;
	cout << "    *          【3】修改学生信息                  *    " << endl;
	cout << "    *          【4】按平均分排名                  *    " << endl;
	cout << "    *          【5】删除学生成绩                  *    " << endl;
	cout << "    *          【6】查看选课信息                  *    " << endl;
	cout << "    *          【7】选课成绩排名                  *    " << endl;
	cout << "    *          【0】退出管理系统                  *    " << endl;
	cout << "******************************************************" << endl;
	cout << "请输入您想要执行的操作: ";
}

int operat::get_choice() {
	int choice;
	cin >> choice;
	if (!(choice >= 0 && choice < 8)) {
		cout << "所选功能不存在，请重新选择：";
		cin >> choice;
	}
	return choice;
}


void operat::input_data(stud students[]) {
	//输入学生信息
	int n;
	cout << "请输入新增学生的个数: ";
	cin >> n;
	if (n > 50) {
		cout << "输入错误，请重新输入新增学生个数：";
		cin >> n;
	}
	int m = stud::show_n();
	string NAME, NUM;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入学生" << i + 1 << "的姓名和学号" << ":";
		cin >> NAME >> NUM;
		students[m].set_name(NAME);
		students[m].set_num(NUM);
		students[m].setCourse();
		students[m].set_sum();
		students[m].set_aver();
		m++;
	}
	stud::set_n(m);

}
void operat::search(stud students[]) {
	//查找学生信息
	string NAME;
	int n = stud::show_n();
	cout << "请输入要查找的学生姓名或学号:";
	cin >> NAME;
	for (int i = 0; i < n; i++)
	{
		if (students[i].show_name() == NAME || students[i].show_num() == NAME) {
			cout << NAME << " 信息如下：" << endl;
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
			cout << endl << endl << endl;
			return;
		}
	}
	cout << "查无此人" << endl << endl;
}
void operat::end(stud* students) {
	cout << "感谢使用，再见！" << endl;
	writeFile(students); exit(0);
}
void operat::readFile(stud students[]) {
	ifstream infile("student.txt", ios::in);
	if (!infile) {
		cerr << "打开失败" << endl; exit(1);
	}
	int mn; string pass, acc;
	infile >> mn;
	password::setN(mn);
	for (int i = 0; i < mn; i++) {
		infile >> acc >> pass;
		passw[i].setAccount(acc, pass);
	}
	int n;
	infile >> n;
	stud::set_n(n);
	string Name; string Num; int num;
	for (int i = 0; i < n; i++) {
		infile >> Name >> Num >> num;
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
	outfile << password::showN() << endl;
	for (int i = 0; i < password::showN(); i++) {
		outfile << passw[i].showAccount() << " " << passw[i].showPass() << endl;
	}

	outfile << stud::show_n() << endl;
	for (int i = 0; i < stud::show_n(); i++) {
		outfile << students[i].show_name() << " ";
		outfile << students[i].show_num() << " ";
		outfile << students[i].courses[0].showCourse_n() << " ";
		for (int j = 0; j < students[i].courses[0].showCourse_n(); j++) {
			outfile << students[i].courses[j].show_course_name() << " ";
			outfile << students[i].courses[j].show_course_number() << " ";
			outfile << students[i].courses[j].show_course_grade() << " ";
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
	for (int i = 0; i < stud::show_n(); i++) {
		if (students[i].show_name() == temp || students[i].show_num() == temp) {
			cout << "请重新输入学生姓名与学号：";
			string NAME, NUM;
			cin >> NAME >> NUM;
			students[i].set_name(NAME);
			students[i].set_num(NUM);
			students[i].setCourse();
			students[i].set_sum();
			students[i].set_aver();
			break;
		}
	}
	cout << endl << endl;
}

void operat::gradeShow(stud students[]) {
	int n = stud::show_n();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (students[j].show_aver() < students[j + 1].show_aver()) {
				stud temp;
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}
	cout << "姓名\t\t" << "学号\t\t" << "平均成绩\t" << "总成绩\t\t" << "选课情况" << endl;
	for (int i = 0; i < n; i++) {
		cout << students[i].show_name() << "\t\t" << students[i].show_num() << "\t\t"
			<< students[i].show_aver() << "\t\t" << students[i].show_sum() << "\t\t";
		for (int e = 0; e < students[i].courses[0].showCourse_n(); e++) {
			cout << students[i].courses[e].show_course_name() << ":" << students[i].courses[e].show_course_grade() << "\t\t";
		}
		cout << endl;
	}

	cout << endl << endl;
}

void operat::delete_st(stud students[]) {
	cout << "请输入要删除的姓名或学号：";
	string find; cin >> find;
	int n = stud::show_n();
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (students[i].show_name() == find || students[i].show_num() == find) {
			flag = true;cout << "删除成功！" << endl;
			for (int j = i; j < n - 1; j++) {
				students[j] = students[j + 1];
				
			}
			n--;
			stud::set_n(n);
		}
	}
	if (!flag)cout << "查无此人！" << endl;
	cout << endl << endl;
}

void operat::course_find(stud students[])//按照课程名称或者编号查找学生姓名，学号，成绩
{
	cout << "请输入查找的课程名称或编号：";
	string infor;
	cin >> infor;
	bool flag = false;
	cout << "选课学生信息如下：" << endl;
	for (int i = 0; i < stud::show_n(); i++) {
		for (int j = 0; j < students[i].courses[0].showCourse_n(); j++) {
			if (students[i].courses[j].show_course_name() == infor ||
				students[i].courses[j].show_course_number() == infor) {
				flag = true;
			}
		}
	}
	if (!flag) {
		cout << "无学生选择此课！";
	}
	else {
		cout << "姓名\t\t学号\t\t成绩" << endl;
		for (int i = 0; i < stud::show_n(); i++) {
			for (int j = 0; j < students[i].courses[0].showCourse_n(); j++) {
				if (students[i].courses[j].show_course_name() == infor ||
					students[i].courses[j].show_course_number() == infor) {
					cout << students[i].show_name() << "\t\t" << students[i].show_num() << "\t\t"
						<< students[i].courses[j].show_course_grade() << endl;
				}
			}
		}
	}
}


void operat::course_show(stud students[])//按照课程名称或者编号输出学生姓名，学号，成绩，并给出平均分
{
	cout << "请输入课程名称或编码：";
	string infor;
	cin >> infor;
	struct tem {
		string name;
		string numb;
		int grade;
	};
	tem st[500]; int p = 0;
	for (int i = 0; i < stud::show_n(); i++) {
		for (int j = 0; j < students[0].courses[0].showCourse_n(); j++) {
			if (students[i].courses[j].show_course_name() == infor ||
				students[i].courses[j].show_course_number() == infor) {
				st[p].name = students[i].show_name();
				st[p].numb = students[i].show_num();
				st[p].grade = students[i].courses[j].show_course_grade();
				p++;
			}
		}
	}
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p - i; j++) {
			if (st[j].grade < st[j + 1].grade) {
				tem temp;
				temp = st[j];
				st[j] = st[j + 1];
				st[j + 1] = temp;
			}
		}
	}
	cout << "选课学生排名为：" << endl;
	cout << "姓名\t\t学号\t\t成绩" << endl;
	for (int i = 0; i < p; i++) {
		cout << st[i].name << "\t\t" << st[i].numb << "\t\t" << st[i].grade << endl;
	}
}

void operat::signIn() {
	cout << "1:登录学生管理系统\n2:注册新账号\n请输入你的选择：";
	int choice; bool flag = false;
	cin >> choice;
	string pass, acct;
	if (choice == 1)
		while (!flag) {
			system("cls");
			cout << "请输入您的账号:";

			cin >> acct;
			cout << "请输入您的密码:";
			cin >> pass;
			for (int i = 0; i < password::showN(); i++) {
				if (passw[i].showAccount() == acct && passw[i].showPass() == pass) {
					flag = true;
					system("cls");
					cout << "正在登陆...";
					Sleep(1000);
					return;
				}
			}
			if (!flag) {
				cout << "账号或密码错误！ 请重新输入！";
				system("pause");
			}
		}
	else {
		cout << "请输入您的手机号或学工号：";
		cin >> acct;
		cout << "请设置密码：";
		cin >> pass;
		passw[password::showN()].setAccount(acct, pass);
		password::setN(password::showN() + 1);
		cout << "账号注册成功！";
		system("pause");
		return;
	}
}

