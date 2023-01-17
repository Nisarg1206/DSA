#include <iostream>
using namespace std;
void pattern1(int n);
void pattern2(int n);
void pattern3(int n);
void pattern4(int n);
void pattern5(int n);
void pattern6(int n);
void pattern7(int n);
void pattern8(int n);
void pattern9(int n);
void pattern10(int n);
void pattern11(int n);
void pattern12(int n);
void pattern13(int n);
void pattern11(int n);
void pattern12(int n);
int main()
{
    int i, j, k, n;
    cout << "Enter number of rows" << endl;
    cin >> n;
    pattern1(n);
    cout << "Pattern 2" << endl;
    pattern2(n);
    cout << "Pattern 3" << endl;
    pattern3(n);
    cout << "Pattern 4" << endl;
    pattern4(n);
    cout << "Pattern 5" << endl;
    pattern5(n);
    cout << "Pattern 6" << endl;
    pattern6(n);
    cout << "Pattern 7" << endl;
    pattern7(n);
    cout << "Pattern 8" << endl;
    pattern8(n);
    cout << "Pattern 9" << endl;
    pattern9(n);
    cout << "Pattern 10" << endl;
    pattern10(n);
    cout << "Pattern 11" << endl;
    pattern11(n);
    cout << "Pattern 12" << endl;
    pattern12(n);
    cout << "Pattern 13" << endl;
    pattern13(n);
}
void pattern1(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (k = n - 1 - i; k > 0; k--)
        {
            cout << " ";
        }
        for (j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int p = 0; p < i; p++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int t = 0; t < i + 1; t++)
        {
            cout << " ";
        }
        for (int k = n - 1 - i; k > 0; k--)
        {
            cout << "*";
        }
        for (int q = n - 2 - i; q > 0; q--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    // for (int i=0; i <n;i++)
    // {
    //     for (int j=0; j <n;j++)
    //     {
    //         cout << j+1 << " ";
    //     }
    //     cout << endl;
    // }
    int i = 1, j = 1;
    while (i <= n)
    {
        j = 1;
        while (j <= n)
        {
            cout << j << " ";
            j++;
        }
        i++;
        cout << endl;
    }
}
void pattern4(int n)
{
    int i = 1, j = 1;
    while (i <= n)
    {
        j = 0;
        while (j < n)
        {
            cout << n - j << " ";
            j++;
        }
        i++;
        cout << endl;
    }
}
void pattern5(int n)
{
    int i = 1, j, k = 1;
    while (i <= n)
    {
        j = 0;
        while (j < n)
        {
            cout << k << " ";
            k++;
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern6(int n)
{
    int i = 0, j;
    while (i < n)
    {
        j = 0;
        while (j <= i)
        {
            cout << i + 1 << " ";
            j++;
        }
        i++;
        cout << endl;
    }
}
void pattern7(int n)
{
    int i = 0, j, k = 1;
    while (i < n)
    {
        j = 0;
        while (j <= i)
        {
            cout << k << " ";
            j++;
            k++;
        }
        i++;
        cout << endl;
    }
}
void pattern8(int n)
{
    int i = 0, j, k;
    while (i < n)
    {
        k = i + 1;
        j = 0;
        while (j <= i)
        {
            cout << k + j << " ";
            j++;
        }
        i++;
        cout << endl;
    }
}
void pattern9(int n)
{
    int i = 0, j, k;
    while (i < n)
    {
        k = i + 1;
        j = 0;
        while (j <= i)
        {
            cout << k << " ";
            j++;
            k--;
        }
        i++;
        cout << endl;
    }
}
void pattern10(int n)
{
    int i = 0, j;
    char ch = 'A';
    while (i < n)
    {
        j = 0;
        ch = 'A' + i;
        while (j < n)
        {
            cout << ch << " ";
            j++;
        }
        i++;
        cout << endl;
    }
}
void pattern11(int n)
{
    int i = 0, j;
    char ch = 'A';
    while (i < n)
    {
        j = 0;

        while (j < n)
        {
            ch = 'A' + j;
            cout << ch << " ";
            j++;
        }
        i++;
        cout << endl;
    }
}
void pattern12(int n)
{
    int i = 0, j, k;
    while (i < n)
    {
        j = 0;
        k = i + 1;
        while (j < n)
        {
            cout << k + j << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern13(int n)
{
    int i = 0, t,j;
    char ch = 'A';
    while (i < n)
    {
        t = i;
        j = 0;
        while (j <= i)
        {
            ch = 'A' + n - 1 - t;
            cout << ch << " ";
            t--;
            j++;
        }
        i++;
        cout << endl;
    }
}