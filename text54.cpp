#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int is_prime_reverse(int val)
{
    string temp;
    int count = 0;
    for(int i = 11;i<=val;i++)
    {
        bool is_prime = true;
        for(int j = 2 ;j*j<=i;j++)
        {
            if(i%j==0)
            {
                is_prime = false;
                break;
            }
        }
        if(is_prime&&i>1)
        {
            string numReverse = to_string (i);
            reverse(numReverse.begin(),numReverse.end());
            temp = numReverse;
            if(temp == numReverse){count++;}
        }
    }
    return count;
}
int main()
{
    int nums;
    cin>>nums;
    cout<<is_prime_reverse(nums);
}