#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        int n = (nums.size());
       
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++)
        {
                if(i&&nums[i]==nums[i-1])
                {
                    continue;
                }
            int left=i+1;
            int right =n-1;
            // 固定i,在定义双指针,即可将三和问题转化为两和问题
        while(left<right)
        {
            
                if(nums[i]+nums[left]+nums[right]<0)
                {
                    left++;
                }
                else if(nums[i]+nums[left]+nums[right]>0)
                {
                    right--;
                }
                else{
                    result.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1])left++;
                    while(left<right && nums[right]==nums[right+1])right--;
                }
        }

        }
        return result;
    }
};