#pragma once
/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: Line
Filename: Line.h
Version 1.1
Author: Tarandeep Kaur
Revision History
-----------------------------------------------------------
Date          Reason
15 November 2023
-----------------------------------------------------------*/


#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds
{
    // Line class inherits from LblShape class
    class Line : public LblShape {
    private:
        // Member variable for the length of the line
        int m_length;

    public:
        // Default constructor
        Line();

        // Constructor with parameters for label and length
        Line(const char* cString, const int length);

        // Override the getSpecs function to read specifications from istream
        void getSpecs(std::istream& is);

        // Override the draw function to draw the line on ostream
        void draw(std::ostream& os) const;
    };
}
#endif // !SDDS_LINE_H