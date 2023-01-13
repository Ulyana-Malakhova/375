// 375.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <string>
#include <vector>
#include "Current_state.h"
#include "Dimensions.h"
#include "System_t.h"
#include "Screen.h"
#include "General_data.h"
#include "Phone.h"
#include "Telephone.h"
#include "Names.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	Current_state current_state = Current_state::Current_state(0, 0, "internet", 0, "no");
	Dimensions dimensions = Dimensions::Dimensions(0, 0, 0, 0);
	System_t system_t = System_t::System_t("opersystem", 0, "card");
	Screen screen = Screen::Screen(0, "pixel", 0, 0);
	General_data general_data = General_data::General_data("country", "model", 0);
	Touch touch = Touch::Touch("wifi", 0, "geo", 0);
	cout << "Работа с перегрузкой оператора присваивания объекту производного класса объектов базового класса" << endl;
	Telephone* spisok5 = new Telephone(current_state, dimensions, system_t, screen, general_data);
	spisok5->read();
	Touch_phone* phone5 = new Touch_phone(current_state, dimensions, system_t, screen, general_data, touch);
	*phone5 = *spisok5;
	cout << *phone5;
	int d, p, t, n, c1, z, f;
	cout << "Вызов виртуальной функции через динамические объекты базового и производного классов после присваивания указателя. Хотите выполнить проверку? 1-да,любая другая клавиша-нет" << endl;
	cin >> z;
	if (z == 1) {
		Telephone* spisok6;
		spisok6 = new Telephone(current_state, dimensions, system_t, screen, general_data);
		Touch_phone* phone6;
		phone6 = new Touch_phone(current_state, dimensions, system_t, screen, general_data, touch);
		spisok6->read();
		phone6->read1();
		spisok6 = phone6;
		spisok6->camera_pixels();
		phone6->camera_pixels();
	}
	cout << "Хотите ввести модели телефонов, данные о которых хотите потом рассмотреть? 1-да,любая другая клавиша-нет" << endl;
	cin >> f;
	if (f == 1) {
		int y;
		cout << "Сколько моделей телефонов вы хотите ввести?" << endl;
		cin >> y;
		Names<string> Model(y);
		Model.read_n();
		Model.display_n();
		cout << endl << "Хотите найти название модели телефона, заданного определенным номером? 1-да,любая другая клавиша-нет" << endl;
		cin >> z;
		if (z == 1) {
			int m;
			cout << "Введите номер элемента,название модели которого хотите получить:";
			cin >> m;
			cout << "Название модели - " << Model.search(m);
		}
	}
	cout << "Создадим контейнер с объектами" << endl;
	vector<Telephone*> vect;
	Telephone* spisok7;
	spisok7 = new Telephone(current_state, dimensions, system_t, screen, general_data);
	Touch_phone* phone7;
	phone7 = new Touch_phone(current_state, dimensions, system_t, screen, general_data, touch);
	int v1 = 1;
	while (v1 == 1) {
		spisok7->read();
		phone7->read();
		phone7->read1();
		vect.push_back(spisok7);
		vect.push_back(phone7);
		cout << "Хотите добавить еще данные?1-да,любая другая цифра-нет";
		cin >> v1;
	}
	vector<Telephone*>::iterator ir;
	for (ir = vect.begin(); ir != vect.end(); ++ir) {
		(*ir)->display();
	}
	int h, c = 0;
	while (c == 0) {
		c = 1;
		cout << endl << "Вы хотите работать с 1-сенсорным телефоном, 2-кнопочным телефоном или 3-общей информацией(данная информация не известна или не важна)?" << endl;
		cin >> h;
		try {
			if (h < 1)
				throw '0';
			if (h > 3)
				throw 0;
		}
		catch (...) {
			c = 0;
			cout << "Неправильные данные, попробуйте выбрать действие заново" << endl;
		}
	}
	if (h == 1) {
		Touch_phone* phone = new Touch_phone(current_state, dimensions, system_t, screen, general_data, touch);
		phone->read1();
		phone->read();
		phone->check_year();
		cout << *phone;
		//phone->display();
		//phone->display1();
		do {
			c = 0;
			while (c == 0) {
				c = 1;
				cout << endl << "Выберите действие, которое хотите совершить:" << endl << "1.Вывод информации" << endl << "2.Зарядить телефон" << endl << "3.Изменить данные памяти" << endl << "4.Ввод новых данных" << endl << "5.Включить режим энергосбережения" << endl << "6.Выход" << endl;
				cin >> d;
				try {
					if (d < 0)
						throw '0';
					if (d > 6)
						throw 0;
				}
				catch (...) {
					c = 0;
					cout << "Неправильные данные, попробуйте выбрать действие заново" << endl;
				}
			}
			if (d == 1) {
				cout << *phone;
				//phone->display();
				//phone->display1();
			}
			if (d == 2)
			{
				phone->zaryad();
			}
			if (d == 3)
				phone->change();
			if (d == 4) {
				phone->read1();
				phone->read();
				phone->check_year();
				cout << *phone;
				//phone->display();
				//phone->display1();
			}
			if (d == 5) {
				int s, s2;
				cout << "1-включить режим энергосбережения, 2-выключить режим энергосбережения";
				cin >> s2;
				cout << "Сколько процентов заряда должно быть на телефоне, чтобы включить/выключить энергосбережение?";
				cin >> s;
				int s1 = 0;
				s1 = *phone->energy_saving(s, s2);
				cout << "Разница введенного значения и заряда телефона ";
				cout << s1 << endl;
			}
			if (d == 6) {
				cout << "Вы действительно хотите выйти? (1-Да,Любая другая клавиша-Нет):";
				cin >> p;
				if (p == 1)
					return 0;
			}
			cout << "Хотите продолжить? Да - любая клавиша, Нет -ESC";
		} while (_getch() != 27);
	}
	if (h == 2) {
		int d, p;
		Push_button_phone* button = new Push_button_phone(0, 0, 0, 0, 0, 0, 0, 0);
		button->read_p();
		button->display_p();
		do {
			c = 0;
			while (c == 0) {
				c = 1;
				cout << endl << "Выберите действие, которое хотите совершить:" << endl << "1.Вывод информации" << endl << "2.Найти диагональ экрана" << endl << "3.Ввод новых данных" << endl << "4.Выход" << endl;
				cin >> d;
				try {
					if (d < 0)
						throw '0';
					if (d > 4)
						throw 0;
				}
				catch (...) {
					c = 0;
					cout << "Неправильные данные, попробуйте выбрать действие заново" << endl;
				}
			}
			if (d == 1) {
				button->display_p();
			}
			if (d == 2)
			{
				cout << "Диагональ экрана(дюйм): " << button->Diagonal() << endl;
			}
			if (d == 3) {
				button->read_p();
				button->display_p();
			}

			if (d == 4) {
				cout << "Вы действительно хотите выйти? (1-Да,Любая другая клавиша-Нет):";
				cin >> p;
				if (p == 1)
					return 0;
			}
			cout << "Хотите продолжить? Да - любая клавиша, Нет -ESC";
		} while (_getch() != 27);
	}
	if (h == 3) {
		Telephone* spisok = new Telephone;
		*spisok = Telephone::Telephone(current_state, dimensions, system_t, screen, general_data);
		spisok->read();
		//spisok->display();
		cout << *spisok;
		spisok->number_phone();
		do {
			c = 0;
			while (c == 0) {
				c = 1;
				cout << endl << "Выберите действие, которое хотите совершить:" << endl << "1.Вывод информации" << endl << "2.Зарядить телефон" << endl << "3.Изменить данные памяти" << endl << "4.Ввод новых данных" << endl << "5.Посчитать соотношение экрана к корпусу телефона" << endl << "6.Позвонить" << endl << "7.Включить режим энергосбережения" << endl << "8.Преверить свободную память" << endl << "9.Выход" << endl;
				cin >> d;
				try {
					if (d < 0)
						throw '0';
					if (d > 9)
						throw 0;
				}
				catch (...) {
					c = 0;
					cout << "Неправильные данные, попробуйте выбрать действие заново" << endl;
				}
			}
			if (d == 1) {
				//spisok->display();
				cout << *spisok;
				spisok->number_phone();
			}
			if (d == 2)
			{
				spisok->zaryad();
			}
			if (d == 3)
				spisok->change();
			if (d == 4) {
				spisok->read();
				//spisok->display();
				cout << *spisok;
				spisok->number_phone();
			}
			if (d == 5) {
				int r = screen_percentage(*spisok);
				cout << "Соотношение экрана к корпусу телефона(%):" << r << endl;
			}
			if (d == 6) {
				cout << "1.Хотите узнать информацию звонков после вызова" << endl << "2.Позвонить без вывода дополнительной информации" << endl << "3. Сделать сразу несколько звонков" << endl;
				cin >> c1;
				Current_state calls1, calls2;
				if (c1 == 1) {
					calls1 = spisok->getCurrent_state();
					calls2 = calls1++;
					spisok->setCurrent_state(calls1);
					int c2 = spisok->number_calls(calls2);
					cout << "Количество звонков до нынешнего:" << c2 << endl;
					c2 = spisok->number_calls(calls1);
					cout << "Количество звонков после нынешнего:" << c2 << endl;
				}
				if (c1 == 2) {
					calls1 = spisok->getCurrent_state();
					calls2 = ++calls1;
					spisok->setCurrent_state(calls1);
					int c2 = spisok->number_calls(calls1);
					cout << "Количество звонков:" << c2 << endl;
				}
				if (c == 3) {
					cout << "Сколько звонков вы планируете сделать?";
					cin >> n;
					calls1 = spisok->getCurrent_state() + n;
					spisok->setCallsCurrent_state(calls1);
				}
			}
			if (d == 7) {
				int s;
				cout << "Сколько процентов заряда должно быть на телефоне, чтобы включить энергосбережение?";
				cin >> s;
				int s1 = 0;
				s1 = *spisok->energy_saving(s);
				cout << "Разница введенного значения и заряда телефона ";
				cout << s1 << endl;
			}
			if (d == 8) {
				int s;
				cout << "Какой объем памяти вы хотели бы оставить свободной?";
				cin >> s;
				int s1 = spisok->check_memory(s);
				cout << "Разница введенного значения и свободной памяти ";
				cout << s1 << endl;
			}
			if (d == 9) {
				cout << "Вы действительно хотите выйти? (1-Да,2-Нет):";
				cin >> p;
				if (p == 1)
					return 0;
			}
			cout << "Хотите продолжить? Да - любая клавиша, Нет -ESC";
		} while (_getch() != 27);
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
