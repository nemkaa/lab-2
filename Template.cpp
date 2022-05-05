//массив структур
#include "functions.h"

int _stateMenu;
void Menu() {
	cout << "Выберете действие: " << endl
		<< "(0) Выход из программы" << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод" << endl
		<< "(3) Изменение" << endl
		<< "(4) Удаление" << endl
		<< "(5) Добавление" << endl
		<< "(6) Сортировка" << endl
		<< "(7) Фильтрация" << endl
		<< "(8) Сохранение" << endl
		<< "Ваш выбор: ";
	cin >> _stateMenu;
}

void main() {
	//руссификация консоли ввода и вывода
	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //установка кодовой страницы win-cp 1251 в поток вывода

	Menu();

	//инициализация данных
	int _actions,
		amountOfData = 0;
	string fileName;

	//массив данных
	Data* d = new Data[amountOfData];

	while (_stateMenu != 0)
	{
		switch (_stateMenu)
		{
		case 1:
			system("cls"); //очистка консоли

			cout << "Ввод вручную из файла?: ";
			cin >> _actions;

			system("cls"); //очистка консоли

			if (_actions == 1) {
				//ввод вручную
				DataEntry(d, amountOfData);
			}
			else {
				//ввод из файла
				/*
				//В случае ввода названия файла с данными
				cout << "Введите название файла: ";
				cin >> fileName;//Input.txt
				*/

				ReadingData(d, amountOfData, "Input.txt");
			}

			system("pause"); //задержка консоли
			system("cls"); // очистка консоли
			Menu();
			break;

			/////////////////////////////////////////////////////
		case 2:
			system("cls"); //очистка консоли

			if (amountOfData != 0) {
				Print(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержки консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			/////////////////////////////////////////////////////
		case 3:
			system("cls"); //очистка консоли

			if (amountOfData != 0) {
				DataChange(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержки консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			/////////////////////////////////////////////////////

		case 4:
			system("cls"); //очистка консоли

			if (amountOfData != 0) {
				DeleteData(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержки консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			/////////////////////////////////////////////////////
		case 5:
			system("cls"); //очистка консоли

			if (amountOfData != 0) {
				AddDate(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержки консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			/////////////////////////////////////////////////////
		case 6:
			system("cls"); //очистка консоли

			if (amountOfData != 0) {
				DataSorting(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержки консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			/////////////////////////////////////////////////////
		case 7:
			system("cls"); //очистка консоли

			if (amountOfData != 0) {
				Filtr(d, amountOfData);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержки консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			/////////////////////////////////////////////////////
		case 8:
			system("cls"); //очистка консоли

			cout << "Введите название файла: ";
			cin >> fileName;

			if (amountOfData != 0) {
				SavingData(d, amountOfData, fileName);
			}
			else
				cout << "Данные пусты!" << endl;

			system("pause"); //задержки консоли
			system("cls"); //очистка консоли
			Menu();
			break;
			/////////////////////////////////////////////////////
		default:
			cout << "Неверно введен номер действия!" << endl;
			system("pause"); //задержки консоли
			system("cls"); //очистка консоли
			break;
		}
	}
}