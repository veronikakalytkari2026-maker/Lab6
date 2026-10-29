#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Створення масиву
void Create(int* c, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        c[i] = Low + rand() % (High - Low + 1);
}

// Виведення масиву
void Print(int* c, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << c[i];

    cout << endl;
}

// Підрахунок кількості елементів, що задовольняють критерій
int Count(int* c, const int size)
{
    int k = 0;

    for (int i = 0; i < size; i++)
        if (!(c[i] % 2 == 0 || i % 13 == 0))
            k++;

    return k;
}

// Обчислення суми елементів, що задовольняють критерій
int Sum(int* c, const int size)
{
    int S = 0;

    for (int i = 0; i < size; i++)
        if (!(c[i] % 2 == 0 || i % 13 == 0))
            S += c[i];

    return S;
}

// Заміна нулями елементів, що задовольняють критерій
void Zero(int* c, const int size)
{
    for (int i = 0; i < size; i++)
        if (!(c[i] % 2 == 0 || i % 13 == 0))
            c[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    const int n = 21;
    int c[n];

    const int Low = 15;
    const int High = 85;

    Create(c, n, Low, High);

    cout << "Початковий масив:" << endl;
    Print(c, n);

    cout << "Кількість = " << Count(c, n) << endl;
    cout << "Сума   = " << Sum(c, n) << endl;

    Zero(c, n);

    cout << "Змінений масив:" << endl;
    Print(c, n);

    return 0;
}