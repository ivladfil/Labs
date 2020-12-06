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
		cout << "Завод производит: " << product << endl;
		cout << "Работает " << kolvo_rab << " работников" << endl;
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
		cout << "	Директор:" << endl;
		cout << "Имя: " << fir_name << endl;
		cout << "Фамилия: " << sec_name << endl;
		cout << "Зарплата: " << zp << endl;
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
		cout << "Завод выпускает " << kol_day << " продукции в день" << endl;
		cout << "Над 1 продукцией работают " << rab_on_one << " человек" << endl;
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
		cout << "	Заведующий:" << endl;
		cout << "Имя: " << fir_name << endl;
		cout << "Фамилия: " << sec_name << endl;
		cout << "Зарплата: " << zp << endl;
	}
};

int main() {
	setlocale(0, "rus");
	cout << "Введите наименование продукции: ";
	string prod, name, sname, name1, sname1;
	int zp, zp1, kold, rabo, kolr;
	prod = writeWords();
	cout << endl;
	cout << "Введите кол-во работников на зваоде: ";
	kolr = writeNumbers();
	cout << endl;
	cout << "Введите имя директора: ";
	name = writeWords();
	cout << endl;
	cout << "Введите фамилию директора: ";
	sname = writeWords();
	cout << endl;
	cout << "Введите зарплату директора: ";
	zp = writeNumbers();
	cout << endl;
	cout << "Введите имя заведующего: ";
	name1 = writeWords();
	cout << endl;
	cout << "Введите фамилию заведующего: ";
	sname1 = writeWords();
	cout << endl;
	cout << "Введите зарплату заведующего: ";
	zp1 = writeNumbers();
	cout << endl;
	cout << "Введите кол-во выпускаемой продукции в день: ";
	kold = writeNumbers();
	cout << endl;
	cout << "Введите кол-во работников на 1 продукции: ";
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
