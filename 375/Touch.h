#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class Touch {
private:
	string wifi;
	int front_c;
	string geo;
	int cameras;
public:
	Touch(string wifi, int front_c, string geo, int cameras);
	Touch(int cameras);
	Touch();
	void read();
	int getCameras();
	friend void operator <<(ostream& o, Touch p);
};