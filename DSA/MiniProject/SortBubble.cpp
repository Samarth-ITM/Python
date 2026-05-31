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

void bubbleSort(Inventory &inventory);

void bubbleSort(Inventory &inventory)
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

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (array[j].price > array[j + 1].price)
            {
                Product temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    long long elapsed = getElapsedMicroseconds(start, end);

    cout << "\n--- Sorted by Price (Bubble Sort) ---\n\n";
    cout << setw(15) << "Name" << setw(10) << "Price\n";
    cout << string(25, '-') << "\n";

    for (int i = 0; i < count; i++)
    {
        cout << setw(15) << array[i].name
             << setw(10) << fixed << setprecision(2) << array[i].price << "\n";
    }

    cout << "\nBubble Sort Time: " << elapsed << " microseconds\n";
    cout << "Complexity: O(n^2)\n\n";

    delete[] array;
}
