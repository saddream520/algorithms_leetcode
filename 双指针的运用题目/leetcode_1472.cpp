#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
using namespace std;
class BrowserHistory {
    stack<string>forward;
    stack<string>back;
    string curr;
public:
    BrowserHistory(string homepage)
    {
        curr = homepage;
    }
    
    void visit(string url) {
        // 访问的话，就将一个指针指向，
        // 然后返回栈首
        back.push(curr);
        curr = url;
        // 悬空设计,没数组确实没招
        while(!back.empty())
        {
            forward.pop();
        }
    }
    
    string back(int steps) {
        // 先压进悬空的那个到另外一个
        while(!back.empty()&&steps>0)
        {
        forward.push(curr);
        curr = back.top();
        back.pop();//让新的再次悬空
        steps--;
        }
        return curr;
    }
    
    string forward(int steps) {
        // 原理和back相同
        while(!forward.empty()&&steps>0)
        {
            back.push(curr);
            curr = forward.top();
            forward.pop();
            steps--;
        }
        return curr;
    
    }
};