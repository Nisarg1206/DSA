#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *NAdd;
} *head = NULL, *tail = NULL;

void createLL()
{
    int t = 1, d;
    while (t)
    {
        cout << "Enter data for node" << endl;
        cin >> d;
        node *p = new node();
        p->data = d;
        p->NAdd = NULL;
        if (head == NULL)
        {
            head = tail = p;
        }
        else
        {
            tail->NAdd = p;
            tail = tail->NAdd;
        }
        cout << "Do you want to add more node in LL(0/1)" << endl;
        cin >> t;
    }
    tail->NAdd = head->NAdd->NAdd;
}

// For printing linked list
void printLinkedList()
{
  node *temp = head;
  cout << "Linked List are" << endl;
  while (temp != NULL)
  {
    cout << temp->data << endl;
    temp = temp->NAdd;
  }
}

void flyodAlgo()
{
    node *p, *q;
    q = head;
    p = head;
    do
    {
        q = q->NAdd;
        p = p->NAdd;
        p = p!=NULL ? p->NAdd : NULL;
    } while ((p != NULL && q != NULL) && p != q);
    if(p==q)
    {
        cout << "loop" << endl;
    }
    else
    {
        cout << "Not loop" << endl;
    }
}

void getFirstOfLoop()
{
    node *p, *q;
    q = head;
    p = head;
    do
    {
        q = q->NAdd;
        p = p->NAdd;
        p = p!=NULL ? p->NAdd : NULL;
    } while ((p != NULL && q != NULL) && p != q);
    p = head;
    while(p!=q)
    {
        p = p->NAdd;
        q = q->NAdd;
    }
    cout << "Starting point for loop is " << p->data << endl;
}

int main()
{
    createLL();
    // printLinkedList();
    flyodAlgo();
    getFirstOfLoop();
}