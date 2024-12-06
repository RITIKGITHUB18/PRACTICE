#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
        cout << "Default constructor is called" << endl;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        cout << "Paramterised constructor is called" << endl;
    }
    ~Node()
    {
        cout << "Destructor called for : " << this->data << endl;
    }
};

// Get Length of LL
int getLength(Node *head)
{
    int count = 1;
    Node *temp = head;
    while (temp != NULL)
    {
        ++count;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // if ll is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert at any position in LL
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    int length = getLength(head);
    if (position == 1)
    {
        insertAtHead(head, tail, data);
    }
    else if (position == length + 1)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        // ! insert at middle

        // Step-1: Create a new Node
        Node *newNode = new Node(data);

        // step-2: traverse prev//curr to position
        Node *prev = NULL;

        Node *curr = head;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }

        // step-3 attach prev to newNode
        prev->next = newNode;
        // step-4 attch newnode to curr
        newNode->next = curr;
    }
}

// Delete the Node
void DeleteNode(Node *&head, Node *&tail, int position)
{
    int length = getLength(head);

    if (head == NULL)
    {
        cout << "unable to delete, the LL is empty" << endl;
        return;
    }
    else if (head == tail)
    {
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    else if (position == 1)
    { // Delete first Node
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else if (position == length)
    { // Delete Last Node
        // Find prev
        Node *prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        prev->next = NULL;
        tail = prev;
    }
    else
    {
        // Delete middle node
        Node *curr = head;
        Node *prev = NULL;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// Print LL
void printll(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 50);
    insertAtPosition(head, tail, 40, 5);
    insertAtPosition(head, tail, 100, 6);
    printll(head);
    DeleteNode(head, tail, 4);
    // insertAtPosition(head, tail, 110, 7);

    printll(head);

    return 0;
}
