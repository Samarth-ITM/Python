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

void mergeSortInventory(Inventory &inventory);

void merge(Product *array, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    Product *leftArray = new Product[leftSize];
    Product *rightArray = new Product[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        leftArray[i] = array[left + i];
    }

    for (int i = 0; i < rightSize; i++)
    {
        rightArray[i] = array[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i].price <= rightArray[j].price)
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSortHelper(Product *array, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortHelper(array, left, mid);
        mergeSortHelper(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void mergeSortInventory(Inventory &inventory)
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

    mergeSortHelper(array, 0, count - 1);

    auto end = chrono::high_resolution_clock::now();
    long long elapsed = getElapsedMicroseconds(start, end);

    cout << "\n--- Sorted by Price (Merge Sort) ---\n\n";
    cout << setw(15) << "Name" << setw(10) << "Price\n";
    cout << string(25, '-') << "\n";

    for (int i = 0; i < count; i++)
    {
        cout << setw(15) << array[i].name
             << setw(10) << fixed << setprecision(2) << array[i].price << "\n";
    }

    cout << "\nMerge Sort Time: " << elapsed << " microseconds\n";
    cout << "Complexity: O(n log n)\n\n";

    delete[] array;
}
