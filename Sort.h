#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>
using namespace std;
#endif



void exch(vector<int>& a, int i, int j);
bool isSorted(vector<int>& a);
void show(vector<int>& a);
//选择排序
void Selection(vector<int>& a);
//插入排序
void Insertion(vector<int>& a);
//希尔排序
void Shell(vector<int>& a);