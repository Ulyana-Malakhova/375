#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

template <class T>class Names {
private:
	T* name;
	int N;
public:
	Names(int n);
	void read_n();
	void display_n();
	T search(int i);
};

template <class T> Names<T>::Names(int n) {
	name = new T[n];
	N = n;
}
template <class T> void Names<T>::read_n() {
	int i;
	for (i = 0; i < N; i++) {
		cout << "Введите модель телефона:";
		cin >> name[i];
	}
}
template <class T> void Names<T>::display_n() {
	int i, j = 0;
	for (i = 0; i < N; i++) {
		j++;
		cout << endl << j << ".Модель:" << name[i];
	}
}
template <class T> T Names<T>::search(int i) {
	return name[i];
}