#pragma once
/* ------------------------------------------------------
Milestone 5
Module: Menu
Filename: Menu.h
Version 1.1
Author: Tarandeep Kaur
Revision History
-----------------------------------------------------------
Date          Reason
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
using namespace std;
namespace sdds {
    const int c_maxnumOptions = 15;

    class Menu{
        char* m_text = nullptr;
        unsigned int m_numOptions;
        void set(unsigned int numOptions, const char* text);
        void setEmpty();

    public:
        Menu(unsigned int numOptions, const char* text);
        Menu(const Menu& menu);
        Menu& operator=(const Menu& menu);
        ~Menu();
        unsigned int run() const;
    };
}
#endif // !SDDS_MENU_H