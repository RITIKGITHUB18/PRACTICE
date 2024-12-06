#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Max heap -by default
    priority_queue<int> pq;
    //! creation of min heap
    priority_queue<int, vector<int>, greater<int>> min_pq; // rest of the method is same for rest of the property

    // insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout << "Top Element of heap: " << pq.top() << endl;

    pq.pop(); // alway element is poped from the pop

    cout << "After poping, the top element of Heap: " << pq.top() << endl;

    cout << "Size of max heap: " << pq.size() << endl;

    if (pq.empty())
    {
        cout << "Priority queue is empty" << endl;
    }
    else
    {
        cout << "Priority queue is not empty" << endl;
    }

    return 0;
}
