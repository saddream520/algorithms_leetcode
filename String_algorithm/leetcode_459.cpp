#include<iostream>
#include<string>
#include<vector>
using namespace std;
// leetcode 459. 重复的子字符串
class Solution {
public:
    vector<int>generateNext(string str)
    {
        int n = str.size();
        vector<int>next(n,0);
        int left = 0; int right =1;
        while(right<n)
        {
            if(str[left] == str[right])
            {
                left++;
                next[right] = left;
                right++;
            }
            else
            {
                if(left > 0)
                {
                    left = next[left-1];
                }
                else{
                    next[right] = 0;
                    right++;
                }
            }
        }
        return next;
    }
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        if(size == 0){return false;}
        vector<int>next =generateNext(s);
        if(next[size-1]!=0&&size%(size-next[size-1])==0){return true;}
        //根据由字串重复组成的字符串性质，我们知道其前缀表开头必为0且末尾一定不为0，且长度必为偶数且能被前缀表末尾的值整除
        return false;
    }
};