#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// It returns the root node of created tree
Node *createTree()
{
    cout << "Enter the value: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // create Node
    Node *root = new Node(data);

    // Create left subTree
    cout << "Left of Node: " << root->data << endl;
    root->left = createTree();
    // Create right subTree
    cout << "Right of Node: " << root->data << endl;
    root->right = createTree();

    return root;
}

// ! Type of traversal
/**
 * N-> current Node
 * L->Left part
 * R->Right Part
 * PreOrder-> NLR
 * InOrder->LNR
 * PostOrder->LRN
 *
 * *Time Complexity is O(n) visiting each node for traversal
 * *Space Complexity is O(H) in recursive method each node is stored in a stack
 *
 * * Level Order Traversal i.e BFS
 */

//* Preorder Traversal

void preOrder(Node *&root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // N L R
    // N
    cout << root->data << " ";
    // L
    preOrder(root->left);
    // R
    preOrder(root->right);
}

// * PostOrder Traversal

void postOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    // L R N
    // L
    postOrderTraversal(root->left);

    // R
    postOrderTraversal(root->right);

    // N
    cout << root->data << " ";
}

// InOrder Traversal
void inOrderTraveral(Node *root)
{
    // Base case

    if (root == NULL)
    {
        return;
    }

    // L N R

    // L
    inOrderTraveral(root->left);

    // N
    cout << root->data << " ";

    // R
    inOrderTraveral(root->right);
}

// Level Order Traversal
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    // Asli traversal start krte hai

    while (q.size() > 1) // ye condition important hai kyu ki isme agar hum !q.empty() lgayenge toh infinite loop me fass jayenge due to inserting the marker i.e.NULL value.
    // likely if we still use !q.empty() instead of q.size() then we have add aditional if statement while inserting NUll in the queue at "not a valid" i.e. if(!q.empty()) q.push(NULL);
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            // Not a valid Node
            cout << endl;
            q.push(NULL);
        }
        else
        {
            // Valid Node
            cout << front->data << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }

            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{

    Node *root = createTree();
    cout << "root data: " << root->data << endl;

    // Pre Order traversal
    cout << "\nPre Order Traversal: " << endl;
    preOrder(root);

    // Post Order traversal
    cout << "\nPost Order Traversal: " << endl;
    postOrderTraversal(root);

    // In order traversal
    cout << "\nIn Order Traversal: " << endl;
    inOrderTraveral(root);

    // Level order traversal
    cout << "\nLevel Order Traversal: " << endl;
    levelOrderTraversal(root);

    return 0;
}
