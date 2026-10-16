#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int count = 0;
    vector<int>result;
    string sentence;
    getline(cin, sentence);
    int n = sentence.size();
    int max_index = 0; int min_index = 0;
    int max_start = 0; int min_start = 0;
    int current_start_index = 0;
    int judge = 0;
    int judge_2 = 0;

    // 第一次循环：提取所有单词长度
    for (int i = 0;i<n;i++)
    {
        // 把连字符 '-' 也作为分隔符考虑，防止 1990-01-02 被当成一个超长单词
        if (sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != '.' && sentence[i] != '-')
        {
            if (count == 0) current_start_index = i;
            count++;
        }
        else
        {
            if (count>0)
            {
                result.push_back(count);
                count = 0;
            }
        }
    }
    if (count > 0)
    {
        result.push_back(count);
        count = 0;
    }
    sort(result.begin(), result.end());
    int min = result[0]; int max = result[result.size()-1];



    // 第二次循环：找第一个最长和最短单词
    count = 0; 
    for (int i = 0; i <= n; i++) // 注意这里是 i <= n，方便处理最后一个单词
    {
        // 如果是分隔符，或者到了字符串末尾，说明前一个单词结束了！
        if (sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '.' || sentence[i] == '-' || i == n)
        {
            if (count > 0) // 确保确实有一个单词刚刚结束
            {
                // 在这里判断长度
                if (count == min && judge_2 == 0)
                {
                    min_start = current_start_index;
                    min_index = i - 1; // 结束索引是 i-1
                    judge_2 = 1;
                }
                if (count == max && judge == 0)
                {
                    max_start = current_start_index;
                    max_index = i - 1;
                    judge = 1;
                }
                count = 0; // 单词结束，计数器清零
            }
        }
        else // 是单词字符
        {
            if (count == 0) current_start_index = i;
            count++;
        }
    }



    

    for (int i = max_start; i <= max_index; i++) cout << sentence[i];
    cout << endl;
    for (int i = min_start; i <= min_index; i++) cout << sentence[i];
    cout << endl;

    return 0;
}