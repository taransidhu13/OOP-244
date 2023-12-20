#pragma once
/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: LblShape
Filename: LblShape.h
Version 1.1
Author: Tarandeep Kaur
Revision History
-----------------------------------------------------------
Date          Reason
15 November 2023
-----------------------------------------------------------*/
#ifndef SDDS_LBL_SHAPE_H
#define SDDS_LBL_SHAPE_H

#include "Shape.h"

namespace sdds {
    // LblShape class inherits from Shape class
    class LblShape : public Shape {
    private:
        // Member variable for the label of the shape
        char* m_label = nullptr;

    protected:
        // Protected query function to access the label
        const char* label() const;

    public:
        // Default constructor
        LblShape();

        // Constructor with a parameter for the label
        LblShape(const char* cString);

        // Override the getSpecs function to read specifications from istream
        void getSpecs(std::istream& is);

        // Destructor to free dynamically allocated memory
        ~LblShape();
    };
} 
#endif // !SDDS_LBL_SHAPE_H