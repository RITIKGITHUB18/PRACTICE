#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = (s + e) / 2;
    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    // create left array and right array
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // copy values from the original array to the left array;
    int k = s; // k-> starting index of left array value in original array;

    for (int i = 0; i < lenLeft; i++)
    {
        left[i] = arr[k];
        k++;
    }
    // copy values form the original array to right array
    k = mid + 1;
    for (int i = 0; i < lenRight; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // actual merge logic here
    int leftIndex = 0;
    int rightIndex = 0;
    // Yahi pr glti karte hai log
    int mainArrayIndex = s;

    while (leftIndex < lenLeft && rightIndex < lenRight)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    while (leftIndex < lenLeft)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    while (rightIndex < lenRight)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e)
{
    if (s > e)
    {
        return;
    }
    if (s == e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // recursion call for left array
    mergeSort(arr, s, mid);
    // recursion call for right array
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{
    int arr[] = {2, 1, 6, 9, 4, 5, 3};
    int size = 7;
    int s = 0;
    int e = size - 1;
    mergeSort(arr, s, e);

    cout << "After Merge Sort: " << endl;
    for (int ele : arr)
    {
        cout << ele << " ";
    }

    return 0;
}
