#include<iostream>
using namespace std;
class cycleLink
{
public:
    struct node
    {
        int val;
        node* next;
        node():val(0),next(NULL){}
        node(int val):val(val),next(NULL){}
    };
    node*head;
    node*tail;
public:
    cycleLink(){
        head = new node();
        head->next =head;
        tail= head;
    }
    ~cycleLink()
    {
        delete head;
    }
    void InsertFirst(int val)
    {
        node* newNode = new node(val);
        newNode->next =head->next;
        head->next = newNode;
        // newNode->next = head;
    }
    void InsertLast(int val)
    {
        node*newNode = new node(val);
        tail->next = newNode;
        tail = newNode;
        newNode->next = head;
    }
    void Print()
    {
        node*p =head->next;
        while(p!=head)
        {
            cout<<p->val<<" ";
            p = p->next;
        }
        cout<<endl;
    }
    void josephus(int n,int m)
    {
        node*p = head->next;
        for(int i = 1;i<=n;i++)
        {
            node* newNode = new node(i);
            newNode->next =p->next;
            p->next = newNode;
            p=newNode;
        }
        int size = n;
        int count = 0;
        node*p2 = head;  
        node* prev = head;
        while(size>0)
        {
            if(p2==head)
            {
                p2 = p2->next;
            }
            count++;
            if(count == m)
            {
                cout<<p2->val<<" ";
                size--;
                count = 0;
                prev->next = p2->next;
                delete p2;
                p2 = prev->next;
            }
            else
            {
            prev = p2;//找到出列的前节点
            p2 = p2->next;
            }
        }
    }
};
int main()
{
    cycleLink link;
    link.josephus(10,3);
    // link.Print();
    // n个人一圈,数到m的人出列，随后出列顺序是？
}