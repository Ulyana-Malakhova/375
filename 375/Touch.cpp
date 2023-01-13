#include "Touch.h"
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

Touch::Touch(string wifi, int front_c, string geo, int cameras) {
	this->wifi = wifi;
	this->front_c = front_c;
	this->geo = geo;
	this->cameras = cameras;
}
Touch::Touch(int cameras) {
	this->cameras = cameras;
	geo = "geo";
	front_c = 0;
	wifi = "wifi";
}
Touch::Touch() {
	cameras = 0;
	geo = "geo";
	front_c = 0;
	wifi = "wifi";
}
void Touch::read() {
	cout << "������ ���������� � ��������� ��������" << endl;
	int p = 0;
	cout << "��������� WI-FI(yes-�������/no-��������): ";
	cin >> wifi;
	while (p == 0) {
		p = 1;
		cout << "���������� �����: ";
		cin >> cameras;
		try {
			if (cameras < 1)
				throw '0';
		}
		catch (char c) {
			p = 0;
			cout << "������������ ������, ���������� ������ ���������� ������" << endl;
		}
	}
	p = 0;
	while (p == 0) {
		p = 1;
		cout << "���������� ������������ ����������� ������: ";
		cin >> front_c;
		try {
			if (front_c < 1)
				throw '0';
		}
		catch (char c) {
			p = 0;
			cout << "������������ ������, ���������� ������ ���������� ������" << endl;
		}
	}
	cout << "����������(yes-��������/no-���������): ";
	cin >> geo;
}
void operator <<(ostream& o, Touch p) {
	cout << "���������� � ��������� ��������:" << endl << "-��������� WI-FI(yes-�������/no-��������):" << p.wifi << endl << "-���������� �����:" << p.cameras << endl << "-���������� ������������ ����������� ������:" << p.front_c << endl << "-����������(yes-��������/no-���������):" << p.geo << endl;
}
int Touch::getCameras() {
	return cameras;
}