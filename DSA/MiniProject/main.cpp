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
void linearSearch(Inventory &inv, string searchName);
void binarySearch(Inventory &inv, string searchName);
void bubbleSort(Inventory &inv, int sortBy);
void mergeSortInventory(Inventory &inv, int sortBy);
void saveToCSV(Inventory &inv);
void loadFromCSV(Inventory &inv);

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
    cout << "\n--- Searching by Product Name (Both Linear & Binary) ---\n";
}

void displaySortMenu()
{
    cout << "\n--- Sort By ---\n";
    cout << "1. Price\n";
    cout << "2. Quantity\n";
    cout << "(Both Bubble & Merge sort will run)\n";
    cout << "Choose: ";
}

int main()
{
    Inventory inv = createInventory();
    loadFromCSV(inv);
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

            cout << "Enter Product Name: ";
            getline(cin, newProduct.name);

            cout << "Enter Quantity: ";
            cin >> newProduct.quantity;
            cin.ignore();

            cout << "Enter Price: ";
            cin >> newProduct.price;
            cin.ignore();

            addProduct(inv, newProduct);
            saveToCSV(inv);
            cout << "\nHere are all the products:\n\n";
            displayProducts(inv);
        }
        else if (choice == 2)
        {
            displayProducts(inv);
        }
        else if (choice == 3)
        {
            cout << "\nHere are all the products:\n\n";
            displayProducts(inv);
            cout << "\nEnter Product ID to Delete: ";
            int deleteId;
            cin >> deleteId;
            deleteProduct(inv, deleteId);
            saveToCSV(inv);
            cout << "\nUpdated product list:\n\n";
            displayProducts(inv);
        }
        else if (choice == 4)
        {
            cout << "\nHere are all the products:\n\n";
            displayProducts(inv);
            cout << "\nEnter Product ID to Update: ";
            int updateId;
            cin >> updateId;
            updateProduct(inv, updateId);
            saveToCSV(inv);
            cout << "\nUpdated product list:\n\n";
            displayProducts(inv);
        }
        else if (choice == 5)
        {
            displaySearchMenu();
            cout << "Enter Product Name to Search: ";
            string searchName;
            getline(cin, searchName);

            linearSearch(inv, searchName);
            binarySearch(inv, searchName);
        }
        else if (choice == 6)
        {
            displaySortMenu();
            int sortBy;
            cin >> sortBy;
            cin.ignore();

            if (sortBy == 1 || sortBy == 2)
            {
                cout << "\n=== Running Both Sorts ===\n";
                bubbleSort(inv, sortBy);
                mergeSortInventory(inv, sortBy);
            }
            else
            {
                cout << "\nInvalid choice!\n\n";
            }
        }
        else if (choice == 7)
        {
            saveToCSV(inv);
            cout << "Exiting Grocery Inventory System. Goodbye!\n\n";
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
