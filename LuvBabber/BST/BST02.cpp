#include <bits/stdc++.h>
using namespace std;

//! In case of bst inorder traversal,it give me the sorted binary tree

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *bstFromInOrder(int inOrder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    // ! 1 case solve krna hai
    int mid = (start + end) / 2;

    int element = inOrder[mid];
    Node *root = new Node(element);

    root->left = bstFromInOrder(inOrder, start, mid - 1);
    root->right = bstFromInOrder(inOrder, mid + 1, end);

    return root;
}

void levelOrderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int start = 0;
    int end = size - 1;
    Node *root = bstFromInOrder(inOrder, start, end);

    levelOrderTraversal(root);
}

// Input 50 30 20 35 40 60 70 80 55 -1