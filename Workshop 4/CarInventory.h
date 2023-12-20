/*                         WORKSHOP 4 PART 1
Name: Tarandeep Kaur
Student ID: 139389225
Seneca Email: tarandeep-kaur6@myseneca.ca
Section: ZEE
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#pragma once
#ifndef CARINVENTORY_H
#define CARINVENTORY_H

namespace sdds {

    class CarInventory {
    private:
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;

        void resetInfo();

    public:
        CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);
        ~CarInventory();

        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);

        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car);
    };

    int find_similar(CarInventory car[], const int num_cars);

}

#endif
