# include<iostream>
#include<vector>
#include<algorithm>
// 解法一暴力枚举
            /*
            class Solution {
            public:
                vector<int> twoSum(vector<int>& nums, int target) {
                    int n = nums.size();
                    for(int i = 0;i<n;i++)
                    {
                        for(int j = i+1;j<n;j++)
                        {
                            if(nums[i]+nums[j]==target)
                            {
                            return{i,j};
                            }
                        }
                    }
                    return{};
                }
            };
            */

// 解法2：暴力枚举的优化，利用最大最小剪枝
/* class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;i++)
        {
            if(nums[i]+nums.back()<target)
            {
                continue;
            }
            if(nums[i]+nums[i+1]>target)
            {
                break;
            }
            for(int j =i+1;j<nums.size();j++)
            {
                  if(nums[i]+nums[j]==target)
                    {
                    return{i,j};
                    }
            }
        }
        return{};
    }
};
/*

// 二分查找
/*
class Solution {
    bool binaryfind(vector<int>&nums,int l,int r,int val)
    {
        while(l<=r)
        {
            int mid =(1+r)>>1;
            if(nums[mid]<val)
            {
                l=mid+1;
            }else if(nums[mid]>val)
            {
                r = mid -1;
            }else{
                return true;
            }
        }
        return false;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size();i++)
        {
            if(binaryfind(nums,i+1,nums.size()-1,target-nums[i]))
            {
                return {nums[i],target-nums[i]};
            }
        }
        return{};
    }
};
*/ 