#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip> // Include for setw
#include <limits> // Include for numeric_limits
char G, r, ch;
using namespace std;

// Define a struct to hold order details
struct Order {
    string customerName;
    string productName;
    int quantity;
    double price;
    double taxAmount;
    double totalCost;
};

// Function to display total cost of all items purchased
void displayTotalCost(const vector<Order>& orderHistory) {
    double totalCostAllItems = 0.0;
    for (const Order& order : orderHistory) {
        totalCostAllItems += order.totalCost;
    }
    cout << "Total cost of all items purchased: Rs. " << totalCostAllItems << endl;
}

int main() {
    int quantity, choice;
    double price = 0, totalSum = 0.0f, taxRate = 0.05f, discountRate = 0.02f, Remaining_stock = 150;
    string productName, customerName;


    bool eligibleForDiscount = false;
    vector<Order> orderHistory; // Vector to store order history
    

    // Define a 2D array to store product information
    const int numProducts = 15;
    const string products[numProducts][3] = {
        {"Strawberry Cake", "1000", "10"},
        {"Cheesecake", "1500", "10"},
        {"Chocolate Cake", "800", "10"},
        {"Sheermal", "1200", "10"},
        {"Ras Malai", "1000", "10"},
        {"Samosa", "20", "10"},
        {"Pizza", "1800", "10"},
        {"Jalebi", "250", "10"},
        {"Barfi", "300", "10"},
        {"Gulab Jamun", "350", "10"},
        {"Rasgulla", "400", "10"},
        {"Rasmalai", "450", "10"},
        {"Cham Cham", "500", "10"},
        {"Gajar Halwa", "400", "10"},
        {"Kheer", "350", "10"}
    };

    do {
        // Get current time and date in Pakistan's local time
        time_t now = time(0);
        tm* localTime = localtime(&now);//pointer
        char* dateTime = asctime(localTime);

        // Display current time and date
        cout << "Current time and date in Pakistan: " << dateTime << endl;
        // Clear the input buffer before taking the customer name   
        cout << "We take some details from you!";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cin.ignore();
        cout << "Enter customer name: ";
        getline(cin, customerName);//Hasan Riaz

        // Check if the name contains only alphabetic characters and spaces
        bool validName = true;
        for (char c : customerName) {
            if (!isalpha(c) && c != ' ') {
                validName = false;
                break;
            }
        }
        if (!validName) {
            cout << "Invalid input. Please enter a valid name." << endl;
            continue; // Skip the rest of the loop and start over
        }

        cout << "Customer Name: " << customerName << endl;

        do {
            // Display menu
            cout << endl;
            cout << "\t\t\t\t\tBakery Management System" << endl;
            cout << "\t\t\t\t----------------------------------------" << endl;
            cout << endl;
            cout << left << setw(10) << "S/NO" << setw(25) << "ITEMS" << setw(15) << "PRICE" << setw(10) << "STOCK" << endl;

            // This loop is for numbering the product
            for (int i = 0; i < numProducts; ++i) {
                cout << setw(10) << i + 1 << setw(25) << products[i][0] << setw(15) << ("Rs. " + products[i][1]) << setw(10) << (products[i][2] + " items") << endl;
            }
            cout << endl;
            cout << setw(10) << 16 << "\t\t\t\t\tQuit" << endl;
            cout << "\t\t\t\t----------------------------------------" << endl;
            cout << endl;

            // Get user choice
            cout << "Enter your choice: ";
            cin >> choice;

            // Check if input is valid
            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid choice, please enter a number between 1 and 16." << endl;
                continue; // Skip the rest of the loop and start over
            }

            // Process user choice
            switch (choice) {
            case 1:
                productName = "Strawberry Cake";
                price = 1000.0f;
                break;
            case 2:
                productName = "Cheesecake";
                price = 1500.0f;
                break;
            case 3:
                productName = "Chocolate Cake";
                price = 800.0f;
                break;
            case 4:
                productName = "Sheermal";
                price = 1200.0f;
                break;
            case 5:
                productName = "Ras Malai";
                price = 1000.0f;
                break;
            case 6:
                productName = "Samosa";
                price = 20.0f;
                break;
            case 7:
                productName = "Pizza";
                price = 1800.0f;    //grab price
                break;
            case 8:
                productName = "Jalebi";
                price = 250.0f;
                break;
            case 9:
                productName = "Barfi";
                price = 300.0f;
                break;
            case 10:
                productName = "Gulab Jamun";
                price = 350.0f;
                break;
            case 11:
                productName = "Rasgulla";
                price = 400.0f;
                break;
            case 12:
                productName = "Rasmalai";
                price = 450.0f;
                break;
            case 13:
                productName = "Cham Cham";
                price = 500.0f;
                break;
            case 14:
                productName = "Gajar Halwa";
                price = 400.0f;
                break;
            case 15:
                productName = "Kheer";
                price = 350.0f;
                break;
            case 16:
                cout << "Thank you for using the Bakery Management System, " << customerName << "!" << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
                continue; // Continue to the next iteration of the loop
            }

            // Get quantity
            cout << "Enter the quantity: ";
            cin >> quantity;

            if (quantity > 10) {
                cout << "You entered more quantity than in stock." << endl;
                continue;
            }

            // Calculate remaining stock
            Remaining_stock -= quantity;

            // Calculate total cost without tax
            totalSum = price * quantity;

            // Calculate tax amount
            double taxAmount = totalSum * taxRate;

            // Calculate total cost including tax
            double totalCost = totalSum + taxAmount;

            // Apply discount if eligible
            if (totalCost > 50) {
                eligibleForDiscount = true;
                totalCost -= totalCost * discountRate;
            }

            // Add current order to history
            Order currentOrder;
            currentOrder.customerName = customerName;
            currentOrder.productName = productName;
            currentOrder.quantity = quantity;
            currentOrder.price = price;
            currentOrder.taxAmount = taxAmount;
            currentOrder.totalCost = totalCost;

            orderHistory.push_back(currentOrder);

            // Display order summary
            cout << endl;
            cout << "\t\t\t\t\t\tOrder Summary" << endl;
            cout << "\t\t\t\t----------------------------------------" << endl;
            cout << endl;
            cout << "Customer Name: " << customerName << endl;
            cout << "Product: " << productName << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "Price: Rs. " << price << endl;
            cout << "Tax (5%): Rs. " << taxAmount << endl;
            cout << "Total Cost (including tax): Rs. " << totalCost << endl;
            cout << endl;

            // Ask if user wants to add more items
            cout << "Do you want to add more items? (T/F): ";
            cin >> G;

            if (G == 'T' || G == 't' || G == 'F' || G == 'f') {
                continue;
            }
            else {
                cout << "Invalid input." << endl;
                break;
            }
        } while (G == 'T' || G == 't');

        // For items
        cout << "Do you want to place another order ? (T/F): ";
        cin >> r;
        if (r == 'T' || r == 't' || r == 'F' || r == 'f') {
            // Clear the input buffer before taking a new order//cin.ignore(numeric
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else {
            cout << "Invalid input." << endl;
            break;
        }
    } while (r == 'T' || r == 't');

    // Check remaining_stock
    cout << "Check the remaining stock of item you purchased press R: ";
    cin >> ch;
    if (ch == 'R' || ch == 'r') {
        cout << "Remaining_stock: " << Remaining_stock << endl;
    }
    else {
        cout << "Invalid input." << endl;
    }
    cout << endl;
    cout << "Thank you for coming to our bakery, " << customerName << "! Enjoy your food!" << endl;
    cout << endl;

    // Show order history
    cout << "\t\t\t\t\t\tOrder History:" << endl;
    cout << "\t\t\t\t-----------------------------------" << endl;
    for (int i = 0; i < orderHistory.size(); ++i) {
        cout << "Order:\t\t\t\t\t\t\t\t " << i + 1 << endl;
        cout << "Customer Name:\t\t\t\t\t\t\t " << orderHistory[i].customerName << endl;
        cout << "Product:\t\t\t\t\t\t\t " << orderHistory[i].productName << endl;
        cout << "Quantity:\t\t\t\t\t\t\t " << orderHistory[i].quantity << endl;
        cout << "Price: Rs.\t\t\t\t\t\t\t " << orderHistory[i].price << endl;
        cout << "Tax (5%): Rs.\t\t\t\t\t\t\t " << orderHistory[i].taxAmount << endl;
        cout << "Total Cost (including tax): Rs.\t\t\t\t\t " << orderHistory[i].totalCost << endl;
        cout << endl;
    }

    // Display total cost of all items purchased
    displayTotalCost(orderHistory);

    return 0;
}/* is project ko chalana ka lia time ka lia apna path ko secure karna */