#include<iostream>
#include<cmath>
using namespace std;
int Plus(int n)
{
    if(n==0){return 0;}
    else if(n==1){return 1;}
    return n + Plus(n-1);
}
int main()
{
    cout<<Plus(5)<<endl;
    return 0;
}