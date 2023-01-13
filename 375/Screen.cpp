#include "Screen.h"
#include <iostream>
#include <string>
using namespace std;

Screen::Screen(double diagonal, string pixel, int width_s, int height_s) {
	this->diagonal = diagonal;
	this->pixel = pixel;
	this->width_s = width_s;
	this->height_s = height_s;
}
Screen::Screen(double diagonal) {
	this->diagonal = diagonal;
	pixel = "pixel";
	width_s = 0;
	height_s = 0;
}
Screen::Screen() {
	diagonal = 0;
	pixel = "pixel";
	width_s = 0;
	height_s = 0;
}
Screen::~Screen() {

}
void Screen::read() {
	cout << "������ ���������� �� ������" << endl;
	int p = 0;
	while (p == 0) {
		p = 1;
		cout << "���������(����): ";
		cin >> diagonal;
		try {
			if (diagonal < 0)
				throw '0';
		}
		catch (char c) {
			p = 0;
			cout << "������������ ������, ���������� ������ ���������� ������" << endl;
		}
	}
	cout << "��������� ��������(ppi): ";
	cin >> pixel;
}
void operator <<(ostream& o, Screen p) {
	cout << "���������� �� ������:" << endl << "-���������:" << p.diagonal << endl << "-��������� ��������:" << p.pixel << endl;
}
int Screen::getWidth_s() {
	return width_s;
}
int Screen::getHeight_s() {
	return height_s;
}