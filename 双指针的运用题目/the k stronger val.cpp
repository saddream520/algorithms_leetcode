#include<iostream>
#include<cstring>
#include<cmath>
#include<cstring>
using namespace std;
// 使用双指针
// 根据k返回列表值
int main()
{
    int arr[5]={1,2,3,4,5};
    int k=2;
    int brr[k];
    memset(brr,0,sizeof(brr));

    int mid = arr[2];
    int* left=arr+5;
    int* right=arr;
   
    for(int i=0;i<5;i++)
    {
        if(abs(*left-mid)>abs(*right-mid))
        {
            for(int j = 0;j<k;j++)
            {
                brr[i];
            }
        }
    }

    return 0;
}