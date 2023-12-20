/***********************************************************************
// OOP244 Workshop # 9
//
// File: Student.cpp
// Version 1.1
// Date: 21 November 2023
// Author: Tarandeep Kaur
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Student.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"

namespace sdds {

    // Default constructor
    Student::Student() : m_name(nullptr), m_age(0) {}

    // Parameterized constructor
    Student::Student(const char* name, int age) : m_age(age) {
        if (name != nullptr) {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
        else {
            m_name = nullptr;
        }
    }

    // Copy constructor
    Student::Student(const Student& src) : m_age(src.m_age) {
        if (src.m_name != nullptr) {
            m_name = new char[strlen(src.m_name) + 1];
            strcpy(m_name, src.m_name);
        }
        else {
            m_name = nullptr;
        }
    }

    // Copy assignment operator
    Student& Student::operator=(const Student& src) {
        if (this != &src) {
            delete[] m_name;
            m_age = src.m_age;
            if (src.m_name != nullptr) {
                m_name = new char[strlen(src.m_name) + 1];
                strcpy(m_name, src.m_name);
            }
            else {
                m_name = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    Student::~Student() {
        delete[] m_name;
    }

    // Display method
    void Student::display() const {
        std::cout << "Name: " << (m_name ? m_name : "N/A") << std::endl;
        std::cout << "Age: " << m_age << std::endl;
    }

} // namespace sdds
