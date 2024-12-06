#include <bits/stdc++.h>
using namespace std;

// ! in this we are going to construt a tree by given preorder and inorder data.

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int data;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Level Order Traversal
void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    // Asli traversal start krte hai

    while (q.size() > 1) // ye condition important hai kyu ki isme agar hum !q.empty() lgayenge toh infinite loop me fass jayenge due to inserting the marker i.e.NULL value.
    // likely if we still use !q.empty() instead of q.size() then we have add aditional if statement while inserting NUll in the queue at "not a valid" i.e. if(!q.empty()) q.push(NULL);
    {
        TreeNode *front = q.front();
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

void createMapping(int inOrder[], int size, map<int, int> &valueToIndexMap)
{
    for (int i = 0; i < size; i++)
    {
        int element = inOrder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

int searchInOrder(int inOrder[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == target)
        {
            return i;
        }
    }

    return -1;
}

TreeNode *constructTreeFromPreAndInorderTraversal(int preOrder[], int inOrder[], int &preOrderIndex, int inOrderStart, int inOrderEnd, map<int, int> &valueToIndexMap, int size)
{

    //! preOrderIndex ko humesa by reference pass krna hai ni toh issue hoga, kyu ki preOrderIndex har recursion call left right ke le same hoga

    if (preOrderIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // processing
    int element = preOrder[preOrderIndex];
    preOrderIndex++;

    TreeNode *root = new TreeNode(element);

    // element search krna padega inOrder array me
    // int position = searchInOrder(inOrder, size, element);//* This search operation is taking O(n) time everyTime thatswhy we created a map to reduce that
    int position = valueToIndexMap[element];

    // Baaki recursion sambhal lega
    root->left = constructTreeFromPreAndInorderTraversal(preOrder, inOrder, preOrderIndex, inOrderStart, position - 1, valueToIndexMap, size);

    root->right = constructTreeFromPreAndInorderTraversal(preOrder, inOrder, preOrderIndex, position + 1, inOrderEnd, valueToIndexMap, size);

    return root;
}

TreeNode *constructTreeFromPostAndInorderTraversal(int postOrder[], int inOrder[], int &postOrderIndex, int inOrderStart, int inOrderEnd, map<int, int> &valueToIndexMap, int size)
{

    //! postOrderIndex ko humesa by reference pass krna hai ni toh issue hoga, kyu ki postOrderIndex har recursion call left right ke le same hoga

    if (postOrderIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // processing
    int element = postOrder[postOrderIndex];
    postOrderIndex--;

    TreeNode *root = new TreeNode(element);

    // element search krna padega inOrder array me
    // int position = searchInOrder(inOrder, size, element);//* This search operation is taking O(n) time everyTime thatswhy we created a map to reduce that
    int position = valueToIndexMap[element];

    // Baaki recursion sambhal lega

    //! In this we have to make the root->right call first because in this we are utilising the postOrder array and in post Order we know it is like "L R N" and we are starting from the back so first it is N then it is "R" then "L"
    root->right = constructTreeFromPostAndInorderTraversal(postOrder, inOrder, postOrderIndex, position + 1, inOrderEnd, valueToIndexMap, size);
    root->left = constructTreeFromPostAndInorderTraversal(postOrder, inOrder, postOrderIndex, inOrderStart, position - 1, valueToIndexMap, size);

    return root;
}

int main()
{
    int inOrder[] = {10, 8, 6, 2, 4, 12};
    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int postOrder[] = {10, 6, 8, 12, 4, 2};
    int size = 6;
    int preOrderIndex = 0;
    int postOrderIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = 5;

    map<int, int> valueToIndexMap; // creating mapping between element to index
    createMapping(inOrder, size, valueToIndexMap);

    TreeNode *root = constructTreeFromPreAndInorderTraversal(preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, valueToIndexMap, size);

    cout << "Printing the entire tree draws from preOrder ans inOrder traversal: " << endl;
    levelOrderTraversal(root);

    TreeNode *root2 = constructTreeFromPostAndInorderTraversal(postOrder, inOrder, postOrderIndex, inOrderStart, inOrderEnd, valueToIndexMap, size);
    cout << "\nPrinting the entire tree draws from postOrder and inOrder traversal: " << endl;
    levelOrderTraversal(root2);
    return 0;
}
