#pragma once
#include<iostream>
using namespace std;
class course
{
private:
	string course_name;//课程名称
	string course_number;//课程编号
	double course_grade;//成绩
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

