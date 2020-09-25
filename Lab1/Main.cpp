#include <Windows.h>
#include "Header.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = NULL, m = NULL;
    int** a = createArray(n, m);
    menuInputArray(a, n, m);
    sortarray(a, n, m);
    deleteArray(a, n);
    return 0;
}