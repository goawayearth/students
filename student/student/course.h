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
	void set_course();//同时设置三个变量
	//分别设置，读取文件时方便
	void setCourse_n(int);
	void set_course_name(string);
	void set_course_number(string);
	void set_course_grade(double);

	int showCourse_n();
	string show_course_name();
	string show_course_number(); 
	double show_course_grade();
};


