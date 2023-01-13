#include "General_data.h"
#include <iostream>
#include <string>
using namespace std;

General_data::General_data(string country, string model, int year) {
	this->country = country;
	this->model = model;
	this->year = year;
}
General_data::General_data(string model) {
	this->model = model;
	country = "country";
	year = 0;
}
General_data::General_data() {
	model = "model";
	country = "country";
	year = 0;
}
General_data::~General_data() {

}
void General_data::read() {
	int p = 0;
	cout << "Введем информацию об общих данных" << endl;
	cout << "Страна-производитель: ";
	cin >> country;
	cout << "Модель: ";
	cin >> model;
	while (p == 0) {
		p = 1;
		cout << "Год выпуска: ";
		cin >> year;
		try {
			if (year < 1876)
				throw '0';
			if (year > 2023)
				throw 0;
		}
		catch (char c) {
			p = 0;
			cout << "Неверная информация, в этом году еще не было телефонов. Попробуйте ввести информацию заново" << endl;
		}
		catch (int c) {
			p = 0;
			cout << "Неверная информация, этот год еще не наступил. Попробуйте ввести информацию заново" << endl;
		}
	}
}
void operator <<(ostream& o, General_data p) {
	cout << "Общие данные:" << endl << "-страна-производитель:" << p.country << endl << "-модель:" << p.model << endl << "-год выпуска:" << p.year << endl;
}
int General_data::getYear() {
	return year;
}
void General_data::setYear(int a) {
	this->year = a;
}