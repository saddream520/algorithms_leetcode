#include <iostream>
#include<string>
using namespace std;
int main()
{
    string a = "leetcode";//
    string b = "leet";
    int text_patten = a.size();
    int patten = b.size();
    // 由于for循环双层性质，j每次都可以归零回溯
    // 注意还有个相等的情况,我们需要确保遍历全部，所以范围要<=
    for (int i = 0; i <= text_patten-patten; i++)
    {
        for (int j = 0; j < patten; j++)
        {
            if (b[j] == a[i+j])//由于双层for循环，这个i得是j结束才移动
            {

                if (j == patten - 1)
                {
                    cout << "the position is:" << i << endl;//得出末位置,起始位置是i
                    cout << "find the target string" << endl;
                }
            }
            else{
                // cout<<-1<<endl;
                return -1;
            }
           
        }
    }
    // 或者用while循环写
    // int i = 0; int j  =0;
    // while(i<=text_patten&&j<=patten)
    // {
    //     if(b[j]==a[i])
    //     {
    //         i++;
    //         j++;
    //     }
    //     else{
    //         // 回溯
    //         i = i-j+1;
    //         j = 0;
    //     }
    //     if(j==patten)
    //     {
    //         return i-patten;
    //     }
    //     else return -1;
    // }
    return 0;
}