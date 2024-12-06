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

void addOne(Node *&head)
{
    // reverse
    Node *prev = NULL;
    Node *curr = head;
    Node *head1 = reverseLL(prev, curr);

    // add
    int carry = 1;
    Node *temp = head1;
    while (temp->next != NULL)
    {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        temp = temp->next;

        if (carry == 0)
        {
            break;
        }
    }

    // process last Node

    if (carry != 0)
    {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
    }

    if (carry != 0)
    {
        Node *newNode = new Node(carry);
        temp->next = newNode;
    }

    // reverse again
    prev = NULL;
    curr = head1;
    head = reverseLL(prev, curr);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 0);
    insertAtHead(head, tail, 0);
    // insertAtHead(head, tail, 9);
    // insertAtHead(head, tail, 9);
    // insertAtHead(head, tail, 9);

    printLL(head);

    addOne(head);
    printLL(head);

    return 0;
}
