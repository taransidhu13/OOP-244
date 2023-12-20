/* 
Final Project Milestone 5
Module: Date
Filename: Date.cpp
Author	Tarandeep Kaur
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
#include "Utils.h"
using namespace std;
namespace sdds{
    bool Date::validate(){
        bool result = false;
        int currentYear;
        ut.getSystemDate(&currentYear);

        if (m_year >= currentYear && m_year <= c_maxYear){
            if (m_month >= 1 && m_month <= 12){
                if (m_day >= 1 && m_day <= ut.daysOfMon(m_month, m_year)){
                    result = true; 
                }
                else{
                    m_state = "Invalid day in date";
                    m_state = 3;
                }
            }
            else {
                m_state = "Invalid month in date";
                m_state = 2;
                return result;
            }
        }
        else {
            m_state = "Invalid year in date";
            m_state = 1;
            return result;
        }
        return result;
    }

    int Date::uniqueDateValue() const { 
        return m_year * 372 + m_month * 31 + m_day;
    }

    void Date::set(int year, int month, int day) {
        if (year != 0 && month != 0 && day != 0) {
            m_year = year;
            m_month = month;
            m_day = day;
            validate();
        }
        else {
            ut.getSystemDate(&year, &month, &day);
            m_year = year;
            m_month = month;
            m_day = day;
        }
    }

    Date::Date(int year, int month, int day) { 
        set(year, month, day);
    }

    bool Date::operator==(const Date& date) const {
        return uniqueDateValue() == date.uniqueDateValue();
    }

    bool Date::operator!=(const Date& date) const {
        return uniqueDateValue() != date.uniqueDateValue();
    }

    bool Date::operator<(const Date& date) const {
        return uniqueDateValue() < date.uniqueDateValue();
    }

    bool Date::operator>(const Date& date) const {
        return uniqueDateValue() > date.uniqueDateValue();
    }

    bool Date::operator<=(const Date& date) const { 
        return uniqueDateValue() <= date.uniqueDateValue();
    }

    bool Date::operator>=(const Date& date) const {
        return uniqueDateValue() >= date.uniqueDateValue();
    }

    const Status& Date::state() const { 
        return m_state;
    }

    Date& Date::formatted(bool flag){
        m_formatted = flag;
        return *this;
    }

    Date::operator bool() const { 
        return m_state;
    }

    ostream& Date::write(ostream& ostr) const {
        if (m_formatted){
            ostr << m_year << "/";
            if (m_month < 10)
                ostr << "0"; 
            ostr << m_month << "/";
            if (m_day < 10)
                ostr << "0"; 
            ostr << m_day;
        }
        else {
            ostr << m_year % 100;
            if (m_month < 10)
                ostr << "0"; 
            ostr << m_month;
            if (m_day < 10)
                ostr << "0"; 
            ostr << m_day;
        }
        return ostr;
    }

    istream& Date::read(istream& istr){
        int integerVal = 0;
        int currentYear = 0;
        ut.getSystemDate(&currentYear);
        istr >> integerVal;

        if (integerVal > 100 && integerVal < 10000){
            m_year = currentYear; 
            m_month = integerVal / 100;
            m_day = integerVal % 100;
        }
        else if (integerVal > 10000 && integerVal < 1000000){
            m_year = integerVal / 10000 + 2000;
            m_month = (integerVal / 100) % 100;
            m_day = integerVal % 100;
        }
        
        else if (integerVal > 0 && integerVal < 100) {
            m_year = currentYear;
            m_month = 0;
            m_day = integerVal;
        }
        else
            m_state = "Invalid date value";

        if (!validate()) 
            istr.setstate(ios::badbit);

        return istr;
    }

    ostream& operator<<(ostream& ostr, const Date& date) {
        date.write(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, Date& date){
        date.read(istr);
        return istr;
    }
}