#pragma once
/* 
Workshop 7 part 1 
Module: Pack
Filename: Pack.h
Author: Tarandeep Kaur
Revision History
-----------------------------------------------------------
Date          Reason
9 November 2023 - Workshop 7 Implementation
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef PACK_H
#define PACK_H

#include "Container.h" // Include the base class header
using namespace sdds;

namespace sdds {
    // Pack class inherits from Container class
    class Pack : public Container {
        int Unit_Size;         // Size of each unit in the pack
        int Size;              // Total size of the pack
        int Number_Of_Units;   // Number of units in the pack

    public:
        // Constructor: initializes a pack with the given description, size, unit size, and optional number of units
        Pack(const char* Content, int Size, int unitSize = 330, int NumberOfUnits = 0);

        // Overload += operator to add the specified number of units to the pack
        int operator += (int units);

        // Overload -= operator to remove the specified number of units from the pack
        int operator -= (int units);

        // Return the size of each unit in the pack
        int unit();

        // Return the total number of units in the pack
        int noOfUnits();

        // Return the total size of the pack
        int size();

        // Clear the pack and set it to a new state with the provided size, unit size, and description
        void clear(int packSize, int unitSize, const char* content);

        // Print the pack information to the given output stream
        std::ostream& print(std::ostream& out);

        // Read pack information from the given input stream
        std::istream& read(std::istream& in);

        // Friend function to overload the << operator for output stream, using the print member function
        friend std::ostream& operator << (std::ostream& out, Pack& P) {
            return P.print(out);
        }

        // Friend function to overload the >> operator for input stream, using the read member function
        friend std::istream& operator >> (std::istream& in, Pack& P) {
            return P.read(in);
        }

    };
}

#endif // PACK_H
