#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 435. 无重叠区间
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>>Copy = intervals;
        sort(Copy.begin(),Copy.end(),[](const vector<int>&a,const vector<int>&b)
        {
            return a[1]<b[1];
        });
        int count = 1;
        // 将找最少的移除区间转化为找到最大的无重叠区间，最后减去这个最大的无重叠区间便是最少的重叠区间
        int end_pos = Copy[0][1]; //记录排序后第一个无重叠区间的结束位置
        for(int i = 1;i<Copy.size();i++)
        {
            if(end_pos<=Copy[i][0])
            {
                count++;
                end_pos = Copy[i][1];
            }
        }
        // 最后返回总区间数减去最大无重叠区间数便是最少的重叠区间数
        return intervals.size() - count;
    }
};

