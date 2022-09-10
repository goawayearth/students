#include<iostream>
using namespace std;
#include"stud.h"
#include"course.h"
void stud::set_name(string NAME) {
	name=NAME;
}

void stud::set_num(string NUM) {
	num=NUM ;
}

string stud::show_name() {
	return name;
}

string stud::show_num() {
	return num;
}

 int stud::show_n() {
	return n;
}

void stud::set_n(int N) {
	n = N;
}

void stud::setCourse() {
	cout << "该学生所选科目数量为：";
	int n;
	cin >> n;
	courses[0].setCourse_n(n);
	for(int i=0;i<n;i++){
		courses[i].set_course();
	}
}
void stud::set_sum() {
	int n = courses[0].showCourse_n();
	sum=0;
	for (int i =0 ; i < n; i++) {
		sum += courses[i].show_course_grade();
	}
}
void stud::set_aver() {
	int n = courses[0].showCourse_n();
	aver = sum / n;
}
double stud::show_sum() {
	return sum;
}
double stud::show_aver() {
	return aver;
}