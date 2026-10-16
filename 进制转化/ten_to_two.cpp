#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n = 10;
    string s;
    while(n!=0)
    {
        s+=n%2+'0';
        n/=2;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}