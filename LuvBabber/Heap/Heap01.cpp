//* MIN Heap = value of Parent node is always smaller then value of child node
//* MAX Heap = value of Parent node is always greater then the value of its child node

//* we tranform the tree in the array format and start indexing with 1 instead of zero
//* To Traverse from parent to child
//* i - left = 2*i;
//* |
//* right = 2*i+1;

//! incase of 0 based indexing
//* To Traverse from parent to child
//* i - left = 2*i+1;
//* |
//* right = 2*i+2;

// * To traverse from the child to parent in both the case either its 0 based indexing or 1 based indexing
// * child to parent
// * i - left/right = i/2; here i is child and i/2 is parent

// insertion in tree
//! Heapification:-During insertion placing the element at the correct place by comparing the value of incoming node from its parent is called heapification

#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow" << endl;
            return;
        }
        // size increase ho jaega element k aane pr
        size++;
        int index = size;
        arr[index] = val;

        // take the val to its correct position
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    // ! Delete the root element
    int deleteFromHeap()
    {
        int answer = arr[1];
        // replacement-> last element ko delete node ki jagah bhejdo
        arr[1] = arr[size];

        size--;

        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            // find out krna h, sabse bda kon
            int largestElementKaIndex = index;
            // check left child
            if (leftIndex <= size && arr[largestElementKaIndex] < arr[leftIndex])
            {
                largestElementKaIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestElementKaIndex] < arr[rightIndex])
            {
                largestElementKaIndex = rightIndex;
            }

            // No change
            if (index == largestElementKaIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestElementKaIndex]);
                index = largestElementKaIndex;
            }
        }
        return answer;
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int *arr, int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestElementKaIndex = index;

    // Teeno me se max lao
    if (leftIndex <= n && arr[largestElementKaIndex] < arr[leftIndex])
    {
        largestElementKaIndex = leftIndex;
    }
    if (rightIndex <= n && arr[largestElementKaIndex] < arr[rightIndex])
    {
        largestElementKaIndex = rightIndex;
    }

    // After these 2 conditions largestKaIndex will be pointing towards largest element among 3
    if (index != largestElementKaIndex)
    {
        swap(arr[index], arr[largestElementKaIndex]);
        // aab recursion sambhal lega
        index = largestElementKaIndex;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n)
{

    // we have to heapify the all the nodes except the leaf one so we can run the loop for index= 0 to index=(n/2) because the nodes from  index=(n/2+1) to index = n all are the heaf node
    // it convert the given array into heapify i.e. given tree in heap structure
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}

void heapSort(int arr[], int n)
{
    while (n != 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main()
{
    Heap h(20);
    // insertion
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout << "Printing the content of heap: " << endl;
    h.printHeap();

    int ans = h.deleteFromHeap();
    cout << "Deleted Element: " << ans << endl;
    h.printHeap();

    cout << "Passing a array to heapify and checking the sorting functionality" << endl;

    int arr[] = {-1, 5, 10, 15, 20, 25, 12}; // inserting -1 at zero'th index is important please make a note of it
    int n = 6;
    buildHeap(arr, 6);

    cout << "Printing heap: " << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "Printing heap after sorting: " << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// Max of heap O(1)
// Min of heap O(1)
// creation of heap O(n)
// insertion of heap O(logn) - insert at last then do heafication to adjust at the right place
// Deletion of root element of heap O(logn)- after deletion it do the heafication to find the right place for the last-node that we swaped with the root
// Heap sort Time complexity is O(nlogn)