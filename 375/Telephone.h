#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Current_state.h"
#include "Dimensions.h"
#include "System_t.h"
#include "Screen.h"
#include "General_data.h"
#include "Touch.h"
using namespace std;

class Telephone {
protected:
	Current_state current_state;
	Dimensions dimensions;
	System_t system_t;
	Screen screen;
	General_data general_data;
	int main_c;
public:
	Telephone(Current_state current_state, Dimensions dimensions, System_t system_t, Screen screen, General_data general_data);
	Telephone(Current_state current_state);
	Telephone();
	~Telephone();
	static int number;
	static void number_phone();
	void read();
	virtual void display();
	void zaryad();
	void change();
	int* energy_saving(int s);
	int& check_memory(int s);
	int number_calls(Current_state current_state1);
	Screen getScreen();
	Dimensions getDimensions();
	Current_state getCurrent_state();
	General_data getGeneral_data();
	System_t getSystem_t();
	void setCurrent_state(Current_state current_state);
	friend void operator <<(ostream& o, Telephone p);
	friend int screen_percentage(Telephone spisok);
	void setCallsCurrent_state(Current_state current_state1);
	virtual void camera_pixels();
};

class Touch_phone :public Telephone {
private:
	Touch touch;
	int front;
	int main_c;
	int a[10];
public:
	Touch_phone(Current_state current_state, Dimensions dimensions, System_t system_t, Screen screen, General_data general_data, Touch touch);
	void read1();
	void display();
	friend void operator <<(ostream& o, Touch_phone p);
	int* energy_saving(int s, int a);
	void camera_pixels();
	void check_year();
	void operator=(Telephone p);
};