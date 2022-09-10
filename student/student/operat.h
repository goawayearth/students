#include<iostream>
//#include"stud.h"
class stud;
using namespace std;
class operat {
public:
	void show_menu();//展示菜单
	int get_choice();
	void end(stud*);
	void input_data(stud*);//输入学生数据
	void search(stud*);//查找学生
	void readFile(stud*);
	void writeFile(stud*);
	////void report_card();输出学生总分平均分成绩单
	void modif(stud*);//修改学生成绩
	void find();//查找学生
	void courseShow(stud*);//单科学生列表
	void gradeShow(stud*);//输出总成绩单
};