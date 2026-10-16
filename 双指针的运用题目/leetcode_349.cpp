#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 双指针---分离指针的使用
// 两个数组的交集
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int ptr_1 = 0; int ptr_2 = 0;//分离指针判断并集
        vector<int>result; result.reserve(1005);
        sort(nums1.begin(),nums1.end()); sort(nums2.begin(),nums2.end());
        bool judge[1005] = {false};//集合去重
        while(ptr_1<nums1.size()&&ptr_2<nums2.size())
        {
            if(nums1[ptr_1]==nums2[ptr_2])
            {
                if(!judge[nums1[ptr_1]])
                {
                judge[nums1[ptr_1]] = true;
                result.push_back(nums1[ptr_1]);
                }
                 ptr_1++; ptr_2++;
            }
            else if(nums1[ptr_1]>nums2[ptr_2])
            {
                ptr_2++;
            }
            else if(nums1[ptr_1]<nums2[ptr_2])
            {
                ptr_1++;
            }
        }
        return  result;
    }
};
