#include "Header.h"

int** createArray(int& n, int& m) {
	cout << "������� ���������� ����� ������� : ";
	cin >> n;
	cout << "������� ���������� �������� ������� : ";
	cin >> m;
	int** a = new int* [n];      //��������� ������
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	return a;
}

void deleteArray(int** a, int n) {
	for (int i = 0; i < n; i++) {       //�������� ������
		delete[]a[i];
	}
	delete[] a;
}

void inputArrayRandom(int** a, int n, int m) {
    srand(time(NULL));
    cout << "���������� ������: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 10 + 1;
            if (rand() % 2 == 0)
                a[i][j] *= -1;
            cout << setw(4) << a[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void inputArrayHand(int** a, int n, int m) {
    cout << "������� �������� �������: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
}

void menuInputArray(int** a, int n, int m) {
    char response;
    while (true) {
        cout << "\n----------���� ����� ��������� �������----------------------------\n";
        cout << " 1 - ���� � ����������\n 2 - ��������� ����\n";
        cout << "----------------------------------------------------------------------\n";
        cin >> response;
        switch (response) {
        case '1': inputArrayHand(a, n, m); return;
        case '2': inputArrayRandom(a, n, m); return;
        default: cout << "������. ������ ���� �� ����������.\n";
        }
    }
}

void outputArray(int** a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

void sortarray(int** a, int n, int m) {
    for (int t = 0; t < m; t++) {
        for (int i = 0; i < n - 1; i++) {
            if (a[i][t] < 0)
            for (int j = i + 1; j < n; j++) {
                if (a[i][t] > a[j][t] && a[j][t] < 0) {
                    int temp = a[j][t];
                    a[j][t] = a[i][t];
                    a[i][t] = temp;
                }
            }
        }
    }
    cout << "��������������� �������: \n";
    outputArray(a, n, m);
}
