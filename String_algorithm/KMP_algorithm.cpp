#include<iostream>
#include<string>
#include<vector>
using namespace std;
// 创建next数组
vector<int> generateNext(string str)
{
    int n = str.size();
    vector<int>next(n, 0);
    int left = 0 ;int right =1;
    while(right<n)
    {
       if(str[left] == str[right])
       {
            left++;
            next[right] = left;//记录前缀
            right++;
       }
       else
        {
            if(left>0)
            {
                left =next[left-1];//回溯到属于left的前缀位置
            }
            else
            {
                next[right] = 0;//无法再回溯，记录0
                right++;
            }
        }
    }
    return next;
}

int KMP(string text,string patten)
{
    int text_size = text.size();
    int patten_size = patten.size();
    if (patten_size == 0) return 0;
    vector<int>next = generateNext(patten);
    int j = 0;
    for(int i = 0 ;i<text_size;i++)
    {
        while(j>0&&text[i]!=patten[j])
        {
            j = next[j-1];//回溯到j的前缀位置
        }
        if(text[i] == patten[j])
        {
            j++;
        }
        if(j == patten_size)
        {
            return i-patten_size+1;
        }
    }
    return -1; // 未找到匹配
}
int main()
{
    string text = "ababcabcabababd";
    string patten = "ababd";
    int position = KMP(text,patten);
    if(position != -1)
    {
        cout<<"find the substring at position: "<<position<<endl;
    }
    else
    {
        cout<<"find the substring failed"<<endl;
    }
    return 0;
}