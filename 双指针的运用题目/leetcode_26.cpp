#include<iostream>
#include<vector>
using namespace std;
// 双指针---快慢指针的使用
// 去掉有序序列中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0; int fast = 1;//快慢指针
        while(fast<nums.size())
        {
            if(nums[fast]!=nums[slow])//如果快指针不等于慢指针，证明当前元素不是重复元素
            {
                slow++;//慢指针移动至重复元素
                nums[slow] = nums[fast];//去掉重复元素
            }
            fast++;
        }
        return slow+1;
    }
};