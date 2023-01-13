#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class General_data {
private:
	string country;
	string model;
	int year;
public:
	General_data(string country, string model, int year);
	General_data(string model);
	General_data();
	~General_data();
	void read();
	friend void operator <<(ostream& o, General_data p);
	int getYear();
	void setYear(int a);
};