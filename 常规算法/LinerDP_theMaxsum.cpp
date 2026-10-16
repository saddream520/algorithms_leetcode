#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n = 0;
    cin>>n;;
    int group[200005] = {0};
    int dp[200005];
    for(int i =0;i<n;i++)cin>>group[i];
    dp[0] = group[0];
    int Max = group[0];
    // 我们让dp存储当前i结尾的最大子段和
    // 所以当前dp初始化就是group[1],他的本身
    for(int i =1;i<n;i++)
    {
        dp[i] = max(group[i],dp[i-1]+group[i]);//比较子段和
        Max = max(Max,dp[i]);
    }
    cout<<Max<<endl;
    return 0;
}