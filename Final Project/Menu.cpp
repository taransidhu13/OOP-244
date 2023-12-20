/* ------------------------------------------------------
Milestone 5
Module: Menu
Filename: Menu.cpp
Version 1.1
Author: Tarandeep Kaur
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds{

    // Deletes the dynamically allocated memory for menu text and resets member variables.
    void Menu::setEmpty() {
        delete[] m_text;
        m_text = nullptr;
        m_numOptions = 0;
    }

    // Sets the menu with the provided number of options and text.
    // If the number of options is too large or the text is null, sets the menu as empty.
    void Menu::set(unsigned int numOptions, const char* text) {
        if (numOptions > c_maxnumOptions || text == nullptr)
            setEmpty();
        else {
            ut.alocpy(m_text, text);
            m_numOptions = numOptions;
        }
    }

    // Constructor that initializes the menu with the provided number of options and text.
    Menu::Menu(unsigned int numOptions, const char* text) {
        set(numOptions, text);
    }

    // Copy constructor that copies values from another Menu object.
    Menu::Menu(const Menu& menu) {
        set(menu.m_numOptions, menu.m_text);
    }

    // Assignment operator that copies values from another Menu object.
    Menu& Menu::operator=(const Menu& menu) {
        if (this == &menu)
            set(menu.m_numOptions, menu.m_text);
        return *this;
    }

    // Destructor that deallocates memory for menu text.
    Menu::~Menu() {
        setEmpty();
    }

    // Displays the menu and returns the user's choice.
    unsigned int Menu::run() const {
        cout << m_text
            << "0- Exit" << endl
            << "> ";
        return ut.getint(0, m_numOptions);
    }

}