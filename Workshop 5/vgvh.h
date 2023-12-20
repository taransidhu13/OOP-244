#pragma once
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

namespace sdds {

    class Portfolio {
        double m_value;
        char m_stock[16];
        char m_type;

        void emptyPortfolio();

    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;

        // Display function
        std::ostream& display() const;

        // Conversion operators
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;
        bool operator~() const;

        // += operator overloads
        Portfolio& operator+=(double value);
        Portfolio& operator-=(double value);

        // << and >> operator overloads
        Portfolio& operator<<(Portfolio& other);
        Portfolio& operator>>(Portfolio& other);

        // Binary helper operator overloads
        double operator+(const Portfolio& left, const Portfolio& right);
        friend double& operator+=(double& left, const Portfolio& right);

    };

}  // namespace sdds
#endif // SDDS_Portfolio_H_

