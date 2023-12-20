/*                         WORKSHOP 6
Name: Tarandeep Kaur
Student ID: 139389225
Student Email: tarandeep-kaur6@myseneca.ca
Date: 01 November 2023
Professor Name: Rania Arbash
Authenticity Declaration
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // Using <cstring> for string operations
#include "HealthCard.h"

using namespace std;

namespace sdds {
    // Function to validate the HealthCard data
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
    {
        // Check if name is not null, not empty, and numbers are in valid ranges
        if (name && name[0] && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9) {
            return true;
        }
        return false;
      
    }

    // Function to set the HealthCard to an empty state
    void HealthCard::setEmpty()
    {
        delete[] m_name;
        m_name = nullptr;
        m_number = 0;
        m_vCode[0] = '\0';
        m_sNumber[0] = '\0';
    }

    // Function to allocate memory and copy a string
    void HealthCard::allocateAndCopy(const char* name)
    {
        delete[] m_name;
        if (name) {
            m_name = new char[std::strlen(name) + 1];
            std::strcpy(m_name, name);
        }
        else {
            m_name = nullptr;
        }
    }

    // Function to extract a character from an input stream and set failbit if not found
    void HealthCard::extractChar(istream& istr, char ch) const
    {
        if (istr.peek() == ch)
            istr.ignore();
        else
        {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }

    // Function to print the ID information
    ostream& HealthCard::printIDInfo(ostream& ostr) const
    {
        return ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
    }

    // Function to set the HealthCard data
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        if (validID(name, number, vCode, sNumber)) {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
        else {
            setEmpty();
        }
    }

    // Constructor with default values
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
    {
        set(name, number, vCode, sNumber);
    }

    // Copy constructor
    HealthCard::HealthCard(const HealthCard& hc)
    {
        *this = hc;
    }

    // Assignment operator
    HealthCard& HealthCard::operator=(const HealthCard& hc)
    {
        if (this != &hc) {
            delete[] m_name;
            m_name = nullptr;
            set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        }
        return *this;
    }

    // Destructor
    HealthCard::~HealthCard()
    {
        delete[] m_name;
    }

    // Conversion operator to bool
    HealthCard::operator bool() const
    {
        return m_name != nullptr;
    }

    // Function to print HealthCard information
    ostream& HealthCard::print(ostream& ostr, bool toFile) const{
        if (*this){
            if (toFile){
                ostr << m_name;
                ostr << ',';
                printIDInfo(ostr);
                ostr << endl;
            }
            else{
                ostr.width(50);
                ostr.fill('.');
                ostr.setf(ios::left);
                ostr << m_name;
                printIDInfo(ostr);
            }
        }
        return ostr;
    }

    // Function to read HealthCard information from an input stream
    istream& HealthCard::read(istream& istr){
        char name[MaxNameLength]{ '\0' };
        long long number{ 0 };
        char vCode[3]{ 0 };
        char sNumber[10]{ 0 };

        istr.get(name, MaxNameLength, ',');      //for m_name
        extractChar(istr, ',');                  //for extraction of comma
        istr >> number;                          //for m_number
        extractChar(istr, '-');                  //for extraction of dash
        istr.get(vCode, 3, ',');                 //for m_vCode
        extractChar(istr, ',');                  //for extraction of comma
        istr.get(sNumber, 10, '\n');             //for m_sNumber
        extractChar(istr, '\n');                 //for extracting newline character

        if (istr){
            set(name, number, vCode, sNumber);
        }
        else{
            istr.clear();
            istr.ignore(1000, '\n');
        }
        return istr;
    }

    // Overloaded output stream operator to print a HealthCard
    ostream& operator<<(ostream& ostr, const HealthCard& hc){
        if (hc){
            hc.print(ostr, false);
        }
        else{
            ostr << "Invalid Health Card Record";
        }
        return ostr;
    }

    // Overloaded input stream operator to read a HealthCard
    istream& operator>>(istream& istr, HealthCard& hc){
        return hc.read(istr);
    }
}
