#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node *createLL()
{
    int d, t = 1;
    node *head = NULL, *tail = NULL;
    while (t)
    {
        cout << "Enter data for Linked List" << endl;
        cin >> d;

        node *p = new node();
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
        cout << "do you want to enter more node in LL" << endl;
        cin >> t;
    }
    return head;
}

// Printing Linked List
void printLL(node *p)
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
    node *mergeSortLL(node *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        node *mid = findMid(head);

        node *left = head;
        node *right = mid->next;
        mid->next = NULL;

        left = mergeSortLL(left);
        right = mergeSortLL(right);

        node *result = merge(left, right);

        return result;
    }

    node *findMid(node *p)
    {
        node *slow = p;
        node *fast = p;

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

    node *merge(node *left, node *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        node *second = NULL;
        node *temp;

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
    node *p = createLL();

    // printing LL
    printLL(p);

    Solution obj;
    node *q = obj.mergeSortLL(p);

    printLL(q);
}