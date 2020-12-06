#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Virus {
protected:
	string type;
	string name;
public:
	Virus() {

	}
	Virus(string a, string a1) {
		type = a;
		name = a1;
	}
	void show() {
		cout << " �������� ������: " << name << endl;
		cout << " ��� ������: " << type << endl;
	}
	void changeType(string w) {
		type = w;
	}
	void changeName(string w) {
		name = w;
	}
	string getName() {
		return name;
	}
	string getType() {
		return type;
	}
};

class WorldInfVirus :virtual public Virus {
protected:
	int godZarinWorld;
	int kolvoInWrold;
public:
	WorldInfVirus() {
		godZarinWorld = 0;
		kolvoInWrold = 0;
	}
	WorldInfVirus(string a, string a1, int a2, int a3) :Virus(a, a1) {
		godZarinWorld = a2;
		kolvoInWrold = a3;
	}
	void changegodZarinWorld(int w) {
		godZarinWorld = w;
	}
	void changekolvoInWrold(int w) {
		kolvoInWrold = w;
	}
	int getkolvoInWrold() {
		return kolvoInWrold;
	}
	int getgodZarinWorld() {
		return godZarinWorld;
	}
	void show() {
		cout << " ��� ������� ��������� � ����: " << godZarinWorld << endl;
		cout << " ���-�� ���������� � ����: " << kolvoInWrold << endl;
	}
};

class CountryInfVirus :virtual public Virus {
protected:
	int godZarinCountr;
	int kolvoInCountry;
public:
	CountryInfVirus() {
		godZarinCountr = 0;
		kolvoInCountry = 0;
	}
	CountryInfVirus(string a, string a1, int a2, int a3) :Virus(a, a1) {
		godZarinCountr = a2;
		kolvoInCountry = a3;
	}
	void changegodZarinCountr(int w) {
		godZarinCountr = w;
	}
	void changekolvoInCountry(int w) {
		kolvoInCountry = w;
	}
	int getkolvoInCountry() {
		return kolvoInCountry;
	}
	int getgodZarinCountr() {
		return godZarinCountr;
	}
	void show() {
		cout << " ��� ������� ��������� � ������: " << godZarinCountr << endl;
		cout << " ���-�� ���������� � ������: " << kolvoInCountry << endl;
	}
};

class VirusName :public WorldInfVirus, public CountryInfVirus {
private:
	string gorod;
	string country;
public:
	VirusName() {};
	VirusName(string a, string a1, string a2, string a3, int s, int s1, int s2, int s3) :CountryInfVirus(a2, a3, s2, s3), WorldInfVirus(a2, a3, s, s1), Virus(a2, a3) {
		gorod = a;
		country = a1;
	}
	void show() {
		cout << " ������: " << country << endl;
		Virus::show();
		WorldInfVirus::show();
		CountryInfVirus::show();
		cout << " ����� � �������� ��� ��������: " << gorod << endl;
	}
	void changegorod(string w) {
		gorod = w;
	}
	void changecountry(string w) {
		country = w;
	}
	string getgorod() {
		return gorod;
	}
	string getcountry() {
		return country;
	}
};

int chooseMenu();
string writeWords();
int writeNumbers();
int chooseWhoRed(VirusName*&, int);
int chooseWhatRed(VirusName*&, int);

