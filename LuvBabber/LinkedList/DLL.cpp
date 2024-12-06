#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->prev = NULL;
        this->next = NULL;
        this->data = data;
    }

    ~Node()
    {
        cout << "Value of deleted Node is " << this->data << endl;
    }
};

void printDLL(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    else
    {
        Node *newNode = new Node(data);

        newNode->next = head;
        head->prev = newNode;
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
        return;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node *prevNode = NULL;
    Node *currNode = head;
    int len = getLength(head);
    if (position == 1)
    {
        insertAtHead(head, tail, data);
    }
    else if (position >= len + 1)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        while (position != 1)
        {
            prevNode = currNode;
            currNode = currNode->next;
            position--;
        }

        Node *newNode = new Node(data);
        newNode->next = currNode;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        currNode->prev = newNode;
    }
}

void deleteNode(Node *&head, Node *&tail, int position)
{

    int len = getLength(head);
    if (head == NULL)
    {
        cout << "No linkedList is present, So unable to delete the node" << endl;
        return;
    }
    else if (position > len || position <= 0)
    {
        cout << "Please Provide the suitable position to delete the node from linkedlist" << endl;
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
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if (position == len)
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        Node *prevNode = NULL;
        Node *nextNode = NULL;

        while (position != 1)
        {
            position--;
            temp = temp->next;
        }
        prevNode = temp->prev;
        nextNode = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete temp;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtTail(head, tail, 10);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 20);
    insertAtPosition(head, tail, 100, 1);
    insertAtPosition(head, tail, 200, 2);
    insertAtPosition(head, tail, 300, 10);
    // deleteNode(head, tail, 1);
    // deleteNode(head, tail, 2);
    deleteNode(head, tail, 7);

    printDLL(head);
    return 0;
}
