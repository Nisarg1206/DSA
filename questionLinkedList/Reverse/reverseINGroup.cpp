#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
} *head = NULL, *tail = NULL;

// Create Linked list
void createLL()
{
    int d, t = 1;
    while (t)
    {
        cout << "Enter data for ListNode" << endl;
        cin >> d;
        ListNode *p = new ListNode();
        p->data = d;
        p->next = NULL;
        if (head == NULL)
        {
            head = tail = p;
        }
        else
        {
            tail->next = p;
            tail = tail->next;
        }
        cout << "Do you want to enter more ListNode(0/1)" << endl;
        cin >> t;
    }
}

ListNode *reverseLLKGroup(ListNode *head, int k)
{
    int i = 0;
    if (head == NULL)
    {
        return NULL;
    }
    ListNode *p = NULL, *r = NULL, *q = head;
    while (q != NULL && i < k)
    {
        p = q->next;
        q->next = r;
        r = q;
        q = p;
        i++;
    }
    if (p != NULL)
    {
        head->next = reverseLLKGroup(p, k+2);
    }
    return r;
}

void printLL(ListNode *p)
{
    cout << "Linked list are" << endl;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
int main()
{
    createLL();
    printLL(head);
    int k;
    cout << "Reverse in group of " << endl;
    cin >> k;
    ListNode *z = reverseLLKGroup(head, k);
    printLL(z);
}