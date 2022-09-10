#include<iostream>
using namespace std;
#include"operat.h"
#include"stud.h"
int main() {
	stud students[50];
	operat operation;
	operation.readFile(students);
	/*cout << students[0].show_aver() << endl;
	cout << students[1].show_aver() << endl;
	cout << students[2].show_aver() << endl;*/
	while(true){
		operation.show_menu();
		switch (operation.get_choice()) {
		case 1:operation.input_data(students); break;
		case 2:operation.search(students); break;
		case 3:operation.modif(students); break;
		case 4:operation.gradeShow(students); break;
		case 0:operation.end(students);
		}
	}
}