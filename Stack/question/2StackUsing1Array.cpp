#include <bits/stdc++.h>
using namespace std;

class Stacks2
{
public:
    int top1;
    int top2;
    int size;
    int *arr;

    // adding element
    int push1(int a)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = a;
        }
        else
        {
            cout << "Stack in overflow condition" << endl;
        }
    }

    int push2(int a)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = a;
        }
        else
        {
            cout << "Stack in overflow condition" << endl;
        }
    }

    // Deleting element
    int pop1()
    {
        if (top1 == -1)
        {
            return -1;
        }
        else
        {
            int p = arr[top1];
            top1--;
            return p;
        }
    }

    int pop2()
    {
        if (top2 == size)
        {
            return -1;
        }
        else
        {
            int p = arr[top2];
            top2++;
            return p;
        }
    }
    Stacks2(int size1, int size2)
    {
        this->size = size1 + size2;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }
};

int main()
{
    int n1, n2;
    cout << "Enter size of stack 1" << endl;
    cin >> n1;
    cout << "Enter size of stack 2" << endl;
    cin >> n2;
    int t = 1, i = 0, j = 0;
    Stacks2 st(n1, n2);


    cout << "Enter element for stack 1" << endl;
    while (t && i < n1)
    {
        i++;
        int p;
        cin >> p;
        st.push1(p);

        cout << "Do you want to add more element in stack" << endl;
        cin >> t;
    }
    cout << endl;

    t = 1;
    cout << "Enter element for stack 2" << endl;
    while (t && j < n2)
    {
        j++;
        int p;
        cin >> p;
        st.push2(p);

        cout << "Do you want to add more element in stack" << endl;
        cin >> t;
    }
    cout << endl;


    cout << "Pop element are " << endl;
    cout << st.pop1() << endl;
    cout << st.pop2() << endl;
    cout << st.pop2() << endl;
}