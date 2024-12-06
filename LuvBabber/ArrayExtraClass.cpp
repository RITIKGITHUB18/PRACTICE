#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {23, -7, 12, -10, -11, 40, 60};
    int n = 7;
    // int j = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] < 0)
    //     {
    //         swap(arr[i], arr[j]);
    //         j++;
    //     }
    // }

    // ! or

    int j = n - 1;
    int i = 0;
    while (j >= i)
    {
        if (arr[j] < 0 && arr[i] > 0)
        {
            swap(arr[i], arr[j]);
            j--;
            i++;
        }
        if (arr[i] < 0 && arr[j] < 0)
        {
            i++;
        }
        if (arr[i] > 0 && arr[j] > 0)
        {
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
