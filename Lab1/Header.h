#pragma once

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int** createArray(int& n, int& m);
void deleteArray(int** a, int n);

void inputArrayRandom(int** a, int n, int m);
void inputArrayHand(int** a, int n, int m);
void menuInputArray(int** a, int n, int m);

void outputArray(int** a, int n, int m);

void sortarray(int** a, int n, int m);
