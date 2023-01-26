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

void printLL(node *temp)
{
    //  = head;
    cout << "Linked List are" << endl;
    while (temp != NULL)  
    {
        cout << temp->data << endl;
        temp = temp->NAdd;
    }
}


// node * uniqueSortedList(node * head) {
//    	//empty List
//     if(head == NULL)
//         return NULL;
    
//     //non empty list
//     node* curr = head;
    
//     while(curr != NULL) {
        
//         if( (curr -> NAdd != NULL) && curr -> data == curr -> NAdd -> data) {
//             node* next_next = curr ->NAdd -> NAdd;
//             node* nodeToDelete = curr -> NAdd;
//             delete(nodeToDelete);
//             curr -> NAdd = next_next;
//         }
//         else //not equal
//         {
//             curr = curr -> NAdd;
//         }   
//     }
    
//     return head; 
// }

void duplicateSorted()
{
    node *p = head;
    while (p != NULL)
    {
        if (p->data == p->NAdd->data && (p->NAdd != NULL))
        {
            node *a = p->NAdd;
            node *b = p->NAdd->NAdd;
            delete (a);
            p->NAdd = b;
        }
        else
        {
            p = p->NAdd;
        }
    }
}

int main()
{
    createLL();
    printLL(head);
    duplicateSorted();
    // node *p=uniqueSortedList(head);
    printLL(head);
}