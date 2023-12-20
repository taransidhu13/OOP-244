/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

/*
NAME: TARANDEEP KAUR
STUDENT ID: 139389225
EMAIL: tarandeep-kaur6@myseneca.ca
Date: 13 Oct 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Flight.h"

namespace sdds {

    const int Boeing747Capacity = 388;
    const int FuelTankCapacity = 238840;

    // Private member function to reset the Flight object to an empty state
    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // Default constructor
    Flight::Flight() {
        emptyPlane();
    }

    // Parameterized constructor
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boeing747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strncpy(m_title, title, 15);
            m_title[15] = '\0';
        }
    }

    // Display flight information
    std::ostream& Flight::display() const {
        if (*this) {
            std::cout << " Flight  |  Ready to Depart    " << std::setw(7) << std::right << m_title << " | Pass: ";
            std::cout.width(10);
            std::cout << m_passengers << " | ";
            std::cout.width(12);
            std::cout.precision(2);
            std::cout.setf(std::ios::fixed);
            std::cout << m_fuel << " Liters";
        }
        else if (~*this) {
            std::cout << " Flight  |  Empty Plane    ";
        }
        else {
            std::cout << " Flight  |  Low Fuel        " << std::setw(10) << std::right << m_title << " | Pass: ";
            std::cout.width(10);
            std::cout << m_passengers << " | ";
            std::cout.width(12);
            std::cout.precision(2);
            std::cout.setf(std::ios::fixed);
            std::cout << m_fuel << " Liters";
        }
        return std::cout;
    }

    // Conversion operator to check if the flight is ready for departure
    Flight::operator bool() const {
        return m_passengers > 0 && m_fuel >= m_passengers * 600.0;
    }

    // Conversion operator to get the number of passengers
    Flight::operator int() const {
        return m_passengers;
    }

    // Conversion operator to get the fuel level
    Flight::operator double() const {
        return m_fuel;
    }

    // Conversion operator to get the flight title
    Flight::operator const char* () const {
        return m_title;
    }

    // Logical NOT operator to check if the flight is empty
    bool Flight::operator~() const {
        return m_passengers == 0;
    }

    // Assignment operator to copy the state of another Flight object
    Flight& Flight::operator=(Flight& other) {
        if (this != &other) {
            m_passengers = other.m_passengers;
            m_fuel = other.m_fuel;
            strncpy(m_title, other.m_title, 15);
            m_title[15] = '\0';
            other.m_passengers = 0;
            other.m_fuel = 0.0;
            strncpy(other.m_title, "EmptyPlane", 15);
            other.m_title[15] = '\0';
        }
        return *this;
    }

    // Assignment operator to set the number of passengers
    Flight& Flight::operator=(int passengers) {
        if (passengers > 0 && passengers <= Boeing747Capacity) {
            m_passengers = passengers;
        }
        return *this;
    }

    // Assignment operator to set the fuel level
    Flight& Flight::operator=(double fuel) {
        if (fuel >= 0 && fuel <= FuelTankCapacity) {
            m_fuel = fuel;
        }
        return *this;
    }


    // Addition assignment operator to add fuel to the flight
    Flight& Flight::operator+=(double fuel) {
        if (fuel > 0 && (m_fuel + fuel) <= FuelTankCapacity) {
            m_fuel += fuel;
        }
        return *this;
    }

    // Addition assignment operator to add passengers to the flight
    Flight& Flight::operator+=(int passengers) {
        if (passengers > 0 && (m_passengers + passengers) <= Boeing747Capacity) {
            m_passengers += passengers;
        }
        return *this;
    }

    // Subtraction assignment operator to subtract fuel from the flight
    Flight& Flight::operator-=(double fuel) {
        if (fuel > 0 && (m_fuel - fuel) >= 0) {
            m_fuel -= fuel;
        }
        return *this;
    }

    // Subtraction assignment operator to remove passengers from the flight
    Flight& Flight::operator-=(int passengers) {
        if (passengers > 0 && (m_passengers - passengers) >= 0) {
            m_passengers -= passengers;
        }
        return *this;
    }

    // Operator to transfer passengers from one Flight to another
    Flight& Flight::operator<<(Flight& other) {
        if (this != &other && *this && other) {
            int totalPassengers = m_passengers + other.m_passengers;
            if (totalPassengers <= Boeing747Capacity) {
                m_passengers = totalPassengers;
                other.m_passengers = 0;
            }
            else {
                m_passengers = Boeing747Capacity;
                other.m_passengers = totalPassengers - Boeing747Capacity;
            }
        }
        return *this;
    }

    // Operator to transfer passengers from one Flight to another
    Flight& Flight::operator>>(Flight& other) {
        if (this != &other && *this && other) {
            int totalPassengers = m_passengers + other.m_passengers;
            if (totalPassengers <= Boeing747Capacity) {
                other.m_passengers = totalPassengers;
                m_passengers = 0;
            }
            else {
                other.m_passengers = Boeing747Capacity;
                m_passengers = totalPassengers - Boeing747Capacity;
            }
        }
        return *this;
    }

    int Flight::operator+(const Flight& other) const {
        if (*this && other) {
            return static_cast<int>(*this) + static_cast<int>(other);
        }
        return 0;
    }

    // Friend function to add passengers to an integer and return the new total
    int operator+=(int& left, const Flight& right) {
        left += static_cast<int>(right);
        return left;
    }

    
  

}  // namespace sdds