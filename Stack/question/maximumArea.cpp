#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> RightSmallerElement(vector<int> nums)
    {
        stack<int> s;
        s.push(-1);
        int n = nums.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = nums[i];
            while (s.top() != -1 && nums[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> LeftSmallerElement(vector<int> nums)
    {
        stack<int> s;
        s.push(-1);
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];
            while (s.top() != -1 && nums[s.top()] >= curr)
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> right = RightSmallerElement(heights);
        vector<int> left = LeftSmallerElement(heights);
        int area;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (right[i] == -1)
            {
                right[i] = n;
            }
            int b = right[i] - left[i] - 1;
            int n1 = l * b;
            area = max(area, n1);
        }
        return area;
    }
};

int main()
{
    int t = 1;
    vector<int> nums;
    while (t)
    {
        int p;
        cin >> p;
        nums.push_back(p);
        cout << "Yes/No" << endl;
        cin >> t;
    }
    Solution s;
    cout << s.largestRectangleArea(nums) << endl;
}