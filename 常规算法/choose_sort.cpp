#include<iostream>
using namespace std;
int chooseSort(int *array,int size)
{
    int temp  =0;
    for(int i =0;i<size-1;i++)
    {
        int index = i;
        for(int j =i+1;j<size;j++)
        {
            if(array[index]>array[j])
            {
                index = j;
            }
           
        }
        temp  =array[i];
        array[i] = array[index];
        array[index] = temp;
    }
}