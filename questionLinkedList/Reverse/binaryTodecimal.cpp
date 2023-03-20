#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;
}*head=NULL,*tail=NULL;
void createLinkedList()
{
    int d, t = 1;
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
}

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
    while (head != NULL)
    {
            res = (res << 1) + head->data;
            head = head->next;
    }
    return res;
    }
};
int main()
{
    createLinkedList();
    Solution s;
    cout << "Decimal value " << endl;
    cout <<s.getDecimalValue(head)<< endl;
}
