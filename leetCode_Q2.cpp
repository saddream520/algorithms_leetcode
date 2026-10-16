#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>result;
        int op1=0;
        int op2=0;
        int last_result=0;
        for(int i =0;i<tokens.size();i++)
        {
            string& single= tokens[i];
            if(isdigit(single)) 
            {
                result.push(stoi(single));
            }
            else
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
        last_result = result.top();
        return last_result;
    }
    bool isdigit(string& c)
    {
      return c.size() > 1 || !(c == "+" || c == "-" || c == "*" || c == "/");
    }

};
int main()
{
    Solution s;
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    cout << s.evalRPN(tokens) << endl;
    return 0;
}