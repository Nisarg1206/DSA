#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
};

// Creating Linked list
ListNode *createLinkedList()
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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        else if (head->next->next->next == NULL)
        {
            int i = 1;
            ListNode *p = head;
            while (p->next != NULL)
            {
                i++;
                p = p->next;
            }
            p->next = head;
            int l = abs(i - (k % i));
            ListNode *z;
            while (l > 0)
            {
                p = p->next;
                l--;
            }
            z = p->next;
            p->next = NULL;
            return z;
        }
        int i = 0;
        ListNode *p = head;
        while (p->next != NULL)
        {
            i++;
            p = p->next;
        }
        p->next = head;
        if (k > i)
        {
            k = k % i;
            // k = k - 1;
        }
        int l = abs(i - k);
        ListNode *z;
        while (l >= 0)
        {
            p = p->next;
            l--;
        }
        z = p->next;
        p->next = NULL;
        return z;
    }
};
int main()
{
    ListNode *p = createLinkedList();
    Solution s;
    int k;
    cin >> k;
    ListNode *r = s.rotateRight(p, k);
    cout << "linked list " << endl;
    while (r)
    {
        cout << r->val << " ";
        r = r->next;
    }
}