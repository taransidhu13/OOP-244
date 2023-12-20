#pragma once
/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: Rectangle
Filename: Rectangle.h
Version 1.1
Author: Tarandeep Kaur
Revision History
-----------------------------------------------------------
Date          Reason
15 November 2023
-----------------------------------------------------------*/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds {
    // Rectangle class inherits from LblShape class
    class Rectangle : public LblShape {
    private:
        // Member variables for width and height of the rectangle
        int m_width;
        int m_height;

    public:
        // Default constructor
        Rectangle();

        // Constructor with parameters for label, width, and height
        Rectangle(const char* cString, const int width, const int height);

        // Override the getSpecs function to read specifications from istream
        void getSpecs(std::istream& is);

        // Override the draw function to draw the rectangle on ostream
        void draw(std::ostream& os) const;
    };
}
#endif // !SDDS_RECTANGLE_H