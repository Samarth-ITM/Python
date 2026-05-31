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
    string category;
};

class Node
{
public:
    Product data;
    Node *next;
};

class Inventory
{
private:
    Node *head;

public:
    Inventory();
    ~Inventory();

    void addProduct(Product p);
    void deleteProduct(int id);
    void updateProduct(int id);
    void displayProducts();
    int countProducts();
    Node *getHead();
};

void binarySearch(Inventory &inventory);

void binarySearch(Inventory &inventory)
{
    int count = inventory.countProducts();

    if (count == 0)
    {
        cout << "\nInventory is empty!\n\n";
        return;
    }

    Product *array = new Product[count];

    Node *current = inventory.getHead();
    int index = 0;
    while (current != NULL)
    {
        array[index] = current->data;
        index++;
        current = current->next;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (array[j].id > array[j + 1].id)
            {
                Product temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    cout << "\nEnter Product ID to Search: ";
    int searchId;
    cin >> searchId;

    auto start = chrono::high_resolution_clock::now();

    int left = 0;
    int right = count - 1;
    bool found = false;
    int foundIndex = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid].id == searchId)
        {
            found = true;
            foundIndex = mid;
            break;
        }
        else if (array[mid].id < searchId)
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
        cout << "\n--- Product Found ---\n\n";
        cout << "ID: " << array[foundIndex].id << "\n";
        cout << "Name: " << array[foundIndex].name << "\n";
        cout << "Quantity: " << array[foundIndex].quantity << "\n";
        cout << "Price: " << fixed << setprecision(2) << array[foundIndex].price << "\n";
        cout << "Category: " << array[foundIndex].category << "\n";
    }
    else
    {
        cout << "\nProduct Not Found!\n";
    }

    cout << "\nBinary Search Time: " << elapsed << " microseconds\n";
    cout << "Complexity: O(log n)\n\n";

    delete[] array;
}
