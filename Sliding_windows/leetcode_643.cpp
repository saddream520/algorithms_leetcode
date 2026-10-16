#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
// 计算最大平均数在子数组内
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //定义双指针
        int left = 0; int right = 0;
        int sum = 0; double MaxAvg = -1e9;
        // 开始寻找最大平均数
        while(right<nums.size())
        {
            sum+=nums[right];
            if(right-left+1>=k)
            {
                MaxAvg = max(MaxAvg,double(sum)/k);
                // 缩减窗口
                sum-=nums[left];
                // 滑动窗口
                left++;
            }
            right++;
        }
        return MaxAvg;
    }
};
