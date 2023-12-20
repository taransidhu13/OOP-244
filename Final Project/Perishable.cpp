/* ------------------------------------------------------
Milestone 5
Module: Perishable
Filename: Perishable.cpp
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
#include "Perishable.h"
#include "Utils.h"

using namespace std;

namespace sdds{

    // Deletes dynamically allocated memory for product handling.
    void Perishable::setEmpty() {
        delete[] m_prodhandling;
        m_prodhandling = nullptr;
    }

    // Sets the attributes for Perishable product.
    void Perishable::set(Date expirydt, const char* prodhandling) {
        m_expirydt = expirydt;
        if (m_prodhandling != nullptr)
            ut.alocpy(m_prodhandling, prodhandling);
        else
            setEmpty();
    }

    // Constructor for Perishable product, initializes with Item constructor.
    Perishable::Perishable() : Item() {
        set();
    }

    // Copy constructor for Perishable product, copies values from another Perishable object.
    Perishable::Perishable(const Perishable& perishable) : Item(perishable) {
        set(perishable.m_expirydt, perishable.m_prodhandling);
    }

    // Assignment operator for Perishable product, copies values from another Perishable object.
    Perishable& Perishable::operator=(const Perishable& perishable) {
        if (this != &perishable) {
            (Item&)*this = perishable;
            set(perishable.m_expirydt, perishable.m_prodhandling);
        }
        return *this;
    }

    // Destructor for Perishable product, deallocates dynamically allocated memory.
    Perishable::~Perishable() {
        setEmpty();
    }

    // Returns the expiry date of the Perishable product.
    const Date& Perishable::expiry() const {
        return m_expirydt;
    }

    // Reads SKU for Perishable product from input stream.
    int Perishable::readSku(istream& istr) {
        return itemsku = ut.getint(10000, 39999, "SKU: ");
    }

    // Saves Perishable product information to output stream.
    ofstream& Perishable::save(ofstream& ofstr) const {
        if (itemstate) {
            Item::save(ofstr);
            ofstr << "\t";
            if (m_prodhandling != nullptr && m_prodhandling[0] != '\0')
                ofstr << m_prodhandling;
            ofstr << "\t";
            Date tempDate = m_expirydt;
            tempDate.formatted(false);
            tempDate.write(ofstr);
        }
        return ofstr;
    }

    // Loads Perishable product information from input stream.
    ifstream& Perishable::load(ifstream& ifstr) {
        string handling;
        Item::load(ifstr);
        delete[] m_prodhandling;
        m_prodhandling = nullptr;

        if (ifstr.peek() != '\t') {
            getline(ifstr, handling, '\t');
            ut.alocpy(m_prodhandling, handling.c_str());
        }
        if (ifstr.peek() == '\t')
            ifstr.ignore();
        ifstr >> m_expirydt;
        if (ifstr.peek() == '\n')
            ifstr.ignore();

        if (ifstr.fail())
            itemstate = "Input file stream read (perishable) failed!";

        return ifstr;
    }

    // Displays Perishable product information to output stream.
    ostream& Perishable::display(ostream& ostr) const {
        if (!itemstate)
            ostr << itemstate;
        else {
            if (linear()) {
                Item::display(ostr);

                if (m_prodhandling != nullptr && m_prodhandling[0] != '\0')
                    ostr << "*";
                else
                    ostr << " ";
                ostr << m_expirydt;
            }
            else {
                ostr << "Perishable ";
                Item::display(ostr);
                ostr << "Expiry date: ";
                ostr << m_expirydt;
                ostr << endl;
                if (m_prodhandling != nullptr && m_prodhandling[0] != '\0')
                    ostr << "Handling Instructions: " << m_prodhandling << endl;
            }
        }
        return ostr;
    }

    // Reads Perishable product information from input stream.
    istream& Perishable::read(istream& istr) {
        Item::read(istr);
        string handling;
        delete[] m_prodhandling;
        m_prodhandling = nullptr;

        cout << "Expiry date (YYMMDD): ";
        istr >> m_expirydt;
        cout << "Handling Instructions, ENTER to skip: ";
        istr.ignore(1000, '\n');
        if (istr.peek() != '\n') {
            getline(istr, handling, '\n');
            ut.alocpy(m_prodhandling, handling.c_str());
        }
        if (istr.fail())
            itemstate = "Perishable console date entry failed!";
        return istr;
    }

}