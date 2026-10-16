#include<iostream>
using namespace std;
int exchangeSort(int *array,int size)
{
    int temp = 0;
    for(int i = 0;i<size;i++)
    {
        for(int j =i+1;j<size;j++)
        {
            if(array[i]>array[j])
            {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            }
        }
    }
    return array[size];
}
int main()
{
    // 插入排序，分为有序无序集，全部比较后再进行插入
    int array[5]={3,5,1,4,2};
    int temp = 0;
    int j;
    for(int i = 1;i<5;i++)
    {
       if(array[i]<array[i-1])
       {
            temp = array[i];
            for( j = i-1;j>=0&&array[j]>temp;j--)
            {
                array[j+1] = array[j];//右移动元素
            }
             array[j+1] = temp;//临界,由于此时j=-1,所以j+1=0,即插入到有序集的最前面，
            //  将取出的元素插入到有序集的正确位置
       }
    }
    for(int i:array)
    {
        cout<<i<<" ";
    }
    cin.get();
}