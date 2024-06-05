/*
Name: Kemari Solomon
Section: 11
Assignment: Programming Assignment 3 
Purpose: To ensure students understand how to create and maintain a dynamically allocated array of objects
*/

#include "grocery.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& o, const GroceryItem& g) 
{
    o << "Name: "<<g.name << "  Description: " << g.description << "  Price: $" << g.price << "  Quantity: "<<g.quantity;
    return o;
}
//defualt constructor
GroceryItem :: GroceryItem()
{
    name = "";
    description = "";
    price = 0;
    quantity = 0;
}
//four parameritized constrcutor
// Assigns the  parameter to the  member variable of the GroceryItem class.
GroceryItem :: GroceryItem(string name, string description, double price, int quantity )
{
    this -> name = name;
    this -> description = description;
    this -> price = price;
    this -> quantity = quantity;
}
//getters
string GroceryItem :: getName() const
{
    return name;
}

string GroceryItem :: getDescription() const 
{
    return description;
}

double GroceryItem :: getPrice() const
{
    return price;
}

int GroceryItem :: getQuantity() const
{
    return quantity;
}

void GroceryItem :: setQuantity(int newQ)
{
    quantity = newQ;
}
//default cart constructor
Cart::Cart()
{
    capacity = 10;
    size = 0;
    items = new GroceryItem[capacity];

}

Cart :: Cart(const Cart& c)
{
    //Copies the size member variable from the Cart object c to the current Cart object being constructed.
    size = c.size;
    //Copies the capacity member variable from the Cart object c to the current Cart object being constructed.
    capacity = c.capacity;
    //Allocates dynamic memory for the items array in the current Cart object
    items = new GroceryItem[capacity];
    for(int i = 0; i < size; i++)
    {
        //Copies each GroceryItem object from the items array of the Cart object c to  array of the current Cart object
        items[i] = c.items[i];
    }
}
//destructor..deallaocates the items object
Cart :: ~Cart()
{
    delete [] items;
}
//copy assignment operator for the Cart class
Cart& Cart :: operator=(const Cart& c)
{
    size =c.size;
    capacity = c.capacity;

    delete [] items;
    items  = new GroceryItem[capacity];
    for(int i = 0; i < size; i++)
    {
        items[i] = c.items[i];
    }
    return *this;
}
//dynamiccaly allocates and resizes an array to accomodate capacity
void Cart :: Create(const GroceryItem& i)
{
    if(size >= capacity)
    {
        GroceryItem* tmp = new GroceryItem[capacity+1];
        for(int i = 0; i < size; i++)
        {
            tmp[i]= items[i];
        }
        
        delete [] items;
        items = tmp;
        capacity = capacity +1;
    }
    items[size++] = i;
}

void Cart:: Update(int index, int newQuantity)
{
    if(index >=0 && index < size)
    {
        items[index].setQuantity(newQuantity);

    }
    else{
        cout <<"Invalid";
    }
}

void Cart :: Delete (int index)
{
    if (index < 0 || index >= size) {
        cout << "Invalid index please try again." << endl;
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        items[i] = items[i + 1];
    }

    --size;
}

ostream& operator<<(ostream& o, const Cart& c) 
{
    double total = 0.0;
    o << "Receipt:" << endl;
    for (int i = 0; i < c.size; ++i) {
        o<<c.items[i]<<endl;
        total += c.items[i].getPrice() * c.items[i].getQuantity();
    }
    o << "Total: $" << total << endl;
    return o;
}
