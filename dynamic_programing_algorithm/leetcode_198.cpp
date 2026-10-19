#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//打劫家舍
class Solution {
public:
    int rob(vector<int>& nums) {
        //计算最大和
        // 但是连续递增会失败，所以加一个要跳过一个
        int size = nums.size();
        vector<int>dp(size+1,0);
        // dp.reserve(size);
        dp[1] = nums[0];
        if(size == 1){return dp[1];}
        for(int i = 2;i<size+1;i++)
        {
           dp[i] = max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        return dp[size];
    }
};