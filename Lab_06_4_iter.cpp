#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Введення елементів масиву
void Create(int* c, const int size)
{
    for (int i = 0; i < size; i++)
        cin >> c[i];
}

// Виведення масиву
void Print(int* c, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << c[i];

    cout << endl;
}

// Пошук мінімального за модулем елемента
int MinAbs(int* c, const int size)
{
    int m = c[0];

    for (int i = 1; i < size; i++)
        if (abs(c[i]) < abs(m))
            m = c[i];

    return m;
}

// Пошук індексу першого нульового елемента
int FirstZeroIndex(int* c, const int size)
{
    for (int i = 0; i < size; i++)
        if (c[i] == 0)
            return i;

    return -1;
}

// Обчислення суми модулів елементів після першого нульового елемента
int SumAbsAfterFirstZero(int* c, const int size, const int zeroIndex)
{
    int S = 0;

    if (zeroIndex == -1)
        return 0;

    for (int i = zeroIndex + 1; i < size; i++)
        S += abs(c[i]);

    return S;
}

// Перестановка: спочатку парні позиції, потім непарні, зі збереженням порядку
void Rearrange(int* c, const int size)
{
    int* temp = new int[size];
    int j = 0;

    for (int i = 1; i < size; i += 2)
        temp[j++] = c[i];

    for (int i = 0; i < size; i += 2)
        temp[j++] = c[i];

    for (int i = 0; i < size; i++)
        c[i] = temp[i];

    delete[] temp;
}

int main()
{
    int n;

    cout << "Кількість елементів n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "n має бути додатнім." << endl;
        return 1;
    }

    int* c = new int[n];

    cout << "Елементи масиву:" << endl;
    Create(c, n);

    cout << "Початковий масив:" << endl;
    Print(c, n);

    cout << "Мінімальний за модулем елемент = " << MinAbs(c, n) << endl;

    int zeroIndex = FirstZeroIndex(c, n);

    if (zeroIndex == -1)
        cout << "Нульового елемента немає." << endl;
    else
        cout << "Сума модулів після першого нульового елемента = " << SumAbsAfterFirstZero(c, n, zeroIndex) << endl;

    Rearrange(c, n);

    cout << "Масив після перестановки:" << endl;
    Print(c, n);

    delete[] c;

    return 0;
}