#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *NAdd;
} *head = NULL, *tail = NULL;

void createLL()
{
    int t = 1, d;
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

node *duplicateNodeLL(node *d)
{
    node *a,*p=d;
    while (p != NULL)
    {
        a = p;
        while (a->NAdd != NULL)
        {
            if (p->data == a->NAdd->data)
            {
                node *c = a->NAdd;
                a->NAdd = a->NAdd->NAdd;
                delete (c);
            }
            else
            {
                a = a->NAdd;
            }
        }
        p = p->NAdd;
    }
    return head;
}

// void removeDuplicates(node* start)
// {
//     node *ptr1, *ptr2, *dup;
//     ptr1 = start;

//     /* Pick elements one by one */
//     while (ptr1 != NULL && ptr1->NAdd != NULL) {
//         ptr2 = ptr1;
//         while (ptr2->NAdd != NULL) {
//             if (ptr1->data == ptr2->NAdd->data) {
//
//                 dup = ptr2->NAdd;
//                 ptr2->NAdd = ptr2->NAdd->NAdd;
//                 delete (dup);
//             }
//             else /* This is tricky */
//                 ptr2 = ptr2->NAdd;
//         }
//         ptr1 = ptr1->NAdd;
//     }
// }

node *printLL(node *p)
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
    node *t = duplicateNodeLL(head);
    // removeDuplicates(head);
    printLL(head);
}

//Error Why??
 /*Becuase of Deletion not perform properly So I didn't get right answer Please 
 Perform Deletion Carefully*/
// node *duplicateNodeLL(node *c)
// {
//     node *a,*p=c;
//     while (p != NULL)
//     {
//         a = p->NAdd;
//         while (a != NULL)
//         {
//             if (p->data == a->data)
//             {
//                 node *d = a;
//                 delete (d);
//                 a =a->NAdd;
                
//             }
//             else
//             {
//                 a= a->NAdd;
//             }
//         }
//         p = p->NAdd;
//     }
//     return head;
// }