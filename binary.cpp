#include <iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int n = 0;
    int trans_time = 0;
    int count=0;
    cout<<"input nums count: ";
    cin>>n;
    int nums[n];
    // int copyNums[n];
    int temp = 0;
    string binary[n];
    vector<int>result;
    vector<int>one_time;
    for(int i =0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"input the trans_time: ";
    cin>>trans_time;
    for(int step=0;step<trans_time;step++)
    {
        for(int i =0;i<n;i++)
        {
                temp = nums[i];
                binary[i]="";
            // while(count<2*trans_time)
            // {
                count++;
                cout<<"the nums :"<<nums[i]<<endl;
                // 转化二进制09
                while(temp>0)
                {
                    binary[i]+=(temp&1)+'0';
                    temp>>=1;
                    // count++;
                }
                cout<<"trans_binary: "<<binary[i]<<endl;;
                // 记录一的个数
                int one_count=0;
                for(char c:binary[i])
                {
                    if(c=='1')
                    one_count++;
                }
                cout<<"1's nums: "<<one_count<<endl;
                nums[i]=nums[i]*one_count;//第一次
                cout<<"record the update nums:"<<nums[i]<<endl;;
                // nums[i]=result[i];//更新初始数组
            // }
        }
    }
    for(int i =0;i<n;i++)
    {
        cout<<nums[i]<<" ";
    }
}