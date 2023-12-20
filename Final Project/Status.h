#pragma once
/* 
Final Project Milestone 5
Module: Status
Filename: Status.h
Author	Tarandeep Kaur
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
using namespace std;
namespace sdds{

    class Status{
        char* m_desc = nullptr;
        int m_code;
        void setEmpty();
        void set(const char* desc, int code = 0);

    public:
        Status(const char* desc = nullptr);
        Status(const Status& status);
        Status& operator=(const Status& status);
        ~Status();
        Status& operator=(const int code);
        Status& operator=(const char* desc);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();
    };

    ostream& operator<<(ostream& ostr, const Status& status);
}

#endif // !SDDS_STATUS_H