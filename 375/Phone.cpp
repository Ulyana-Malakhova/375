#include "Phone.h"
#include <iostream>
#include <string.h>
using namespace std;

Phone::Phone(int accumulator, int pixel_density, int height_s, int width_s, int weight, int height, int width, int memory) {
	this->accumulator = accumulator;
	this->pixel_density = pixel_density;
	this->height_s = height_s;
	this->width_s = width_s;
	this->weight = weight;
	this->height = height;
	this->width = width;
	this->memory = memory;
}
void Phone::read_p() {
	cout << "Введем  базовую информацию о кнопочном телефоне" << endl;
	int p = 0;
	while (p == 0) {
		p = 1;
		cout << "Емкость аккумулятора(мАч): ";
		cin >> accumulator;
		try {
			if (accumulator < 0)
				throw '0';
			if (accumulator > 6000)
				throw 0;
		}
		catch (...) {
			p = 0;
			cout << "Неправильные данные, попробуйте ввести информацию заново" << endl;
		}
	}
	p = 0;
	while (p == 0) {
		p = 1;
		cout << "Плотность пикселей(ppi): ";
		cin >> pixel_density;
		try {
			if (pixel_density < 0)
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
		cout << "Высота экрана(мм): ";
		cin >> height_s;
		try {
			if (height_s < 0)
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
		cout << "Ширина экрана(мм): ";
		cin >> width_s;
		try {
			if (width_s < 0)
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
		cout << "Вес(г): ";
		cin >> weight;
		try {
			if (weight < 0)
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
		cout << "Ширина телефона(мм): ";
		cin >> width;
		try {
			if (width < 0)
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
		cout << "Высота телефона(мм): ";
		cin >> height;
		try {
			if (height < 0)
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
		cout << "Объем встроенной памяти(Гб): ";
		cin >> memory;
		try {
			if (memory < 0)
				throw '0';
			if (memory > 64)
				throw 0;
		}
		catch (char c) {
			p = 0;
			cout << "Неправильные данные, попробуйте ввести информацию заново" << endl;
		}
		catch (int c) {
			p = 0;
			cout << "Неверная информация, слишком большой объем памяти. Попробуйте ввести информацию заново" << endl;
		}
	}
}
void Phone::display_p() {
	cout << endl;
	cout << "Информация о кнопочном телефоне:" << endl;
	cout << "-емкость аккумулятора(мАч):" << accumulator << endl;
	cout << "-плотность пикселей:" << pixel_density << endl;
	cout << "-высота экрана(мм):" << height_s << endl;
	cout << "-ширина экрана(мм):" << width_s << endl;
	cout << "-вес(г):" << weight << endl;
	cout << "-высота телефона(мм):" << height << endl;
	cout << "-ширина телефона(мм):" << width << endl;
	cout << "-объем встроенной памяти(Гб):" << memory << endl;

}
Push_button_phone::Push_button_phone(int accumulator, int pixel_density, int height_s, int width_s, int weight, int height, int width, int memory) :Phone(accumulator, pixel_density, height_s, width_s, weight, height, width, memory) {

}
double Push_button_phone::Diagonal() {
	double a, b;
	b = sqrt(width_s * width_s + height_s * height_s);
	a = b / 10;
	b = a / 2.54;
	return b;
}