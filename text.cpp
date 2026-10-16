#include <iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
  // 请在此输入您的代码
  string patten = "202";
  string patten_2 = "2026";
  string text_patten;
  getline(cin,text_patten);
  int F = text_patten.size();
  int S = patten.size();
  int S2 = patten_2.size();
  int count = 0;
  int count_2 = 0;
  for(int i =0;i<=F-S;i++)
  {
    for(int j =0;j<=S;j++)
    {
      if(patten[j] == text_patten[i+j])
      {
        if(j == S-1&&text_patten[i+j+1]!='6'&&text_patten[i+j+1]!='0')
        {
          cout<<"the position is "<<i+j<<endl;
          text_patten[i+j] = ' ';
          count++;
        }
      }
      else{
        break;
      }
    }
  }
  for(int i =0;i<=F-S2;i++)
  {
    for(int j = 0;j<S2;j++)
    {
      if(patten_2[j]==text_patten[i+j])
      {
        if(j==S2-1)
        {
          count_2++;
        }
      }
      else{
        break;
      }
    }
  }
  cout<<"the 202 count is "<<count<<endl;
  cout<<"the 2026 count is "<<count_2<<endl;
  cout<<"the sum is"<<(count/2)+count_2<<endl;
  cout<<"the string is "<<text_patten;
  return 0;
}