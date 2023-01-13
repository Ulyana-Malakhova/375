#include "Current_state.h"
#include <iostream>
#include <string>
using namespace std;

Current_state::Current_state(int charge, int memory, string internet, int calls, string energy) {
	this->charge = charge;
	this->memory = memory;
	this->internet = internet;
	this->calls = calls;
	this->energy = energy;
}
Current_state::Current_state(int charge) {
	this->charge = charge;
	memory = 0;
	internet = "internet";
	calls = 0;
	energy = "no";
}
Current_state::Current_state() {
	charge = 0;
	memory = 0;
	internet = "internet";
	calls = 0;
	energy = "no";
}
Current_state::~Current_state() {

}
void Current_state::read() {
	cout << "������ ���������� � �������� ���������" << endl;
	int p = 0;
	while (p == 0) {
		p = 1;
		cout << "�����(� ���������): ";
		cin >> charge;
		try {
			if (charge < 0)
				throw '0';
			if (charge > 100)
				throw 0;
		}
		catch (char c) {
			p = 0;
			cout << "������� ������ ������ 0. ���������� ������ ���������� ������" << endl;
		}
		catch (int c) {
			p = 0;
			cout << "������� ������ ������ 100. ���������� ������ ���������� ������" << endl;
		}
	}
	p = 0;
	while (p == 0) {
		p = 1;
		cout << "��������� ������(��): ";
		cin >> memory;
		try {
			if (memory < 0)
				throw 0;
		}
		catch (int c) {
			p = 0;
			cout << "����� ������ ������ 0. ���������� ������ ���������� ������" << endl;
		}
	}
	cout << "��������: ";
	cin >> internet;
}
void operator <<(ostream& o, Current_state p) {
	cout << "�������� ���������:" << endl << "-�����:" << p.charge << endl << "-��������� ������:" << p.memory << endl << "-��������:" << p.internet << endl;
}
void Current_state::setCharge(int a) {
	this->charge = a;
}
void Current_state::setMemory(int a) {
	this->memory = a;
}
void Current_state::setEnergy(string a) {
	this->energy = a;
}
int Current_state::getMemory() {
	return memory;
}
int Current_state::getCalls() {
	return calls;
}
int Current_state::getCharge() {
	return charge;
}
void Current_state::setCalls(int a) {
	this->calls = a;
}
Current_state Current_state::operator+(int n) {
	Current_state calls1;
	calls1.calls = this->calls + n;
	return calls1;
}
Current_state Current_state::operator++() {
	this->calls++;
	return *this;
}
Current_state Current_state::operator++(int d) {
	Current_state calls1 = *this;
	++* this;
	return calls1;
}
