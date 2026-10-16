#include<iostream>
#include<cstring>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{   //计重复，再累加，就可以找到累计个数了
    vector<int>nums;
    nums.reserve(101);
    nums.push_back(8);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    vector<int>count;
    count.reserve(101);
    int n = count.max_size();
    for(int i =0;i<n;i++)
    {
        count[nums[i]]++;
        //重复递增
    }
    for(int i =1;i<n;i++)
    {
        if(!count.empty())
        count[i]+=count[i-1];
    }
    for(int &x:count)
    {
        cout<<x<<" ";
    }
    cin.get();
}