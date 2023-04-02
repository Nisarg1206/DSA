#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
} ;


// Creating Linked list
ListNode* createLinkedList()
{
    ListNode *head = NULL, *tail = NULL;
    int d, t = 1;
    while (t == 1)
    {
        cout << "Enter value for linked list" << endl;
        cin >> d;
        ListNode *p = new ListNode();
        p->val = d;
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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *p=head,*q=head->next,*result=NULL,*cur=NULL;
        while(p!=NULL)
        {
            ListNode *t = new ListNode();
            t->val = p->val;
            t->next = NULL;
            if(result==NULL)
            {
                result=cur=t;
                cur->next=NULL;   
            }
            else
            {
                cur->next=t;
                cur=cur->next;
            }
            if(p->next!=NULL)
            {
                p=p->next;
            }
            else
            {
                p=NULL;
                break;
            }
            if(p->next!=NULL)
            {
                p=p->next;
            }
            else
            {
                p=NULL;
                break;
            }
        }
        while(q!=NULL)
        {
            ListNode *t = new ListNode();
            t->val = p->val;
            t->next = NULL;
            cur->next = t;
            cur = cur->next;
            if(q->next!=NULL)
            {
                q=q->next;
            }
            else
            {
                q=NULL;
                break;
            }
            if(q->next!=NULL)
            {
                q=q->next;
            }
            else
            {
                q=NULL;
                break;
            }
        }
        return result;
    }
};

int main()
{
    ListNode *p=createLinkedList();
    Solution s;
    ListNode *u=s.oddEvenList(p);
    cout << "Linked List is";
    while(u!=NULL)
    {
        cout << u->val << " ";
        u = u->next;
    }
}