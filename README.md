Grocery Store Inventory System 🖥
DSA Animation

Overview
This project implements an Inventory System for a Grocery Store using C++ with array-based data structures. It supports basic inventory operations like insertion, deletion, searching by ID or name, efficient storage using sparse representation for rarely restocked products, and organizes price and quantity data in both row-major and column-major order.

Features
Inventory Item ADT with attributes ItemID, ItemName, Quantity, and Price.
Insertion, deletion, and search operations.
Use of single-dimensional array (ItemArray) for item storage.
Management of price and quantity data using both row-major and column-major ordering.
Sparse matrix optimization for rarely restocked products to save space.
Console output for feedback and data display.
Straightforward and efficient handling following DSA principles.
Project Structure
InventoryItem struct defining the item data.
InventorySystem class:
Core methods: insertItem(), deleteItem(), searchItem(), addItemRecord(), removeItemRecord(), searchByItem().
Presentation methods for row-major and column-major data organization.
optimizeSparseStorage() for sparse matrix representation.
main() function contains sample test cases demonstrating functionality.
How to Run
Clone the repository.
Compile the C++ file using a C++ compiler:
Run the executable:
Sample Output
Complexity Analysis
Function	Time Complexity	Space Complexity
insertItem	O(1) average, O(n) worst-case	O(1)
deleteItem	O(n)	O(1)
searchItem	O(n)	O(1)
Row-major and Column-major displays	O(n)	O(n)
Sparse Storage Output	O(n)	O(k) where k = rarely restocked count
Technologies Used
C++ (Standard Template Library not used to focus on array implementations)
Command Line Interface for interaction
Author
Mohit goyal
BTech CSE AI/ML – Roll Number: 2401730209

Array GIF
