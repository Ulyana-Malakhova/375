#include "System_t.h"
#include <iostream>
#include <string>
using namespace std;

System_t::System_t(string opersystem, int internalm, string card) {
	this->opersystem = opersystem;
	this->internalm = internalm;
	this->card = card;
}
System_t::System_t(string opersystem) {
	this->opersystem = opersystem;
	internalm = 0;
	card = "card";
}
System_t::System_t() {
	opersystem = "opersystem";
	internalm = 0;
	card = "card";
}
System_t::~System_t() {

}
void System_t::read() {
	cout << "Введем информацию о системе" << endl;
	cout << "Операционная система: ";
	cin >> opersystem;
	int p = 0;
	while (p == 0) {
		p = 1;
		cout << "Встроенная память(Гб): ";
		cin >> internalm;
		try {
			if (internalm < 0)
				throw '0';
		}
		catch (char c) {
			p = 0;
			cout << "Неправильные данные, попробуйте ввести информацию заново" << endl;
		}
	}
	cout << "Карта памяти(yes/no): ";
	cin >> card;
}
void operator <<(ostream& o, System_t p) {
	cout << "Система:" << endl << "-операционная система:" << p.opersystem << endl << "-встроенная память:" << p.internalm << endl << "-карта памяти:" << p.card << endl;
}
string System_t::getCard() {
	return card;
}
void System_t::setCard(string a) {
	this->card = a;
}