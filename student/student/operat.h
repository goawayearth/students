#include<iostream>
#include"password.h"
class stud;
using namespace std;
class operat {
public:
	password passw[100];
	void signIn();//登录或注册
	void show_menu();//展示菜单
	int get_choice();
	void end(stud*);
	void input_data(stud*);//输入学生数据
	void search(stud*);//查找学生
	void readFile(stud*);//读取文件
	void writeFile(stud*);//写入文件
	void modif(stud*);//修改学生成绩
	void courseShow(stud*);//单科学生列表
	void gradeShow(stud*);//输出总成绩单
	void delete_st(stud*);//删除学生成绩
	void course_find(stud*);//按照课程名称或者编号查找学生姓名，学号，成绩
	void course_show(stud*);//按照课程名称或者编号修改学生姓名，学号，成绩
};