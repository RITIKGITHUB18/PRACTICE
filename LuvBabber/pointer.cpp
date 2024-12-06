#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num[5] = {2, 4, 5, 6, 7};
    int arr[5] = {12, 10, 13, 90, 6};
    int(*ptr)[5] = &arr;
    int *ptr1[5];
    ptr1[0] = &num[0];
    ptr1[1] = &num[1];
    ptr1[2] = &num[2];

    for (int i = 0; i < 5; i++)
    {
        cout << "ptr1 " << i << " " << ptr1[i] << endl;
    }

    // float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};

    // float *ptr1 = &arr[0];
    // float *ptr2 = ptr1 + 3;
    // cout << *ptr2 << " ";
    // cout << ptr2 - ptr1;
    return 0;
}