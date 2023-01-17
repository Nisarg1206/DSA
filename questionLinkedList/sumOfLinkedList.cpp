#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *NAdd;
}*head=NULL,*tail=NULL;

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
  }
}

void sumofll()
{
    node *temp=head;
    int sum=0;
    while(temp!=NULL)
    {
        sum=sum+temp->data;
        temp=temp->NAdd;
    }
    cout<<"Sum is "<<sum<<endl;
}


int main()
{
    createLinkedList();
    sumofll();
}