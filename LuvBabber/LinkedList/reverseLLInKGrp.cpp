
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
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

void printLL(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << endl;
}

Node *reverseLL(Node *&prev, Node *&curr)
{
    if (curr == NULL)
    {
        return prev;
    }

    // precessing;
    Node *forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;

    // recursive call

    return reverseLL(prev, curr);
}

Node *reverseInKGrp(Node *prev, Node *curr, int k)
{
    // base case
    if (curr == NULL)
    {
        return prev;
    }

    Node *forward = NULL;
    // processing
    while (k != 0)
    {
        k--;
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr->next = forward;
    }

    return reverseInKGrp(prev, curr, k);
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 7);

    printLL(head);
    Node *prev = NULL;
    Node *curr = head;
    int k = 2;
    Node *head2 = reverseInKGrp(prev, curr, k);
    printLL(head2);

    return 0;
}
