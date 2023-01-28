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
        cout << "Do you want to enter more node (0/1)" << endl;
        cin >> t;
    }
}

class solution
{
public:
    bool CheckPalindrome(node *p)
    {
        vector<int> arr;
        while (p != NULL)
        {
            arr.push_back(p->data);
            p = p->NAdd;
        }
        return CheckLL(arr);
    }

private:
    bool CheckLL(vector<int> a)
    {
        int t = a.size();
        int c = 0;
        int b = t - 1;
        while (c <= b)
        {
            if (a[c] != a[b])
                return 0;
            c++;
            b--;
        }
        return 1;
    }
};

class solution2
{
public:
    void checkPalindrome(node *&p)
    {
        node *a = head;
        node *b = head;
        while(a!=NULL)
        {
            a = a->NAdd->NAdd;
            b = b->NAdd;
        }
        reverseLL(b);
    }
private:
void reverseLL(node *&t)
{
    
}
};

// Printing Linked List
void printLL(node *p)
{
    cout << "Linked List are" << endl;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->NAdd;
    }
}

int main()
{
    createLL();
    printLL(head);
    solution check;
    int p = check.CheckPalindrome(head);
    if (p)
    {
        cout << "Palindrome Number" << endl;
    }
    else
    {
        cout << "Not Palindrome Number" << endl;
    }
}