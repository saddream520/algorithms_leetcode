#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
// 快速排序
// 1.快排的划分
// 注意在没引入随机化的前提下，时间复杂度为n方
int Partition(int a[], int low, int high)
{
    //int target = a[low];
    //注意这里的分割函数每次调用只会分割一次，就是可能左边一次，或者右边一次
    //当左边的置换成立时，右边就不再执行，当右边置换成立时，左边不再执行
    int pivot = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= pivot)
        { 
            high--; 
        }
        if (low < high)
        {
            a[low] = a[high];
            low++;
        }
        while (low < high && a[low] <= pivot)
        {
            low++; 
        }
        if (low < high)
        {
            a[high] = a[low];
            high--;
        }
    }
    a[low] = pivot;
    return low;
}
// 引入随机枢纽（由于排序可能会出现有序的,正常折半可能会影响）
int ramdom_Partition(int a[],int low,int high)
{
    int i = (rand()%(high - low+1))+low;
    int temp = a[low];
    a[low] = a[i];
    a[i] = temp;
    return Partition(a,low,high);
}
void QuickSort(int a[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = ramdom_Partition(a, low, high);
        QuickSort(a, low, pivot-1);
        QuickSort(a,pivot+1,high);
        //分割子表更新枢纽
    }
}
void Print(int a[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[6] = { 37,19,43,22,89,26 };
    int h = 5;
    int l = 0;
    QuickSort(a, l, h);
    Print(a, 6);
    return 0;
}