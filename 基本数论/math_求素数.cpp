#include<iostream>
using namespace std;
int main()
{
    int count = 0;
    for(int i =1;i<=10;i++)
    {
        bool is_prime = true;
        for(int j = 2;j<i;j++)
        {
            if(i%j==0)
            {
                // 标志变量
                is_prime = false;
                break;
            }
        }
         if(is_prime&&i>1){cout<<i<<endl;count++;}
    }
    return 0;
}
