#include<iostream>
//#include"stud.h"
class stud;
using namespace std;
class operat {
public:
	void show_menu();//չʾ�˵�
	int get_choice();
	void end(stud*);
	void input_data(stud*);//����ѧ������
	void search(stud*);//����ѧ��
	void readFile(stud*);
	void writeFile(stud*);
	////void report_card();���ѧ���ܷ�ƽ���ֳɼ���
	void modif(stud*);//�޸�ѧ���ɼ�
	void find();//����ѧ��
	void courseShow(stud*);//����ѧ���б�
	void gradeShow(stud*);//����ܳɼ���
};