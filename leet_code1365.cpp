#include<iostream>
#include<cstring>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // 排序+哈希表
        unordered_map<int,int>index;
        vector<int>sorted = nums;
        sort(sorted.begin(),sorted.end());
        int n  =nums.size();
        vector<int>result;
        result.reserve(n);
        for(int i = 0;i<sorted.size();i++)
        {
            //使用find方法当不匹配的时候，返回的是末尾迭代器，至此我们可以利用此去将下标作为累计个数
            if(index.find(sorted[i])==index.end())
            {
                index[sorted[i]] = i;
            }
        }

        for(int x:nums)
        {
            result.push_back(index[x]);
        }
        return result;
    }
};