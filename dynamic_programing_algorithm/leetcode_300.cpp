#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //不改变顺序
          int n = nums.size();
        vector<int>dp(n,1);
        int result = 0;
        // dp.reserve(n);
        for (int i = 0; i <nums.size(); i++)
        {
            for (int j = 0; j <i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
             result = max(result,dp[i]);
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int>nums = {10,9,2,5,3,7,101,18};
    int temp = s.lengthOfLIS(nums);
    cout<<temp<<endl;
    return 0;
}