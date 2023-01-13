#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Current_state {
private:
	int charge;
	int memory;
	string internet;
	int calls;
	string energy;
public:
	Current_state(int charge, int memory, string internet, int calls, string energy);
	Current_state(int charge);
	Current_state();
	~Current_state();
	void read();
	friend void operator <<(ostream& o, Current_state p);
	void setCharge(int a);
	void setMemory(int a);
	void setEnergy(string a);
	int getMemory();
	int getCalls();
	int getCharge();
	void setCalls(int a);
	Current_state operator+(int n);
	Current_state operator++();
	Current_state operator++(int d);
};
