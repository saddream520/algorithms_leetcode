#include <iostream>
using namespace std;
class linklist
{
public:
    struct Node
    {
        int val;
        Node* next;
        Node(int x) : val(x), next(NULL) {}
        Node() : val(0), next(nullptr) {}
    
    };
    Node*head;
    Node*tail;
    linklist()
    {
        head = new Node();
        tail = head;
    }
    ~linklist()
    {
        delete head;
    }
    void push_back(int x)
    {
        Node*newNode = new Node(x);
        tail->next = newNode;
        tail = newNode;
    }
    void reverse()
    {
        Node*prev = nullptr;
        Node*cur = head;
        while(cur!=nullptr)
        {
            // next类似temp,进行变量的暂存
            Node*next = cur->next;
            cur->next = prev;
            //1->null 2->3->null;
            // 类似于截段操作
            prev =cur;//使得prev变为新的头
            cur = next;
        }
        // head = prev;
    }
    void Print()
    {
        for(Node*p = head;p!=nullptr;p=p->next)
        {
            cout<<p->val<<" ";
        }
    }
};
int main()
{
    linklist l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.Print();
    return 0;
}

