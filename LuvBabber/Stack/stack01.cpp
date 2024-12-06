// Data structure - LIFO=> Last in first Out
// Stack Underflow - if stcak is empty and you are trying to remove element so this is the condition of stack underflow
// Stack overflow -If stack is full and you trying to insert a new element into it so this will be the condition of stack overflow

// using ctrl+z is the best example of stack, it reverse the last action that we performed

// #include <bits/stdc++.h>
// #include <stack>

// using namespace std;

#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack is fulll,i.e underflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty, i.e. underflow" << endl;
            return;
        }
        else
        {
            top--;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        else
        {
            return arr[top];
        }
    }

    int getSize()
    {
        return top + 1;
    }

    void print()
    {
        cout << "Top " << top << endl;
        cout << "Element: " << getTop() << endl;
        cout << "Stack: ";
        for (int i = 0; i < getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << endl;
    }
};

int main()
{

    // creation of stack
    // stack<int> st;
    // // stack<char>st;
    // // stack<string>st;

    // // input
    // st.push(13);
    // st.push(14);
    // st.push(15);
    // st.push(16);
    // // remove
    // st.pop();
    // // get length or size
    // st.size();
    // // check whether the stack is empty or not
    // st.empty();
    // // get the top element of stack
    // st.top();

    //! Creation of Stack
    Stack st(8);

    // Push
    st.push(10);
    st.print();

    st.push(20);
    st.print();

    st.push(30);
    st.print();

    st.push(40);
    st.print();

    // return arr[top];

    st.pop();
    st.print();

    return 0;
}
