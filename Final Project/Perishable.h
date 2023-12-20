#pragma once
/* ------------------------------------------------------
Milestone 5
Module: Perishable
Filename: Perishable.h
Author: Tarandeep Kaur
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include <fstream>
#include "Perishable.h"
#include "Item.h"
#include "Date.h"
using namespace std;
namespace sdds
{
    class Perishable : public Item
    {       
        char* m_prodhandling = nullptr;
        Date m_expirydt;
        void setEmpty();
        void set(Date expirydt = 0, const char* prodhandling = nullptr);

    public:
        Perishable();
        Perishable(const Perishable& perishable);
        Perishable& operator=(const Perishable& perishable);
        ~Perishable();
        const Date& expiry() const;
        int readSku(istream& istr);
        ofstream& save(ofstream& ofstr) const;
        ifstream& load(ifstream& ifstr);
        ostream& display(ostream& ostr) const;
        istream& read(istream& istr);
    };
}

#endif // !SDDS_PERISHABLE_H