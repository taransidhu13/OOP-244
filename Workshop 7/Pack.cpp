/* 
Workshop 7 
Module: Pack
Filename: Pack.cpp
Author: Tarandeep Kaur
Revision History
-----------------------------------------------------------
Date          Reason
9 November 2023 - Workshop 7 Implementation
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Pack.h"
using namespace std;

namespace sdds {
    Pack::Pack(const char* Content, int Size, int unitSize, int NumberOfUnits)
        :Container(Content, Size* unitSize, unitSize* NumberOfUnits) 
    {
        this->Size = Size;
        this->Unit_Size = unitSize;
        this->Number_Of_Units = NumberOfUnits;
    }

    int Pack::operator += (int units) 
    {
        int result = Container::operator+=(units * Unit_Size) / Unit_Size;
        this->Number_Of_Units += result;
        return result;
    }

    int Pack::operator -= (int units) 
    {
        int result = Container::operator-=(units * Unit_Size) / Unit_Size;
        this->Number_Of_Units -= result;
        return result;
    }


    // returns the unit size attribute
    int Pack::unit() 
    {
        return Unit_Size;
    }


    // returns the content volume of the Base class divided by the unit size
    int Pack::noOfUnits() 
    {
        return Number_Of_Units;
    }


    // return the capacity of the base class divided by the unit size
    int Pack::size() 
    {
        return Size;
    }



    void Pack::clear(int packSize, int unitSize, const char* content) 
    {
        if (unitSize > 0) 
        {
            int packunit = packSize * unitSize;
            Size = packSize;

            Container::clear(packunit, content);
            this->Unit_Size = unitSize;
            this->Number_Of_Units = 0;
        }
    }


    ostream& Pack::print(ostream& out) 
    {
        Container::print(out);
        if (valid()) {
            out << ", " << Number_Of_Units << " in a pack of " << Size;
        }
        return out;
    }



    istream& Pack::read(istream& in) 
    {
        int units;

        if (!valid()) 
        {            
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            in.get();            
        }
        else if (Number_Of_Units == Size) 
        {
            in.ignore();
            cout << "Pack is full!, press <ENTER> to continue...";
            in.get();
        }
        else 
        {
            bool validValue = false;
            cout << "Add to ";
            print(cout);

            int maxVal = Size - Number_Of_Units;
            int flag = 0;
            while (!validValue && flag == 0) 
            {
                cout << endl << "> ";
                in >> units;

                if (units > Size) 
                {
                    cout << "Invalid Integer, retry: ";
                }

                else if (units < 1 || units > maxVal) 
                {
                    cout << "Value out of range [1<=val<=" << maxVal << "]: ";
                    in >> units;
                    flag = 1;
                }

                else validValue = true;
            }

            units = (*this += units);
            cout << "Added " << units << endl;
        }

        return in;
    }
}