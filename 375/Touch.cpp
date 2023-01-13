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
	cout << "Введем информацию о сенсорном телефоне" << endl;
	int p = 0;
	cout << "Состояние WI-FI(yes-включен/no-выключен): ";
	cin >> wifi;
	while (p == 0) {
		p = 1;
		cout << "Количество камер: ";
		cin >> cameras;
		try {
			if (cameras < 1)
				throw '0';
		}
		catch (char c) {
			p = 0;
			cout << "Неправильные данные, попробуйте ввести информацию заново" << endl;
		}
	}
	p = 0;
	while (p == 0) {
		p = 1;
		cout << "Количество мегапикселей фронтальной камеры: ";
		cin >> front_c;
		try {
			if (front_c < 1)
				throw '0';
		}
		catch (char c) {
			p = 0;
			cout << "Неправильные данные, попробуйте ввести информацию заново" << endl;
		}
	}
	cout << "Геолокация(yes-включена/no-выключена): ";
	cin >> geo;
}
void operator <<(ostream& o, Touch p) {
	cout << "Информация о сенсорном телефоне:" << endl << "-состояние WI-FI(yes-включен/no-выключен):" << p.wifi << endl << "-количество камер:" << p.cameras << endl << "-количество мегапикселей фронтальной камеры:" << p.front_c << endl << "-геолокация(yes-включена/no-выключена):" << p.geo << endl;
}
int Touch::getCameras() {
	return cameras;
}