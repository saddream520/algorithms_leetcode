#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class solution
{
    int eval(vector<string>&tokens)
    {
        stack<int>result;
        int op1=0,op2=0;
        int n = tokens.size();
        for(int i =0;i<n;i++)
        {
            string& single = tokens[i];//获取当前的单个字符串
            if(isdigit(single))
            {
                result.push(stoi(single));
            }
            else//碰见运算符情况
            {
                op1 = result.top();
                result.pop();
                op2 = result.top();
                result.pop();
                switch(single[0])
                {
                    case '+':
                    result.push(op1+op2);
                    break;
                    case '-':
                    result.push(op2-op1);
                    break;
                    case '*':
                    result.push(op1*op2);
                    break;
                    case '/':
                    result.push(op2/op1);
                    break;
                }
            }
        }
        return result.top();
    }
    bool isdigit(string&c)
    {
        return c.size()>1||!(c=="+"||c=="-"||c=="*"||c=="/");
    }
};