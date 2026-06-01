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

void merge(Product *array, int left, int mid, int right, int sortBy)
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
        bool leftSmaller = false;
        if (sortBy == 1)
        {
            leftSmaller = leftArray[i].price <= rightArray[j].price;
        }
        else if (sortBy == 2)
        {
            leftSmaller = leftArray[i].quantity <= rightArray[j].quantity;
        }

        if (leftSmaller)
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

void mergeSortHelper(Product *array, int left, int right, int sortBy)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortHelper(array, left, mid, sortBy);
        mergeSortHelper(array, mid + 1, right, sortBy);
        merge(array, left, mid, right, sortBy);
    }
}

void mergeSortInventory(Inventory &inv, int sortBy)
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

    mergeSortHelper(array, 0, count - 1, sortBy);

    auto end = chrono::high_resolution_clock::now();
    long long elapsed = getElapsedMicroseconds(start, end);

    string sortType = (sortBy == 1) ? "Price" : "Quantity";
    cout << "\n--- Sorted by " << sortType << " (Merge Sort) ---\n\n";
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

    cout << "\nMerge Sort Time: " << elapsed << " microseconds\n";
    cout << "Complexity: O(n log n)\n\n";

    delete[] array;
}
