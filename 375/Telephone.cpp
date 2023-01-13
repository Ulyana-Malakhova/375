#include "Telephone.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int Telephone::number = 0;
Telephone::Telephone(Current_state current_state, Dimensions dimensions, System_t system_t, Screen screen, General_data general_data) {
	this->current_state = current_state;
	this->dimensions = dimensions;
	this->system_t = system_t;
	this->screen = screen;
	this->general_data = general_data;
	number++;
}
Telephone::Telephone(Current_state current_state) {
	this->current_state = current_state;
	number++;
}
Telephone::Telephone() {
	number++;
}
Telephone::~Telephone() {
	number--;
}
void Telephone::read() {
	current_state.read();
	dimensions.read();
	system_t.read();
	camera_pixels();
	screen.read();
	general_data.read();
}
void Telephone::number_phone() {
	cout << "���������� ��������� - " << number << endl;
}
void Telephone::display() {
	cout << current_state;
	cout << dimensions;
	cout << system_t;
	cout << screen;
	cout << general_data;
}
void operator <<(ostream& o, Telephone p) {
	cout << p.current_state;
	cout << p.dimensions;
	cout << p.system_t;
	cout << p.screen;
	cout << p.general_data;
}
void Telephone::zaryad() {
	int p = 0, charge1;
	while (p == 0) {
		p = 1;
		cout << "������� ����� ��������� ������ �� ��������?";
		cin >> charge1;
		try {
			if (charge1 < 0)
				throw '0';
			if (charge1 > 100)
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
	current_state.setCharge(charge1);
}
void Telephone::change() {
	int i, t, j, k, p = 0;
	int memory1 = current_state.getMemory();
	string card1 = system_t.getCard();
	while (p == 0) {
		p = 1;
		cout << "��������� � ������� ������ ������� �:" << endl << "1.���������� ��������� ����� ������" << endl << "2.���������� ������ ����������" << endl;
		cin >> i;
		try {
			if (i < 1)
				throw '0';
			if (i > 2)
				throw 0;
		}
		catch (...) {
			p = 0;
			cout << "������������ ������, ���������� ������� �������� ������" << endl;
		}
	}
	if (i == 1) {
		p = 0;
		while (p == 0) {
			p = 1;
			cout << "1.����� ������ ������ � �������" << endl << "2.����� ������ ������� �� ��������" << endl;
			cin >> j;
			try {
				if (j < 1)
					throw '0';
				if (j > 2)
					throw 0;
			}
			catch (...) {
				p = 0;
				cout << "������������ ������, ���������� ������� �������� ������" << endl;
			}
		}
		p = 0;
		while (p == 0) {
			p = 1;
			cout << "����� ����� ������ � �����?";
			cin >> k;
			try {
				if (k < 0)
					throw '0';
			}
			catch (...) {
				p = 0;
				cout << "������������ ������, ���������� ������ ���������� ������" << endl;
			}
		}
		if (j == 1) {
			if (card1 == "no") {
				memory1 += k;
				current_state.setMemory(memory1);
				system_t.setCard("yes");
			}
			else
				cout << "����� ��� ��� ��������� � ��������, ��� ���������� � ��� �������" << endl;
		}
		if (j == 2) {
			if (card1 == "yes") {
				memory1 -= k;
				current_state.setMemory(memory1);
				system_t.setCard("no");
			}
			else
				cout << "����� ��� ��� � ��������, ��� ���������� � ��� �������" << endl;
		}
	}
	if (i == 2) {
		p = 0;
		while (p == 0) {
			p = 1;
			cout << "1.� ������� ��������� ����������" << endl << "2.�� �������� ������� ����������" << endl;
			cin >> j;
			try {
				if (j < 1)
					throw '0';
				if (j > 2)
					throw 0;
			}
			catch (...) {
				p = 0;
				cout << "������������ ������, ���������� ������� �������� ������" << endl;
			}
		}
		p = 0;
		while (p == 0) {
			p = 1;
			cout << "����� ����� ������ �������� ��� �������?";
			cin >> k;
			try {
				if (k < 0)
					throw '0';
			}
			catch (...) {
				p = 0;
				cout << "������������ ������, ���������� ������ ���������� ������" << endl;
			}
		}
		if (j == 1) {
			memory1 -= k;
			current_state.setMemory(memory1);
		}
		if (j == 2) {
			memory1 += k;
			current_state.setMemory(memory1);
		}
	}
}
Screen Telephone::getScreen() {
	return screen;
}
int screen_percentage(Telephone spisok) {
	Screen screen1 = spisok.getScreen();
	Dimensions dimensions1 = spisok.getDimensions();
	int r1 = screen1.getWidth_s();
	int r2 = screen1.getHeight_s();
	int r3 = dimensions1.getWidth();
	int r4 = dimensions1.getHeight();
	int r = (r1 * r2 * 100) / (r3 * r4);
	return r;
}
Dimensions Telephone::getDimensions() {
	return dimensions;
}
Current_state Telephone::getCurrent_state() {
	return current_state;
}
System_t Telephone::getSystem_t() {
	return system_t;
}
General_data Telephone::getGeneral_data() {
	return general_data;
}
int Telephone::number_calls(Current_state current_state1) {
	int c = current_state1.getCalls();
	return c;
}
int* Telephone::energy_saving(int s) {
	int f = current_state.getCharge();
	if (s >= f) {
		cout << "������� ����� ����������������" << endl;
		current_state.setEnergy("yes");
	}
	else {
		cout << "����� �������� ������ ����������" << endl;
		current_state.setEnergy("no");
	}
	s -= f;
	return &s;
}
int& Telephone::check_memory(int s) {
	int f = current_state.getMemory();
	if (s >= f) {
		cout << "��� ���� ��������� ������" << endl;
	}
	else
		cout << "��������� ����� ������ �����. ������� ������ �����" << endl;
	s -= f;
	return s;
}
void Telephone::setCurrent_state(Current_state current_state) {
	this->current_state = current_state;
}
void Telephone::setCallsCurrent_state(Current_state current_state1) {
	int c = current_state1.getCalls();
	current_state.setCalls(c);
}
Touch_phone::Touch_phone(Current_state current_state, Dimensions dimensions, System_t system_t, Screen screen, General_data general_data, Touch touch) :Telephone(current_state, dimensions, system_t, screen, general_data) {
	this->touch = touch;
}
void Touch_phone::read1() {
	touch.read();
}
void Touch_phone::display() {
	cout << current_state;
	cout << dimensions;
	cout << system_t;
	cout << screen;
	cout << general_data;
	cout << touch;
}
void operator <<(ostream& o, Touch_phone p) {
	cout << p.current_state;
	cout << p.dimensions;
	cout << p.system_t;
	cout << p.screen;
	cout << p.general_data;
	cout << p.touch;
}
void Telephone::camera_pixels() {
	cout << "������� ���������� �������� �������� ������:";
	cin >> this->main_c;
}

void Touch_phone::check_year() {
	int p = 0;
	int year1 = general_data.getYear();
	if (year1 < 1993) {
		cout << "� ���� ���� ��� �� ���� ��������� ���������, ���������� ������" << endl;
		while (p == 0) {
			p = 1;
			cin >> year1;
			try {
				if (year1 < 1993)
					throw '0';
				if (year1 > 2023)
					throw 0;
			}
			catch (char c) {
				p = 0;
				cout << "� ���� ���� ��� �� ���� ��������� ���������, ���������� ������" << endl;
			}
			catch (int c) {
				p = 0;
				cout << "�������� ����������, ���� ��� ��� �� ��������. ���������� ������ ���������� ������" << endl;
			}
			general_data.setYear(year1);
		}
	}
}
int* Touch_phone::energy_saving(int s, int a) {
	int f = current_state.getCharge();
	if (a == 1) {
		if (s >= f) {
			cout << "������� ����� ����������������" << endl;
			current_state.setEnergy("yes");
		}
		else {
			cout << "����� �������� ������ ����������" << endl;
		}
		s -= f;
		return &s;
	}
	if (a == 2) {
		if (s <= f) {
			cout << "����� ���������������� ��������" << endl;
			current_state.setEnergy("no");
		}
		else {
			cout << "����� �������� ������ ����������" << endl;
		}
		s -= f;
		return &s;
	}
}
void Touch_phone::operator=(Telephone p) {
	this->current_state = p.getCurrent_state();
	this->dimensions = p.getDimensions();
	this->general_data = p.getGeneral_data();
	this->screen = p.getScreen();
	this->system_t = p.getSystem_t();
}
void Touch_phone::camera_pixels() {
	int n = touch.getCameras();
	int i, j;
	for (i = 0; i < n; i++) {
		j = i + 1;
		cout << "������� ���������� �������� " << j << " ������:";
		cin >> this->a[i];
	}
}