#pragma once
/***********************************************************************
// OOP244 Workshop # 9
//
// File: Graduate.h
// Version 1.1
// Date: 21 November 2023
// Author: Tarandeep Kaur
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

// Graduate.h
#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H
#include "Student.h"

namespace sdds {
    class Graduate : public Student {
        char* m_thesisTitle;
        char* m_supervisor;

    public:
        // Constructors and Destructor
        Graduate();
        Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor);
        Graduate(const Graduate& src);
        Graduate& operator=(const Graduate& src);
        ~Graduate();

        // Display method
        void display() const;
    };
}

#endif