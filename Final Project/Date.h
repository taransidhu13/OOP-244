#pragma once
/* Citation and Sources...
Final Project Milestone 5
Module: Date
Filename: Date.h
Author	Tarandeep Kaur
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
using namespace std;
namespace sdds{

    // Maximum year allowed
    const int c_maxYear = 2030;

    // Class representing a date with year, month, and day components
    class Date {
        int m_year;
        int m_month;
        int m_day;
        Status m_state;
        bool m_formatted = true;

        // Private member functions
        bool validate(); // Validates the date components
        int uniqueDateValue() const; // Calculates a unique value for the date
        void set(int year, int month, int day); // Sets the date components

    public:
        // Constructors
        Date(int year = 0, int month = 0, int day = 0);

        // Comparison operators
        bool operator==(const Date& date) const;
        bool operator!=(const Date& date) const;
        bool operator<(const Date& date) const;
        bool operator>(const Date& date) const;
        bool operator<=(const Date& date) const;
        bool operator>=(const Date& date) const;

        // Accessor functions
        const Status& state() const; // Returns the current state of the date
        Date& formatted(bool flag); // Sets the formatting flag for date output
        operator bool() const; // Conversion to bool, checks if the date is valid

        // Input/output functions
        ostream& write(ostream& ostr) const; // Writes the date to an output stream
        istream& read(istream& istr); // Reads the date from an input stream
    };

    // Overloaded stream insertion operator for Date class
    ostream& operator<<(ostream& ostr, const Date& date);

    // Overloaded stream extraction operator for Date class
    istream& operator>>(istream& istr, Date& date);
}

#endif // !SDDS_DATE_H