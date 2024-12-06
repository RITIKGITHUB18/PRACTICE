// Problem is insert the given element at the bottom of the stack

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int &element)
{
    // base case
    if (st.empty())
    {
        st.push(element);
        return;
    }

    // Processing;
    int temp = st.top();
    st.pop();

    // recursive call
    insertAtBottom(st, element);

    // backtracking
    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    // recursive code
    reverseStack(st);

    // putting the element at the bottom after hitting the base case
    insertAtBottom(st, temp);
}

// Insert in a sorted Stack

void insertInASortedStack(stack<int> &st, int &element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }

    // processing
    if (st.top() <= element)
    {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();

    insertInASortedStack(st, element);

    // backtracking
    st.push(temp);
}

// Sort a stack
void sortAStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    // Processing
    int temp = st.top();
    st.pop();

    sortAStack(st);

    insertInASortedStack(st, temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(2);
    st.push(30);
    st.push(40);
    st.push(5);
    int element = 25;
    // insertAtBottom(st, element);
    // reverseStack(st);

    // insertInASortedStack(st, element);
    sortAStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
