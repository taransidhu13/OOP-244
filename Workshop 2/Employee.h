#pragma once
/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File Employee.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Tarandeep Kaur  18 Sep 2023     Implementation of Workshop 2
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***********************************************************************/

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    void sort();
    bool load(Employee& emp);
    bool load();
    void display(const Employee& emp);
    void display();
    void deallocateMemory();
}

#endif // SDDS_EMPLOYEE_H_
