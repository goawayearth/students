#pragma once
#include<iostream>
using namespace std;
class course
{
private:
	string course_name;//�γ�����
	string course_number;//�γ̱��
	double course_grade;//�ɼ�
	int course_n;
public :
	void set_course();
	string show_course_name();
	string show_course_number(); 
	double show_course_grade();
	void setCourse_n(int N);
	int showCourse_n();
	void set_course_name(string);
	void set_course_number(string);
	void set_course_grade(double);
};

