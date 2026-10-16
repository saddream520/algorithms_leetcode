#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
    int text_patten = haystack.size();
    int patten = needle.size();
    int position = 0;
    for(int i =0;i<=text_patten-patten;i++)
    {
        int j;
        for( j = 0;j<patten;j++)
        {
            if(haystack[i+j]!=needle[j])
            {
                break;
            }
        }
          if(j == patten)
            {
                return i;
            }
    }
    return -1;
    }
};