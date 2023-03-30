#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
};

ListNode *createLL()
{
    int d, t = 1;
    ListNode *head = NULL, *tail = NULL;
    while (t)
    {
        cout << "Enter data for Linked List" << endl;
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
        cout << "do you want to enter more ListNode in LL" << endl;
        cin >> t;
    }
    return head;
}

// Printing Linked List
void printLL(ListNode *p)
{
    cout << "Linked list are" << endl;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

// Solution
class Solution
{
public:
    ListNode *mergeSortLL(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *mid = findMid(head);

        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;

        left = mergeSortLL(left);
        right = mergeSortLL(right);

        ListNode *result = merge(left, right);

        return result;
    }

    ListNode *findMid(ListNode *p)
    {
        ListNode *slow = p;
        ListNode *fast = p;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast ->next!= NULL)
            {
                fast = fast->next;
            }
            else
            {
                fast = NULL;
                break;
            }
            slow = slow->next;
        }
        return slow;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        ListNode *second = NULL;
        ListNode *temp;

        while (left != NULL && right != NULL)
        {
            if (left->data < right->data)
            {
                if (second == NULL)
                {
                    second = temp = left;
                    left=left->next;
                }
                else
                {
                    temp->next = left;
                    temp = temp->next;
                    left = left->next;
                }
            }
            else
            {
                if (second == NULL)
                {
                    second = temp = right;
                    right=right->next;
                }
                else
                {
                    temp->next = right;
                    temp = temp->next;
                    right = right->next;
                }
            }
        }

        while (left != NULL)
        {
            temp->next = left;
            temp = temp->next;
            left = left->next;
        }

        while (right != NULL)
        {
            temp->next = right;
            temp = temp->next;
            right = right->next;
        }

        return second;
    }
};

int main()
{
    // Cretaing LL
    ListNode *p = createLL();

    // printing LL
    printLL(p);

    Solution obj;
    ListNode *q = obj.mergeSortLL(p);

    printLL(q);
}