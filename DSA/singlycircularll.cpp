#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);

    node1->prev = node3;
    node1->next = node2;

    node2->next = node3;
    node2->prev = node2;

    node3->prev = node2;
    node3->next = node1;

    Node *temp = node2;
    Node *f = node1;
    cout << f->data << " <-> ";

    while (temp != f and temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
}