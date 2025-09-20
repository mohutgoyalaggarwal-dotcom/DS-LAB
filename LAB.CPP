#include <iostream>
#include <string>
using namespace std;

class InventoryItem {
public:
    int itemID;
    string itemName;
    int quantity;
    float price;

    InventoryItem() {
        itemID = -1;
        itemName = "";
        quantity = 0;
        price = 0.0;
    }

    InventoryItem(int id, string name, int qty, float pr) {
        itemID = id;
        itemName = name;
        quantity = qty;
        price = pr;
    }
};

class InventorySystem {
private:
    InventoryItem* items;
    int capacity;
    int size;

public:
    InventorySystem(int cap = 100) {
        capacity = cap;
        size = 0;
        items = new InventoryItem[capacity];
    }

    // Insert Item (O(1))
    void insertItem(int id, string name, int qty, float pr) {
        if (size >= capacity) {
            cout << "Inventory Full! Cannot insert more items.\n";
            return;
        }
        items[size++] = InventoryItem(id, name, qty, pr);
        cout << "Item '" << name << "' inserted successfully.\n";
    }

    // Delete Item by ID (O(n))
    void deleteItem(int id) {
        for (int i = 0; i < size; i++) {
            if (items[i].itemID == id) {
                cout << "Item '" << items[i].itemName << "' deleted.\n";
                for (int j = i; j < size - 1; j++) {
                    items[j] = items[j + 1];
                }
                size--;
                return;
            }
        }
        cout << "Item not found.\n";
    }

    // Search Item by ID or Name (O(n))
    void searchItem(string key) {
        for (int i = 0; i < size; i++) {
            if (to_string(items[i].itemID) == key || items[i].itemName == key) {
                cout << "Found: ID=" << items[i].itemID
                     << ", Name=" << items[i].itemName
                     << ", Qty=" << items[i].quantity
                     << ", Price=" << items[i].price << endl;
                return;
            }
        }
        cout << "Item not found.\n";
    }

    // Manage Price and Quantity in Row-Major Order (O(n))
    void managePriceQuantity() {
        cout << "Price-Quantity Table (Row-Major):\n";
        for (int i = 0; i < size; i++) {
            cout << "[" << items[i].price << ", " << items[i].quantity << "] ";
        }
        cout << endl;
    }

    // Sparse Representation (for qty < 5) (O(n))
    void optimizeSparseStorage() {
        cout << "Sparse Storage (Rarely Restocked Items):\n";
        for (int i = 0; i < size; i++) {
            if (items[i].quantity < 5) {
                cout << "[ID=" << items[i].itemID 
                     << ", Name=" << items[i].itemName 
                     << ", Qty=" << items[i].quantity << "]\n";
            }
        }
    }

    ~InventorySystem() {
        delete[] items;
    }
};

int main() {
    InventorySystem inv(10);

    inv.insertItem(101, "Rice", 20, 45.5);
    inv.insertItem(102, "Sugar", 2, 38.0);
    inv.insertItem(103, "Wheat", 0, 50.0);

    inv.searchItem("102");      // Search by ID
    inv.searchItem("Sugar");    // Search by Name

    inv.managePriceQuantity();
    inv.optimizeSparseStorage();

    inv.deleteItem(101);
    inv.searchItem("101");

    return 0;
}
