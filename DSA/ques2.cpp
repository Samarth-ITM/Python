#include <iostream>
#include <string>
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
    int n;
    cout << "Enter the number of letters in your name: ";
    cin >> n;

    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < n; i++)
    {
        char letter;
        cout << "Enter letter " << i + 1 << ": ";
        cin >> letter;

        Node *newNode = new Node(letter);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            current->next = newNode;
        }
        current = newNode;
    }

    current = head;
    while (current != NULL)
    {
        cout << static_cast<char>(current->data) << "";
        current = current->next;
    }
    cout << endl;

    return 0;
}
