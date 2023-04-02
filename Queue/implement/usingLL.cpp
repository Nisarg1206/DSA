#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
} *front = NULL, *rear = NULL;
int enqueue(int x)
{
    ListNode *t = new ListNode();
    if(t==NULL)
    {
        cout << "Queue is full";
    }
    else
    {
        t->val = x;
        t->next = NULL;
        if(front==NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = rear->next;
        }
    }
}
int dequeue()
{
    int x = -1;
    ListNode *p = NULL;
    if(front==NULL)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        p = front;
        x=p->val;
        front = front->next;
        // free(p);
    }
    return x;
}
int display()
{
    ListNode *p = front;
    while(p!=NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
int main()
{
    enqueue(10);
    enqueue(15);
    enqueue(80);
    enqueue(40);
    enqueue(65);

    display();

    dequeue();
    display();
}