/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
/*
Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Section: ZEE
Date: 14 October 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

// Disable CRT security warnings
#define _CRT_SECURE_NO_WARNINGS

// Include the header file for the Portfolio class
#include "Portfolio.h"

// Include necessary C++ libraries
#include <iostream>
#include <cstring>

// Use the standard namespace for simplicity
using namespace std;

namespace sdds {

    // Default constructor for Portfolio class
    Portfolio::Portfolio() {
        // Initialize the portfolio to an empty state
        emptyPortfolio();
    }

    // Function to clear the portfolio data
    void Portfolio::emptyPortfolio() {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E'; // 'E' represents an empty state
    }

    // Parameterized constructor for Portfolio class
    Portfolio::Portfolio(double value, const char* stock, char type) {
        // Start with an empty portfolio
        emptyPortfolio();
        // Check if the provided data is valid and update the portfolio
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strncpy(m_stock, stock, 15); // Copy at most 15 characters from stock
            m_stock[15] = '\0'; // Ensure the string is null-terminated
        }
    }

    // Function to display the portfolio information
    void Portfolio::dispPortfolio() const {
        // Display portfolio data with proper formatting
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this); // Calls the const char* conversion operator
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this); // Calls the double conversion operator
        cout << " | ";
        cout << " Type: ";
        cout << char(*this); // Calls the char conversion operator
    }

    // Function to display the portfolio status and data
    std::ostream& Portfolio::display() const {
        if (~*this) {
            cout << " Portfolio  |  Bad-NG |"; // Bad-NG represents a negative value
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |"; // Active represents a valid portfolio
            dispPortfolio();
        }
        else {
            cout << " Portfolio  |  EMPTY  |"; // EMPTY represents an empty portfolio
            dispPortfolio();
        }
        return cout;
    }

    // Conversion operator: Convert the Portfolio to a double (value)
    Portfolio::operator double() const {
        return m_value;
    }

    // Conversion operator: Convert the Portfolio to a C-style string (stock)
    Portfolio::operator const char* () const {
        return m_stock;
    }

    // Conversion operator: Convert the Portfolio to a char (type)
    Portfolio::operator char() const {
        return m_type;
    }

    // Conversion operator: Convert the Portfolio to a bool (true if type is 'V', 'G', or 'I')
    Portfolio::operator bool() const {
        return (m_type == 'V' || m_type == 'G' || m_type == 'I');
    }

    // Unary operator ~ overload: True if the value is negative
    bool Portfolio::operator~() const {
        return m_value < 0;
    }

    // Compound addition operator (+=) overload: Add a value to the portfolio if it's valid
    Portfolio& Portfolio::operator+=(double value) {
        if (*this && value >= 0) {
            m_value += value;
        }
        return *this;
    }

    // Compound subtraction operator (-=) overload: Subtract a value from the portfolio if it's valid
    Portfolio& Portfolio::operator-=(double value) {
        if (*this && value >= 0) {
            m_value -= value;
        }
        return *this;
    }

    // Shift-in operator (<<) overload: Add the value of another Portfolio to this one
    Portfolio& Portfolio::operator<<(Portfolio& other) {
        if (this != &other && *this && other) {
            m_value += other.m_value;
            other.emptyPortfolio();
        }
        return *this;
    }

    // Shift-out operator (>>) overload: Transfer the value of this Portfolio to another one
    Portfolio& Portfolio::operator>>(Portfolio& other) {
        if (this != &other && *this && other) {
            other.m_value += m_value;
            emptyPortfolio();
        }
        return *this;
    }

    // Binary addition operator (+) overload: Add the values of two Portfolios
    double operator+(const Portfolio& left, const Portfolio& right) {
        if (left && right) {
            return left.m_value + right.m_value;
        }
        return 0.0;
    }

    // Compound addition operator (+=) overload for a double and a Portfolio
    double& operator+=(double& left, const Portfolio& right) {
        if (right && right.m_value >= 0.0) {
            left += right.m_value;
        }
        return left;
    }

}
