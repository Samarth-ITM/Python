#include "Timer.h"
#include <iostream>
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

void bubbleSort(Inventory &inv, int sortBy)
{
    int count = countProducts(inv);

    if (count == 0)
    {
        cout << "\nInventory is empty!\n\n";
        return;
    }

    Product *array = new Product[count];

    Node *current = getHead(inv);
    int index = 0;
    while (current != NULL)
    {
        array[index] = current->data;
        index++;
        current = current->next;
    }

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            bool swap = false;
            if (sortBy == 1)
            {
                swap = array[j].price > array[j + 1].price;
            }
            else if (sortBy == 2)
            {
                swap = array[j].quantity > array[j + 1].quantity;
            }

            if (swap)
            {
                Product temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    long long elapsed = getElapsedMicroseconds(start, end);

    string sortType = (sortBy == 1) ? "Price" : "Quantity";
    cout << "\n--- Sorted by " << sortType << " (Bubble Sort) ---\n\n";
    cout << setw(15) << "Name" << setw(12) << sortType << "\n";
    cout << string(27, '-') << "\n";

    for (int i = 0; i < count; i++)
    {
        if (sortBy == 1)
        {
            cout << setw(15) << array[i].name
                 << setw(12) << fixed << setprecision(2) << array[i].price << "\n";
        }
        else
        {
            cout << setw(15) << array[i].name
                 << setw(12) << array[i].quantity << "\n";
        }
    }

    cout << "\nBubble Sort Time: " << elapsed << " microseconds\n";
    cout << "Complexity: O(n^2)\n\n";

    delete[] array;
}
