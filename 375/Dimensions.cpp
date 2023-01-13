#include "Dimensions.h"
#include <iostream>
#include <string>
using namespace std;

Dimensions::Dimensions(int width, int height, int thickness, int weight) {
	this->width = width;
	this->height = height;
	this->thickness = thickness;
	this->weight = weight;
}
Dimensions::Dimensions(int weight) {
	this->weight = weight;
	height = 0;
	thickness = 0;
	width = 0;
}
Dimensions::Dimensions() {
	weight = 0;
	height = 0;
	thickness = 0;
	width = 0;
}
Dimensions::~Dimensions() {

}
void Dimensions::read() {
	cout << "������ ���������� � ���������� ��������" << endl;
	int p = 0;
	while (p == 0) {
		p = 1;
		cout << "������(��): ";
		cin >> width;
		try {
			if (width < 40)
				throw 0;
		}
		catch (int c) {
			p = 0;
			cout << "������������ ������, ���������� ������ ���������� ������" << endl;
		}
	}
	p = 0;
	while (p == 0) {
		p = 1;
		cout << "������(��): ";
		cin >> height;
		try {
			if (height < 90)
				throw 0;
		}
		catch (int c) {
			p = 0;
			cout << "������������ ������, ���������� ������ ���������� ������" << endl;
		}
	}
	p = 0;
	while (p == 0) {
		p = 1;
		cout << "�������(��): ";
		cin >> thickness;
		try {
			if (thickness < 7)
				throw 0;
		}
		catch (int c) {
			p = 0;
			cout << "������������ ������, ���������� ������ ���������� ������" << endl;
		}
	}
	p = 0;
	while (p == 0) {
		p = 1;
		cout << "���(� �������): ";
		cin >> weight;
		try {
			if (weight < 32)
				throw 0;
		}
		catch (int c) {
			p = 0;
			cout << "������������ ������, ���������� ������ ���������� ������" << endl;
		}
	}
}
void operator <<(ostream& o, Dimensions p) {
	cout << "���������:" << endl << "-������:" << p.width << endl << "-������:" << p.height << endl << "-�������:" << p.thickness << endl << "-���:" << p.weight << endl;
}
int Dimensions::getWidth() {
	return width;
}
int Dimensions::getHeight() {
	return height;
}