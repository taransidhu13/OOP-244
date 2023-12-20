#pragma once

/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
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

#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>

namespace sdds {

    // Declaration of the Portfolio class
    class Portfolio {
        double m_value;        // The value of the portfolio
        char m_stock[16];       // A character array to store the stock
        char m_type;           // A character to represent the type

        // Private function to clear the portfolio
        void emptyPortfolio();

    public:
        // Default constructor
        Portfolio();

        // Constructor with parameters
        Portfolio(double value, const char* stock, char type);

        // Function to display the portfolio
        void dispPortfolio() const;

        // Display function using the ostream
        std::ostream& display() const;

        // Conversion operators

        // Convert the portfolio to a double
        operator double() const;

        // Convert the portfolio to a C-style string (const char*)
        operator const char* () const;

        // Convert the portfolio to a char
        operator char() const;

        // Convert the portfolio to a bool
        operator bool() const;

        // Unary operator ~ overload
        bool operator~() const;

        // += operator overloads

        // Add a double value to the portfolio
        Portfolio& operator+=(double value);

        // Subtract a double value from the portfolio
        Portfolio& operator-=(double value);

        // << and >> operator overloads

        // Shift-in operator overload to input data into the portfolio
        Portfolio& operator<<(Portfolio& other);

        // Shift-out operator overload to extract data from the portfolio
        Portfolio& operator>>(Portfolio& other);

        // Binary helper operator overloads

        // Addition operator overload to add two portfolios
        friend double operator+(const Portfolio& left, const Portfolio& right);

        // Compound addition operator overload to add a portfolio to a double
        friend double& operator+=(double& left, const Portfolio& right);
    };

}  // namespace sdds

#endif // SDDS_Portfolio_H_
