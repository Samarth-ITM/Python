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

void binarySearch(Inventory &inv, string searchName)
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

    // Sort by product name for binary search
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (array[j].name > array[j + 1].name)
            {
                Product temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    auto start = chrono::high_resolution_clock::now();

    int left = 0;
    int right = count - 1;
    bool found = false;
    int foundIndex = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid].name == searchName)
        {
            found = true;
            foundIndex = mid;
            break;
        }
        else if (array[mid].name < searchName)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    long long elapsed = getElapsedMicroseconds(start, end);

    if (found)
    {
        cout << "\n--- Binary Search Results ---\n";
        cout << "Product Found!\n";
        cout << "ID: " << array[foundIndex].id << "\n";
        cout << "Name: " << array[foundIndex].name << "\n";
        cout << "Quantity: " << array[foundIndex].quantity << "\n";
        cout << "Price: " << fixed << setprecision(2) << array[foundIndex].price << "\n";
        cout << "Time: " << elapsed << " microseconds | Complexity: O(log n)\n\n";
    }
    else
    {
        cout << "\n--- Binary Search Results ---\n";
        cout << "Product Not Found!\n";
        cout << "Time: " << elapsed << " microseconds | Complexity: O(log n)\n\n";
    }

    delete[] array;
}
