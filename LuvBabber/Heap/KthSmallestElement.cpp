//! Find the Kth Smallest element in a array

#include <bits/stdc++.h>
using namespace std;

int getKthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> pq;

    // First Element ko process kro
    for (int i = 0; i < k; i++)
    {
        int element = arr[i];
        pq.push(element);
    }

    // remaining element ko tbhi insert karenge jab wo top element se chota hoga
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if (element < pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > pq.top())
        { // sirf bade element hi insert krne hai
            pq.pop();
            pq.push(nums[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int k;
    cout << "Enter the value of K" << endl;
    cin >> k;
    cout << "Enter the element to get Kth smallest Element of all" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Kth Smallest element present in the list is: " << getKthSmallestElement(arr, n, k) << endl;
    ;

    return 0;
}
