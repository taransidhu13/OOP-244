/* 
Workshop 7 part 1 
Module: Container
Filename: Container.cpp
Author: Tarandeep Kaur
Revision History
-----------------------------------------------------------
Date          Reason
9 November 2023 - Workshop 7 Implementation
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Container.h"
using namespace std;

namespace sdds {
    // Set the container to an empty/invalid state
    void Container::setEmpty()
    {
        Valid_Container = false;
    }

    // Return the capacity of the container
    int Container::capacity()
    {
        return Capacity;
    }

    // Return the current volume of the container
    int Container::volume()
    {
        return Volume;
    }

    // Constructor: initializes a container with the given description, capacity, and optional content volume
    Container::Container(const char* Content, int Capacity, int Content_volume)
    {
        if (Content == NULL || Content_volume > Capacity)
        {
            // If content is NULL or content volume exceeds capacity, set the container to an invalid state
            Valid_Container = false;
        }
        else
        {
            // Initialize the container with the provided values
            strcpy(this->Desc, Content);
            this->Capacity = Capacity;
            this->Volume = Content_volume;
            Valid_Container = true;
        }
    }

    // Overload += operator to add the specified value to the container's volume
    int Container::operator += (int value)
    {
        if (Volume + value <= Capacity)
        {
            // If adding the value does not exceed capacity, add it to the volume
            Volume += value;
        }
        else
        {
            // If adding the value exceeds capacity, add only up to the capacity
            value = Capacity - Volume;
            Volume = Capacity;
        }

        return value;
    }

    // Overload -= operator to subtract the specified value from the container's volume
    int Container::operator -= (int value)
    {
        if (Volume - value >= 0)
        {
            // If subtracting the value does not result in a negative volume, subtract it
            Volume -= value;
        }
        else
        {
            // If subtracting the value results in a negative volume, subtract only up to 0
            value = Volume;
            Volume = 0;
        }

        return value;
    }

    // Check if the container is in a valid state
    bool Container::valid()
    {
        return Valid_Container;
    }

    // Clear the container and set it to a new state with the provided capacity and description
    void Container::clear(int Capacity, const char* m_desc)
    {
        if (Capacity >= 1 && m_desc != NULL && strlen(m_desc) >= 1)
        {
            // If the provided capacity and description are valid, set the container to a new state
            this->Capacity = Capacity;
            strcpy(this->Desc, m_desc);
            this->Volume = 0;
            Valid_Container = true;
        }
    }

    // Print the container information to the given output stream
    ostream& Container::print(ostream& ostr)
    {
        if (Valid_Container)
        {
            // If the container is valid, print its information
            ostr << Desc << ": (" << Volume << "cc/" << Capacity << ")";
        }
        else
        {
            // If the container is invalid, print a default message
            ostr << "****: (**cc/***)";
        }

        return ostr;
    }

    // Read container information from the given input stream
    istream& Container::read(istream& istr)
    {
        int number;

        if (!Valid_Container)
        {
            // If the container is invalid, print an error message and wait for user input
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            istr.ignore();
            istr.get();
        }
        else
        {
            bool validValue = false;
            cout << "Add to ";
            print(cout);

            while (!validValue)
            {
                // Prompt the user for input until a valid value is entered
                cout << endl << "> ";
                istr >> number;

                if (number > Capacity)
                {
                    // If the entered number exceeds capacity, prompt for a valid input
                    cout << "Invalid Integer, retry:";
                }

                else if (number < 1 || number > 999)
                {
                    // If the entered number is out of range, prompt for a valid input
                    cout << "Value out of range [1<=val<=999]:";
                }

                else validValue = true;
            }
            // Add the valid number to the container and print a message
            number = (*this += number);
            cout << "Added " << number << " CCs" << endl;
        }
        return istr;
    }
} // End of the sdds namespace
