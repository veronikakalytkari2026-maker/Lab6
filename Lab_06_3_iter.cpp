#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Прототип звичайної функції
int Min(int* a, const int size);

// Прототип шаблону функції
template <typename T>
T Min(T* a, const int size);

// Виведення масиву
template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(10) << a[i];

    cout << endl;
}

// Знаходження найменшого елемента звичайною функцією
int Min(int* a, const int size)
{
    int m = a[0];

    for (int i = 1; i < size; i++)
        if (a[i] < m)
            m = a[i];

    return m;
}

// Знаходження найменшого елемента шаблоном функції
template <typename T>
T Min(T* a, const int size)
{
    T m = a[0];

    for (int i = 1; i < size; i++)
        if (a[i] < m)
            m = a[i];

    return m;
}

int main()
{
    const int n = 10;

    int a[n] = { 7, -2, 5, 0, -8, 4, 12, -1, 3, 6 };

    double b[n] = { 7.1, -2.4, 5.5, 0.0, -8.2, 4.6, 12.3, -1.1, 3.9, 6.2 };

    string c[n] = { "delta", "alpha", "gamma", "beta", "omega", "kappa", "eta", "theta", "zeta", "iota" };

    cout << "Massiv a:" << endl;
    Print(a, n);

    cout << "Min(a, n) = " << Min(a, n) << endl;

    cout << "Min<int>(a, n) = " << Min<int>(a, n) << endl;

    cout << endl << "Massiv b:" << endl;
    Print(b, n);

    cout << "Min<double>(b, n) = " << Min<double>(b, n) << endl;

    cout << endl << "Massiv c:" << endl;
    Print(c, n);

    cout << "Min<string>(c, n) = " << Min<string>(c, n) << endl;

    return 0;
}