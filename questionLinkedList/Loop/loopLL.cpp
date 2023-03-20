#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
} *head = NULL, *tail = NULL;
static int k = 0;
// Creating Linked list
void createLinkedList()
{
    int t = 1;
    while (t)
    {
        cout << "Enter value for linked list " << endl;
        node *p = new node();
        cin >> p->val;
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
        cout << "Do you want to add more node in linked list" << endl;
        cin >> t;
        k++;
    }
    tail->next = head;
}

class Solution {
public:
    node *detectCycle(node *head) {
        if(head==NULL)
        {
            return NULL;
        }
        else
    {
        node *p=head;
        node *q=head;
        do
        {
            q=q->next;
            p=p->next;
            if(p==NULL)
            {
                break;
            }
            else
            {
                p=p->next;
            }
        }while(p!=NULL && p!=q);
        if(p==NULL)
        {
            
            return NULL;
        }
        else
        {
            map<int ,int>m;
            node *t=head;
            int k=0;
            while(t)
            {
                if(m[t->val]==0)
                {
                    m[t->val]=1;
                    t=t->next;
                }
                else
                {
                    break;
                }
                
            }
            return t;
        }
    }
    }
};
// int LoopLL()
// {
//     node *p = head, *q = head;
//     do
//     {
//         p = p->next;
//         q = q->next;
//         q = q != NULL ? q->next : NULL;
//     } while (p != q && (p!=NULL && q!=NULL));
//     if (p == q)
//     {
//         cout << "Loop present" << endl;
//     }
//     else
//     {
//         cout << "Loop not present" << endl;
//     }
// }
int main()
{
    createLinkedList();
    Solution s;
    node *p = s.detectCycle(head);
    cout << "Cycle start at " << endl
         << p->val << endl;
}