#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 打劫家舍II
class Solution {
public:
    int rob(vector<int>& nums) {
        // 状态方程依然和原题一是一样的
        //但是现在由于是首尾相邻，所以现在是取0 -- size-2和1 -- size-1之间的和最大值比较
        int size = nums.size();
        int size_1 = size-1;
        int size_2 = size-1;
        vector<int>dp_1(size_1+1,0);
        vector<int>dp_2(size_2+1,0);
        if(size == 1){return nums[0];}
        dp_1[1] = nums[0];
        for(int i = 2;i<size_1+1;i++)
        {
            dp_1[i] = max(dp_1[i-2]+nums[i-1],dp_1[i-1]);
        }
        int ans_1 = dp_1[size_1];

        dp_2[1] = nums[1];
        for(int i = 2;i<size_2+2;i++)
        {
            dp_2[i] = max(dp_2[i-2]+nums[i],dp_2[i-1]);
        }
        int ans_2 = dp_2[size_2];
        return max(ans_1,ans_2);
    }
};