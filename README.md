
Bakery Management System!

This program is designed to efficiently manage and analyze bakery operations. Users can input customer orders, view order summaries, check remaining stock, and view order history.

Features

Add Order:

Users can input order details, including customer name, product name, quantity, and price. The program calculates the total cost, including tax, and applies a discount if eligible. Order details are stored in a history for future reference.

View Order Summary:

Users can view a summary of their current order, including customer name, product, quantity, price, tax amount, and total cost.
Check Remaining Stock:

Users can check the remaining stock of items after placing an order.

Order History:

The program maintains a history of all orders placed during the session, allowing users to review past orders and the total cost of all items purchased.
How to Build the Program
Step 1: Set up your development environment

Ensure you have a C++ compiler installed on your system. Options include GCC for Linux, MinGW for Windows, or Xcode Command Line Tools for macOS.

Step 2: Create a new C++ source file

Copy the provided C++ code into a new file with a .cpp extension, for example, bakery_management.cpp.

Step 3: Compile the program

Open a terminal or command prompt.
Navigate to the directory where you saved bakery_management.cpp.
Use the appropriate compiler command to compile the program. For example, with GCC on Linux, you can use the command: g++ bakery_management.cpp -o bakery_management.

Step 4: Run the program

After successful compilation, execute the program to interact with it. On Linux, you can run the program by typing ./bakery_management in the terminal.

How to Use

1. Choose an Option:

Upon running the program, you'll be presented with a menu displaying various options:

Add Product: Input product details to store them in a file named "bakery_storage.txt".
View Product Report: Enter the product ID to view the specific product report.
View All Product Reports: View reports for all products stored in the file.
Analyze Sales Data: Placeholder for future functionality.
Exit: Select this option to exit the program gracefully.

2. Follow Prompts:

After choosing an option, follow the on-screen prompts to input data, select a product ID, or navigate through the menu.

3. Manage Bakery Operations:

Utilize the program to manage and analyze bakery operations efficiently.
Dependencies
C++ standard libraries
Notes
Product data is stored in a file named "bakery_storage.txt".
This program is a basic implementation and may be expanded or enhanced for specific use cases.
