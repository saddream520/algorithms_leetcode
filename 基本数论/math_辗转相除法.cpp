#include<iostream>
using namespace std;
void GCD(int a,int b)
{
    while(b!=0)
    {
        int temp = a%b;
        a = b;
        b = temp;
    }
    cout<<a<<endl;
}
int main()
{
    // 辗转相除法求最大公约数
    int a ;int b ;
    cin>>a>>b;
    int c;
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
    cout<<a<<endl;

    cin.get();
}
