/*
Name: Kemari Solomon
Section: 11
Assignment: Programming Assignment 3
Purpose: To ensure students understand how to create and maintain a dynamically allocated array of objects
*/
#include "grocery.h"
#include <iostream>
using namespace std;

int main()
{
    Cart myCart;
    char choice = '\0';
    int selectedOption = -1;
    cout << "Shopping Cart" << endl;

    do {
        cout << "A: Add Item" << endl;
        cout << "V: View Cart" << endl;
        cout << "U: Update Quantity" << endl;
        cout << "R: Remove Item" << endl;
        cout << "P: Print Receipt and Quit" << endl;
        cout << "Q: Quit" << endl;

        cin >> choice;

        switch(choice) {
            case 'A':
            case 'a': {
                string name, description;
                double price;
                int quantity;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Description: ";
                getline(cin, description);
                cout << "Price: ";
                cin >> price;
                cout << "Quantity: ";
                cin >> quantity;
                myCart.Create(GroceryItem(name, description, price, quantity));
                break;
            }
            case 'V':
            case 'v':
                cout << myCart << endl;
                break;
            case 'U':
            case 'u': {
                cout << myCart << endl;
                cout << myCart << endl;
                cout << "Enter the item index of the item you would like to update: ";
                cin >> selectedOption;
                int newQuantity;
                cout << "New quantity: ";
                cin >> newQuantity;
                myCart.Update(selectedOption - 1, newQuantity);

                break;
            }
            case 'R':
            case 'r': {
                cout << myCart << endl;
                cout << "Enter item index of the item you would like to remove: ";
                cin >> selectedOption;
                myCart.Delete(selectedOption - 1); 
                break;
            }
            case 'P':
            case 'p':
                cout << "Receipt Printing" << endl;
                cout << myCart << endl;
                cout << "Exiting..." << endl;
                ;
                return 0; 
            case 'Q':
            case 'q':
                break; 
            default:
                cout << "Please enter a valid choice." << endl;
        }
    } while (choice != 'Q' && choice != 'q');




    return 0;
}