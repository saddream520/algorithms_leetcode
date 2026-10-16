#include<iostream>
#include<vector>
#include<string>
using namespace std;
int BinarySearch(vector<int>&nums,int target)
{
    int low=0,high=nums.size()-1,mid=0;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]<target)
        {
            low = mid+1;
        }
        else if(nums[mid]>target)
        {
            high = mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int>nums;
    int target = 9;
    nums.reserve(10);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(10);
    int result = BinarySearch(nums, target);
    cout << result << endl;
    cin.get();
}