#include<iostream>
#include<fstream>
using namespace std;
#include"operat.h"
#include"stud.h"
#include<Windows.h>
void operat::show_menu() {
	cout << "******************************************************" << endl;
	cout << "----------------��ӭʹ��ѧ���ɼ�����ϵͳ---------------" << endl;
	cout << "    *          ��1������ѧ����Ϣ                  *    " << endl;
	cout << "    *          ��2������ѧ����Ϣ                  *    " << endl;
	cout << "    *          ��3���޸�ѧ����Ϣ                  *    " << endl;
	cout << "    *          ��4����ƽ��������                  *    " << endl;
	cout << "    *          ��5��ɾ��ѧ���ɼ�                  *    " << endl;
	cout << "    *          ��6���鿴ѡ����Ϣ                  *    " << endl;
	cout << "    *          ��7��ѡ�γɼ�����                  *    " << endl;
	cout << "    *          ��0���˳�����ϵͳ                  *    " << endl;
	cout << "******************************************************" << endl;
	cout << "����������Ҫִ�еĲ���: ";
}

int operat::get_choice() {
	int choice;
	cin >> choice;
	if (!(choice >= 0 && choice < 8)) {
		cout << "��ѡ���ܲ����ڣ�������ѡ��";
		cin >> choice;
	}
	return choice;
}


void operat::input_data(stud students[]) {
	//����ѧ����Ϣ
	int n;
	cout << "����������ѧ���ĸ���: ";
	cin >> n;
	if (n > 50) {
		cout << "���������������������ѧ��������";
		cin >> n;
	}
	int m = stud::show_n();
	string NAME, NUM;
	for (int i = 0; i < n; i++)
	{
		cout << "������ѧ��" << i + 1 << "��������ѧ��" << ":";
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
	//����ѧ����Ϣ
	string NAME;
	int n = stud::show_n();
	cout << "������Ҫ���ҵ�ѧ��������ѧ��:";
	cin >> NAME;
	for (int i = 0; i < n; i++)
	{
		if (students[i].show_name() == NAME || students[i].show_num() == NAME) {
			cout << NAME << " ��Ϣ���£�" << endl;
			cout << "����\t\tѧ��\t\t";
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
	cout << "���޴���" << endl << endl;
}
void operat::end(stud* students) {
	cout << "��лʹ�ã��ټ���" << endl;
	writeFile(students); exit(0);
}
void operat::readFile(stud students[]) {
	ifstream infile("student.txt", ios::in);
	if (!infile) {
		cerr << "��ʧ��" << endl; exit(1);
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
		cerr << "��ʧ��" << endl; exit(1);
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
	//����ѧ�Ż������޸�ѧ����Ϣ
	cout << "��������Ҫ�޸ĵ�ѧ��������ѧ�ţ�";
	string temp;
	cin >> temp;
	for (int i = 0; i < stud::show_n(); i++) {
		if (students[i].show_name() == temp || students[i].show_num() == temp) {
			cout << "����������ѧ��������ѧ�ţ�";
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
	cout << "����\t\t" << "ѧ��\t\t" << "ƽ���ɼ�\t" << "�ܳɼ�\t\t" << "ѡ�����" << endl;
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
	cout << "������Ҫɾ����������ѧ�ţ�";
	string find; cin >> find;
	int n = stud::show_n();
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (students[i].show_name() == find || students[i].show_num() == find) {
			flag = true;cout << "ɾ���ɹ���" << endl;
			for (int j = i; j < n - 1; j++) {
				students[j] = students[j + 1];
				
			}
			n--;
			stud::set_n(n);
		}
	}
	if (!flag)cout << "���޴��ˣ�" << endl;
	cout << endl << endl;
}

void operat::course_find(stud students[])//���տγ����ƻ��߱�Ų���ѧ��������ѧ�ţ��ɼ�
{
	cout << "��������ҵĿγ����ƻ��ţ�";
	string infor;
	cin >> infor;
	bool flag = false;
	cout << "ѡ��ѧ����Ϣ���£�" << endl;
	for (int i = 0; i < stud::show_n(); i++) {
		for (int j = 0; j < students[i].courses[0].showCourse_n(); j++) {
			if (students[i].courses[j].show_course_name() == infor ||
				students[i].courses[j].show_course_number() == infor) {
				flag = true;
			}
		}
	}
	if (!flag) {
		cout << "��ѧ��ѡ��˿Σ�";
	}
	else {
		cout << "����\t\tѧ��\t\t�ɼ�" << endl;
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


void operat::course_show(stud students[])//���տγ����ƻ��߱�����ѧ��������ѧ�ţ��ɼ���������ƽ����
{
	cout << "������γ����ƻ���룺";
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
	cout << "ѡ��ѧ������Ϊ��" << endl;
	cout << "����\t\tѧ��\t\t�ɼ�" << endl;
	for (int i = 0; i < p; i++) {
		cout << st[i].name << "\t\t" << st[i].numb << "\t\t" << st[i].grade << endl;
	}
}

void operat::signIn() {
	cout << "1:��¼ѧ������ϵͳ\n2:ע�����˺�\n���������ѡ��";
	int choice; bool flag = false;
	cin >> choice;
	string pass, acct;
	if (choice == 1)
		while (!flag) {
			system("cls");
			cout << "�����������˺�:";

			cin >> acct;
			cout << "��������������:";
			cin >> pass;
			for (int i = 0; i < password::showN(); i++) {
				if (passw[i].showAccount() == acct && passw[i].showPass() == pass) {
					flag = true;
					system("cls");
					cout << "���ڵ�½...";
					Sleep(1000);
					return;
				}
			}
			if (!flag) {
				cout << "�˺Ż�������� ���������룡";
				system("pause");
			}
		}
	else {
		cout << "�����������ֻ��Ż�ѧ���ţ�";
		cin >> acct;
		cout << "���������룺";
		cin >> pass;
		passw[password::showN()].setAccount(acct, pass);
		password::setN(password::showN() + 1);
		cout << "�˺�ע��ɹ���";
		system("pause");
		return;
	}
}

