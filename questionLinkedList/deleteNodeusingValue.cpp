#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int key) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode *p,*q;
        
        while(head->data==key)
        {
            head=head->next;
            p=head;
            q=nullptr;
        }
        while (p!=NULL)
        {
            if (p->data == key)
            {
                q->next=p->next;
            }
            else
            {
                q=p;
            }
            p=p->next;
        }
        return head;
    }
};
void printLinkedList(ListNode *p)
{
    cout << "After deletion of node Linked list are" << endl;
    while(p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}
int main()
{
    ListNode *head = NULL, *tail = NULL;
    int d,t = 1;
    while (t == 1)
    {
        cout << "Enter value for linked list" << endl;
        cin >> d;
        ListNode *p = new ListNode();
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
    Solution s;
    int key;
    cout <<"Enter value for delete node"<<endl;
    cin>>key;
    ListNode *p = s.removeElements(head,key);
    printLinkedList(p);
}