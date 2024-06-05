/*
Name: Kemari Solomon
Section: 11
Assignment: Programming Assignment 3
Purpose: To ensure students understand how to create and maintain a dynamically allocated array of objects
*/

#include <iostream>
#include <string>
using namespace std;

class GroceryItem
{
    friend ostream& operator<<(ostream& o, const GroceryItem& g);

    public:
    //defualt constructor
    GroceryItem(); 
    //four paramter constructor    
    GroceryItem(string name, string description, double price, int quantity);
    //getters
    string getName() const;
    string getDescription() const;
    double getPrice() const;
    int getQuantity() const;
    //setter
    void setQuantity(int quantity);

    private:
    string name;
    string description;
    double price;
    int quantity;
};


class Cart
{
    friend ostream& operator<<(ostream& o, const Cart& c);
    private:
        GroceryItem *items;
        int size;
        int capacity;
    public:
        Cart();
        Cart(const Cart& c);
        //Deconstructor
        ~Cart();
        //Deep copy assignment
        Cart& operator=(const Cart& c);

        void Create(const GroceryItem& i);
        void Update(int index, int newQuantity);
        void Delete(int index);
        

};



