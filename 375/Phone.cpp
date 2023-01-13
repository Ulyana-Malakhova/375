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
	cout << "������  ������� ���������� � ��������� ��������" << endl;
	int p = 0;
	while (p == 0) {
		p = 1;
		cout << "������� ������������(���): ";
		cin >> accumulator;
		try {
			if (accumulator < 0)
				throw '0';
			if (accumulator > 6000)
				throw 0;
		}
		catch (...) {
			p = 0;
			cout << "������������ ������, ���������� ������ ���������� ������" << endl;
		}
	}
	p = 0;
	while (p == 0) {
		p = 1;
		cout << "��������� ��������(ppi): ";
		cin >> pixel_density;
		try {
			if (pixel_density < 0)
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
		cout << "������ ������(��): ";
		cin >> height_s;
		try {
			if (height_s < 0)
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
		cout << "������ ������(��): ";
		cin >> width_s;
		try {
			if (width_s < 0)
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
		cout << "���(�): ";
		cin >> weight;
		try {
			if (weight < 0)
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
		cout << "������ ��������(��): ";
		cin >> width;
		try {
			if (width < 0)
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
		cout << "������ ��������(��): ";
		cin >> height;
		try {
			if (height < 0)
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
		cout << "����� ���������� ������(��): ";
		cin >> memory;
		try {
			if (memory < 0)
				throw '0';
			if (memory > 64)
				throw 0;
		}
		catch (char c) {
			p = 0;
			cout << "������������ ������, ���������� ������ ���������� ������" << endl;
		}
		catch (int c) {
			p = 0;
			cout << "�������� ����������, ������� ������� ����� ������. ���������� ������ ���������� ������" << endl;
		}
	}
}
void Phone::display_p() {
	cout << endl;
	cout << "���������� � ��������� ��������:" << endl;
	cout << "-������� ������������(���):" << accumulator << endl;
	cout << "-��������� ��������:" << pixel_density << endl;
	cout << "-������ ������(��):" << height_s << endl;
	cout << "-������ ������(��):" << width_s << endl;
	cout << "-���(�):" << weight << endl;
	cout << "-������ ��������(��):" << height << endl;
	cout << "-������ ��������(��):" << width << endl;
	cout << "-����� ���������� ������(��):" << memory << endl;

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