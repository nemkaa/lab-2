#include "Telephone.h"
#include <algorithm>

void addTelephone(vector<Telephone> &vrr) {
	Telephone tel;
	vrr.push_back(tel);
}

void printVector(vector<Telephone> vrr) {
	for (Telephone tel : vrr)
	{
		tel.printTelephone();
	}
}

void filtration(vector<Telephone> vrr, string number) {
	for (Telephone tel : vrr)
	{
		if (tel.tel_number[0] == number[0] && tel.tel_number[1] == number[1] && tel.tel_number[2] == number[2]) {
			tel.printTelephone();
		}
	}
}

void findDate(vector<Telephone> vrr, Date date) {

	for (Telephone tel : vrr)
	{
		if (date.day == tel.date.day && tel.date.month == date.month) {
			tel.printTelephone();
		}
	}
}

void sortName(vector<Telephone> vrr) {
	vector<string> temp;
	for (Telephone tel : vrr)
	{
		temp.push_back(tel.name);
	}

	sort(temp.begin(), temp.end());

	for (string name : temp) {
		for (Telephone tel : vrr) {
			if (name == tel.name) {
				tel.printTelephone();
				break;
			}
		}
	}

}

int main()
{
	vector<Telephone> vrr;

	Date date;
	string number;
	int simbol = -1;

	cout << "======Menu:=====" << endl;
	cout << "Enter (0) to stop" << endl;
	cout << "Enter (1) to add telephone" << endl;
	cout << "Enter (2) to print telephone book" << endl;
	cout << "Enter (3) to filtrate by tellephone number" << endl;
	cout << "Enter (4) to find clothes date" << endl;
	cout << "Enter (5) to sort by name" << endl;

	while (simbol != 0) {

		cout << "Enter simbol: ";
		cin >> simbol;

		switch (simbol) {
		case 0:
			break;
		case 1:
			cout << "\nAdd element\n\n";
			addTelephone(vrr);
			break;
		case 2:
			cout << "\nPrint telephone\n\n";
			printVector(vrr);
			break;
		case 3:
			cout << "\nFiltration\n";
			cout << "Enter 3 first letters: ";
			cin >> number;
			filtration(vrr, number);
			break;
		case 4:
			cout << "\nFind date\n\n";
			cout << "Enter date: ";
			cin >> date.day >> date.month;
			findDate(vrr, date);
			break;
		case 5:
			cout << "\nSorting by name\n\n";
			sortName(vrr);
			break;
		}
	}

	return 0;
}