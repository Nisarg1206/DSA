#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
} *head = NULL, *tail = NULL;

class Stack : public node
{
public:
    int size;
    int top;

    //Adding element
    int push(int a)
    {
        if(size-top>0)
        {
            top++;
            node *p = new node();
            p->data = a;
            p->next = NULL;

            if(head==NULL)
            {
                head=tail=p;
            }
            else
            {
                tail->next = p;
                tail = tail->next;
            }
        }
        else
        {
            cout << "Stack in overflow condition" << endl;
        }
    }


    //Deleting element
    int pop()
    {
        if(top>=0)
        {
            top--;
            node *p = head, *q = NULL;
            while(p->next!=NULL)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            tail = q;
        }
    }


    //top element
    int peek()
    {
        if(top>=0)
        {
            cout << "Top element is " << tail->data << endl;
        }
        else
        {
            cout << "Stack in underflow condition" << endl;
        }
    }


    //is stack empty or not??
    int isEmpty()
    {
        if(top>=0)
        {
            cout << "Stack is not empty" << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
    Stack(int size)
    {
        top = -1;
        this->size = size;
    }
};

int main()
{
    int n;
    cout << "What is size of stack??" << endl;
    cin >> n;
    Stack s(n);

    cout << "Enter element for stack" << endl;
    for (int i = 0; i < n;i++)
    {
        int t;
        cin >> t;
        s.push(t);
    }

    s.pop();

    s.peek();

    s.isEmpty();
}