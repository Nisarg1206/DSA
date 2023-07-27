#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        size = 0;
        arr[size] = -1;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
        }

        arr[1] = arr[size];

        size--;

        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            if (left <= size and arr[index] < arr[left])
            {
                swap(arr[index], arr[left]);
                index = left;
            }
            else if (right <= size and arr[index] < arr[right])
            {
                swap(arr[index], arr[right]);
                index = right;
            }
            else
            {
                return;
            }
        }
    }

    void delete2()
    {
        int x, i, j;
        x = arr[0];

        i = 1, j = 2 * i + 1;
        size--;
        while(j<size-1)
        {
            if(arr[j]<arr[j+1])
            {
                j = j + 1;
            }

            if(arr[i]<arr[j])
            {
                swap(arr[i], arr[j]);
                i = j;
            }
            else
            {
                break;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left <=n and arr[largest] < arr[left])
    {
        largest = left;
    }
    else if (right <=n and arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
// void heapify(int arr[], int n, int i)  
//     {
//       int a=i;
//       int left=2*i+1;
//       int right=2*i+2;
      
//       if(left<n and arr[a]<arr[left])
//       {
//           a=left;
//       }
//       if(right<n and arr[a]<arr[right])
//       {
//           a=right;
//       }
      
//       if(a!=i)
//       {
//           swap(arr[i],arr[a]);
//           heapify(arr,n,a);
//       }
//     }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=(n/2);i>=0;i--)
        {
            heapify(arr,n,i);
        }
    }

    
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        int size=n;
        while(size>0)
        {
            swap(arr[size],arr[0]);
            size--;
            
            heapify(arr,size,0);
        }
    }
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    // h.insert(74);

    h.print();

    h.delete2();
    h.print();

    h.delete2();
    h.print();

    int arr[] = {54, 55, 53,85,52};

    int n = 5;
    // for (int i = (n / 2)-1; i >= 0; i--)
    //     heapify(arr, n, i);

    buildHeap(arr, n);
    for (int i = 0; i <n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << endl;

    heapSort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}