#include<iostream>
#include<cstring>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // 也就是说这个数组是按顺序的
        sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,int>index;
        // vector<int>result;
        int missing = 0;
        int repeat = 0;
        int target = nums.back();
        for(int i =0;i<n;i++)
        {
            index[nums[i]]++;
        }
        for(int i =1;i<=n;i++)
        {
            if(index[i]>1)
            {
                //推入重复元素
                repeat = i;
            }
            else if(index[i] == 0)
            {
                // 推入缺失元素，因为缺失计数为0
                missing = i;
            }
        }
      
        return {repeat,missing};
    }
};

 

//   cout<<index[1]<<endl;
//   cout<<index[2]<<endl;
//   cout<<index[3]<<endl;
