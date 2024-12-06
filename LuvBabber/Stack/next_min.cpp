// find the next smaller integer of current integer or prev smaller integer just traversing of array is from Left to right
//  example
// input [8,9,7,4,5,6]
// output [7,7,4,-1,-1];

// If there is no smaller number present in the right hand side you can return -1 to it.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {8, 4, 6, 2, 3};
    int size = 5;
    stack<int> st;
    st.push(-1);
    int result[5] = {0};

    for (int i = size - 1; i >= 0; i--)
    {
        int top = st.top();
        if (arr[i] >= top)
        {
            result[i] = top;
            st.push(arr[i]);
        }
        else
        {
            st.pop();
            while (!st.empty())
            {
                int top = st.top();
                if (arr[i] >= top)
                {
                    result[i] = top;
                    st.push(arr[i]);
                    break;
                }
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
