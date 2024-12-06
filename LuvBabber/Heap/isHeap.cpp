//! Given CBT is a heap or not
// for Heap condition is Complete binary tree and must follow either max heap property or min heap property

// So here intuition is that we will go to the leaf node and ask wheteher it is a valid heap or not in return we will take two value that is maximum val and whether heap or not i.e. true or false

// instead of using pair for storing the two value we will creat our own class

class Info
{
public:
    int maxVal;
    bool isHeap;

    Info(int a, bool b)
    {
        this->maxVal = a;
        this->isHeap = b;
    }
};

Info checkMaxHeap(Node *root)
{
    // Base case
    if (root == NULL)
    {
        Info temp;
        temp.maxVal = INT_MIN;
        temp.isHeap = true;
        return temp;
    }

    if (root->left == NULL && root->right == NULL)
    {
        Info temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }

    Info leftAns = checkMaxHeap(root->left);
    Info rightAns = checkMaxHeap(root->right);

    // We have to solve one case
    if (root->data > leftAns.maxVal && root->data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap)
    {
        Info ans;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }
    else
    {
        Info ans;
        ans.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
        ans.isHeap = false;
        return ans;
    }
}

// ! New Problem: we have to convert given CBT + BST into max heap

void storeInorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
    {
        return;
    }
    // Inorder is LNR
    storeInorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    storeInorderTraversal(root->right, inorder);
}

void replaceUsingPostOrder(Node *root, vector<int> &inorder, int &i)
{
    if (root == NULL)
    {
        return;
    }
    // LRN-postOrder you can check why we are using the postOrder/levelOrderTraversal traversal by doing the dry run in LRN ,
    // we are using Because by post order we are first setting up the left and right child then we go to the parent node andyou know we are traversing the data present in the sorted format so our parent node will be alway greater then its left and right child
    replaceUsingPostOrder(root->left, inorder, i);
    replaceUsingPostOrder(root->right, inorder, i);
    root->data = inorder[i++];
}

void convertBSTIntoMaxHeap(Node *root)
{
    // * step-1 Store inorder - because inorder give us the sorted array
    vector<int> inorder;
    storeInorderTraversal(root, inorder);
    //* step-2 replace the node values with the sorted inorder values,using the postorder traversal
    int index = 0;
    replaceUsingPostOrder(root, inorder, index);
}