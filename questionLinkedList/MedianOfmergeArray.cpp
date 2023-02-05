#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();

        int n = size1 + size2;
        int mid = n / 2;
        int a[n];

        int i = 0, j = 0, k = 0;

        double median;

        if (size1 != 0 && size2 != 0)
        {
            while (i < size1 && j < size2)
            {
                if (k <= mid)
                {
                    if (nums1[i] < nums2[j])
                    {
                        a[k] = nums1[i];
                        i++;
                        k++;
                    }
                    else
                    {
                        a[k] = nums2[j];
                        j++;
                        k++;
                    }
                    // cout << "Hi" << endl;
                }
                else
                {
                    break;
                }
            }

            for (; i < size1; i++)
            {
                if (k <= mid)
                {
                    a[k] = nums1[i];
                    k++;
                }
                else
                {
                    break;
                }
            }

            for (; j < size2; j++)
            {
                if (k <= mid)
                {
                    a[k] = nums2[j];
                    k++;
                }
                else
                {
                    break;
                }
            }

            if (n % 2 != 0)
            {
                median = a[mid];
            }
            else
            {
                median = (double)(a[mid - 1] + a[mid]) / 2;
            }
        }

        // else
        // {
        //     if (size1 != 0)
        //     {
        //         for (i = 0; i < size1; i++)
        //         {
        //             if (k <= mid)
        //             {
        //                 a[k] = nums1[i];
        //                 k++;
        //             }
        //             else
        //             {
        //                 break;
        //             }
        //         }
        //     }
        //     if (size2 != 0)
        //     {
        //         for (j = 0; j < size2; j++)
        //         {
        //             if (k <= mid)
        //             {
        //                 a[k] = nums2[j];
        //                 k++;
        //             }
        //             else
        //             {
        //                 break;
        //             }
        //         }
        //     }
        //     if (n % 2 != 0)
        //     {
        //         median = a[mid];
        //     }
        //     else
        //     {
        //         median = (double)(a[mid - 1] + a[mid]) / 2;
        //     }

        // }
        return median;
    }
};

int main()
{
    Solution obj;
    int n;
    cout << "Enter index for vector 1" << endl;
    cin >> n;

    int p;
    vector<int> a1;

    cout << "Vector element is" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        a1.push_back(p);
    }

    int n1;
    cout << "Enter index for vector 2" << endl;
    cin >> n1;
    vector<int> a2;
    cout << "Vector element is" << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> p;
        a2.push_back(p);
    }
    double t = (double)obj.findMedianSortedArrays(a1, a2);

    cout << "Median is " << t << endl;
}