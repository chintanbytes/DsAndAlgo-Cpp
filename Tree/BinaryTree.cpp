#include <iostream>
#include <queue>
#include "./BinaryTreeNode.cpp"

template <typename T>
class BinaryTree
{
private:
    BinaryTreeNode<T> *root;

    BinaryTreeNode<T> *BuildRecursive();
    void BuildLevelOrder();
    void PreOrder(BinaryTreeNode<T> *node);
    void InOrder(BinaryTreeNode<T> *node);
    void PostOrder(BinaryTreeNode<T> *node);
    void LevelOrder();
    int Count(BinaryTreeNode<T> *node);

public:
    BinaryTree();
    ~BinaryTree();
    void Build();
    void Travers();
    int CountNodes();
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    delete root;
}

template <typename T>
void BinaryTree<T>::Build()
{
    int choice;
    std::cout << "Select Recursive(1) OR LevelOrder(2): ";
    std::cin >> choice;

    if (choice == 1)
        root = BuildRecursive();
    else if (choice == 2)
        BuildLevelOrder();
    else
    {
        std::cout << "Not a valid entry. Try again" << std::endl;
        Build();
    }
}

template <typename T>
void BinaryTree<T>::Travers()
{
    std::cout << "Pre Order: ";
    PreOrder(root);
    std::cout << std::endl;

    std::cout << "In Order: ";
    InOrder(root);
    std::cout << std::endl;

    std::cout << "Post Order: ";
    PostOrder(root);
    std::cout << std::endl;

    std::cout << "Level Order: ";
    LevelOrder();
}

template <typename T>
int BinaryTree<T>::CountNodes()
{
    return Count(root);
}

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::BuildRecursive()
{
    T data;
    std::cout << "Enter data: ";
    std::cin >> data;

    auto node = new BinaryTreeNode<T>(data);

    char left;
    std::cout << "want to input left? (y/n): ";
    std::cin >> left;

    if (left == 'y')
        node->left = BuildRecursive();
    else
        node->left = nullptr;

    char right;
    std::cout << "want to input right? (y/n): ";
    std::cin >> right;

    if (right == 'y')
        node->right = BuildRecursive();
    else
        node->right = nullptr;

    return node;
}

template <typename T>
void BinaryTree<T>::BuildLevelOrder()
{
    T data;
    std::cout << "Enter data: ";
    std::cin >> data;

    root = new BinaryTreeNode<T>(data);
    std::queue<BinaryTreeNode<T> *> nodeTracker;
    nodeTracker.push(root);

    while (!nodeTracker.empty())
    {
        BinaryTreeNode<T> *front = nodeTracker.front();
        nodeTracker.pop();

        char left;
        std::cout << "want to input left? (y/n): ";
        std::cin >> left;

        if (left == 'y')
        {
            std::cout << "Enter data: ";
            std::cin >> data;

            auto leftNode = new BinaryTreeNode<T>(data);
            front->left = leftNode;
            nodeTracker.push(leftNode);
        }
        else
        {
            front->left = nullptr;
        }

        char right;
        std::cout << "want to input right? (y/n): ";
        std::cin >> right;

        if (right == 'y')
        {
            std::cout << "Enter data: ";
            std::cin >> data;

            auto rightNode = new BinaryTreeNode<T>(data);
            front->right = rightNode;
            nodeTracker.push(rightNode);
        }
        else
        {
            front->right = nullptr;
        }
    }
}

template <typename T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *node)
{
    if (node == nullptr)
        return;

    std::cout << node->data
              << " ";

    PreOrder(node->left);
    PreOrder(node->right);
}

template <typename T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T> *node)
{
    if (node == nullptr)
        return;

    InOrder(node->left);

    std::cout << node->data
              << " ";

    InOrder(node->right);
}

template <typename T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *node)
{
    if (node == nullptr)
        return;

    PostOrder(node->left);
    PostOrder(node->right);

    std::cout << node->data
              << " ";
}

template <typename T>
void BinaryTree<T>::LevelOrder()
{
    if (root == nullptr)
        return;

    std::queue<BinaryTreeNode<T> *> nodeTracker;
    nodeTracker.push(root);

    while (!nodeTracker.empty())
    {
        auto front = nodeTracker.front();
        nodeTracker.pop();

        std::cout << front->data << " ";

        if (front->left != nullptr)
            nodeTracker.push(front->left);

        if (front->right != nullptr)
            nodeTracker.push(front->right);
    }

    std::cout << std::endl;
}

template <typename T>
int BinaryTree<T>::Count(BinaryTreeNode<T> *node)
{
    if (node == nullptr)
        return 0;

    return Count(node->left) + Count(node->right) + 1;
}

// int main(int argc, char const *argv[])
// {
//     auto tree = new BinaryTree<int>();
//     tree->Build();
//     tree->Travers();
//     auto count = tree->CountNodes();
// }