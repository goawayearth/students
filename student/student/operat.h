#include<iostream>
#include"password.h"
class stud;
using namespace std;
class operat {
public:
	password passw[100];
	void signIn();//��¼��ע��
	void show_menu();//չʾ�˵�
	int get_choice();
	void end(stud*);
	void input_data(stud*);//����ѧ������
	void search(stud*);//����ѧ��
	void readFile(stud*);//��ȡ�ļ�
	void writeFile(stud*);//д���ļ�
	void modif(stud*);//�޸�ѧ���ɼ�
	void courseShow(stud*);//����ѧ���б�
	void gradeShow(stud*);//����ܳɼ���
	void delete_st(stud*);//ɾ��ѧ���ɼ�
	void course_find(stud*);//���տγ����ƻ��߱�Ų���ѧ��������ѧ�ţ��ɼ�
	void course_show(stud*);//���տγ����ƻ��߱���޸�ѧ��������ѧ�ţ��ɼ�
};