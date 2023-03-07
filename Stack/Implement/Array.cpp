#include<bits/stdc++.h>
using namespace std;

class Stack
{
    public:
        int top;
        int *arr;
        int size;


        //Adding element
        int push(int a)
        {
            if (size==top)
            {
                cout << "Stack is overflow" << endl;
            }
            else
            {
                top++;
                arr[top] = a;
            }
      }


      //Deleting Element
      int pop()
      {
        if(top==-1)
        {
            cout << "Stck in underflow" << endl;
        }
        else
        {
            top--;
        }
      }


      //Peek element
      int peek()
      {
        if(top==-1)
        {
            cout << "Stack is underflow" << endl;
        }
        else{
            cout << "Top element is " << arr[top] << endl;
        }
      }



      //Empty element
      bool isEmpty()
      {
        if(top==-1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack is non empty" << endl;
        }
      }


    //Constructor
    Stack(int size)
    {
        this->size=size;
        arr = new int[size];
        top = -1;
    }
};

int main()
{
    int n;
    cout << "What is size of stack??" << endl;
    cin >> n;
    Stack s(n);
}