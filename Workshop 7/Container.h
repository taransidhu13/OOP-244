#pragma once
/* 
Workshop 7 
Module: Container
Filename: Container.h
Author: Tarandeep Kaur
Revision History
-----------------------------------------------------------
Date          Reason
9 November 2023 - Workshop 7 Implementation
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <cstring>

namespace sdds {
    // Container class represents a container with a description, capacity, volume, and validity flag
    class Container {
        char Desc[50];        // Description of the container
        int Capacity;         // Capacity of the container
        int Volume;           // Current volume in the container
        bool Valid_Container; // Flag indicating whether the container is valid

    protected:
        // Set the container to an empty/invalid state
        void setEmpty();

        // Return the capacity of the container
        int capacity();

        // Return the current volume of the container
        int volume();

    public:
        // Constructor: initializes a container with the given description, capacity, and optional content volume
        Container(const char* Content, int Capacity, int Content_volume = 0);

        // Overload += operator to add the specified value to the container's volume
        int operator += (int value);

        // Overload -= operator to subtract the specified value from the container's volume
        int operator -= (int value);

        // Check if the container is in a valid state
        bool valid();

        // Clear the container and set it to a new state with the provided capacity and description
        void clear(int Capacity, const char* Content);

        // Print the container information to the given output stream
        std::ostream& print(std::ostream& out);

        // Read container information from the given input stream
        std::istream& read(std::istream& in);

        // Friend function to overload the << operator for output stream, using the print member function
        friend std::ostream& operator << (std::ostream& out, Container& C) {
            return C.print(out);
        }

        // Friend function to overload the >> operator for input stream, using the read member function
        friend std::istream& operator >> (std::istream& in, Container& C) {
            return C.read(in);
        }
    };
}

#endif // CONTAINER_H
