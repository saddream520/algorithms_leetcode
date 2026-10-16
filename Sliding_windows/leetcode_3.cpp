#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
// 3.无重复字符的最长子串
//知识点:不定长的滑动窗口，随时维护
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 定义双指针
        int left = 0; int right = 0;
        // 定义标记次数哈希表
        unordered_map<char,int>window;
        // 定义记录的最大长度
        int maxLen = 0;
        while(right<s.size())
        {
            // 记录当前字符的次数
            window[s[right]]++;
            // 有重复，开始缩减窗口
            while(window[s[right]]>1)
            {
                // 如果当前字符次数大于一，那么左指针移动，次数进行缩减，知道无重复
                window[s[left]]--;
                left++;//左指针移动至无重复字符
            }
            // 更新最大长度
            maxLen = max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};