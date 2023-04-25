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
    int Height(BinaryTreeNode<T> *node);
    bool Symmetric(BinaryTreeNode<T> *left, BinaryTreeNode<T> *right);
    BinaryTreeNode<T> *InPreHelper(std::vector<T> &inOrder, std::vector<T> &preOrder, int inS, int inE, int preS, int preE);
    BinaryTreeNode<T> *InPostHelper(std::vector<T> &inOrder, std::vector<T> &postOrder, int inS, int inE, int postS, int postE);
    std::pair<int, int> HeightDiameter(BinaryTreeNode<T> *node);

public:
    BinaryTree();
    ~BinaryTree();
    void Build();
    void Travers();
    int CountNodes();
    int TreeHeight();
    int IsSymmetric();
    BinaryTreeNode<T> *GetRoot();
    void FindMin(BinaryTreeNode<T> *node, int &min);
    void FindMax(BinaryTreeNode<T> *node, int &max);
    int CountLeafNode(BinaryTreeNode<T> *node);
    BinaryTreeNode<T> *BuildTreeUsingInPre(std::vector<T> &inOrder, std::vector<T> &preOrder);
    BinaryTreeNode<T> *BuildTreeUsingInPost(std::vector<T> &inOrder, std::vector<T> &postOrder);
    int Diameter(BinaryTreeNode<T> *node);
    int DiameterBetter(BinaryTreeNode<T> *node);
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
int BinaryTree<T>::TreeHeight()
{
    return Height(root);
}

template <typename T>
int BinaryTree<T>::IsSymmetric()
{
    if (root == nullptr)
        return true;

    return Symmetric(root->left, root->right);
}

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::GetRoot()
{
    return root;
}

template <typename T>
void BinaryTree<T>::FindMin(BinaryTreeNode<T> *node, int &min)
{
    if (node == nullptr)
        return;

    min = std::min(node->data, min);
    FindMin(node->left, min);
    FindMin(node->right, min);
}

template <typename T>
void BinaryTree<T>::FindMax(BinaryTreeNode<T> *node, int &max)
{
    if (node == nullptr)
        return;

    max = std::max(node->data, max);
    FindMax(node->left, max);
    FindMax(node->right, max);
}

template <typename T>
int BinaryTree<T>::CountLeafNode(BinaryTreeNode<T> *node)
{
    if (node == nullptr)
        return 0;
    if (node->left == nullptr && node->right == nullptr)
        return 1;

    return CountLeafNode(node->left) + CountLeafNode(node->right);
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

template <typename T>
int BinaryTree<T>::Height(BinaryTreeNode<T> *node)
{
    auto height = 0;
    if (node == nullptr)
        return 0;

    auto leftHeight = Height(node->left);
    auto rightHeight = Height(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}

template <typename T>
bool BinaryTree<T>::Symmetric(BinaryTreeNode<T> *left, BinaryTreeNode<T> *right)
{
    if (left == nullptr && right != nullptr)
        return false;
    else if (left != nullptr && right == nullptr)
        return false;
    else if (left == nullptr && right == nullptr)
        return true;
    else if (left->data != right->data)
        return false;

    return Symmetric(left->left, right->right) && Symmetric(left->right, right->left);
}

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::InPreHelper(std::vector<T> &inOrder, std::vector<T> &preOrder, int InS, int InE, int preS, int preE)
{
    if (InE < InS)
        return nullptr;

    auto rootData = preOrder[preS];
    auto rootNode = new BinaryTreeNode(rootData);
    if (root == nullptr)
        root = rootNode;

    int rootIndex = -1;
    for (int i = InS; i <= InE; i++)
    {
        if (inOrder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInStart = InS;
    int leftInEnd = rootIndex - 1;
    int leftPreStart = preS + 1;
    int leftPreEnd = leftPreStart + leftInEnd - leftInStart;

    int rightInStart = rootIndex + 1;
    int rightInEnd = InE;
    int rightPreStart = leftPreEnd + 1;
    int rightPreEnd = preE;

    rootNode->left = InPreHelper(inOrder, preOrder, leftInStart, leftInEnd, leftPreStart, leftPreEnd);
    rootNode->right = InPreHelper(inOrder, preOrder, rightInStart, rightInEnd, rightPreStart, rightPreEnd);

    return rootNode;
}

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::InPostHelper(std::vector<T> &inOrder, std::vector<T> &postOrder, int inS, int inE, int postS, int postE)
{
    if (inE < inS)
        return nullptr;

    auto rootData = postOrder[postE];
    auto rootNode = new BinaryTreeNode(rootData);
    if (root == nullptr)
        root = rootNode;

    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (inOrder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInStart = inS;
    int leftInEnd = rootIndex - 1;
    int leftPostStart = postS;
    int leftPostEnd = leftPostStart + leftInEnd - leftInStart;

    int rightInStart = rootIndex + 1;
    int rightInEnd = inE;
    int rightPostStart = leftPostEnd + 1;
    int rightPostEnd = postE - 1;

    rootNode->left = InPreHelper(inOrder, postOrder, leftInStart, leftInEnd, leftPostStart, leftPostEnd);
    rootNode->right = InPreHelper(inOrder, postOrder, rightInStart, rightInEnd, rightPostStart, rightPostEnd);

    return rootNode;
}

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::BuildTreeUsingInPre(std::vector<T> &inOrder, std::vector<T> &preOrder)
{
    int n = inOrder.size();
    return InPreHelper(inOrder, preOrder, 0, n - 1, 0, n - 1);
}

template <typename T>
BinaryTreeNode<T> *BinaryTree<T>::BuildTreeUsingInPost(std::vector<T> &inOrder, std::vector<T> &postOrder)
{
    int n = inOrder.size();
    return InPreHelper(inOrder, postOrder, 0, n - 1, 0, n - 1);
}

template <typename T>
int BinaryTree<T>::Diameter(BinaryTreeNode<T> *node)
{
    if (node == nullptr)
        return 0;

    int option1 = Height(node->left) + Height(node->right);
    int option2 = Diameter(node->left);
    int option3 = Diameter(node->right);

    return std::max(option1, std::max(option2, option3));
}

template <typename T>
std::pair<int, int> BinaryTree<T>::HeightDiameter(BinaryTreeNode<T> *node)
{
    if (node == nullptr)
    {
        return {(0, 0)};
    }

    auto lefthd = HeightDiameter(node->left);
    auto righthd = HeightDiameter(node->right);

    int rh = righthd.first;
    int lh = lefthd.first;
    int rd = righthd.second;
    int ld = lefthd.second;

    auto ht = 1 + std::max(rh, lh);
    auto dia = std::max(rh + lh, std::max(ld, rd));

    return {(ht, dia)};
}

template <typename T>
int BinaryTree<T>::DiameterBetter(BinaryTreeNode<T> *node)
{
    auto pair = HeightDiameter(node);
    return pair.second;
}

// int main(int argc, char const *argv[])
// {
//     auto tree = new BinaryTree<int>();
//     tree->Build();
//     tree->Travers();
//     auto count = tree->CountNodes();
// }