int main() {
	setlocale(0, "rus");
	int nVirus = 0;
	VirusName* virus = new VirusName[nVirus];
	while (true) {
		int choose = chooseMenu();
		if (choose == 1) {
			if (nVirus != 0) {
				while (true) {
					int choose1 = chooseWhoRed(virus, nVirus);
					if (choose1 == nVirus) break;
					while (true) {
						int choose2 = chooseWhatRed(virus, choose1);
						if (choose2 == 8) break;
						if (choose2 == 0) {
							cout << "������� �������� ������: ";
							string ptr1 = writeWords();
							virus[choose1].changeName(ptr1);
							system("cls");
						}
						else
							if (choose2 == 1) {
								cout << "������� ��� ������: ";
								string ptr1 = writeWords();
								virus[choose1].changeType(ptr1);
								system("cls");
							}
							else
								if (choose2 == 2) {
									cout << "������� ��� ������� ��������� � ����: ";
									int ptr = writeNumbers();
									virus[choose1].changegodZarinWorld(ptr);
									system("cls");
								}
								else
									if (choose2 == 3) {
										cout << "������� ���-�� ���������� � ����: ";
										int ptr = writeNumbers();
										virus[choose1].changekolvoInWrold(ptr);
										system("cls");
									}
									else
										if (choose2 == 4) {
											cout << "������� ������: ";
											string ptr1 = writeWords();
											virus[choose1].changecountry(ptr1);
											system("cls");
										}
										else
											if (choose2 == 5) {
												cout << "������� ��� ������� ��������� � ������: ";
												int ptr = writeNumbers();
												virus[choose1].changegodZarinCountr(ptr);
												system("cls");
											}
											else
												if (choose2 == 6) {
													cout << "������� ���-�� ���������� � ������: ";
													int ptr = writeNumbers();
													virus[choose1].changekolvoInCountry(ptr);
													system("cls");
												}
												else
													if (choose2 == 7) {
														cout << "������� ����� � ������� ��� ��������: ";
														string ptr1 = writeWords();
														virus[choose1].changegorod(ptr1);
														system("cls");
													}
					}
				}
			}
			else {
				cout << "�� ��� �� �������� �������" << endl;
				system("pause");
				system("cls");
			}
		}
		else
			if (choose == 0) {
				VirusName sum;
				cout << "������� �������� ������: ";
				string ptr1 = writeWords();
				sum.changeName(ptr1);
				system("cls");
				cout << "������� ��� ������: ";
				ptr1 = writeWords();
				sum.changeType(ptr1);
				system("cls");
				cout << "������� ��� ������� ��������� � ����: ";
				int ptr = writeNumbers();
				sum.changegodZarinWorld(ptr);
				system("cls");
				cout << "������� ���-�� ���������� � ����: ";
				ptr = writeNumbers();
				sum.changekolvoInWrold(ptr);
				system("cls");
				cout << "������� ������: ";
				ptr1 = writeWords();
				sum.changecountry(ptr1);
				system("cls");
				cout << "������� ��� ������� ��������� � ������: ";
				ptr = writeNumbers();
				sum.changegodZarinCountr(ptr);
				system("cls");
				cout << "������� ���-�� ���������� � ������: ";
				ptr = writeNumbers();
				sum.changekolvoInCountry(ptr);
				system("cls");
				cout << "������� ����� � ������� ��� ��������: ";
				ptr1 = writeWords();
				sum.changegorod(ptr1);
				system("cls");
				nVirus++;
				VirusName* ptrr = new VirusName[nVirus];
				for (int i = 0; i < nVirus - 1; i++)
					ptrr[i] = virus[i];
				virus = ptrr;
				ptrr = NULL;
				delete[]ptrr;
				virus[nVirus - 1] = sum;
			}
			else
				if (choose == 2) {
					for (int i = 0; i < nVirus; i++) {
						virus[i].show();
						cout << endl;
						cout << endl;
					}
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) break;
	}
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
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "����������� ����� � ���� �������� ����� ����: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> �������� �����" << endl; }
		else { cout << " �������� �����" << endl; }

		if (choose_menu == 1) { cout << " -> ������������� ������" << endl; }
		else { cout << " ������������� ������" << endl; }

		if (choose_menu == 2) { cout << " -> �������� ���� �������" << endl; }
		else { cout << " �������� ���� �������" << endl; }

		if (choose_menu == 3) { cout << " -> ��������� ���������" << endl; }
		else { cout << " ��������� ���������" << endl; }

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

int chooseWhoRed(VirusName*& virus, int nVirus) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "����������� ����� � ���� �������� ����� ����" << endl;
		choose_menu = (choose_menu + (nVirus + 1)) % (nVirus + 1);

		for (int i = 0; i < nVirus; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << virus[i].getName() << endl; }
			else { cout << " " << i + 1 << " - " << virus[i].getName() << endl; }

		if (choose_menu == nVirus) { cout << " -> ����� � ������ ������" << endl; }
		else cout << " ����� � ������ ������" << endl;

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

int chooseWhatRed(VirusName*& virus, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "����������� ����� � ���� �������� ����� ����" << endl;
		choose_menu = (choose_menu + 9) % 9;

		if (choose_menu == 0) { cout << " -> �������� ������: " << virus[choose].getName() << endl; }
		else cout << " �������� ������: " << virus[choose].getName() << endl;

		if (choose_menu == 1) { cout << " -> ��� ������: " << virus[choose].getType() << endl; }
		else cout << " ��� ������: " << virus[choose].getType() << endl;

		if (choose_menu == 2) { cout << " -> ��� ������� ��������� � ����: " << virus[choose].getgodZarinWorld() << endl; }
		else cout << " ��� ������� ��������� � ����: " << virus[choose].getgodZarinWorld() << endl;

		if (choose_menu == 3) { cout << " -> ���-�� ���������� � ����: " << virus[choose].getkolvoInWrold() << endl; }
		else cout << " ���-�� ���������� � ����: " << virus[choose].getkolvoInWrold() << endl;

		if (choose_menu == 4) { cout << " -> ������: " << virus[choose].getcountry() << endl; }
		else cout << " ������: " << virus[choose].getcountry() << endl;

		if (choose_menu == 5) { cout << " -> ��� ������� ��������� � ������: " << virus[choose].getgodZarinCountr() << endl; }
		else cout << " ��� ������� ��������� � ������: " << virus[choose].getgodZarinCountr() << endl;

		if (choose_menu == 6) { cout << " -> ���-�� ���������� � ������: " << virus[choose].getkolvoInCountry() << endl; }
		else cout << " ���-�� ���������� � ������: " << virus[choose].getkolvoInCountry() << endl;

		if (choose_menu == 7) { cout << " -> ����� � ������� ��� ��������: " << virus[choose].getgorod() << endl; }
		else cout << " ����� � ������� ��� ��������: " << virus[choose].getgorod() << endl;

		if (choose_menu == 8) { cout << " -> ����� � ���� ������ ������ " << endl; }
		else cout << " ����� � ���� ������ ������ " << endl;


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
