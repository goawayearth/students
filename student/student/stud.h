#include<iostream>
using namespace std;
#include"course.h"
class stud {

private:
	int n;//学生总数
	string name;//姓名
	string num;//学号
	double sum, aver;
public:
	course courses[10];
	void set_name(string);
	void set_num(string);
	void set_n(int N);
	string show_name();
	string show_num();
	int  show_n();
	void setCourse();
	void set_sum();
	void set_aver();
	double show_sum();
	double show_aver();
};