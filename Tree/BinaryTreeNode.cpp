template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data);
    ~BinaryTreeNode();
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T data)
{
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
    delete left;
    delete right;
}