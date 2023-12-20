#pragma once
/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

/*                  
NAME: TARANDEEP KAUR
STUDENT ID: 139389225
EMAIL: tarandeep-kaur6@myseneca.ca
Date: 13 Oct 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H

#include <iostream>

namespace sdds {

    class Flight {
        int m_passengers = 0;       // Number of passengers on the flight
        double m_fuel = 0;          // Fuel level of the flight
        char m_title[16];           // Title of the flight (up to 15 characters)

        void emptyPlane();          // Private member function to empty the plane

    public:
        // Constructors
        Flight();                  // Default constructor
        Flight(int passengers, double fuel, const char* title); // Parameterized constructor

        // Display function to print flight information
        std::ostream& display() const;

        // Conversion operators
        operator bool() const;      // Convert to boolean
        operator int() const;       // Convert to integer (number of passengers)
        operator double() const;    // Convert to double (fuel level)
        operator const char* () const; // Convert to C-string (title)
        bool operator~() const;     // Logical NOT operator, returns true if the flight is not empty

        // Assignment operators
        Flight& operator=(Flight& other); // Assignment from another Flight object
        Flight& operator=(int passengers); // Assignment from an integer (set number of passengers)
        Flight& operator=(double fuel);   // Assignment from a double (set fuel level)

        // Arithmetic operators
        Flight& operator+=(double fuel);               // Add fuel to the flight
        Flight& operator+=(int passengers);            // Add passengers to the flight
        Flight& operator-=(double fuel);               // Subtract fuel from the flight
        Flight& operator-=(int passengers);            // Remove passengers from the flight

        // Stream operators for input and output
        Flight& operator<<(Flight& other);   // Output operator to display flight information
        Flight& operator>>(Flight& other);   // Input operator to set flight information

        int operator+(const Flight& other) const;
    };

    // Friend function to add passengers to an integer and return the new total
    int operator+=(int& left, const Flight& right);

}
#endif // SDDS_FLIGHT_H
