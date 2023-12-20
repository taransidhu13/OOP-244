#pragma once
/***********************************************************************
// OOP244 Workshop # 9
//
// File: Student.h
// Version 1.1
// Date: 21 November 2023
// Author: Tarandeep Kaur
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

// Student.h
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {
    class Student {
        char* m_name;
        int m_age;

    public:
        // Constructors and Destructor
        Student();
        Student(const char* name, int age);
        Student(const Student& src);
        Student& operator=(const Student& src);
        virtual ~Student();

        // Display method
        void display() const;

    };
}

#endif