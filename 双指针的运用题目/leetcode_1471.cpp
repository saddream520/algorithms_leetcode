#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());//进行排序
        int mid = arr[(arr.size()-1)/2];//找到中位数
        int left=0;
        int right = (arr.size())-1;//定义双指针
        int count =0;//计数
        int st_left=0;
        int st_right = 0;
        vector<int>result;
        while(count!=k)
        {
            st_left = abs(arr[left]-mid);
            st_right=abs(arr[right]-mid);
            if(st_left>st_right)
            {
                result.push_back(arr[left]);
                left++;
            }
            else{
                result.push_back(arr[right]);
                right--;
            }
            count++;
        }
        return result;
    }
};
int main()
{

    cin.get();
}