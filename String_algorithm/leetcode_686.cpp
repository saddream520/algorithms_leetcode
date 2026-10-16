#include<iostream>
#include<vector>
#include<string>
using namespace std;
// leetcode 686. 重复叠加字符串匹配
// 这是最暴力的解法了，利用了穷举的方法把各种情况都适用了个遍
// 但是时间复杂度较高，需要优化
// TODO：使用stl的find函数来优化
class Solution {
public:
    vector<int>generateNext(string str)
    {
        int n = str.size();
        vector<int>next(n,0);
        int left = 0; int right = 1;
        while(right<n)
        {
            if(str[left] == str[right])
            {
                left++;
                next[right]=left;
                right++;
            }
            else
            {
                if(left>0){left = next[left-1];}
                else{next[right] = 0; right++;}
            }
        }
        return next;
    }
    int KMP(string t,string p)
    {
        int t_s = t.size();
        int p_s = p.size();
        if(p_s == 0){return 0;}
        vector<int>next = generateNext(p);
        int j = 0;
        for(int i = 0;i<t_s;i++)
        {
            while(j>0&&t[i]!=p[j])
            {
                j = next[j-1];
            }
            if(t[i] == p[j])
            {
                j++;
            }
            if(j == p_s)
            {
                return i - p_s + j;//匹配的第一个位置
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        int a_size = a.size();
        int b_size = b.size();
        if(a_size == 0){return -1;}
        vector<int>next = generateNext(a);
        //todo:kmp 匹配
        int count = 0;
        string temp;
        if(a_size == b_size)
        {
            string temp_2 = a;
            int count_2 = 1;
            int position_2 = KMP(a,b);
            if(position_2!=-1)
                return 1;
            else if(position_2==-1){temp_2+=a;position_2 = KMP(temp_2,b);if(position_2!=-1){return count_2+1;}}
            return -1;
        }
        while(temp.size()<b_size)
        {
            temp+=a;
            count++;
        }
        int position = KMP(temp,b);
        if(position==-1){temp+=a;position = KMP(temp,b);if(position!=-1){return count+1;}}
        else if(position!=-1){return count;}
        return -1;
    }
};