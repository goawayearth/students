#pragma once
#include<iostream>
using namespace std;
class password
{
private:
	string account;
	string passwords;
	static int n;
public:
	void setAccount(string,string);
	string showPass();
	string showAccount();
	static void setN(int );
	static int showN();
};

