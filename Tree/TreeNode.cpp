#include <iostream>
#include <vector>

template <typename T>
class TreeNode
{
private:
    T data;
    TreeNode<T> *parent;
    std::vector<TreeNode<T> *> children;

public:
    TreeNode(T v);
    ~TreeNode();
    void AddChild(TreeNode<T> *child);
    std::vector<TreeNode<T> *> GetChildren();
    T GetData();
};

template <typename T>
TreeNode<T>::TreeNode(T data)
{
    this->data = data;
}

template <typename T>
TreeNode<T>::~TreeNode()
{
    for (auto child : children)
    {
        delete child;
    }
}

template <typename T>
void TreeNode<T>::AddChild(TreeNode<T> *child)
{
    this->children.push_back(child);
    child->parent = this;
}

template <typename T>
std::vector<TreeNode<T> *> TreeNode<T>::GetChildren()
{
    return this->children;
}

template <typename T>
T TreeNode<T>::GetData()
{
    return this->data;
}
