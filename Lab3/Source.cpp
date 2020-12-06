#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Array {
	int** mas;
	int n;
public:
	Array(int ValueN) {
		n = ValueN;
		mas = new int* [n];
		for (int i = 0; i < n; i++)
			mas[i] = new int[n];
	}
	friend ostream& operator<<(ostream& out, const Array& arr) {
		for (int i = 0; i < arr.n; i++) {
			for (int j = 0; j < arr.n; j++)
				out << arr.mas[i][j] << " ";
			out << endl;
		}
		return out;
	}
	friend istream& operator>>(istream& in, const Array& arr) {
		for (int i = 0; i < arr.n; i++)
			for (int j = 0; j < arr.n; j++)
				in >> arr.mas[i][j];
		return in;
	}
	Array operator&(const Array& arr);
	Array operator=(const Array& arr);
	Array operator+(const Array& arr);
	void freeMemory() {
		for (int i = 0; i < n; i++)
			delete mas[i];
		delete[] mas;
	}
};

Array Array::operator+(const Array& arr) {
	Array arr1(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr1.mas[i][j] = mas[i][j] + arr.mas[i][j];
	return arr1;
}

Array Array::operator=(const Array& arr) {
	n = arr.n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			mas[i][j] = arr.mas[i][j];
	return *this;
}

Array Array::operator&(const Array& arr)
{
	Array arr1(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr1.mas[i][j] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int ij = 0; ij < n; ij++)
				arr1.mas[i][j] += mas[i][ij] * arr.mas[ij][j];
	return arr1;
}

int main() {
	setlocale(0, "rus");
	int n;
	cout << "Введите размер массива n = ";
	cin >> n;
	Array arr(n);
	Array arr1(n);
	Array arr2(n);
	Array arr3(n);
	cout << "Введите элементы массива: " << endl;
	cin >> arr;
	cout << "Введите элементы второго массива: " << endl;
	cin >> arr1;
	system("cls");
	arr2 = arr & arr1;
	cout << "Умножеине матриц = " << endl;
	cout << arr2;
	arr3 = arr + arr1;
	cout << "Сложение матриц = " << endl;
	cout << arr3;
	arr.freeMemory();
	arr1.freeMemory();
	arr2.freeMemory();
	arr3.freeMemory();
	cout << "Память освобождена!!!" << endl;
	return 0;
}

