#include "functions.h"

void DataEntry(Data* (&d), int& n)
{
	cout << "Введите количество данных: ";
	cin >> n;

	//выделим память
	d = new Data[n];

	for (int i = 0; i < n; i++) {
		cout << "Введите ФИО: ";
		cin >> d[i]._initial.surname;
		cin >> d[i]._initial.patronymic;
		cin >> d[i]._initial.name;

		cout << "Введите дату: ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;

		cout << "Введите номер телефона: ";
		cin >> d[i]._number.number;

		cout << "Введите адрес: ";
		cin >> d[i]._address.city;
		cin >> d[i]._address.street;
		cin >> d[i]._address.home;

		cout << "______________________________________" << endl;

	}
}

void ReadingData(Data* (&d), int& n, string fileName)
{
	//создаём поток для чтения
	std::ifstream reading(fileName);

	if (reading) {

		reading >> n;

		//выделим память
		d = new Data[n];

		for (int i = 0; i < n; i++) {
			cout << "Введите ФИО: ";
			cin >> d[i]._initial.surname;
			cin >> d[i]._initial.patronymic;
			cin >> d[i]._initial.name;

			cout << "Введите дату: ";
			cin >> d[i]._date.day;
			cin >> d[i]._date.month;
			cin >> d[i]._date.year;

			cout << "Введите номер телефона: ";
			cin >> d[i]._number.number;

			cout << "Введите адрес: ";
			cin >> d[i]._address.city;
			cin >> d[i]._address.street;
			cin >> d[i]._address.home;

			cout << "Данные считаны!" << endl;
		}
	}
	else
		cout << "Ошибка открытия файла!" << endl;

	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "Данные №" << i + 1 << ":" << endl;

		cout << "ФИО: " << d[i]._initial.surname << " " << d[i]._initial.name << " " << d[i]._initial.patronymic << endl;
		cout << "Дата: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;
		cout << "Номер телефона: " << d[i]._number.number << " " << endl;
		cout << "Адрес : " << d[i]._address.city << " " << d[i]._address.street << " " << d[i]._address.home << endl;

		cout << "_________________________________" << endl;
	}
}

void DataChange(Data* (&d), int n)
{
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	//проверка, что ввели правильно значение
	if (_n >= 0 && _n < n) {
		cout << "Введите ФИО: ";
		cin >> d[_n]._initial.surname;
		cin >> d[_n]._initial.patronymic;
		cin >> d[_n]._initial.name;

		cout << "Введите дату: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;

		cout << "Введите номер телефона: ";
		cin >> d[_n]._number.number;

		cout << "Введите адрес: ";
		cin >> d[_n]._address.city;
		cin >> d[_n]._address.street;
		cin >> d[_n]._address.home;

		system("cls");

		cout << "Данные изменены!" << endl;
	}
	else
		cout << "Номер введен неверно!" << endl;

}

void DeleteData(Data* (&d), int& n)
{
	int _n;
	cout << "Введите номер элемента (от 1 до " << n << "): ";
	cin >> _n;
	_n--;

	system("cls");

	//проверка, что ввели правильно значение
	if (_n >= 0 && _n < n) {

		//временный массив
		Data* buf = new Data[n];

		Copy(buf, d, n);

		//выделяем новую память
		--n;
		d = new Data[n];

		int q = 0;

		//запоминаем данные кроме ненужного
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}

		system("cls");
		delete[]buf;

		cout << "Данные удалены!" << endl;
	}
	else
		cout << "Номер введен неверно!" << endl;
}

void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void Copy(Data& d_n, Data& d_o)
{
	d_n._initial.surname = d_o._initial.surname;
	d_n._initial.name = d_o._initial.name;
	d_n._initial.patronymic = d_o._initial.patronymic;

	d_n._date.day = d_o._date.day;
	d_n._date.month = d_o._date.month;
	d_n._date.year = d_o._date.year;

	d_n._number.number = d_o._number.number;

	d_n._address.city = d_o._address.city;
	d_n._address.street = d_o._address.street;
	d_n._address.home = d_o._address.home;
}

void AddDate(Data* (&d), int& n)
{
	//временный массив
	Data* buf = new Data[n];

	Copy(buf, d, n);

	//выделяем новую память
	n++;
	d = new Data[n];

	//возвращаем данные
	Copy(d, buf, --n);

	cout << "Введите ФИО: ";
	cin >> d[n]._initial.surname >> d[n]._initial.name >> d[n]._initial.patronymic;

	cout << "Введите дату: ";
	cin >> d[n]._date.day >> d[n]._date.month >> d[n]._date.year;

	cout << "Введите номер телефона: ";
	cin >> d[n]._number.number;

	cout << "Введите адрес: ";
	cin >> d[n]._address.city >> d[n]._address.home;

	system("cls");

	cout << "Данные добавлены!" << endl;

	delete[]buf;
}

void DataSorting(Data* d, int n)
{
	//временная переменнся
	Data buf;

	//сортировка методом пузырька
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i]._initial.surname > d[j]._initial.surname) {
				Copy(buf, d[j]);
				Copy(d[j], d[i]);
				Copy(d[i], buf);
			}
		}
	}
	
	cout << "Данные отсортированы!" << endl;
}

void Filtr(Data* (&d), int& n)
{
	string nomer;
	int counter = 0;
	cout << "Введите номер телефона, по которому вы хотите посмотреть информацию: ";
	cin >> nomer;
	for (int i = 0; i < n; i++) {
		if (d[i] == nomer) {
			counter = 1;
			cout << "Номер телефона: " << " " << d[i]._number.number << endl;
			cout << "ФИО: " << d[i]._initial.surname << d[i]._initial.name << d[i]._initial.patronymic << endl;
			cout << "Дата: " << " " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;
			cout << "Адрес: " << " " << d[i]._address.city << d[i]._address.street << d[i]._address.home << endl;
			cout << "________________________________________" << endl;
		}
		else {
			if (counter == 0 && i == n - 1)
				cout << "Данного номера телефона не существует" << endl;
		}
	}
}

void SavingData(Data* d, int n, string fileName)
{
	//создаётся поток для записи
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i]._initial.surname << endl;
			record << d[i]._initial.name << endl;
			record << d[i]._initial.patronymic << endl;

			record << d[i]._date.day << endl;
			record << d[i]._date.month << endl;
			record << d[i]._date.year << endl;

			record << d[i]._number.number << endl;

			record << d[i]._address.city << " ";
			if (i < n - 1)
				record << d[i]._address.street << endl;
			else
				record << d[i]._address.street;
			if (i < n - 1)
				record << d[i]._address.home << endl;
			else
				record << d[i]._address.home;

		}

	}
	else
		cout << "Ощибка открытия файла!" << endl;

	record.close();
}


