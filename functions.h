#pragma once
//���������� ���� ����������� ���������, �����������, ���, �������� � ��������� �������

#include <iostream>// ��������� ����� � ������
#include <fstream>//���������� ��� ������ � �������
#include <string>//���������� ��� ������ �� ��������
#include <Windows.h>//���������� ��� ������ � ������� ��������� �������

using namespace std;

/*
	������:
	1. �������� (���)
	2. ����
	3. ����� ��������
	4. �����
*/

//��������� ���
struct Initial {
	string surname,
		name,
		patronymic;
};

//��������� ����
struct Date {
	int day,
		month,
		year;
};

//�������� ������
struct Phone_number {
	string number;
};

//��������� ������
struct Address {
	string city,
		street,
		home;
};

//��������� ������
struct Data {
	Initial _initial;
	Date _date;
	Phone_number _number;
	Address _address;
};

//��������� �������
void DataEntry(Data* (&d), int& n); //���� ������ �������
void ReadingData(Data* (&d), int& n, string fileName); //������ ������ �� �����
void Print(Data* d, int n); //����� ������
void DataChange(Data* (&d), int n); //��������� ������
void DeleteData(Data* (&d), int& n); //�������� ������
void Copy(Data* (&d_n), Data* (&d_o), int n); // ����� ������
void Copy(Data& d_n, Data& d_o); //����� ������ ��������
void AddDate(Data* (&d), int& n); //�������� ������
void DataSorting(Data* d, int n); //���������� ������
void Filtr(Data* (&d), int& n); // ���������� ������
void SavingData(Data* d, int n, string fileName); //���������� ������