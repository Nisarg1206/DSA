#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *NAdd;
} *head = NULL, *tail = NULL;

void createLL()
{
        int t = 1,d;
        while(t)
        {
            cout << "Enter data " << endl;
            node *p = new node();
            cin >> d;
            p->data = d;
            p->NAdd=NULL;
            if(head==NULL)
            {
                head = p;
                tail = p;
            }
            else{
                tail->NAdd = p;
                tail = tail->NAdd;
            }
            cout << "Do you want to add more node" << endl;
            cin >> t;
        }
}

void printLL()
{
        node *p;
        cout << "Linked list is " << endl;
}