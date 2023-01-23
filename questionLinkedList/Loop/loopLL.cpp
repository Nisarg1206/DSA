#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *NAdd;
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
        cin >> p->data;
        p->NAdd = NULL;
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->NAdd = p;
            tail = tail->NAdd;
        }
        cout << "Do you want to add more node in linked list" << endl;
        cin >> t;
        k++;
    }
    tail->NAdd = head;
}

int LoopLL()
{
    node *p = head, *q = head;
    do
    {
        p = p->NAdd;
        q = q->NAdd;
        q = q != NULL ? q->NAdd : NULL;
    } while (p != q && (p!=NULL && q!=NULL));
    if (p == q)
    {
        cout << "Loop present" << endl;
    }
    else
    {
        cout << "Loop not present" << endl;
    }
}
int main()
{
    createLinkedList();
    LoopLL();
}