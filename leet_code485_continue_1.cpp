#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    int count = 0;
    int index = 0;
    int n = nums.size();
    vector<int>result_group;
    result_group.reserve(n);
    for(int i = 0 ;i<nums.size();i++)
    {
       if (nums[i] == 1)
       {
           count++;
       }
       else if (nums[i] == 0)
       {
           result_group.emplace_back(count);//记录长度数组
           count = 0;
       }
    }
    if(count>0)
    {
         result_group.emplace_back(count);//记录长度数组
    }
    int max_val=0;
    for(int v:result_group)
    {
        if(v>max_val)max_val=v;
    }
    cin.get();
}