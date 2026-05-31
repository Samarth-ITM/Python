#include "Timer.h"
#include <iostream>
#include <string>
#include <iomanip>

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

int countProducts(Inventory &inv);
Node *getHead(Inventory &inv);

void linearSearch(Inventory &inv)
{
    if (countProducts(inv) == 0)
    {
        cout << "\nInventory is empty!\n\n";
        return;
    }

    cin.ignore();
    cout << "\nEnter Product Name to Search: ";
    string searchName;
    getline(cin, searchName);

    auto start = chrono::high_resolution_clock::now();

    Node *current = getHead(inv);
    bool found = false;

    while (current != NULL)
    {
        if (current->data.name == searchName)
        {
            auto end = chrono::high_resolution_clock::now();
            long long elapsed = getElapsedMicroseconds(start, end);

            cout << "\n--- Product Found ---\n\n";
            cout << "ID: " << current->data.id << "\n";
            cout << "Name: " << current->data.name << "\n";
            cout << "Quantity: " << current->data.quantity << "\n";
            cout << "Price: " << fixed << setprecision(2) << current->data.price << "\n";
            cout << "Category: " << current->data.category << "\n";

            cout << "\nLinear Search Time: " << elapsed << " microseconds\n";
            cout << "Complexity: O(n)\n\n";

            found = true;
            return;
        }
        current = current->next;
    }

    if (!found)
    {
        auto end = chrono::high_resolution_clock::now();
        long long elapsed = getElapsedMicroseconds(start, end);

        cout << "\nProduct Not Found!\n";
        cout << "Linear Search Time: " << elapsed << " microseconds\n";
        cout << "Complexity: O(n)\n\n";
    }
}
