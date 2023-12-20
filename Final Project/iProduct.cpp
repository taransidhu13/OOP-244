/* ------------------------------------------------------
Milestone 5
Module: iProduct
Filename: iProduct.cpp
Author: Tarandeep Kaur
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "iProduct.h"
using namespace std;
namespace sdds {

    iProduct::~iProduct() {
    //destructor
    }

    istream& operator>>(istream& istr, iProduct& iprd){
        iprd.read(istr);
        return istr;
    }

    ostream& operator<<(ostream& ostr, const iProduct& iprd){
        iprd.display(ostr);
        return ostr;
    }

}