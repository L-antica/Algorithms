#include "Sort.h"
void exch(int a[], int i, int j)
{
    int length = sizeof(a);
    if (i >= 0 && i < length && j >= 0 && j < length)
    {
        int m = a[i];
        a[i] = a[j];
        a[j] = m;
    }
}
bool isSorted(int a[])
{
    int length = sizeof(a);
    for (int i = 0; i < length - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}
void show(int a[])
{
    int length = sizeof(a);
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
}

void Selection(int a[])
{
    int length = sizeof(a);
    for (int i = 0; i < length; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        exch(a, min, i);
    }
}

void Insertion(int a[])
{
    int length = sizeof(a);
    for (int i = 1; i < length; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j] < a[j - 1])
            {
                exch(a, j, j - 1);
            }
        }
    }
}