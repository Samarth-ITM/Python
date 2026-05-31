#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Product
{
    int id;
    string name;
    int quantity;
    float price;
    string category;
};

struct Node
{
    Product data;
    Node *next;
};

struct Inventory
{
    Node *head;
};

Inventory createInventory()
{
    Inventory inv;
    inv.head = NULL;
    return inv;
}

void deleteAllProducts(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}

void addProduct(Inventory &inv, Product p)
{
    Node *newNode = new Node();
    newNode->data = p;
    newNode->next = NULL;

    if (inv.head == NULL)
    {
        inv.head = newNode;
    }
    else
    {
        Node *current = inv.head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    cout << "\nProduct Added Successfully!\n\n";
}

void deleteProduct(Inventory &inv, int id)
{
    if (inv.head == NULL)
    {
        cout << "\nInventory is empty!\n\n";
        return;
    }

    if (inv.head->data.id == id)
    {
        Node *temp = inv.head;
        inv.head = inv.head->next;
        delete temp;
        cout << "\nProduct Deleted Successfully!\n\n";
        return;
    }

    Node *current = inv.head;
    while (current->next != NULL)
    {
        if (current->next->data.id == id)
        {
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "\nProduct Deleted Successfully!\n\n";
            return;
        }
        current = current->next;
    }

    cout << "\nProduct not found!\n\n";
}

void updateProduct(Inventory &inv, int id)
{
    Node *current = inv.head;
    while (current != NULL)
    {
        if (current->data.id == id)
        {
            int choice;
            cout << "\n--- Update Product ---\n";
            cout << "1. Update Name\n";
            cout << "2. Update Quantity\n";
            cout << "3. Update Price\n";
            cout << "4. Update Category\n";
            cout << "Enter choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1)
            {
                cout << "New Name: ";
                getline(cin, current->data.name);
            }
            else if (choice == 2)
            {
                cout << "New Quantity: ";
                cin >> current->data.quantity;
            }
            else if (choice == 3)
            {
                cout << "New Price: ";
                cin >> current->data.price;
            }
            else if (choice == 4)
            {
                cout << "New Category: ";
                cin.ignore();
                getline(cin, current->data.category);
            }
            else
            {
                cout << "Invalid choice!\n";
            }

            cout << "\nProduct Updated Successfully!\n\n";
            return;
        }
        current = current->next;
    }

    cout << "\nProduct not found!\n\n";
}

void displayProducts(Inventory &inv)
{
    if (inv.head == NULL)
    {
        cout << "\nNo products in inventory!\n\n";
        return;
    }

    cout << "\n--- Inventory ---\n\n";
    cout << setw(6) << "ID" << setw(15) << "Name" << setw(12) << "Quantity"
         << setw(10) << "Price" << setw(15) << "Category" << "\n";
    cout << string(58, '-') << "\n";

    Node *current = inv.head;
    while (current != NULL)
    {
        cout << setw(6) << current->data.id
             << setw(15) << current->data.name
             << setw(12) << current->data.quantity
             << setw(10) << fixed << setprecision(2) << current->data.price
             << setw(15) << current->data.category << "\n";
        current = current->next;
    }

    cout << "\n";
}

int countProducts(Inventory &inv)
{
    int count = 0;
    Node *current = inv.head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

Node *getHead(Inventory &inv)
{
    return inv.head;
}
