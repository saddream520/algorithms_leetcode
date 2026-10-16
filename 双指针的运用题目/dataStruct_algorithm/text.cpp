#include<iostream>
using namespace std;
class cyclelink
{
public:
    struct node
    {
        int val;
        node*next;
        node():val(0),next(NULL){}
        node(int val):val(val),next(NULL){}
    };
    node*head;
    node*tail;
public:
    cyclelink()
    {
        head = new node();
        head->next =head;
        tail = head;
    }
    void josephus(int n,int m)
    {
        node*p=head->next;
        for(int i =1;i<=n;i++)
        {
            node*newNode = new node(i);
            newNode->next = p->next;
            p->next = newNode->next;
            p=newNode;
        }
        int size = n;
        int count = 0;
        node*p2 = head;
        node*prev = head;
        while(size>0)
        {
            if(p2==head)
            {
                p2=p2->next;
            }
            count++;
            if(count==m)
            {
                cout<<p2->val<<" ";
                count=0;
                size--;
                prev->next = p2->next;
                delete p2;
                p2 = prev->next;
            }
            else{
                prev = p2;
                p2=p2->next;
            }
        }
    }
};
int main()
{
    cyclelink link;
    int all;
    int step;
    cin>>all>>step;
    link.josephus(all,step);
    return 0;
}