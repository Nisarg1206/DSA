#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node *NAdd;
} *head1 = NULL,*head2=NULL,*head3=NULL,*tail2=NULL,*tail3=NULL, *tail1 = NULL;

void createLL1()
{
        int t = 1,d;
        while(t)
        {
            cout << "Enter data " << endl;
            node *p = new node();
            cin >> d;
            p->data = d;
            p->NAdd=NULL;
            if(head1==NULL)
            {
                head1 = p;
                tail1 = p;
            }
            else{
                tail1->NAdd = p;
                tail1= tail1->NAdd;
            }
            cout << "Do you want to add more node" << endl;
            cin >> t;
        }
}


void createLL2()
{
        int t = 1,d;
        while(t)
        {
            cout << "Enter data " << endl;
            node *p = new node();
            cin >> d;
            p->data = d;
            p->NAdd=NULL;
            if(head2==NULL)
            {
                head2 = p;
                tail2 = p;
            }
            else{
                tail2->NAdd = p;
                tail2 = tail2->NAdd;
            }
            cout << "Do you want to add more node" << endl;
            cin >> t;
        }
}
void createLL3()
{
        int t = 1,d;
        while(t)
        {
            cout << "Enter data " << endl;
            node *p = new node();
            cin >> d;
            p->data = d;
            p->NAdd=NULL;
            if(head3==NULL)
            {
                head3 = p;
                tail3 = p;
            }
            else{
                tail3->NAdd = p;
                tail3 = tail3->NAdd;
            }
            cout << "Do you want to add more node" << endl;
            cin >> t;
        }
}


void printLL(node *p)
{
        cout << "Linked list is " << endl;
        while(p!=NULL)
        {
            cout << p->data << endl;
            p = p->NAdd;
        }
}

void concatenatingLL(node *p,node *q,node *r)
{
    while (p->NAdd!=NULL)
    {
            p = p->NAdd;
    }
    while (q!=NULL)
    {
            p->NAdd = q;
            p = q;
            q = q->NAdd;
    }
    while (r->NAdd!=NULL)
    {
            p->NAdd = r;
            p = r;
            r = r->NAdd;
    }
}

int main()
{
    createLL1();
    printLL(head1);
    createLL2();
    printLL(head2);
    createLL3();
    printLL(head3);
    concatenatingLL(head1,head2,head3);
    printLL(head1);
}