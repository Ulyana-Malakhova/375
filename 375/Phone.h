#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Phone {
protected:
	int accumulator;
	int pixel_density;
	int height_s;
	int width_s;
	int weight;
	int height;
	int width;
	int memory;
public:
	Phone(int accumulator, int pixel_density, int height_s, int width_s, int weight, int height, int width, int memory);
	virtual double Diagonal() = 0;
	void read_p();
	void display_p();
};

class Push_button_phone :public Phone {
public:
	Push_button_phone(int accumulator, int pixel_density, int height_s, int width_s, int weight, int height, int width, int memory);
	double Diagonal();
};