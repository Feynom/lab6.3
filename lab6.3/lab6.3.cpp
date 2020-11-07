#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void sort_i(int a[], const int SIZE);
void sort_r(int a[], const int SIZE, int i, int j);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE;
    cout << "Введіть розмір масиву a[]:"; cin >> SIZE;
    int* a = new int[SIZE];

    cout << "a[] = ";
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % SIZE;
        cout << a[i] << " ";
    }
    cout << "\nІтераційний спосіб:" << endl;
    cout << "\nВпорядкований масив за спаданням:";
    sort_i(a, SIZE);
    cout << "\nРекурсивний спосіб:" << endl;
    cout << "\nВпорядкований масив за спаданням:";
    sort_r(a, SIZE, 1, 0);
    for (int j = 0; j < SIZE; j++)
        cout << a[j] << " ";
    delete[]a;
    return 0;
}
//ітераційний спосіб
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
    for (int j = 0; j < SIZE; j++)
        cout << a[j] << " ";

}
//рекурсивний спосіб
void sort_r(int a[], const int SIZE, int i, int j)
{
    if(a[j] < a[j + 1])
    {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
    }
    if (j > SIZE - i - 1)
        sort_r(a, SIZE, i, j + 1);
    if (j > SIZE - 1)
        sort_r(a, SIZE, i + 1, 0);
}
