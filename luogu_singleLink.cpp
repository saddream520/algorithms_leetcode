#include<iostream>
using namespace std;
class list
{
public:
  struct node
  {
      int val;
      node* next;
      node(int value):next(nullptr),val(value)
      {
          
      }
  };
    node*head;
    node*tail;
public:
    list()
    {
        head = new node(1);
        tail = head;
    }
    ~list()
    {
        delete head;
        delete tail;
    }
    void val_push_back(int x,int y)
    {
        node*newNode = new node(y);
        node*p =head;
        while(p->next->val!=x)
        {
            p = p->next;
        }
        if(p->next = tail)
        {
            tail->next = newNode;
            tail = newNode;
        }
        p = p->next;
        newNode->next = p->next;
        p->next = newNode;
        
    }
    // 1
    void push_back(int e)
    {
        node*newNode = new node(e);
        tail->next = newNode;
        tail = newNode;
        // return newNode->val;
    }
    // 2
    void getNode(int value)
    {
      node*p=head;
      while(p->next->val != value)
      {
          p=p->next;
      }
        p=p->next;
        if(p->next == nullptr)
        {
            cout<<0;
        }
        else{
        int nextNode = p->next->val;
        cout<<nextNode;
        }
        
    }
    // 3
    void removeNext(int value)
    {
        node*p =head;
        while(p->val!=value)
        {
            p=p->next;
        }
        node*deleteNode = p->next;
        p->next = deleteNode->next;
        delete deleteNode;
    }
    void change(node*q)
    {
        node*p =head;
        while(p->next!=q)
        {
            p=p->next;
            p->next=head;
        }
    }
    void print()
    {
        node*p = head;
        while(p!=nullptr)
        {
            cout<<p->val<<endl;
            p=p->next;
        }
    }
};
int main()
{
    list linklist;
    linklist.push_back(1);
    linklist.push_back(2);
    linklist.push_back(3);
    linklist.push_back(4);
    linklist.push_back(5);
    linklist.push_back(6);
    // int count = 0;
    // cin>>count;
    // // int n = 0;
   
    // while(count--)
    // {
    //     int val_x = 0;
    //     int val_y = 0;
    //     int type = 0;
    //     cin>>type;
    //     if(type == 1)
    //     {
    //         cin>>val_x>>val_y;
    //         linklist.val_push_back(val_x,val_y);
    //     }
    //     else if(type == 2)
    //     {
    //         cin>>val_x;
    //         linklist.getNode(val_x);
    //     }
    //     else if(type == 3){
    //         cin>>val_x;
    //         linklist.removeNext(val_x);
    //     }
    // }
    linklist.change();
    linklist.print();
    return 0;
}