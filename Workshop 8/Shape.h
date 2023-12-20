#pragma once
/* ------------------------------------------------------
Workshop 8 part 1 (Only the coding part)
Module: Shape
Filename: Shape.h
Version 1.1
Author: Tarandeep Kaur
Revision History
-----------------------------------------------------------
Date          Reason
15 November 2023
-----------------------------------------------------------*/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds {
    // Shape class with pure virtual functions
    class Shape {
    public:
        // Pure virtual function to draw the shape on ostream
        virtual void draw(std::ostream& os) const = 0;

        // Pure virtual function to read specifications from istream
        virtual void getSpecs(std::istream& is) = 0;

        // Virtual destructor to ensure proper cleanup of derived classes
        virtual ~Shape();
    };

    // Overload the insertion operator to output the shape using the draw function
    std::ostream& operator<<(std::ostream& os, const Shape& shape);

    // Overload the extraction operator to input the shape using the getSpecs function
    std::istream& operator>>(std::istream& is, Shape& shape);
} // Close the sdds namespace

#endif // !SDDS_SHAPE_H