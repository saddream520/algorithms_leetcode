#include<iostream>
#include<vector>
using namespace std;
// 双指针---对撞指针的使用
class Solution {
public:
// 输出下标
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;int high = numbers.size()-1;
        while(low<=high)
        {
            if(numbers[low]+numbers[high]==target)
            {
                return{low+1,high+1};
            }
            else if(numbers[low]+numbers[high]<target)
            {
                low = low+1;
            }
            else if(numbers[low]+numbers[high]>target)
            {
                high = high-1;
            }
        }
        return {};
    }
};