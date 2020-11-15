#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void Create_i(int* a, const int SIZE);
void Print_i(int* a, const int SIZE);
void sort_i(int a[], const int SIZE);

void Create_r(int* a, const int SIZE, int i);
void Print_r(int* a, const int SIZE, int i);
void sort_r(int a[], const int SIZE, int i, int j);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE;
    cout << "Введіть розмір масиву a[]:"; cin >> SIZE;
    int* a = new int[SIZE];

    cout << "\nІтераційний спосіб:" << endl;
    cout << "Масив: ";
    Create_i(a, SIZE);
    Print_i(a, SIZE); cout << endl;
    cout << "\nВпорядкований масив за спаданням:";
    sort_i(a, SIZE);
    Print_i(a, SIZE); cout << endl;

    cout << "\nРекурсивний спосіб:" << endl;
    cout << "Масив: ";
    Create_r(a, SIZE, 0);
    Print_r(a, SIZE, 0); cout << endl;
    cout << "\nВпорядкований масив за спаданням:";
    sort_r(a, SIZE, 0, 0);
    

    for (int j = 0; j < SIZE; j++)
        cout << a[j] << " ";
    delete[]a;
    return 0;
}
//ітераційний спосіб
void Create_i(int* a, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        a[i] = rand() % SIZE;
}
void Print_i(int* a, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << a[i] << " ";
}
void sort_i(int a[], const int SIZE)
{
    for(int i = 1; i < SIZE; i++)
        for (int j = 0; j < SIZE - 1; j++)
            if (a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}
//рекурсивний спосіб
void Create_r(int* a, const int SIZE, int i)
{
    if (i < SIZE)
    {
        a[i] = rand() % SIZE;
        return Create_r(a, SIZE, i + 1);
    }
}
void Print_r(int* a, const int SIZE, int i)
{
    if (i < SIZE)
    {
        cout << a[i] << " ";
        return Print_r(a, SIZE, i + 1);
    }
}
void sort_r(int a[], const int SIZE, int i, int j)
{
    if (j < SIZE - 1)
    {
        if (a[j] < a[j + 1])
        {
            int temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
        return sort_r(a, SIZE, i, j + 1);
    }
    if (i < SIZE - 1)
        return sort_r(a, SIZE, i + 1, 0);
}
