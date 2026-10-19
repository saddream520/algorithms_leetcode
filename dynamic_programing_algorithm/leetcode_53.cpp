#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
//最大子序列和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int>dp;
        dp.reserve(size);
        if(size == 1){return nums[0];}
        dp[0] = nums[0];
        int result = nums[0];
        for(int i = 1;i<size;i++)
        {
            if(dp[i-1]<0)
            {
                dp[i] = nums[i];
                //若当前数字小于0，那就是对子序列和有着负影响
                // 所以我们跳过这个负影响数字，去下一位大于0的
            }
            else
            {
                dp[i] = dp[i-1]+nums[i];//否则直接累加当前数字即可
            }
            result = max(result,dp[i]);
        }
        return result;
    }
};