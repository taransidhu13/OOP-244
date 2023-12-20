/***********************************************************************
// OOP244 Workshop # 9
//
// File: Graduate.cpp
// Version 1.1
// Date: 21 November 2023
// Author: Tarandeep Kaur
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Graduate.h"

namespace sdds {

    // Default constructor
    Graduate::Graduate() : Student(), m_thesisTitle(nullptr), m_supervisor(nullptr) {}

    // Parameterized constructor
    Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor)
        : Student(name, age), m_thesisTitle(nullptr), m_supervisor(nullptr) {
        if (thesisTitle != nullptr) {
            m_thesisTitle = new char[strlen(thesisTitle) + 1];
            strcpy(m_thesisTitle, thesisTitle);
        }
        if (supervisor != nullptr) {
            m_supervisor = new char[strlen(supervisor) + 1];
            strcpy(m_supervisor, supervisor);
        }
    }

    // Copy constructor
    Graduate::Graduate(const Graduate& src) : Student(src) {
        if (src.m_thesisTitle != nullptr) {
            m_thesisTitle = new char[strlen(src.m_thesisTitle) + 1];
            strcpy(m_thesisTitle, src.m_thesisTitle);
        }
        else {
            m_thesisTitle = nullptr;
        }

        if (src.m_supervisor != nullptr) {
            m_supervisor = new char[strlen(src.m_supervisor) + 1];
            strcpy(m_supervisor, src.m_supervisor);
        }
        else {
            m_supervisor = nullptr;
        }
    }

    // Copy assignment operator
    Graduate& Graduate::operator=(const Graduate& src) {
        if (this != &src) {
            Student::operator=(src);

            delete[] m_thesisTitle;
            delete[] m_supervisor;

            if (src.m_thesisTitle != nullptr) {
                m_thesisTitle = new char[strlen(src.m_thesisTitle) + 1];
                strcpy(m_thesisTitle, src.m_thesisTitle);
            }
            else {
                m_thesisTitle = nullptr;
            }

            if (src.m_supervisor != nullptr) {
                m_supervisor = new char[strlen(src.m_supervisor) + 1];
                strcpy(m_supervisor, src.m_supervisor);
            }
            else {
                m_supervisor = nullptr;
            }
        }
        return *this;
    }

    // Destructor
    Graduate::~Graduate() {
        delete[] m_thesisTitle;
        delete[] m_supervisor;
    }

    // Display method
    void Graduate::display() const {
        Student::display();
        std::cout << "Thesis Title: " << (m_thesisTitle ? m_thesisTitle : "N/A") << std::endl;
        std::cout << "Supervisor: " << (m_supervisor ? m_supervisor : "N/A") << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }

} // namespace sdds