#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *NAdd;
} *head = NULL, *tail = NULL;
static int k=0;


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

// Inserting linked list
void InsertNode()
{
  int t;
  cout << "Enter after position for inserting in linked list" << endl;
  cin >> t;
  node *temp = new node();
  cout << "Enter value for inserting node" << endl;
  cin >> temp->data;
  temp->NAdd = NULL;

  if (t == 1)
  {
    temp->NAdd = head;
    head = temp;
  }
  else
  {
    int i = 1;
    node *a = NULL, *b = head;
    while (i <= t)
    {
      a = b;
      b = b->NAdd;
      i++;
    }
    a->NAdd = temp;
    temp->NAdd = b;
    if (temp->NAdd == NULL)
    {
      tail = temp;
    }
  }
  k++;
}

// For deleting node
void deleteNode()
{
  int t;
  node *a = NULL, *b = head;
  cout << "Enter position to delete node" << endl;
  cin >> t;
  if (t == 1)
  {
    b = b->NAdd;
    head = b;
  }
  else
  {
    int i = 2;
    while (i <= t)
    {
      a = b;
      b = b->NAdd;
      i++;
    }
    a->NAdd = b->NAdd;
    if(a->NAdd==NULL)
    {
      tail = a;
    }
  }
  k--;
}

// For printing linked list
void printLinkedList()
{
  node *temp = head;
  cout << "Linked List are" << endl;
  while (temp != NULL)
  {
    cout << temp->data << endl;
    temp = temp->NAdd;
  }
}

int main()
{
  createLinkedList();
  printLinkedList();
  int n = sizeof(head);
  InsertNode();
  printLinkedList();
  deleteNode();
  printLinkedList();
}