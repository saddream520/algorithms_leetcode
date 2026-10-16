#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool BracketCorrespondency(const string& s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            // 检查栈顶左括号是否与当前右括号匹配
            char top = st.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{'))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    // 栈为空说明全部配对成功
    return st.empty();
}