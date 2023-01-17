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
    int d, t = 1;
    while (t == 1)
    {
        cout << "Enter value for linked list" << endl;
        cin >> d;
        node *p = new node();
        p->data = d;
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
        cout << "Do you want to enter more linked list (0/1)" << endl;
        cin >> t;
        k++;
    }
}

void searchMoveToHead()
{
    int sea;
    cout << "enter search elements " << endl;
    cin >> sea;
    int z = 0;
    node *p = head, *a = head;
    while (p!=NULL)
    {
        if (p->data == sea)
        {
            a->NAdd = p->NAdd;
            p->NAdd = head;
            head = p;
            z++;
        }
        a = p;
        p = p->NAdd;
    }

    if (z == 1)
        cout << "found" << endl;
    else
        cout << "not found" << endl;
}
int main()
{
    createLinkedList();
    searchMoveToHead();
}