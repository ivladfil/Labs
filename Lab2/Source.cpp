#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int viborZapMass();
int viborMenu();

class Array {
	int** mas;
	int n, m;
public:
	void fillArray();
	void obnuleniStrAndStolb();
	void swapOddAndFirst();
	void printArray() const;
	Array(int ValueN, int ValueM);
	~Array();
};

Array::Array(int ValueN, int ValueM) {
	n = ValueN; m = ValueM;
	mas = new int* [n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[m];
}

Array::~Array() {
	for (int i = 0; i < n; i++)
		delete[]mas[i];
	delete[]mas;
}

void Array::printArray() const {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	system("pause");
	system("cls");
}

void Array::fillArray() {
	int choose = viborZapMass();
	if (choose == 0) {
		system("cls");
		cout << "Введите левый диапозон рандома: ";
		int l = 0, r = 0;
		cin >> l;
		cout << "Введите правый диапозон рандома: ";
		cin >> r;
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mas[i][j] = rand() % (r - l + 1) + l;
	}
	else {
		cout << "Введите элементы массива: " << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << " - строка из " << m << " символов: ";
			for (int j = 0; j < m; j++)
				cin >> mas[i][j];
		}
	}
}

void Array::obnuleniStrAndStolb() {
	int min = mas[0][0];
	int mini = 0, minj = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (mas[i][j] < min) {
				min = mas[i][j];
				mini = i;
				minj = j;
			}
		}
	for (int i = 0; i < n; i++)
		mas[i][minj] = 0;
	for (int j = 0; j < m; j++)
		mas[mini][j] = 0;
}

void Array::swapOddAndFirst() {
	for (int i = 0; i < n; i++) {
		int k = -1;
		for (int j = 0; j < m; j++)
			if (mas[i][j] % 2 != 0) {
				k = j;
				break;
			}
		if (k != -1) {
			int sw = mas[i][0];
			mas[i][0] = mas[i][k];
			mas[i][k] = sw;
		}
	}
}

int main() {
	setlocale(0, "rus");
	int n = 0, m = 0;
	cout << "Введите размеры массива для создания: " << endl;
	cout << "N = ";
	cin >> n;
	cout << "M = ";
	cin >> m;
	system("cls");
	Array Array(n, m);
	Array.fillArray();
	system("cls");
	while (true) {
		int choose = viborMenu();
		if (choose == 0) {
			Array.obnuleniStrAndStolb();
			cout << "Строка и столбец с минимальным элементом матрицы обнулены." << endl;
			system("pause");
			system("cls");
		}
		else
			if (choose == 1) {
				Array.swapOddAndFirst();
				cout << "В каждой строке поменяны первый нечетный и первый элементы." << endl;
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) {
					Array.printArray();
				}
				else
					break;
	}
	return 0;
}

int viborMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " => Обнулить строку и столбец с минимальным элементом матрицы." << endl; }
		else { cout << " Обнулить строку и столбец с минимальным элементом матрицы." << endl; }

		if (choose_menu == 1) { cout << " => В каждой строке первый нечетный поменять с первым." << endl; }
		else { cout << " В каждой строке первый нечетный поменять с первым." << endl; }

		if (choose_menu == 2) { cout << " => Вывести матрицу" << endl; }
		else { cout << " Вывести матрицу" << endl; }

		if (choose_menu == 3) { cout << " => Завершить программу" << endl; }
		else { cout << " Завершить программу" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

int viborZapMass() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите как заполнить матрицу: " << endl;
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) { cout << " => Через рандом" << endl; }
		else { cout << " Через рандом" << endl; }

		if (choose_menu == 1) { cout << " => С клавиатуры" << endl; }
		else { cout << " С клавиатуры" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}