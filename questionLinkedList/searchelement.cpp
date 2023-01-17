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

void maximum()
{
  node *p=head;
  int max=p->data;
  while(p)
  {
    if(p->data>max)
    {
      max=p->data;
    }
    p=p->NAdd;
  }
  cout<<"max "<<max<<endl;
}

void minimum()
{
  node *p=head;
  int min=p->data;
  while(p)
  {
    if(p->data<min)
    {
      min=p->data;
    }
    p=p->NAdd;
  }
  cout<<"min "<<min<<endl;
}


void search()
{
  int sea;
  cout<<"enter search elements "<<endl;
  cin>>sea;
   node *p=head;
  int z=0;
  while(p)
  {
    if(p->data==sea)
    {
      z++;
    }
    p=p->NAdd;
  }
  if(z==1)
  cout<<"found"<<endl;
  else
  cout<<"not found"<<endl;
}
int main()
{
    createLinkedList();
    maximum();
    minimum ();
    search();
}