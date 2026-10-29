
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Створення масиву
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Виведення масиву
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];

    cout << endl;
}

// Обчислення суми елементів з парними індексами
int SumEvenIndex(int* a, const int size)
{
    int S = 0;

    for (int i = 0; i < size; i += 2)
        S += a[i];

    return S;
}

// Обчислення середнього арифметичного елементів з парними індексами
double AverageEvenIndex(int* a, const int size)
{
    int k = 0;

    for (int i = 0; i < size; i += 2)
        k++;

    if (k == 0)
        return 0;

    return (double)SumEvenIndex(a, size) / k;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;
    int a[n];

    int Low = -10;
    int High = 30;

    Create(a, n, Low, High);

    cout << "Початковий масив:" << endl;
    Print(a, n);

    cout << "Середнє арифметичне = "
         << fixed << setprecision(2)
         << AverageEvenIndex(a, n) << endl;

    return 0;
}