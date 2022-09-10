#include<iostream>
#include<fstream>
using namespace std;
#include"operat.h"
#include"stud.h"

//class stud;
void operat::show_menu() {
	cout << "******************************************************" << endl;
	cout << "----------------��ӭʹ��ѧ���ɼ�����ϵͳ---------------" << endl;
	cout << "    *          ��1������ѧ����Ϣ                  *    " << endl;
	cout << "    *          ��2������ѧ����Ϣ                  *    " << endl;
	cout << "    *          ��3���޸�ѧ����Ϣ                  *    " << endl;
	cout << "    *          ��4���޸�ѧ���ɼ�                  *    " << endl;
	cout << "    *          ��5��ɾ��ѧ���ɼ�                  *    " << endl;
	cout << "    *          ��6������ѧ���ɼ�                  *    " << endl;
	cout << "    *          ��7����ƽ��������                  *    " << endl;
	cout << "    *          ��8����ʾѧ���ɼ�                  *    " << endl;
	cout << "    *          ��0���˳�����ϵͳ                  *    " << endl;
	cout << "******************************************************" << endl;
	cout << "����������Ҫִ�еĲ���: ";
}

int operat::get_choice() {
	int choice;
	cin >> choice;
	return choice;
}


void operat::input_data(stud students[]) {
	//����ѧ����Ϣ
	int n;
	cout << "����������ѧ���ĸ���: ";
	cin >> n;
	int m = students[0].show_n();
	string NAME,NUM;
	for (int i = 0; i < n; i++)
	{
		cout << "������ѧ��"<<i+1<<"��������ѧ��" << ":";
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
	//����ѧ����Ϣ
	string NAME;
	int n = students[0].show_n();
	cout << "������Ҫ���ҵ�ѧ��������ѧ��:";
	cin >> NAME;
	for (int i = 0; i < n; i++)
	{
		if (students[i].show_name() == NAME||students[i].show_num()==NAME) {
			cout << NAME << " ��Ϣ���£�"<< endl;
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
			cout << endl<<endl<<endl;
			return;
		}
	}
	cout << "���޴���\n\n\n";
}
void operat::end(stud* students) {
	cout << "��лʹ�ã��ټ���" << endl;
	//cout << students[1].courses[0].show_course_name() << endl;
	operat::writeFile(students);
	exit(0);
}
void operat::readFile(stud students[]) {
	ifstream infile("student.txt", ios::in);
	if (!infile) {
		cerr << "��ʧ��" << endl; exit(1);
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
		cerr << "��ʧ��" << endl; exit(1);
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
	//����ѧ�Ż������޸�ѧ����Ϣ
	cout << "��������Ҫ�޸ĵ�ѧ��������ѧ�ţ�";
	string temp;
	cin >> temp;
	for (int i = 0; i < students[0].show_n(); i++) {
		if (students[i].show_name() == temp || students[i].show_num() == temp) {
			cout << "����������ѧ��������ѧ�ţ�";
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
	cout << "����\t\t" << "ѧ��\t\t" << "�ܳɼ�\t\t" << "ƽ���ɼ�" << endl;
	for (int i = 0; i < n; i++) {
		cout << students[i].show_name() << "\t\t" << students[i].show_num() << "\t\t" << students[i].show_sum() << "\t\t" << students[i].show_aver()<<endl;
	}
	cout << endl << endl << endl;
}
