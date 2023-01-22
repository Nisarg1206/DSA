#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *NAdd;
} *head = NULL, *tail = NULL;


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
  }
}

void middleLL()
{
  node *p=NULL, *q=NULL;
  p = q = head;
  while(q->NAdd!=NULL)
  {
    q = q->NAdd;
    if(q){
      q = q->NAdd;
    }
    if(p)
    {
      p = p->NAdd;
    }
  }
  cout << "Middle element is " << p->data << endl;
}


int main()
{
  createLinkedList();
  middleLL();
}