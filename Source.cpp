#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

string writeWords();
int writeNumbers();

class Zavod {
protected:
	string product;
	int kolvo_rab;
public:
	Zavod(string str, int kol) {
		product = str;
		kolvo_rab = kol;
	}
	void showZavodInf() {
		cout << "����� ����������: " << product << endl;
		cout << "�������� " << kolvo_rab << " ����������" << endl;
	}
};

class Director :public Zavod {
private:
	string fir_name;
	string sec_name;
	int zp;
public:
	Director(string str1, string str2, int zpp, string str, int kol) :Zavod(str, kol) {
		fir_name = str1;
		sec_name = str2;
		zp = zpp;
	}
	void showInfDir() {
		cout << "	��������:" << endl;
		cout << "���: " << fir_name << endl;
		cout << "�������: " << sec_name << endl;
		cout << "��������: " << zp << endl;
	}
};

class Product :public Zavod {
private:
	int kol_day;
	int rab_on_one;
public:
	Product(int kold, int rabo, string str, int kol) :Zavod(str, kol) {
		kol_day = kold;
		rab_on_one = rabo;
	}
	void showInfProd() {
		cout << "����� ��������� " << kol_day << " ��������� � ����" << endl;
		cout << "��� 1 ���������� �������� " << rab_on_one << " �������" << endl;
	}
};

class Zavedu :public Zavod {
private:
	string fir_name;
	string sec_name;
	int zp;
public:
	Zavedu(string str1, string str2, int zpp, string str, int kol) :Zavod(str, kol) {
		fir_name = str1;
		sec_name = str2;
		zp = zpp;
	}
	void showInfRab() {
		cout << "	����������:" << endl;
		cout << "���: " << fir_name << endl;
		cout << "�������: " << sec_name << endl;
		cout << "��������: " << zp << endl;
	}
};

int main() {
	setlocale(0, "rus");
	cout << "������� ������������ ���������: ";
	string prod, name, sname, name1, sname1;
	int zp, zp1, kold, rabo, kolr;
	prod = writeWords();
	cout << endl;
	cout << "������� ���-�� ���������� �� ������: ";
	kolr = writeNumbers();
	cout << endl;
	cout << "������� ��� ���������: ";
	name = writeWords();
	cout << endl;
	cout << "������� ������� ���������: ";
	sname = writeWords();
	cout << endl;
	cout << "������� �������� ���������: ";
	zp = writeNumbers();
	cout << endl;
	cout << "������� ��� �����������: ";
	name1 = writeWords();
	cout << endl;
	cout << "������� ������� �����������: ";
	sname1 = writeWords();
	cout << endl;
	cout << "������� �������� �����������: ";
	zp1 = writeNumbers();
	cout << endl;
	cout << "������� ���-�� ����������� ��������� � ����: ";
	kold = writeNumbers();
	cout << endl;
	cout << "������� ���-�� ���������� �� 1 ���������: ";
	rabo = writeNumbers();
	cout << endl;
	system("cls");
	Director dir(name, sname, zp, prod, kolr);
	Zavedu zav(name1, sname1, zp1, prod, kolr);
	Product produ(kold, rabo, prod, kolr);
	dir.showZavodInf();
	produ.showInfProd();
	dir.showInfDir();
	zav.showInfRab();
	return 0;
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}
