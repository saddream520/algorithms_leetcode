#include<iostream>
using namespace std;
const int N = 100005;
int MOD =100003;
int dp[N];
int main()
{
    int n =0; int k =0;
    cin>>n>>k;
    dp[0] = 1;
    for(int i =1;i<=n;i++)
    {
        for(int j = 1;j<=k&&i-j>=0;j++)
        {
            dp[i] = (dp[i]+dp[i-j])%MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}