#include <iostream> 
#include <locale.h> 
#include <string>

using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount() {
        balance = 0;
    }

    BankAccount(double balance) {
        this->balance = balance;
    }

    void show();
    void withdraw(double sum); //�����
    void replenish(double sum); //���������
    double get();
    void set(double balance);
}; 
void  BankAccount::show() {
    cout << "��������� ������: " << this->balance << endl;
}

double  BankAccount::get()
{
    return this->balance;
}

void  BankAccount::set(double balance) {
    this->balance = balance;
}

void   BankAccount::withdraw(double sum) {
    balance -= sum;
}

void  BankAccount::replenish(double sum) {
    balance += sum;
}

template <class T>
class Tran
{
    T* that;
    T* prev;
public:
    Tran() :prev(NULL), that(new T) {}
    Tran(const Tran& obj) :
        that(new T(*(obj.that))), prev(NULL) {}
    ~Tran() { delete that;  delete prev; }
    Tran& operator=(const Tran& obj);
    void Show(int);

    bool Begin();
    void Commit();
    void Back();
    T* operator->();
};

template <class T>
Tran<T>& Tran<T>::operator=(const Tran<T>& obj)
{
    if (this != &obj)
    {
        delete that;
        that = new T(*(obj.that));
    }
    return *this;
}

template <class T>
T* Tran<T>::operator->()
{
    return that;
}

template <class T>
void Tran<T>::Show(int fl)
{
    cout << "\t\t���������� ���� ";
    if (!fl)
        cout << "�� ������ ���������� " << endl;
    else
        cout << "����� ���������� ����������: " << endl;

    if (prev)
        cout << "\t\t�� ��������: " << prev->get() << endl;
    else
        cout << "\t\t�� ��������: ������ ����������" << endl;
    cout << "\t\t� ������ ������ " << that->get() << endl;
}

template <class T>
bool Tran<T>::Begin()
{
    delete prev;
    prev = that;
    that = new T(*prev);
    if (!that)
        return false;
    return true;
}

template <class T>
void Tran<T>::Commit()
{
    delete prev;
    prev = NULL;
}

template <class T>
void Tran<T>::Back()
{
    if (prev != NULL)
    {
        delete that;
        that = prev;
        prev = NULL;
    }
}

void showMenu() {
    cout << "\t\t\t\t1 - ��������� ������" << endl;
    cout << "\t\t\t\t2 - ����� �� �����" << endl;
    cout << "\t\t\t\t3 - �������� ������" << endl;
    cout << "\t\t\t\t4 - �������� ��������� ��������" << endl;
    cout << "\t\t\t\t5 - ������� ��������" << endl;
    cout << "\t\t\t\t6 - ���������� �������� ����������" << endl;
    cout << "\t\t\t\t7 - ��������� ����" << endl;
    cout << "\t\t\t\t0 - �����" << endl;
    cout << "\t\t\t>> ";
}

int main()
{
    string log = "";
    Tran<BankAccount> tr;
    setlocale(LC_ALL, "Russian");
    int choice = 0;
    double sum;
    tr.Show(false);
    do {
        showMenu();
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            cout << "\t������� ����� ��� ����������: ";
            cin >> sum;
            if (tr.Begin()) {
                tr->replenish(sum);
                log += "\n����������: " + to_string(sum);
            }
            else {
                cout << "������ � �������� ����������!";
                log += "\n����������: ������ � �������� ����������!";
            }
            break;
        case 2:
            cout << "\t������� ����� ��� ������: ";
            cin >> sum;
            if (tr.Begin()) {
                tr->withdraw(sum);
                log += "\n������: " + to_string(sum);
            }
            else {
                cout << "������ � �������� ����������!";
                log += "\nC�����: ������ � �������� ����������!";
            }

            if (tr->get() < 0) {
                cout << "\t��������� ������������� ������(������������ ������� ��� ������), ���������� ����� �������..." << endl;
                log += "\nC�����: ������������� ������ - ����� �����";
                tr.Back();
            }

            break;
        case 3:
            cout << "\t\t";
            tr->show();
            break;
        case 4:
            tr.Back();
            log += " - ����� �����";
            break;
        case 5:
            cout << endl << log << endl << endl;
            break;
        case 6:
            tr.Show(true);
            break;
        case 7:
            tr.Commit();
            log += "\n���� ���������";
            break;
        default:
            break;
        }
    } while (choice != 0);

    tr.Show(true);
    return 0;
}

