/***********************************************************************
// OOP244 Workshop # 10: tester program
//
// File: selection.h
// Version 1.0
// Date: 2023/11/27
// Author: Tarandeep Kaur
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SELECTION_H
#define SELECTION_H

#include <iostream>

namespace sdds {
    // Function template to select indices where a key is found in an array
    template <typename arrayType, typename keyType>
    int* select(const arrayType array[], const keyType& key, size_t size) {
        int* indices = new int[size + 1]; // +1 for the terminator -1
        int count = 0;

        // Iterate through the array to find occurrences of the key
        for (size_t i = 0; i < size; ++i) {
            if (array[i] == key) {
                indices[count++] = static_cast<int>(i);
            }
        }

        indices[count] = -1; // Terminator

        return indices;
    }

    // Function template to display elements at specified indices as a CSV list
    template <typename arrayType>
    void csvDisplaySelection(const char* title, const arrayType array[], const int* indices) {
        std::cout << title << std::endl;

        // Check if indices are not null and not empty
        if (indices && indices[0] != -1) {
            for (int i = 0; indices[i] != -1; ++i) {
                std::cout << array[indices[i]];
                if (indices[i + 1] != -1) {
                    std::cout << ", ";
                }
            }
        }
        else {
            std::cout << "Empty Selection";
        }

        std::cout << std::endl;
    }
}

#endif // SELECTION_H
