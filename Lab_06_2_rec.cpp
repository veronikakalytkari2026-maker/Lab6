#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Створення масиву рекурсивним способом
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Виведення масиву рекурсивним способом
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];

    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Обчислення суми елементів з парними індексами
int SumEvenIndex(int* a, const int size, int i)
{
    if (i < size)
        return a[i] + SumEvenIndex(a, size, i + 2);
    else
        return 0;
}

// Підрахунок кількості елементів з парними індексами
int CountEvenIndex(int* a, const int size, int i)
{
    if (i < size)
        return 1 + CountEvenIndex(a, size, i + 2);
    else
        return 0;
}

// Обчислення середнього арифметичного елементів
// з парними індексами
double AverageEvenIndex(int* a, const int size)
{
    int k = CountEvenIndex(a, size, 0);

    if (k == 0)
        return 0;

    return (double)SumEvenIndex(a, size, 0) / k;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;
    int a[n];

    const int Low = -10;
    const int High = 30;

    Create(a, n, Low, High, 0);

    cout << "Початковий масив:" << endl;
    Print(a, n, 0);

    cout << "Середнє арифметичне = "
         << fixed << setprecision(2)
         << AverageEvenIndex(a, n) << endl;

    return 0;
}