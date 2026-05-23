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

    void Display()
    {
        cout << "Data: " << data << endl;

        if (next != NULL)
        {
            next->Display();
        }
    }
};

int main()
{
    Node *node1 = new Node(5);
    Node *node2 = new Node(10);
    Node *node3 = new Node(15);
    Node *node4 = new Node(20);
    Node *node5 = new Node(25);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    cout << "Displaying all nodes:" << endl;
    node1->Display();

    // delete first node
    node1 = node1->next;

    cout << "After deleting first node:" << endl;
    node1->Display();

    // delete last node
    delete node5;
    node5 = NULL;

    cout << "After deleting last node:" << endl;
    node1->Display();

    // delete middle node
    Node *temp = node1;
    while (temp->data != 20)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;
    delete temp->next;
    temp->next = temp;

    cout << "After deleting middle node:" << endl;
    node1->Display();

    // Insert node in between
    Node *newNode = new Node(1000);
    newNode->next = node4;
    node3->next = newNode;

    cout << "After inserting new node:" << endl;
    node1->Display();
}
