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

Node *startingNodeOfLoop(Node *&head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            slow = head;
            break;
        }
    }

    if (fast == NULL)
    {
        return NULL;
    }

    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }

    if (fast == slow)
    {
        return slow;
    }
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

void removeLoop(Node *&head)
{
    Node *startingPoint = startingNodeOfLoop(head);

    Node *temp = startingPoint;
    while (temp->next != startingPoint)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 60);
    printLL(head);

    tail->next = head->next->next;
    cout << startingNodeOfLoop(head)->data << endl;
    // printLL(head);
    removeLoop(head);
    printLL(head);

    return 0;
}
