#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int *ptr = &a;
    cout << "Value of a using pointer " << *ptr << endl;
    cout << "Address of a is " << ptr << endl;
    int **q = &ptr;
    (**q)++;
    cout << "Value of a using pointer " << **q << endl;
    cout << "Address of a is " << ptr << endl;
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << "Printing array element using pointer" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << *(arr + i) << endl;
    // }
}