/*
Final Project Milestone 5
Module: Status
Filename: Status.cpp
Author	Tarandeep Kaur
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"
#include "Utils.h"
using namespace std;
namespace sdds{
    // Deletes dynamically allocated memory for the description.
    void Status::setEmpty() {
        delete[] m_desc;
        m_desc = nullptr;
        m_code = 0;
    }

    // Sets the attributes for Status with a description and a code.
    void Status::set(const char* desc, int code) {
        m_code = code;
        if (desc != nullptr)
            ut.alocpy(m_desc, desc);
        else
            setEmpty();
    }

    // Constructor for Status with a description.
    Status::Status(const char* desc) {
        set(desc);
    }

    // Copy constructor for Status, copies values from another Status object.
    Status::Status(const Status& status) {
        set(status.m_desc, status.m_code);
    }

    // Assignment operator for Status, copies values from another Status object.
    Status& Status::operator=(const Status& status) {
        if (this != &status)
            set(status.m_desc, status.m_code);
        return *this;
    }

    // Destructor for Status, deallocates dynamically allocated memory.
    Status::~Status() {
        setEmpty();
    }

    // Assignment operator for Status with an integer code.
    Status& Status::operator=(const int code) {
        m_code = code;
        return *this;
    }

    // Assignment operator for Status with a description.
    Status& Status::operator=(const char* desc) {
        ut.alocpy(m_desc, desc);
        return *this;
    }

    // Conversion operator for Status to integer.
    Status::operator int() const {
        return m_code;
    }

    // Conversion operator for Status to const char*.
    Status::operator const char* () const {
        return m_desc;
    }

    // Conversion operator for Status to boolean.
    Status::operator bool() const {
        return m_desc == nullptr;
    }

    // Clears the status by setting to an empty state.
    Status& Status::clear() {
        setEmpty();
        return *this;
    }

    // Output stream operator for Status, displays the status message.
    ostream& operator<<(ostream& ostr, const Status& status) {
        if (!status)
        {
            if (int(status) != 0)
                ostr << "ERR#" << int(status) << ": ";
            ostr << (const char*)(status);
        }
        return ostr;
    }
}