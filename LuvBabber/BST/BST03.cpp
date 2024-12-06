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

/** !Convert BST INTO SORTED DOUBLY LINKED list
 * INPUT:
 *          100
 *         /   \
 *        50    200
 *       /  \     \
 *      5   60    300
 *
 * OUTPUT:
 *  tree: left,right
 *  tree into LL: left=>prev, right=>next
 *  BST -> Doubly LL
 *  5<->50<->60<->100<->200< ->300
 */
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

// convert this bst into a sorted doubly Linked List
void convertBSTtoDLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }

    // RNL

    // R
    convertBSTtoDLL(root->right, head);

    // N
    root->right = head; // act like a next pointer
    if (head != NULL)
        head->left = root; // act like a prev pointer

    head = root;

    // L
    convertBSTtoDLL(root->left, head);
}

// here n is the number of Node
// head is head of doubly linked list
Node *convertDLLtoBST(Node *&head, int n)
{
    // Base case
    if (head == NULL || n <= 0)
    {
        return NULL;
    }

    // LNR

    // L
    Node *leftSubTree = convertDLLtoBST(head, n / 2);

    // N
    Node *root = head;
    root->left = leftSubTree;

    //! Important
    head = head->right;

    // R

    // Calculation of n is like our n/2 node goes to leftSubTree and 1 node goes to root node then we left with our n-n/2-1;
    Node *rightSubTree = convertDLLtoBST(head, n - n / 2 - 1);
    root->right = rightSubTree;
    return root;
}

void printLinkedList(Node *head)
{
    Node *temp = head;

    cout << "Printing the entire list: " << endl;
    while (temp->right != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->right;

        // if we want to print it in reverse order we can do it by temp = temp->left;
    }
    cout << temp->data;
    cout << endl;
}

int main()
{
    int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int start = 0;
    int end = size - 1;
    Node *root = bstFromInOrder(inOrder, start, end);

    levelOrderTraversal(root);
    Node *head = NULL;
    convertBSTtoDLL(root, head);
    printLinkedList(head);
    Node *newRoot = convertDLLtoBST(head, 7);
    cout << "Printing Tree from DLL to BST" << endl;
    levelOrderTraversal(newRoot);
}

// Input 50 30 20 35 40 60 70 80 55 -1