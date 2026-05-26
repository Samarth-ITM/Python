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

    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else
        root->right = insert(root->right, value);

    return root;
}

bool search(Node *root, int key)
{

    // Value not found
    if (root == NULL)
        return false;

    // Value found
    if (root->data == key)
        return true;

    // Search left
    if (key < root->data)
        return search(root->left, key);

    // Search right
    return search(root->right, key);
}

int main()
{

    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    int key = 40;

    if (search(root, key))
        cout << "Element Found";

    else
        cout << "Element Not Found";

    return 0;
}
