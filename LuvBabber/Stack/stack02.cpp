// Implement functionality of two stack using a single array
#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
    }

    void push1(int data)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "Stack is completely full, i.e. this is the condition of overflow" << endl;
        }
    }

    void push2(int data)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = data;
        }
        else
        {
            cout << "Stack is completely full, i.e. this is the condition of overflow" << endl;
        }
    }

    void pop1()
    {
        if (top1 != -1)
        {
            arr[top1] = 0;
            top1--;
        }
        else
        {
            cout << "Stack is already empty, i.e  this is the condition of underflow" << endl;
        }
    }

    void pop2()
    {
        if (top2 != size)
        {
            arr[top2] = 0;
            top2++;
        }
        else
        {
            cout << "Stack is already empty, i.e this is the condition of underflow" << endl;
        }
    }

    void print()
    {

        cout << "Top1: " << top1 + 1 << endl;
        cout << "Top2: " << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(10);
    st.push1(10);
    st.push1(20);
    st.push1(30);
    st.push1(40);

    // push in stack 2
    st.push2(100);
    st.push2(200);
    st.push2(300);
    st.push2(400);
    st.push2(500);

    st.print();

    return 0;
}
