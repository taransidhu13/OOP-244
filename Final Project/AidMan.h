#pragma once
/* ------------------------------------------------------
Milestone 5
Module: AidMan
Filename: AidMan.h
Author: Tarandeep Kaur
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_AID_MAN_H
#define SDDS_AID_MAN_H
#include <iostream>
#include "Menu.h"
#include "iProduct.h"
using namespace std;
namespace sdds
{
    const int sdds_max_num_items = 100;

    class AidMan
    {
        char* m_fileName = nullptr;
        Menu m_mainMenu;
        iProduct* m_iProduct[sdds_max_num_items] = {};
        int m_numOfiProds;
        unsigned int menu() const;
        void setEmpty();
        void set(const char* fileName = nullptr);
        

        void save() const;
        void deallocate();
        void remove(int index);
        int search(int sku) const;
        int list(const char* sub_desc = nullptr); 
        void add();                               
        void remove();
        void update();
        void sort();
        void ship();
        bool load();                              
        void exit();                              

    public:
        AidMan();
        AidMan(const AidMan& aidMan);
        AidMan& operator=(const AidMan& aidMan);
        ~AidMan();
        void run();
    };
}
#endif // !SDDS_AID_MAN_H