#pragma once
//объявление всех необходимых библиотек, пространств, имён, структур и прототипы функций

#include <iostream>// библиотек ввода и вывода
#include <fstream>//библиотека для работы с файлами
#include <string>//библиотека для работы со строками
#include <Windows.h>//библиотека для работы с нужными функциями системы

using namespace std;

/*
	Данные:
	1. Инициалы (ФИО)
	2. Дата
	3. Номер телефона
	4. Адрес
*/

//структура ФИО
struct Initial {
	string surname,
		name,
		patronymic;
};

//структура дата
struct Date {
	int day,
		month,
		year;
};

//стуктура номера
struct Phone_number {
	string number;
};

//структура адреса
struct Address {
	string city,
		street,
		home;
};

//структура данных
struct Data {
	Initial _initial;
	Date _date;
	Phone_number _number;
	Address _address;
};

//прототипы функций
void DataEntry(Data* (&d), int& n); //ввод данных вручную
void ReadingData(Data* (&d), int& n, string fileName); //чтение данных из файла
void Print(Data* d, int n); //вывод данных
void DataChange(Data* (&d), int n); //изменение данных
void DeleteData(Data* (&d), int& n); //удаление данных
void Copy(Data* (&d_n), Data* (&d_o), int n); // копия данных
void Copy(Data& d_n, Data& d_o); //копия данных элемента
void AddDate(Data* (&d), int& n); //добавить данные
void DataSorting(Data* d, int n); //сортировка данных
void Filtr(Data* (&d), int& n); // фильтрация данных
void SavingData(Data* d, int n, string fileName); //сохранение данных