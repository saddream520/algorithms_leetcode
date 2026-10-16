#include<iostream>
#include<algorithm>
using namespace std;
const int n = 5000;
int main()
{
    // 强制以当前元素结尾的局部长度
    int nums = 0;
    cin>>nums;
    int group[5005];
    int ans  =1;
    for(int i =0;i<nums;i++)
    {
        cin>>group[i];
    }
    int dp[n];
    // 因为子序列最小为1，易于理解
    for(int i =0;i<n;i++)
    {
        dp[i] = 1;
    }
    for(int i = 1;i<nums;i++)
    {
        for(int j = 0;j<i;j++)//接尾比较，以i做头，注意这里用1开头更好计算
        {
            if(group[j]<group[i])
            {
            dp[i] = max(dp[i],dp[j]+1);
            }
        }
         ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}