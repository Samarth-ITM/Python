#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int value)
{

    // If tree empty
    if (root == NULL)
    {
        return new Node(value);
    }

    // Go to left subtree
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }

    // Go to right subtree
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

void inorder(Node *root)
{

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    Node *root = NULL;
    // 99 59 70 49 9 5 1 10
    root = insert(root, 99);
    root = insert(root, 59);
    root = insert(root, 70);
    root = insert(root, 49);
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 10);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}
