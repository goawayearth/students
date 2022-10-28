#include "course.h"
void course::set_course() {
	cout << "请输入课程名称、编号和成绩：";
	cin >> course_name>>course_number>>course_grade;
}

string course::show_course_name() {
	return course_name;
}

string course::show_course_number() {
	return course_number;
}
double course::show_course_grade() {
	return course_grade;
}
 void course::setCourse_n(int N) {
	course_n = N;
}
int course::showCourse_n() {
	return course_n;
}
void course::set_course_name(string name) {
	course_name = name;
}
void course::set_course_number(string num) {
	course_number = num;
}
void course::set_course_grade(double n) {
	course_grade = n;
}