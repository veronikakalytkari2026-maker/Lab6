#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Введення елементів масиву рекурсивно
void Create(int* c, const int size, int i)
{
    if (i < size)
    {
        cin >> c[i];
        Create(c, size, i + 1);
    }
}

// Виведення масиву рекурсивно
void Print(int* c, const int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << c[i];
        Print(c, size, i + 1);
    }
    else
        cout << endl;
}

// Пошук мінімального за модулем елемента
int MinAbs(int* c, const int size, int i)
{
    if (i == size - 1)
        return c[i];

    int m = MinAbs(c, size, i + 1);

    if (abs(c[i]) < abs(m))
        return c[i];
    else
        return m;
}

// Пошук індексу першого нульового елемента
int FirstZeroIndex(int* c, const int size, int i)
{
    if (i >= size)
        return -1;

    if (c[i] == 0)
        return i;

    return FirstZeroIndex(c, size, i + 1);
}

// Обчислення суми модулів елементів
// після першого нульового елемента
int SumAbsAfterFirstZero(int* c, const int size, int i)
{
    if (i >= size)
        return 0;

    return abs(c[i]) +
           SumAbsAfterFirstZero(c, size, i + 1);
}

// Копіювання елементів із парних позицій
int CopyEvenPositions(int* c, int* temp,
                      const int size, int i, int j)
{
    if (i >= size)
        return j;

    temp[j] = c[i];

    return CopyEvenPositions(c, temp, size, i + 2, j + 1);
}

// Копіювання елементів із непарних позицій
void CopyOddPositions(int* c, int* temp,
                      const int size, int i, int j)
{
    if (i >= size)
        return;

    temp[j] = c[i];

    CopyOddPositions(c, temp, size, i + 2, j + 1);
}

// Копіювання результату назад у масив
void CopyBack(int* c, int* temp, const int size, int i)
{
    if (i < size)
    {
        c[i] = temp[i];
        CopyBack(c, temp, size, i + 1);
    }
}

// Перестановка елементів рекурсивно
void Rearrange(int* c, const int size)
{
    int* temp = new int[size];

    int j = CopyEvenPositions(c, temp, size, 1, 0);

    CopyOddPositions(c, temp, size, 0, j);

    CopyBack(c, temp, size, 0);

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
    Create(c, n, 0);

    cout << "Початковий масив:" << endl;
    Print(c, n, 0);

    cout << "Мінімальний за модулем елемент = " << MinAbs(c, n, 0) << endl;

    int zeroIndex = FirstZeroIndex(c, n, 0);

    if (zeroIndex == -1)
        cout << "Нульового елемента немає." << endl;
    else
        cout << "Сума модулів після першого нульового елемента = " << SumAbsAfterFirstZero(c, n, zeroIndex + 1) << endl;

    Rearrange(c, n);

    cout << "Масив після перестановки:" << endl;
    Print(c, n, 0);

    delete[] c;

    return 0;
}