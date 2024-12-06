#include <bits/stdc++.h>
using namespace std;

// Recursively done quick sort

void quicksort(int *arr, int start, int end)
{

    // base case
    if (start >= end)
    {
        return;
    }
    int i = start - 1;
    int j = start;
    int pivot = end;
    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            ++i;
            swap(arr[i], arr[j]);
        }
        j++;
    }

    ++i;
    swap(arr[i], arr[pivot]);

    // For LHS
    quicksort(arr, start, i - 1);
    // For RHS
    quicksort(arr, i + 1, end);
}

int main()
{
    int arr[] = {3, 5, 1, 6, 8, 9, 4};
    int size = 7;
    int start = 0;
    int end = size - 1;
    quicksort(arr, start, end);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
