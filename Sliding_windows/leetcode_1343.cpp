#include <iostream>
#include<vector>
using namespace std;
// 1343. 大于平均值的子数组
// https://leetcode.cn/problems/number-of-subarrays-with-average-greater-than-threshold/
// 滑动窗口
// 解法一：滑动窗口+双指针+滑动窗口内元素的和(o(n-k):粗略版)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // 使用滑动窗口，滑动窗口的大小等于k，计算存在于窗口三元素的平均值是否大于阈值
        // 大于就记录一次
        vector<int>window;
        window.reserve(k);
        int count = 0;
        //窗口双指针
        int left = 0; int right = 0;
        int temp_left = left;
        int sum = 0;
        while(right<arr.size())
        {
            window.push_back(arr[right]);
            if(right-left+1>=k)
            {
               while(temp_left<=right)
               {
                // 计算窗口内元素的和
                 sum += window[temp_left];
                temp_left++;
               }
            //  若成立 则记录一次
               if(sum>=threshold*k){count++;left++;temp_left = left;sum = 0;}
               else
               {
                left++;temp_left = left;sum = 0;
               }
            }
            right++;

        }
        return count;
    }
};
