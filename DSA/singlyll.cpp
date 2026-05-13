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

    // delete at end:
    node2->next = NULL;

    // Insert at end
    node2->next = node3;

    // Inser at new
    Node *node0 = new Node(40);
    node3->next = node0;

    Node *temp = node1;

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "None" << endl;
}