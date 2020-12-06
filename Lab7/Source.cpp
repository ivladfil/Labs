#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

template<typename T> class Time {
private:
	T hour;
	T minute;
	T second;
public:
	Time() {
		hour = 0;
		minute = 0;
		second = 0;
	};
	Time(T h, T m, T s) {
		hour = h;
		minute = m;
		second = s;
	}
	Time(const Time<T>& clock) {
		hour = clock.hour;
		minute = clock.minute;
		second = clock.second;
	}
	void task();
	void showTime();
	friend void operator>><T>(istream&, Time<T>&);
	void operator+=(Time<T>&);
};

int writeSeconds();
int chooseMainMenu();
int menuChange(Time<int>&);
int writeNumbers(int);

template <typename T> void Time<T>::task() {
	if (hour < 12)
		cout << "������ ����� �� �������" << endl << endl;
	else if (hour == 12 && minute == 0 && second == 0)
		cout << "�������" << endl << endl;
	else cout << "������ ����� ����� �������" << endl << endl;
}

template <typename T> void Time<T>::showTime() {
	if (hour <= 9)
		cout << "0" << hour << ":";
	else cout << hour << ":";
	if (minute <= 9)
		cout << "0" << minute << ":";
	else cout << minute << ":";
	if (second <= 9)
		cout << "0" << second << endl;
	else cout << second;
}

template<typename T> void operator>>(istream& in, Time<T>& tm) {
	cout << "������� ����: ";
	tm.hour = writeNumbers(24);
	system("cls");
	cout << "������� ������: ";
	tm.minute = writeNumbers(60);
	system("cls");
	cout << "������� �������: ";
	tm.second = writeNumbers(60);
	system("cls");
}

template<typename T> void Time<T>::operator+=(Time<T>& tm) {
	cout << "�������, ������� ������ �������� � ������� ";
	tm.showTime();
	cout << " : ";
	int second1 = writeSeconds();
	hour = hour + (second + second1) / 3600;
	minute = minute + ((second + second1) % 3600) / 60;
	second = ((second + second1) % 3600) % 60;
	while (second >= 60)
	{
		minute += 1;
		second = second - 60;
	}
	while (minute >= 60)
	{
		hour += 1;
		minute = minute - 60;
	}
	while (hour >= 24)
		hour = hour - 24;
	cout << "������������ �����: ";
	showTime();
}

int main() {
	setlocale(0, "rus");
	int nTime = 0;
	Time<int>* mas = new Time<int>[1];
	while (true)
	{
		int chooseMenu1 = chooseMainMenu();
		if (chooseMenu1 == 0)
		{
			nTime++;
			Time<int>* ptr = new Time<int>[nTime];
			for (int i = 0; i < nTime - 1; i++)
				ptr[i] = mas[i];
			mas = ptr;
			ptr = NULL;
			delete[]ptr;
			cin >> mas[nTime - 1];
		}
		else
			if (chooseMenu1 == 1)
			{
				for (int i = 0; i < nTime; i++) {
					mas[i].showTime();
					cout << endl;
				}
				system("pause");
			}
			else
				if (chooseMenu1 == 2)
				{
					for (int i = 0; i < nTime; i++) {
						mas[i].showTime();
						cout << endl;
						mas[i].task();
					}
					system("pause");
				}
				else
					if (chooseMenu1 == 3)
					{
						for (int i = 0; i < nTime; i++)
							mas[i].operator+=(mas[i]);
						system("pause");
					}
					else
						if (chooseMenu1 == 4) break;
	}
	return 0;
}

int chooseMainMenu() {
	int choose_menu = 0, key = 0;
	system("cls");
	while (true)
	{
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) cout << "-> �������� �����" << endl;
		else cout << " �������� �����" << endl;

		if (choose_menu == 1) cout << "-> ���������� �����" << endl;
		else cout << " ���������� �����" << endl;

		if (choose_menu == 2) cout << " -> ���������� ����� ������� ��� �� ������� �����" << endl;
		else cout << " ���������� ����� ������� ��� �� ������� �����" << endl;

		if (choose_menu == 3) cout << " -> �������� � ������� �������" << endl;
		else cout << " �������� � ������� �������" << endl;

		if (choose_menu == 4) cout << " -> �����" << endl;
		else cout << " �����" << endl;

		key = _getch();
		if (key == 224)
		{
			key = _getch();
			if (key == 72) choose_menu--;
			if (key == 80) choose_menu++;
		}
		if (key == 13) {
			system("cls");
			return choose_menu;
		}
		system("cls");
	}
}

int writeNumbers(int c) {
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
				if (key == 13 && numbers.length() != 0 && stoi(numbers) < c) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}

int writeSeconds() {
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
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}
