#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *NAdd;
}*head=NULL,*tail=NULL;

//Create Linked list
void createLL()
{
    int d,t = 1;
    while(t)
    {
        cout << "Enter data for node" << endl;
        cin >> d;
        node *p = new node();
        p->data=d;
        p->NAdd = NULL;
        if(head==NULL)
        {
            head = tail = p;
        }
        else{
            tail->NAdd = p;
            tail = tail->NAdd;
        }
        cout<<"Do you want to enter more node(0/1)"<<endl;
    }
}