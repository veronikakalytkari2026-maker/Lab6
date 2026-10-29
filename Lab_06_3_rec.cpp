#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Прототип звичайної рекурсивної функції
int Min(int* a, const int size, int i);

// Прототип рекурсивного шаблону функції
template <typename T>
T Min(T* a, const int size, int i);

// Виведення масиву
template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(10) << a[i];

    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

// Знаходження найменшого елемента рекурсивною функцією
int Min(int* a, const int size, int i)
{
    if (i == size - 1)
        return a[i];

    int m = Min(a, size, i + 1);

    if (a[i] < m)
        return a[i];
    else
        return m;
}

// Знаходження найменшого елемента рекурсивним шаблоном функції
template <typename T>
T Min(T* a, const int size, int i)
{
    if (i == size - 1)
        return a[i];

    T m = Min<T>(a, size, i + 1);

    if (a[i] < m)
        return a[i];
    else
        return m;
}

int main()
{
    const int n = 10;

    int a[n] = { 7, -2, 5, 0, -8, 4, 12, -1, 3, 6 };

    double b[n] = { 7.1, -2.4, 5.5, 0.0, -8.2, 4.6, 12.3, -1.1, 3.9, 6.2 };

    string c[n] = { "delta", "alpha", "gamma", "beta", "omega", "kappa", "eta", "theta", "zeta", "iota" };

    cout << "Massiv a:" << endl;
    Print(a, n, 0);

    cout << "Min(a, n, 0) = " << Min(a, n, 0) << endl;

    cout << "Min<int>(a, n, 0) = " << Min<int>(a, n, 0) << endl;

    cout << endl << "Massiv b:" << endl;
    Print(b, n, 0);

    cout << "Min<double>(b, n, 0) = " << Min<double>(b, n, 0) << endl;

    cout << endl << "Massiv c:" << endl;
    Print(c, n, 0);

    cout << "Min<string>(c, n, 0) = " << Min<string>(c, n, 0) << endl;

    return 0;
}