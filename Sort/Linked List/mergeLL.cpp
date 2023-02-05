#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *head = NULL, *tail = NULL;

class Solution
{
public:
    void mergeLL(Node *head, Node *tail)
    {
        Node *mid = midInLL(head);

        // Left Side LL
        mergeLL(head, mid);

        // Right side LL
        mergeLL(mid->next, tail);

        addMerge(head, tail);
    }

    // finding mid element in LL
    Node *midInLL(Node *head)
    {
        Node *p = head;
        Node *q = head;

        while (q != NULL)
        {

            q = q->next;
            if (q != NULL)
            {
                q = q->next;
            }
            else
            {
                q = NULL;
                break;
            }
            p = p->next;
        }
        return p;
    }

    // merging LL in sorted way

    void addMerge(Node *head1, Node *tail1)
    {
        Node *mid;
        if (head != tail1)
        {
            mid = midInLL(head1);
        }
        else
        {
            return;
        }

        Node *p = head1;
        Node *q = mid->next;

        Node *tail3, *third;
        while (p != mid->next && q != NULL)
        {
            if (p->data < q->data)
            {
                if (third == NULL)
                {
                    third = tail = p;
                }
                else
                {
                    tail3->next = p;
                    tail3 = tail3->next;
                }
                p = p->next;
            }
            else
            {
                if (third == NULL)
                {
                    third = tail = q;
                }
                else
                {
                    tail3->next = q;
                    tail3 = tail3->next;
                }
                q = q->next;
            }
        }

        while (p != mid->next)
        {
            tail3->next = p;
            tail3 = tail3->next;
            p = p->next;
        }
        while (q != NULL)
        {
            tail3->next = q;
            tail3 = tail3->next;
            q = q->next;
        }
    }
};

void createLinkedList()
{
    int d, t = 1;
    while (t == 1)
    {
        cout << "Enter value for linked list" << endl;
        cin >> d;
        Node *p = new Node();
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

void printLL(Node *p)
{
    cout << "Linked List are" << endl;
    while (p != NULL)
    {
        cout << p->data << endl;
    }
}

int main()
{
    createLinkedList();
    cout << "Before" << endl;
    printLL(head);
    Solution obj;
    obj.mergeLL(head, tail);
}