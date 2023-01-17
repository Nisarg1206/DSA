#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *NAdd;
} *head = NULL, *tail = NULL;

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


void duplicates()
{
  int k = 0;
  node *p = head, *a, *b = head;
  while (p != NULL)
  {
    a = p->NAdd;
    while (a != NULL)
    {
      if (p->data == a->data)
      {
        b->NAdd = a->NAdd;
        free(a);
        k++;
        a = b;
      }
      b = a;
      a = a->NAdd;
    }
    p = p->NAdd;
  }
  if(k==1)
  {
    cout << "Duplicates present" << endl;
  }
  else
    cout << "Not duplicates present" << endl;
}


void printLL()
{
  node *p = head;
  cout << "Linked list are" << endl;
  while(p!=NULL)
  {
    cout << p->data<<endl;
    p=p->NAdd;
  }
}
int main()
{
  createLinkedList();
  printLL();
  duplicates();
  printLL();
}