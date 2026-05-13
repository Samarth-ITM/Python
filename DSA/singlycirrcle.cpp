#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

int main()
{
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);

    node1->next = node2;

    node2->next = node3;

    node3->next = node1;

    Node *temp = node2;

    cout << node1->data << " <-> ";
    while (temp != node1 and temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "None" << endl;
}