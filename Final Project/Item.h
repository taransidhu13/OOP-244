#pragma once
/* ------------------------------------------------------
Milestone 5
Module: Item
Filename: Item.h
Author: Tarandeep Kaur
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include <iostream>
#include <fstream>

#include "iProduct.h"
#include "Status.h"
using namespace std;
namespace sdds {

    class Item : public iProduct{
        double itemprice;
        int itemqty;
        int itemqtyNeeded;
        char* itemdescription = nullptr;
        bool itemlinear;       
        void set(double price = 0, int qty = 0, int qtyNeeded = 0, const char* description = nullptr, bool linear = false, Status state = 0, int sku = 0);
        void setEmpty();

    protected:
        Status itemstate; 
        int itemsku;
        bool linear() const;

    public:
        Item();
        Item(const Item& item);
        Item& operator=(const Item& item);
        ~Item();
        int qtyNeeded() const;
        int qty() const;
        operator double() const;
        operator bool() const;
        int operator-=(int qty);
        int operator+=(int qty);
        void linear(bool isLinear);
        Status clear();
        bool operator==(int sku) const;
        bool operator==(const char* description) const;
        ofstream& save(ofstream& ofstr) const;
        ifstream& load(ifstream& ifstr);
        ostream& display(ostream& ostr) const;
        int readSku(istream& istr);
        istream& read(istream& istr);
    };
}

#endif // !SDDS_ITEM_H
