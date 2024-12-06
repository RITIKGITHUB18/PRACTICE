#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int &pos, int &ans)
{
    // base condotion
    if (pos == 1)
    {
        ans = st.top();
        return;
    }

    // 1 case that we solve
    pos--;
    int temp = st.top();
    st.pop();

    // recursion call
    solve(st, pos, ans);

    // backtrack
    st.push(temp);
}

int getMiddleElement(stack<int> &st)
{
    int size = st.size();
    int pos = 0;

    // If stack is empty
    if (st.empty())
    {
        return -1;
    }
    else
    {
        // stack is not empty

        // odd
        if (size & 1)
        {
            pos = size / 2 + 1;
        }
        else
        {
            pos = size / 2;
        }
    }

    int ans = -1;
    solve(st, pos, ans);
    return ans;
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);

    int mid = getMiddleElement(st);
    cout << "Middle Element is: " << mid << endl;
    return 0;
}
