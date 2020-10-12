#include "Sort.h"
void exch(vector<int> &a, int i, int j)
{
    int length = a.size();
    if (i >= 0 && i < length && j >= 0 && j < length)
    {
        int m = a[i];
        a[i] = a[j];
        a[j] = m;
    }
}
bool isSorted(vector<int> &a)
{
    int length = a.size();
    for (int i = 0; i < length - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}
void show(vector<int> &a)
{
    int length = a.size();
    for (int i = 0; i < length; i++)
        cout << a[i] << " ";
    cout << endl;
}

void Selection(vector<int> &a)
{
    int length = a.size();
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

void Insertion(vector<int> &a)
{
    int length = a.size();
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

void Shell(vector<int> &a)
{
    int length = a.size();
    int h = 1;
    while (h < length / 3)
    {
        h = 3 * h + 1; //书上给出的递增序列
    }
    while (h >= 1)
    {
        for (int i = h; i < length; i++)
        {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
            {
                exch(a, j, j - h);
            }
        }
        h = h / 3;
    }
}
//归并
void merge(vector<int> &a, int low, int mid, int high)
{
    vector<int> aux = a;
    int i = low;
    int j = mid + 1;
    for (int k = low; k <= high; k++)
    {
        if (i > mid)
            a[k] = aux[j++];
        else if (j > high)
            a[k] = aux[i++];
        else if (aux[i] < aux[j])
            a[k] = aux[i++];
        else if (aux[i] >= aux[j])
            a[k] = aux[j++];
    }
}
//归并排序
void MergeSort(vector<int> &a, int low, int high)
{
    int mid = (high + low) / 2;
    if (low >= high)
    {
        return;
    }
    MergeSort(a, low, mid);
    MergeSort(a, mid + 1, high);
    merge(a, low, mid, high);
}