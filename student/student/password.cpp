#include "password.h"
void password::setAccount(string account,string passwords) {
	this->account = account;
	this->passwords = passwords;
}

string password::showPass() {
	return passwords;
}
string password::showAccount() {
	return account;
}
void password::setN(int N) {
	n = N;
}
int password::showN() {
	return n;
}