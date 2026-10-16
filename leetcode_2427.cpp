#include<iostream>
using namespace std;
int main()
{
    int a ;int b ;
    int count = 0;
    cin>>a>>b;
    int temp = 0;
    if(a>b)
    {
        temp = a;
    }
    else
    {
        temp = b;
    }
    for(int i =1;i<=temp;i++)
    {
        if(a%i==0&&b%i==0)
        {
            cout<<i<<endl;
            count++;
        }
    }
    cout<<"the nums is:"<<count<<endl;
    return 0;
}
