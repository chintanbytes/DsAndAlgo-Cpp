#include "TreeNode.cpp"
#include <queue>

template <typename T>
class Tree
{
private:
    TreeNode<T> *root;
    TreeNode<T> *BuildRecursive();
    void PrintRecursive(TreeNode<T> *node);
    void BuildByLevel();
    void PrintByLevel();
    int Height(TreeNode<T> *root);
    int NodeCount(TreeNode<T> *root);
    void PreOrder(TreeNode<T> *node);
    void PostOrder(TreeNode<T> *node);

public:
    Tree();
    ~Tree();
    void Build();
    void Print();
    int GetHeight();
    int GetNodeCount();
    void PrintLevelK(TreeNode<T> *node, int k);
    int CountLeafNodes(TreeNode<T> *node);
    void Traverse();
};

template <typename T>
Tree<T>::Tree()
{
    root = nullptr;
}

template <typename T>
Tree<T>::~Tree()
{
    delete root;
}

template <typename T>
TreeNode<T> *Tree<T>::BuildRecursive()
{
    std::cout << "Enter data: ";
    T data;
    std::cin >> data;

    auto node = new TreeNode<T>(data);

    std::cout << "Enter number of children: ";
    int count;
    std::cin >> count;

    for (int i = 0; i < count; i++)
    {
        node->AddChild(BuildRecursive());
    }

    return node;
}

template <typename T>
void Tree<T>::PrintRecursive(TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    std::cout << node->GetData() << " : ";
    for (auto child : node->GetChildren())
    {
        std::cout << child->GetData() << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < node->GetChildren().size(); i++)
        PrintRecursive(node->GetChildren()[i]);
}

template <typename T>
void Tree<T>::BuildByLevel()
{
    std::cout << "Enter data: ";
    T data;
    std::cin >> data;

    root = new TreeNode<T>(data);

    std::queue<TreeNode<T> *> nodeTracker;
    nodeTracker.push(root);

    while (!nodeTracker.empty())
    {
        TreeNode<T> *first = nodeTracker.front();
        std::cout << "Enter number of children for "
                  << first->GetData()
                  << ": ";
        int count;
        std::cin >> count;

        for (int j = 0; j < count; j++)
        {
            std::cout << "Enter data for child "
                      << j + 1
                      << ": ";
            std::cin >> data;

            auto child = new TreeNode<T>(data);
            nodeTracker.push(child);
            first->AddChild(child);
        }

        nodeTracker.pop();
    }
}

template <typename T>
void Tree<T>::PrintByLevel()
{
    if (root == nullptr)
        return;

    std::queue<TreeNode<T> *> nodeTracker;
    nodeTracker.push(root);

    while (!nodeTracker.empty())
    {
        auto first = nodeTracker.front();
        nodeTracker.pop();

        std::cout << first->GetData() << " : ";
        for (auto child : first->GetChildren())
        {
            std::cout << child->GetData() << " ";
            nodeTracker.push(child);
        }
        std::cout << std::endl;
    }
}

template <typename T>
int Tree<T>::Height(TreeNode<T> *node)
{
    auto max = 0;

    for (auto child : node->GetChildren())
    {
        int childHeight = Height(child);
        if (childHeight > max)
            max = childHeight;
    }

    return max + 1;
}

template <typename T>
int Tree<T>::NodeCount(TreeNode<T> *node)
{
    auto count = 0;
    if (node == nullptr)
        return count;

    for (int i = 0; i < node->GetChildren().size(); i++)
        count += NodeCount(node->GetChildren()[i]);

    return count + 1;
}

template <typename T>
void Tree<T>::PreOrder(TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    std::cout << node->GetData() << " ";

    for (auto child : node->GetChildren())
    {
        PreOrder(child);
    }
}

template <typename T>
void Tree<T>::PostOrder(TreeNode<T> *node)
{
    if (node == nullptr)
        return;

    for (auto child : node->GetChildren())
    {
        PostOrder(child);
    }

    std::cout << node->GetData() << " ";
}

template <typename T>
void Tree<T>::PrintLevelK(TreeNode<T> *node, int k)
{
    if (node == nullptr)
        return;

    if (k == 0)
        std::cout << node->GetData() << " ";

    for (auto child : node->GetChildren())
    {
        PrintLevelAtK(child, k - 1);
    }
}

template <typename T>
int Tree<T>::CountLeafNodes(TreeNode<T> *node)
{
    if (node == nullptr)
        return 0;

    if (node->GetChildren().size() == 0)
        return 1;

    auto count = 0;
    for (auto child : node->GetChildren())
    {
        count += CountLeafNodes(child);
    }
    return count;
}

template <typename T>
void Tree<T>::Traverse()
{
    int choice;
    std::cout << "Enter 1 for PreOrder or 2 for Post Order: ";
    std::cin >> choice;

    if (choice == 1)
        PreOrder();
    else if (choice == 2)
        PostOrder();
    else
    {
        std::cout << "Not a valid entry. Try again" << std::endl;
        Traverse();
    }
}

template <typename T>
void Tree<T>::Build()
{
    char choice;
    std::cout << "Enter R for Recursice Build or L for By Level: ";
    std::cin >> choice;

    if (choice == 'R')
        root = BuildRecursive();
    else if (choice == 'L')
        BuildByLevel();
    else
    {
        std::cout << "Not a valid entry. Try again" << std::endl;
        Build();
    }
}

template <typename T>
void Tree<T>::Print()
{
    char choice;
    std::cout << "Enter R for Recursice Print or L for By Level: ";
    std::cin >> choice;

    if (choice == 'R')
        PrintRecursive(root);
    else if (choice == 'L')
        PrintByLevel();
    else
    {
        std::cout << "Not a valid entry. Try again" << std::endl;
        Print();
    }
}

template <typename T>
int Tree<T>::GetHeight()
{
    return Height(root);
}

template <typename T>
int Tree<T>::GetNodeCount()
{
    return NodeCount(root);
}

// int main(int argc, char const *argv[])
// {
//     Tree<int> *tree = new Tree<int>;
//     tree->Build();
//     tree->Print();
//     std::cout << "Tree height is: "
//               << tree->GetHeight()
//               << std::endl;
//     std::cout << "Node count is: "
//               << tree->GetNodeCount()
//               << std::endl;
//     /* code */
//     return 0;
// }