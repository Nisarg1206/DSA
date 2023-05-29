#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

// Creating Linked list
node *createLinkedList()
{
    node *head = NULL, *tail = NULL;
    int d, t = 1;
    while (t == 1)
    {
        cout << "Enter value for linked list" << endl;
        cin >> d;
        node *p = new node();
        p->data = d;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
        cout << "Do you want to enter more linked list (0/1)" << endl;
        cin >> t;
    }
    return head;
}

node *reverse(node *p)
{
    node *a = NULL, *b = p, *c = NULL;
    while (b)
    {
        a = b->next;
        b->next = c;
        c = b;
        b = a;
    }
    return c;
}
node* reorderLL(node *head)
{
    node *p = head, *q = head;
    while (q->next!=NULL)
    {
        q = q->next;
        if (q)
        {
            q = q->next;
        }
        if (p)
        {
            p = p->next;
        }
    }
    node *a = q->next;
    q->next=NULL;
    a=reverse(a);
    node *head2=NULL,*tail=NULL;
    int i=0;
    while(head)
    {
        if(i%2==0)
        {
            if(head2==NULL)
            {
                head2=tail=head;
                head=head->next;
            }
            else
            {
                tail->next=head;
                tail=tail->next;
                head=head->next;
            }
        }
        else
        {
            tail->next=a;
            tail=tail->next;
            a=a->next;
        }
        i++;
    }
    return head2;
}
int main()
{
    node *p = createLinkedList();
    p=reorderLL(p);
    cout << "LL is " << endl;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
