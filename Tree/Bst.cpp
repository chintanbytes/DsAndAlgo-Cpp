#include <iostream>
#include <queue>
#include "BinaryTreeNode.cpp"

template <typename T>
class Bst
{
private:
    BinaryTreeNode<T> *root;
    bool helperValid(BinaryTreeNode<T> *root, long long minV = INT_MIN - 1LL, long long maxV = INT_MAX + 1LL);

public:
    Bst(/* args */);
    ~Bst();
    BinaryTreeNode<T> *GetRroot();
    BinaryTreeNode<T> *SearchBSTIterative(BinaryTreeNode<T> *root, T val);
    BinaryTreeNode<T> *SearchBSTRecursive(BinaryTreeNode<T> *root, T val);
    BinaryTreeNode<T> *FindMin(BinaryTreeNode<T> *root);
    BinaryTreeNode<T> *FindMax(BinaryTreeNode<T> *root);
    int rangeSumBST(BinaryTreeNode<T> *root, int low, int high);
    bool isValidBST(BinaryTreeNode<T> *root);
};

template <typename T>
Bst<T>::Bst(/* args */)
{
}

template <typename T>
Bst<T>::~Bst()
{
}

template <typename T>
BinaryTreeNode<T> *Bst<T>::GetRroot()
{
    return BinaryTreeNode<T>();
}

template <typename T>
BinaryTreeNode<T> *Bst<T>::SearchBSTRecursive(BinaryTreeNode<T> *root, T val)
{
    if (!root || root->data == val)
        return root;
    if (root->data > val)
        return SearchBSTRecursive(root->left, val);
    return SearchBSTRecursive(root->right, val);
}

template <typename T>
BinaryTreeNode<T> *Bst<T>::FindMin(BinaryTreeNode<T> *root)
{
    if (!root || !root->left)
        return root;
    return FindMin(root->left);
}

template <typename T>
BinaryTreeNode<T> *Bst<T>::FindMax(BinaryTreeNode<T> *root)
{
    if (!root || !root->right)
        return root;
    return FindMax(root->right);
}

template <typename T>
bool helperValid(BinaryTreeNode<T> *root, long long minV = INT_MIN - 1LL, long long maxV = INT_MAX + 1LL)
{
    if (root == NULL)
        return true;

    bool left = helper(root->left, minV, root->val);
    bool right = helper(root->right, root->val, maxV);

    if (left && right && root->val > minV && root->val < maxV)
        return true;
    else
        return false;
}
template <typename T>
bool isValidBST(BinaryTreeNode<T> *root)
{
    return helper(root);
}

template <typename T>
BinaryTreeNode<T> *Bst<T>::SearchBSTIterative(BinaryTreeNode<T> *root, T val)
{
    while (root && root->data != val)
    {
        if (root->data > val)
            root = root.left;
        else
            root = root.right;
    }
    return root;
}

template <typename T>
int rangeSumBST(BinaryTreeNode<T> *root, int low, int high)
{
    auto ans = 0;
    if (!root)
        return ans;

    if (root->data >= low && root->data <= high)
        ans += root->data;

    if (root->data > high)
        ans += rangeSumBST(root->left, low, high);
    else if (root->data < low)
        ans += rangeSumBST(root->right, low, high);
    else
        ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    return ans;
}
