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

void linearSearch(Inventory &inv, string searchName)
{
    if (countProducts(inv) == 0)
    {
        cout << "\nInventory is empty!\n\n";
        return;
    }

    auto start = chrono::high_resolution_clock::now();

    Node *current = getHead(inv);
    bool found = false;

    while (current != NULL)
    {
        if (current->data.name == searchName)
        {
            auto end = chrono::high_resolution_clock::now();
            long long elapsed = getElapsedMicroseconds(start, end);

            cout << "\n--- Linear Search Results ---\n";
            cout << "Product Found!\n";
            cout << "ID: " << current->data.id << "\n";
            cout << "Name: " << current->data.name << "\n";
            cout << "Quantity: " << current->data.quantity << "\n";
            cout << "Price: " << fixed << setprecision(2) << current->data.price << "\n";
            cout << "Time: " << elapsed << " microseconds | Complexity: O(n)\n\n";

            found = true;
            return;
        }
        current = current->next;
    }

    auto end = chrono::high_resolution_clock::now();
    long long elapsed = getElapsedMicroseconds(start, end);

    if (!found)
    {
        cout << "\n--- Linear Search Results ---\n";
        cout << "Product Not Found!\n";
        cout << "Time: " << elapsed << " microseconds | Complexity: O(n)\n\n";
    }
}
