#pragma once
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

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

#include <iostream>

namespace sdds {
    // Maximum length for the person's name
    const int MaxNameLength = 55;

    // HealthCard class declaration
    class HealthCard {
        char* m_name{};         // Pointer to store the person's name
        long long m_number;     // Main health number
        char m_vCode[3];        // Version code (2 characters)
        char m_sNumber[10];     // Stock control number (9 characters)

        // Private member functions
        bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
        void setEmpty();
        void allocateAndCopy(const char* name);
        void extractChar(std::istream& istr, char ch) const;
        std::ostream& printIDInfo(std::ostream& ostr) const;
        void set(const char* name, long long number, const char vCode[], const char sNumber[]);

    public:
        // Constructor with default values
        HealthCard(const char* name = nullptr, long long number = 0, const char vCode[] = {}, const char sNumber[] = {});

        // Copy constructor
        HealthCard(const HealthCard& hc);

        // Assignment operator
        HealthCard& operator=(const HealthCard& hc);

        // Destructor
        ~HealthCard();

        // Conversion operator to bool
        operator bool() const;

        // Print the HealthCard information to an output stream
        std::ostream& print(std::ostream& ostr, bool toFile = true) const;

        // Read the HealthCard information from an input stream
        std::istream& read(std::istream& istr);
    };

    // Overloaded output stream operator to print a HealthCard
    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);

    // Overloaded input stream operator to read a HealthCard
    std::istream& operator>>(std::istream& istr, HealthCard& hc);
}

#endif // !SDDS_HEALTHCARD_H
