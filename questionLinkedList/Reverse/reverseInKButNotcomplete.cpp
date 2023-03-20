#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *NAdd;
} *head = NULL, *tail = NULL;

// Create Linked list
void createLL()
{
    int d, t = 1;
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
        cout << "Do you want to enter more node(0/1)" << endl;
        cin >> t;
    }
}

class Solution
{
public:
    int sizeofLL(node *head)
    {
        node *p = head;
        int i = 0;
        while (p != NULL)
        {
            p = p->NAdd;
            i++;
        }
        return i;
    }
    node *reverseKGroup(node *head, int k)
    {
        int n = sizeofLL(head);
        int i = 0;
        if (n >= k)
        {
            if (head == NULL)
            {
                return NULL;
            }
            node *p = NULL, *r = NULL, *q = head, *t = head;
            while (q != NULL && i < k)
            {
                p = q->NAdd;
                q->NAdd = r;
                r = q;
                q = p;
                i++;
            }
            if (p != NULL && i == k)
            {
                head->NAdd = reverseKGroup(p, k);
            }

            return r;
        }
        else
        {
            return head;
        }
    }
};

void printLL(node *p)
{
    cout << "Linked list are" << endl;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->NAdd;
    }
}
int main()
{
    createLL();
    printLL(head);
    int k;
    cout << "Reverse in group of " << endl;
    cin >> k;
    Solution s;
    node *z = s.reverseKGroup(head, k);
    printLL(z);
}