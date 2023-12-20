/* ------------------------------------------------------
Milestone 5
Module: Item
Filename: Item.cpp
Author: Tarandeep Kaur
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Item.h"
#include "Utils.h"
#include "Status.h"
using namespace std;
namespace sdds
{

    // Deallocates memory for the item description.
    void Item::setEmpty() {
        delete[] itemdescription;
        itemdescription = nullptr;
    }

    // Sets the values for an Item object.
    void Item::set(double price, int qty, int qtyNeeded, const char* description, bool linear, Status state, int sku) {
        itemprice = price;
        itemqty = qty;
        itemqtyNeeded = qtyNeeded;
        itemsku = sku;
        itemstate = state;
        itemlinear = linear;
        if (description != nullptr)
            ut.alocpy(itemdescription, description);
        else
            setEmpty();
    }

    // Checks if the item should be displayed in linear format.
    bool Item::linear() const {
        return itemlinear;
    }

    // Default constructor, initializes the Item object.
    Item::Item() {
        set();
    }

    // Copy constructor, copies values from another Item object.
    Item::Item(const Item& item) {
        set(item.itemprice, item.itemqty, item.itemqtyNeeded, item.itemdescription, item.itemlinear, item.itemstate, item.itemsku);
    }

    // Assignment operator, copies values from another Item object.
    Item& Item::operator=(const Item& item) {
        if (this != &item)
            set(item.itemprice, item.itemqty, item.itemqtyNeeded, item.itemdescription, item.itemlinear, item.itemstate, item.itemsku);
        return *this;
    }

    // Destructor, deallocates memory for the item description.
    Item::~Item() {
        setEmpty();
    }

    // Returns the quantity needed for the item.
    int Item::qtyNeeded() const {
        return itemqtyNeeded;
    }

    // Returns the quantity on hand for the item.
    int Item::qty() const {
        return itemqty;
    }

    // Conversion operator to double, returns the item price.
    Item::operator double() const {
        return itemprice;
    }

    // Conversion operator to bool, checks if the item is valid.
    Item::operator bool() const {
        return itemsku > 0 && itemstate;
    }

    // Decreases the quantity on hand by the specified amount.
    int Item::operator-=(int qty) {
        return itemqty -= qty;
    }

    // Increases the quantity on hand by the specified amount.
    int Item::operator+=(int qty) {
        return itemqty += qty;
    }

    // Sets the linear formatting flag for the item display.
    void Item::linear(bool isLinear) {
        itemlinear = isLinear;
    }

    // Clears the status of the item.
    Status Item::clear() {
        return itemstate = 0;
    }

    // Equality comparison with SKU.
    bool Item::operator==(int sku) const {
        return itemsku == sku;
    }

    // Equality comparison with description.
    bool Item::operator==(const char* description) const {
        return strstr(itemdescription, description) != nullptr;
    }

    // Saves the item to an output file stream.
    ofstream& Item::save(ofstream& ofstr) const {
        if (itemstate) {
            ofstr << itemsku << "\t" << itemdescription << "\t" << itemqty << "\t" << itemqtyNeeded << "\t";
            ofstr.setf(ios::fixed);
            ofstr.precision(2);
            ofstr << itemprice;
        }
        return ofstr;
    }

    // Loads the item from an input file stream.
    ifstream& Item::load(ifstream& ifstr) {
        string description;
        delete[] itemdescription;
        itemdescription = nullptr;

        ifstr >> itemsku;
        if (ifstr.peek() == '\t')
            ifstr.ignore();
        getline(ifstr, description, '\t');
        ut.alocpy(itemdescription, description.c_str());
        if (ifstr.peek() == '\t')
            ifstr.ignore();
        ifstr >> itemqty;
        if (ifstr.peek() == '\t')
            ifstr.ignore();
        ifstr >> itemqtyNeeded;
        if (ifstr.peek() == '\t')
            ifstr.ignore();
        ifstr >> itemprice;

        ifstr.ignore(1);

        if (ifstr.fail())
            itemstate = "Input file stream read failed!";

        return ifstr;
    }

    // Displays the item information.
    ostream& Item::display(ostream& ostr) const {
        char* tempDesc = nullptr;
        if (!itemstate)
            ostr << itemstate;
        else {
            if (linear()) {
                ostr.setf(ios::left);
                ostr.width(5);
                ostr << itemsku;
                ostr << " | ";
                if (strlen(itemdescription) > 35) {
                    ut.alocpy(tempDesc, itemdescription);
                    tempDesc[35] = '\0';
                    ostr << tempDesc;
                    delete[] tempDesc;
                    tempDesc = nullptr;
                }
                else {
                    ostr.width(35);
                    ostr << itemdescription;
                }

                ostr.setf(ios::right);
                ostr << " | ";
                ostr.width(4);
                ostr << itemqty;
                ostr << " | ";
                ostr.width(4);
                ostr << itemqtyNeeded;
                ostr << " | ";
                ostr.width(7);
                ostr.setf(ios::fixed);
                ostr.precision(2);
                ostr << itemprice;
                ostr << " |";
                cout.unsetf(ios::right);
            }
            else {
                ostr << "AMA Item:" << endl
                    << itemsku << ": " << itemdescription << endl
                    << "Quantity Needed: " << itemqtyNeeded << endl
                    << "Quantity Available: " << itemqty << endl;
                ostr.setf(ios::fixed);
                ostr.precision(2);
                ostr << "Unit Price: $" << itemprice << endl
                    << "Needed Purchase Fund: $" << itemprice * (itemqtyNeeded - itemqty) << endl;
            }
        }
        return ostr;
    }

    // Reads the SKU from the console.
    int Item::readSku(istream& istr) {
        return itemsku = ut.getint(40000, 99999, "SKU: ");
    }

    // Reads the item from the console.
    istream& Item::read(istream& istr) {
        string description;
        delete[] itemdescription;
        itemdescription = nullptr;
        itemstate = 0;

        cout << "AMA Item:" << endl
            << "SKU: " << itemsku << endl
            << "Description: ";
        getline(istr, description, '\n');
        ut.alocpy(itemdescription, description.c_str());
        itemqtyNeeded = ut.getint(1, 9999, "Quantity Needed: ");
        itemqty = ut.getint(0, itemqtyNeeded, "Quantity On Hand: ");
        itemprice = ut.getdouble(0.0, 9999.0, "Unit Price: $");

        if (istr.fail())
            itemstate = "Console entry failed!";

        return istr;
    }
}
