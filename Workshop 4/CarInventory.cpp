/*                         WORKSHOP 4 PART 1
Name: Tarandeep Kaur
Student ID: 139389225
Seneca Email: tarandeep-kaur6@myseneca.ca
Section: ZEE
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

namespace sdds {

    void CarInventory::resetInfo() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0.0;
    }

    CarInventory::CarInventory() {
        resetInfo(); // Initialize member variables with default values
    }

    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
        resetInfo(); // Initialize member variables
        setInfo(type, brand, model, year, code, price); // Set member variables with provided values
    }

    CarInventory::~CarInventory() {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model; // Clean up dynamically allocated memory
    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

        if (type && brand && model && year >= 1990 && code >= 100 && code <= 999 && price > 0) {
            m_type = new char[strlen(type) + 1];
            m_brand = new char[strlen(brand) + 1];
            m_model = new char[strlen(model) + 1];

            strcpy(m_type, type);
            strcpy(m_brand, brand);
            strcpy(m_model, model);

            m_year = year;
            m_code = code;
            m_price = price;
        }
        else {
            resetInfo(); // Reset member variables if input is invalid
        }

        return *this;
    }

    void CarInventory::printInfo() const {
        if (isValid()) {
            cout << "| " << left << setw(10) << m_type << " | "
                << left << setw(16) << m_brand << " | "
                << left << setw(16) << m_model << " | "
                << setw(4) << m_year << " | " 
                << right << setw(4) << m_code << " | "
                << right << setw(9) << fixed << setprecision(2) << m_price << " |" << endl;
        }
    }

    bool CarInventory::isValid() const {
        return (m_type && m_brand && m_model && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0);
    }

    bool CarInventory::isSimilarTo(const CarInventory& car) {
        if (!m_type || !m_brand || !m_model || !car.m_type || !car.m_brand || !car.m_model) {
            return false;
        }

        return (strcmp(m_type, car.m_type) == 0 && strcmp(m_brand, car.m_brand) == 0 &&
            strcmp(m_model, car.m_model) == 0 && m_year == car.m_year);
    }

    int find_similar(CarInventory car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return i;
                }
            }
        }
        return -1; // No similar entries found
    }

}
