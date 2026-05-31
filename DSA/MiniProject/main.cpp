#include <iostream>
#include <string>
#include <iomanip>
#include "Timer.h"

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

Inventory createInventory();
void deleteAllProducts(Node *head);
void addProduct(Inventory &inv, Product p);
void deleteProduct(Inventory &inv, int id);
void updateProduct(Inventory &inv, int id);
void displayProducts(Inventory &inv);
int countProducts(Inventory &inv);
Node *getHead(Inventory &inv);
void linearSearch(Inventory &inv);
void binarySearch(Inventory &inv);
void bubbleSort(Inventory &inv);
void mergeSortInventory(Inventory &inv);

void displayMainMenu()
{
    cout << "\n========== Grocery Inventory System ==========\n";
    cout << "1. Add Product\n";
    cout << "2. View All Products\n";
    cout << "3. Delete Product\n";
    cout << "4. Update Product\n";
    cout << "5. Search Product\n";
    cout << "6. Sort Products\n";
    cout << "7. Exit\n";
    cout << "============================================\n";
    cout << "Enter your choice: ";
}

void displaySearchMenu()
{
    cout << "\n--- Search Options ---\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "Enter choice: ";
}

void displaySortMenu()
{
    cout << "\n--- Sort Options ---\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Merge Sort\n";
    cout << "Enter choice: ";
}

int main()
{
    Inventory inv = createInventory();
    int choice;
    bool running = true;

    while (running)
    {
        displayMainMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            Product newProduct;
            cout << "\n--- Add New Product ---\n";
            cout << "Enter Product ID: ";
            cin >> newProduct.id;
            cin.ignore();

            cout << "Enter Product Name: ";
            getline(cin, newProduct.name);

            cout << "Enter Quantity: ";
            cin >> newProduct.quantity;

            cout << "Enter Price: ";
            cin >> newProduct.price;
            cin.ignore();

            cout << "Enter Category: ";
            getline(cin, newProduct.category);

            addProduct(inv, newProduct);
        }
        else if (choice == 2)
        {
            displayProducts(inv);
        }
        else if (choice == 3)
        {
            cout << "\nEnter Product ID to Delete: ";
            int deleteId;
            cin >> deleteId;
            deleteProduct(inv, deleteId);
        }
        else if (choice == 4)
        {
            cout << "\nEnter Product ID to Update: ";
            int updateId;
            cin >> updateId;
            updateProduct(inv, updateId);
        }
        else if (choice == 5)
        {
            displaySearchMenu();
            int searchChoice;
            cin >> searchChoice;

            if (searchChoice == 1)
            {
                linearSearch(inv);
            }
            else if (searchChoice == 2)
            {
                binarySearch(inv);
            }
            else
            {
                cout << "\nInvalid choice!\n\n";
            }
        }
        else if (choice == 6)
        {
            displaySortMenu();
            int sortChoice;
            cin >> sortChoice;

            if (sortChoice == 1)
            {
                bubbleSort(inv);
            }
            else if (sortChoice == 2)
            {
                mergeSortInventory(inv);
            }
            else
            {
                cout << "\nInvalid choice!\n\n";
            }
        }
        else if (choice == 7)
        {
            cout << "\nExiting Grocery Inventory System. Goodbye!\n\n";
            deleteAllProducts(inv.head);
            running = false;
        }
        else
        {
            cout << "\nInvalid choice! Please try again.\n\n";
        }
    }

    return 0;
}
