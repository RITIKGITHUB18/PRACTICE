#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    cout << "Enter the value for Node: " << endl;
    int value;
    cin >> value;

    if (value == -1)
    {
        return NULL;
    }

    // create Node
    Node *root = new Node(value);
    cout << "Entering in the left of: " << value << endl;
    root->left = createTree();
    cout << "Entering in the right of: " << value << endl;
    root->right = createTree();

    return root;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);

    postOrder(root->right);
    cout << root->data << " ";
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void levelOrderTraversal(Node *root)
{
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

// ! print left view

void printLeftView(Node *root, int level, vector<int> &leftView)
{
    if (root == NULL)
    {
        return;
    }

    if (level == leftView.size())
    {
        // iska matlab left view ki node milgyi hai, store karlo
        leftView.push_back(root->data);
    }

    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

void printRightView(Node *root, int level, vector<int> &rightView)
{
    if (root == NULL)
    {
        return;
    }

    if (level == rightView.size())
    {
        // iska matlab left view ki node milgyi hai, store karlo and isme level ko by reference isliye pass ni kiya taki humme dusre node na mile only left view me jo dikhenge whi humme chahiye it is not simeilar lo level order traversal
        rightView.push_back(root->data);
    }

    printRightView(root->right, level + 1, rightView);
    printRightView(root->left, level + 1, rightView);
}

void printTopView(Node *root)
{
    // hd is horizontal distance
    map<int, int> hdToNodeMap;

    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // if there is no entry for horizontal distance [hd] in the map, then create a new entry
        if (hdToNodeMap.find(hd) == hdToNodeMap.end())
        {
            hdToNodeMap[hd] = frontNode->data;
        }

        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    cout << "\nPrinting Top View: " << endl;

    for (auto i : hdToNodeMap)
    {
        cout << i.second << " ";
    }
}

// Boundary Traversal
//  Part A print left node
//  Part B print leaf Node
//  Part C print right Node

void printLeftBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // leaf Node
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    cout << root->data << " ";
    if (root->left != NULL)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root->right != NULL)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }

    cout << root->data << " ";
}

void boundaryTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    printLeftBoundary(root);
    printLeafBoundary(root);
    if (root->right != NULL)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
}

void printBottomView(Node *root)
{
    map<int, int> hdToNodeMap;

    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // Just overwrite the value if it already present
        hdToNodeMap[hd] = frontNode->data;

        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }

        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    cout << "\nPrinting Bottom View: " << endl;

    for (auto i : hdToNodeMap)
    {
        cout << i.second << " ";
    }
}

int main()
{
    Node *root = createTree();
    cout << "Tree's lool like: " << endl;
    levelOrderTraversal(root);

    vector<int> leftView;
    printLeftView(root, 0, leftView);
    cout << "\nPrinting Left View: " << endl;
    for (int i = 0; i < leftView.size(); i++)
    {
        cout << leftView[i] << " ";
    }

    // * right view
    vector<int> rightView;
    printRightView(root, 0, rightView);
    cout << "\nPrinting right View: " << endl;
    for (int i = 0; i < rightView.size(); i++)
    {
        cout << rightView[i] << " ";
    }

    printTopView(root);
    printBottomView(root);

    cout << "\nPrinting the Boundary Traversal" << endl;
    boundaryTraversal(root);

    return 0;
}

// input
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1