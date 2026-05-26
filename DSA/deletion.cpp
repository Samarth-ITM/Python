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

Node *findMin(Node *root)
{

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node *deleteNode(Node *root, int key)
{

    if (root == NULL)
        return NULL;

    // Search node
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    // Node found
    else
    {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: One child (right)
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: One child (left)
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else
        {

            Node *temp = findMin(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
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

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Before Deletion: ";
    inorder(root);

    root = deleteNode(root, 50);

    cout << "\nAfter Deletion: ";
    inorder(root);

    return 0;
}
