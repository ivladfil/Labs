#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int chooseMenu();
string writeWords();
string writeNumbers();
string chooseVirus();

class Virus {
protected:
	string name;
	string god_open;
public:
	Virus(string a, string a1) {
		name = a;
		god_open = a1;
	}
	virtual void showData() = 0;
};

class Bio :public Virus {
private:
	string classif;
	string kolvo_shtamm;
public:
	Bio(string a, string a1, string a2, string a3) :Virus(a, a1) {
		classif = a2;
		kolvo_shtamm = a3;
	}
	void showData() {
		cout << "	Биологический вирус" << endl;
		cout << " Тип вируса: " << classif << endl;
		cout << " Год появления: " << god_open << endl;
		cout << " Название: " << name << endl;
		cout << " Кол-во штаммов: " << kolvo_shtamm << endl;
	}
};

class Tech :public Virus {
private:
	string classif;
	string kol_vo_komp;
public:
	Tech(string a, string a1, string a2, string a3) :Virus(a, a1) {
		classif = a2;
		kol_vo_komp = a3;
	}
	void showData() {
		cout << "	Технологический вирус" << endl;
		cout << " Тип вируса: " << classif << endl;
		cout << " Год появления: " << god_open << endl;
		cout << " Название: " << name << endl;
		cout << " Кол-во зараженных ком.: " << kol_vo_komp << endl;
	}
};

class AntiVirus :public Virus {
private:
	string type_virus;
	string kolvo_skach;
public:
	AntiVirus(string a, string a1, string a2, string a3) :Virus(a, a1) {
		type_virus = a2;
		kolvo_skach = a3;
	}
	void showData() {
		cout << "	Антивирус" << endl;
		cout << " Для: " << type_virus << endl;
		cout << " Год появления: " << god_open << endl;
		cout << " Название: " << name << endl;
		cout << " Кол-во скачиваний/вакцинаций: " << kolvo_skach << endl;
	}
};

int main() {
	setlocale(0, "rus");
	int n = 1;
	Virus** mas = new Virus * [n];
	n--;
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			string name, god_open, classif, kolvo_shtamm;
			cout << "Введите имя вируса: ";
			name = writeWords();
			system("cls");
			cout << "Введите год открытия вируса: ";
			god_open = writeNumbers();
			system("cls");
			cout << "Введите тип вируса: ";
			classif = writeWords();
			system("cls");
			cout << "Введите кол-во штаммов: ";
			kolvo_shtamm = writeNumbers();
			system("cls");
			mas[n] = new Bio(name, god_open, classif, kolvo_shtamm);
			mas[n]->showData();
			n++;
			n++;
			Virus** ptr = new Virus * [n];
			n--;
			copy(mas, mas + n, ptr);
			mas = ptr;
			ptr = NULL;
			delete[]ptr;
			system("pause");
			system("cls");
		}
		else
			if (choose == 1) {
				string name, god_open, type_virus, kolvo_skach;
				cout << "Введите имя вируса: ";
				name = writeWords();
				system("cls");
				cout << "Введите год создания вируса: ";
				god_open = writeNumbers();
				system("cls");
				cout << "Введите тип вируса: ";
				type_virus = writeWords();
				system("cls");
				cout << "Введите кол-во зараженных комп.: ";
				kolvo_skach = writeNumbers();
				system("cls");
				mas[n] = new Tech(name, god_open, type_virus, kolvo_skach);
				mas[n]->showData();
				n++;
				n++;
				Virus** ptr = new Virus * [n];
				n--;
				copy(mas, mas + n, ptr);
				mas = ptr;
				ptr = NULL;
				delete[]ptr;
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) {
					string name, god_open, classif, kol_vo_komp;
					cout << "Введите имя антивируса: ";
					name = writeWords();
					system("cls");
					cout << "Введите год открытия вируса: ";
					god_open = writeNumbers();
					system("cls");
					classif = chooseVirus();
					system("cls");
					cout << "Введите кол-во скачиваний/вакцинаций: ";
					kol_vo_komp = writeNumbers();
					system("cls");
					mas[n] = new AntiVirus(name, god_open, classif, kol_vo_komp);
					mas[n]->showData();
					n++;
					n++;
					Virus** ptr = new Virus * [n];
					n--;
					copy(mas, mas + n, ptr);
					mas = ptr;
					ptr = NULL;
					delete[]ptr;
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) {
						for (int i = 0; i < n; i++)
							mas[i]->showData();
						system("pause");
						system("cls");
					}
					else break;
	}
	delete[] mas;
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
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

string writeNumbers() {
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
	return numbers;
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) { cout << " -> Биологический вирус" << endl; }
		else { cout << " Биологический вирус" << endl; }

		if (choose_menu == 1) { cout << " -> Технологический вирус" << endl; }
		else { cout << " Технологический вирус" << endl; }

		if (choose_menu == 2) { cout << " -> Антивирус" << endl; }
		else { cout << " Антивирус" << endl; }

		if (choose_menu == 3) { cout << " -> Вывод всей информации" << endl; }
		else { cout << " Вывод всей информации" << endl; }

		if (choose_menu == 4) { cout << " -> Завершить программу" << endl; }
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

string chooseVirus() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) { cout << " -> Биологический вирус" << endl; }
		else { cout << " Биологический вирус" << endl; }

		if (choose_menu == 1) { cout << " -> Технологический вирус" << endl; }
		else { cout << " Технологический вирус" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) {
			system("cls");
			if (choose_menu == 0) return "Bio";
			else
				return "Tech";
		}
		system("cls");
	}
}