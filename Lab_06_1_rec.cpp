#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Створення масиву
void Create(int* c, const int size, const int Low, const int High, int i)
{
    c[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create(c, size, Low, High, i + 1);
}

// Виведення масиву
void Print(int* c, const int size, int i)
{
    cout << setw(4) << c[i];

    if (i < size - 1)
        Print(c, size, i + 1);
    else
        cout << endl;
}

// Підрахунок кількості елементів, що задовольняють критерій
int Count(int* c, const int size, int i)
{
    if (i < size)
    {
        if (!(c[i] % 2 == 0 || i % 13 == 0))
            return 1 + Count(c, size, i + 1);
        else
            return Count(c, size, i + 1);
    }
    else
        return 0;
}

// Обчислення суми елементів, що задовольняють критерій
int Sum(int* c, const int size, int i)
{
    if (i < size)
    {
        if (!(c[i] % 2 == 0 || i % 13 == 0))
            return c[i] + Sum(c, size, i + 1);
        else
            return Sum(c, size, i + 1);
    }
    else
        return 0;
}

// Заміна нулями елементів, що задовольняють критерій
void Zero(int* c, const int size, int i)
{
    if (!(c[i] % 2 == 0 || i % 13 == 0))
        c[i] = 0;

    if (i < size - 1)
        Zero(c, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел

    const int n = 21;
    int c[n];

    const int Low = 15;
    const int High = 85;

    Create(c, n, Low, High, 0);

    cout << "Початковий масив:" << endl;
    Print(c, n, 0);

    cout << "Кількість = " << Count(c, n, 0) << endl;
    cout << "Сума = " << Sum(c, n, 0) << endl;

    Zero(c, n, 0);

    cout << "Змінений масив:" << endl;
    Print(c, n, 0);

    return 0;
}