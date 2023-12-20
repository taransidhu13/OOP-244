#pragma once
/* ------------------------------------------------------
Milestone 5
Module: iProduct
Filename: iProduct.h
Author: Tarandeep Kaur
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_I_PRODUCT_H
#define SDDS_I_PRODUCT_H

#include <iostream>
#include <fstream>

using namespace std;
namespace sdds{
    class iProduct{
    public:       
        virtual ~iProduct() = 0;       
        virtual int readSku(istream& istr) = 0;        
        virtual int operator-=(int qty) = 0;        
        virtual int operator+=(int qty) = 0;        
        virtual operator double() const = 0;        
        virtual operator bool() const = 0;       
        virtual int qtyNeeded() const = 0;       
        virtual int qty() const = 0;       
        virtual void linear(bool isLinear) = 0;        
        virtual ofstream& save(ofstream& ofstr) const = 0;        
        virtual ifstream& load(ifstream& ifstr) = 0;        
        virtual ostream& display(ostream& ostr) const = 0;
        virtual istream& read(istream& istr) = 0;
        virtual bool operator==(int sku) const = 0;        
        virtual bool operator==(const char* description) const = 0;
    };

    istream& operator>>(istream& istr, iProduct& prod);
    ostream& operator<<(ostream& ostr, const iProduct& prod);
}

#endif // !SDDS_I_PRODUCT_H