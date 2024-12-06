#include <bits/stdc++.h>
using namespace std;

//! In case of bst inorder traversal give me the sorted binary tree

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

Node *minValue(Node *root)
{
    if (root == NULL)
    {
        cout << "No Min Value" << endl;
        return NULL;
    }

    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxValue(Node *root)
{
    if (root == NULL)
    {
        cout << "No max value" << endl;
        return NULL;
    }

    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void *createBST(Node *&root)
{
    cout << "Enter Data: " << endl;
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter Data: " << endl;
        cin >> data;
    }
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

bool searchInBST(Node *root, int &target)
{
    if (root == NULL)
    {
        return false;
    }

    if (target == root->data)
    {
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;

    if (target > root->data)
    {
        rightAns = searchInBST(root->right, target);
    }
    else
    {
        leftAns = searchInBST(root->left, target);
    }

    return leftAns || rightAns;
}

Node *deleteFromBST(Node *root, int target)
{
    // target ko dhundo
    // target ko delete karo

    if (root == NULL)
    {
        return NULL;
    }

    if (target == root->data)
    {
        // ab delete karenge
        //  4 cases

        // * case -1 leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // * case -2 left non null and right null
        else if (root->left != NULL && root->right == NULL)
        {
            Node *childSubTree = root->left;
            delete root;
            return childSubTree;
        }

        // * case-3 right non null and left null
        else if (root->left == NULL && root->right != NULL)
        {
            Node *childSubTree = root->right;
            delete root;
            return childSubTree;
        }

        //* case-4 left non null and right non null

        //! Two ways to solve it
        // * --- get the maximum value from left tree
        // * OR --- get the minimum value from right tree
        else
        {
            Node *maxi = maxValue(root->left);
            // replacement
            root->data = maxi->data;
            // delete actual maxi wali node
            root->left = deleteFromBST(root->left, maxi->data);
            return root;
        }
    }
    else if (root->data >= target)
    {
        root->left = deleteFromBST(root->left, target);
    }
    else
    {
        root->right = deleteFromBST(root->right, target);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);

    cout << "\nInOrder: " << endl;
    inOrder(root);
    cout << "\npreOrder: ";
    preOrder(root);
    cout << "\npostOrder: " << endl;
    postOrder(root);

    cout << endl;

    Node *minNode = minValue(root);
    if (minNode)
    {
        cout << "\nmin value: " << minNode->data << endl;
    }
    else
    {
        cout << "\nThere is no node in tree, so no min value" << endl;
    }

    Node *maxNode = maxValue(root);
    if (maxNode)
    {
        cout << "\nmax value: " << maxNode->data << endl;
    }
    else
    {
        cout << "\nThere is no node in tree, so no max value" << endl;
    }

    // ! Delete the node frome the binary search tree

    int target;
    cout << "Enter the value of target: " << endl;
    cin >> target;
    while (target != -1)
    {
        root = deleteFromBST(root, target);
        cout << "\n Printing the level order traversal: " << endl;
        levelOrderTraversal(root);

        cout << "\nEnter the value of target: " << endl;
        cin >> target;
    }

    // ! searching
    // int target = 25;
    // bool result = searchInBST(root, target);
    // if (result)
    // {
    //     cout << "This value is present in the Tree" << endl;
    // }
    // else
    // {
    //     cout << "Sorry, This is not present in the tree" << endl;
    // }
    // return 0;
}

// Input 50 30 20 35 40 60 70 80 55 -1