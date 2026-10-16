#include<iostream>
#include<string>
using namespace std;
class MyLinkedList {
public:
 struct Node
    {
        int val;
        Node*next;
        Node(int x)
        :val(x),next(nullptr)
        {}
    };
        Node*head;
        Node*tail;
        int size;
public:
    MyLinkedList() {
        head = new Node(0);
        tail = head;
        size = 0;
    }
       ~MyLinkedList()
    {
        delete head;
        delete tail;
    }
    int get(int index) //得到认为节点值
    {
        if(index>size-1)
        {
            return -1;
        }
        Node*p = head->next;
        for(int i = 0;i<index;i++)
        {
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) //头插法
    {
        Node*newNode = new Node(val);
        newNode->next = head ->next;
        head->next = newNode;
        if(size==0)
        tail = newNode;
        size++;
    }
    
    void addAtTail(int val) //尾插法
    {
        Node* newNode = new Node(val);
        tail->next = newNode;
        newNode->next = nullptr;
        tail = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val)//中间插
    {
        if(size == index)
        {
            addAtTail(val);
            return;
        }
        Node*newNode = new Node(val);
        Node*p = head;//找到前驱节点
        for(int i =0 ;i<index; i++)
        {
            p = p->next;
        }
        newNode->next =p->next;
        p->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index)//删除任意节点
    {
        if(index>size-1)
        return;
        Node*p=head;
        for(int i = 0;i<index;i++)
        {
            p=p->next;
        }
        Node*deleteNode = p->next;
        p->next = deleteNode->next;
        if (deleteNode == tail) {
            tail = p;          // prev 可能是哨兵（当 size==1 时）
        }
        size--;
        delete deleteNode;
    }
    void display() {
        cout << "size = " << size << endl;
        for (Node* p = head->next; p != tail; p = p->next) {
            cout << p->val << " - ";
        }
        cout << endl;
    }
};

int main()
{
    // ["MyLinkedList","addAtHead","deleteAtIndex","addAtTail","get"]
    // [[],[1],[0],[2],[0]]
    MyLinkedList list; 
    list.addAtHead(1);
    list.deleteAtIndex(0); //删除了头节点
    list.addAtTail(2);
    list.get(0);
    cout<<"the 0 value is:"<<list.get(0);
    // list.display();
    cin.get();
}