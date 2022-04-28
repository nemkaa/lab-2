#pragma once
#include "Date.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Telephone {
public:
	string name;
	string tel_number;
	Date date;

	Telephone() {
		cout << "Enter name: ";
		cin >> this->name;

		cout << "Enter telephone: ";
		cin >> this->tel_number;

		cout << "Enter date(day,month): ";
		cin >> this->date.day;
		cin >> this->date.month;
	}
	
	void printTelephone() {
		cout << "Name: " << this->name << endl;
		cout << "Telephone: " << this->tel_number << endl;
		cout << "Date: ";
		if (this->date.day < 10) {
			cout << 0 << this->date.day << ".";
		}
		else {
			cout << this->date.day << ".";
		}

		if (this->date.month < 10) {
			cout << 0 << this->date.month << endl;
		}
		else {
			cout << this->date.month << endl;
		}
		
	}
};