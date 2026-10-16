#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //不改变顺序
        int save = 0;
        int count = 1;
        int n = nums.size();
        vector<int>temp_count(n,0);
        for(int i =0;i<nums.size();i++)
        {
            save = nums[i];
            for(int j = i+1;j<nums.size();j++)
            {
                if(nums[j]>save){count++;}
            }
            temp_count.push_back(count);
            count = 0;
        }
        sort(temp_count.begin(),temp_count.end());
        return temp_count[n-1];
    }
};