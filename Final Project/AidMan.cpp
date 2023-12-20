/* ------------------------------------------------------
Milestone 5
Module: AidMan
Filename: AidMan.cpp
Author: Tarandeep Kaur
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "AidMan.h"
#include "Perishable.h"
#include "Date.h"
#include "Utils.h"

using namespace std;
namespace sdds{

    unsigned int AidMan::menu() const {
        cout << "Aid Management System" << endl
            << "Date: " << Date() << endl 
            << "Data file: ";

        if (m_fileName != nullptr)
            cout << m_fileName << endl;

        else
            cout << "No file" << endl;
        cout << "---------------------------------" << endl;
        return m_mainMenu.run(); 
    }

    void AidMan::setEmpty(){
        delete[] m_fileName;
        m_fileName = nullptr;
    }

    void AidMan::set(const char* fileName){
        if (fileName != nullptr)
            ut.alocpy(m_fileName, fileName);
        else
            setEmpty();
    }

    AidMan::AidMan() : m_mainMenu(7, 
        "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n"){
        set();
    }

    AidMan::AidMan(const AidMan& aidMan): m_mainMenu(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n"){
        set(aidMan.m_fileName);
    }

    AidMan& AidMan::operator=(const AidMan& aidMan){
        if (this != &aidMan)
            set(aidMan.m_fileName);
        return *this;
    }

    AidMan::~AidMan() { 
        setEmpty(); 
    }

    void AidMan::save() const{
        if (m_fileName != nullptr){
            ofstream ofstr(m_fileName, ios::out);
            for (int i = 0; i < m_numOfiProds; i++)
                m_iProduct[i]->save(ofstr) << endl;
            ofstr.flush();
            ofstr.close();
        }
    }

    void AidMan::deallocate(){
        for (int i = 0; m_iProduct[i]; i++)
            delete m_iProduct[i];
        delete[] m_fileName;
        m_fileName = nullptr;
        m_numOfiProds = 0;
    }

    bool AidMan::load(){
        bool result = false;
        string fileName;

        save();
        deallocate();
        cout << "\n****New/Open Aid Database****\n"
            << "Enter file name: ";
        getline(cin, fileName, '\n');
        ut.alocpy(m_fileName, fileName.c_str());
        ifstream ifstr(m_fileName);

        if (!ifstr){
            cout << "Failed to open " << m_fileName << " for reading!" << endl
                << "Would you like to create a new data file?" << endl
                << "1- Yes!" << endl
                << "0- Exit" << endl
                << "> ";
            switch (ut.getint(0, 1))
            {
            case 0:
                delete[] m_fileName;
                m_fileName = nullptr;
                cout << "Aborted!" << endl;
                break;
            case 1:
                ofstream ofstr(m_fileName, ios::out);
                break;
            }
        }
        else{
            int i = 0;
            while (i < sdds_max_num_items && ifstr){
                if (ifstr.peek() >= '1' && ifstr.peek() <= '3')
                    m_iProduct[i] = new Perishable; 
                else if (ifstr.peek() >= '4' && ifstr.peek() <= '9')
                    m_iProduct[i] = new Item; 
                else
                    delete m_iProduct[i]; 

                if (m_iProduct[i]) {
                    m_iProduct[i]->load(ifstr); 
                    i++;                        
                }
                else
                    ifstr.setstate(ios::badbit); 
            }
            m_numOfiProds = i; 
        }

        if (m_numOfiProds > 0){
            result = true;
            cout << m_numOfiProds << " records loaded!" << endl;
        }

        cout << endl;
        return result;
    }

    int AidMan::list(const char* sub_desc){
        int i = 0;
        if (sub_desc == nullptr) 
        {
            cout << "\n****List Items****" << endl
                << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl
                << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
            for (i = 0; i < m_numOfiProds; i++)
            {
                cout.setf(ios::right);
                cout.width(4);
                cout << i + 1;
                cout << " | ";
                cout.unsetf(ios::right);
                m_iProduct[i]->linear(true);
                m_iProduct[i]->display(cout) << endl;
            }
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
            cout << "Enter row number to display details or <ENTER> to continue:" << endl
                << "> ";
            if (cin.peek() != '\n') 
            {
                int idx = ut.getint(1, i) - 1;
                m_iProduct[idx]->linear(false);
                m_iProduct[idx]->display(cout);
                cout << endl;
            }
            else
                cin.ignore();
            cout << endl;
        }
        else 
        {
            cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl
                << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
            for (i = 0; i < m_numOfiProds; i++)
            {
                if (*m_iProduct[i] == sub_desc)
                {
                    cout.setf(ios::right);
                    cout.width(4);
                    cout << i + 1;
                    cout << " | ";
                    cout.unsetf(ios::right);
                    m_iProduct[i]->linear(true);
                    m_iProduct[i]->display(cout);
                    cout << endl;
                }
            }
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
        }

        if (m_numOfiProds == 0)
            cout << "The list is emtpy!" << endl;

        return i;
    }

    int AidMan::search(int sku) const{
        int idx = -1;
        for (int i = 0; i < m_numOfiProds; i++) 
        {
            if (*m_iProduct[i] == sku) 
                idx = i;               
        }
        return idx;
    }

    void AidMan::add() {
        cout << "\n****Add Item****\n";
        if (m_numOfiProds >= sdds_max_num_items)
            cout << "Database full!" << endl;
        else
            cout << "1- Perishable" << endl
            << "2- Non-Perishable" << endl
            << "-----------------" << endl
            << "0- Exit" << endl
            << "> ";

        int select = ut.getint(0, 2);
        switch (select){
        case 0:
            cout << "Aborted!" << endl;
            break;
        case 1:
            m_iProduct[m_numOfiProds] = new Perishable; 
            break;
        case 2:
            m_iProduct[m_numOfiProds] = new Item; 
            break;
        }

        if (select == 1 || select == 2) {
            int tempSku = m_iProduct[m_numOfiProds]->readSku(cin); 

            if (search(tempSku) != -1){
                cout << "Sku: " << tempSku << " is already in the system, try updating quantity instead." << endl;
                delete m_iProduct[m_numOfiProds];
                m_iProduct[m_numOfiProds] = nullptr;
            }
            else {
                m_iProduct[m_numOfiProds]->read(cin); 
                m_numOfiProds++;                      
            }
        }
        cout << endl;
    }

    void AidMan::remove(int index){
        delete m_iProduct[index]; 
        for (int i = index; i < m_numOfiProds; i++)
            m_iProduct[i] = m_iProduct[i + 1]; 
        m_numOfiProds--;                        
    }

    void AidMan::remove() {
        string desc;
        cout << "\n****Remove Item****\n"
            << "Item description: ";
        getline(cin, desc, '\n'); 
        list(desc.c_str());       

        int index = search(ut.getint(10000, 99999, "Enter SKU: "));
        if (index == -1) 
            cout << "SKU not found!" << endl;
        else {
            cout << "Following item will be removed: " << endl;
            m_iProduct[index]->linear(false);
            m_iProduct[index]->display(cout) << endl;
            cout << "Are you sure?" << endl
                << "1- Yes!" << endl
                << "0- Exit" << endl
                << "> ";

            switch (ut.getint(0, 1)){
            case 0:
                cout << "Aborted!" << endl;
                break;
            case 1:
                remove(index);
                cout << "Item removed!" << endl;
                break;
            }
        }
        cout << endl;
    }

    void AidMan::update()
    {
        int amount = -1;
        string desc;
        cout << "\n****Update Quantity****\n"
            << "Item description: ";
        getline(cin, desc, '\n'); 
        list(desc.c_str());       

        int index = search(ut.getint(10000, 99999, "Enter SKU: "));
        if (index == -1) 
            cout << "SKU not found!" << endl;
        else {
            cout << "1- Add" << endl
                << "2- Reduce" << endl
                << "0- Exit" << endl
                << "> ";

            switch (ut.getint(0, 2)){
            
            case 0:
                cout << "Aborted!" << endl;
                break;
            case 1:

                if (m_iProduct[index]->qty() == m_iProduct[index]->qtyNeeded()) 
                    cout << "Quantity Needed already fulfilled!" << endl;

                else{
                    amount = ut.getint(1, m_iProduct[index]->qtyNeeded(), "Quantity to add: ");
                    *m_iProduct[index] += amount;
                    cout << amount << " items added!" << endl;
                }
                break;

            case 2:
                if (m_iProduct[index]->qty() == 0) 
                    cout << "Quaintity on hand is zero!" << endl;

                else{
                    amount = ut.getint(1, m_iProduct[index]->qtyNeeded(), "Quantity to reduce: ");
                    *m_iProduct[index] -= amount;
                    cout << amount << " items removed!" << endl;
                }
                break;
            }
        }
        cout << endl;
    }

    void AidMan::sort(){
        iProduct* temp = nullptr;
        cout << "\n****Sort****\n";

        for (int i = 0; i < m_numOfiProds - 1; i++) {
            for (int j = 0; j < m_numOfiProds - i - 1; j++){

                if (m_iProduct[j]->qtyNeeded() - m_iProduct[j]->qty() <
                    m_iProduct[j + 1]->qtyNeeded() - m_iProduct[j + 1]->qty()) {
                    temp = m_iProduct[j];
                    m_iProduct[j] = m_iProduct[j + 1];
                    m_iProduct[j + 1] = temp;
                }
            }
        }
        cout << "Sort completed!" << endl << endl;
     }

    void AidMan::ship(){
        int shipped = 0;
        ofstream ofstr("shippingOrder.txt", ios::out);
        cout << "\n****Ship Items****\n";

        ofstr << "Shipping Order, Date: " << Date() << endl
            << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl
            << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
        for (int i = 0; i < m_numOfiProds; i++)
        {
            if (m_iProduct[i]->qtyNeeded() == m_iProduct[i]->qty())
            {
                ofstr.setf(ios::right);
                ofstr.width(4);
                ofstr << shipped + 1;
                ofstr << " | ";
                ofstr.unsetf(ios::right);
                m_iProduct[i]->linear(true);
                m_iProduct[i]->display(ofstr) << endl;
                remove(i);
                shipped++;
            }
        }
        ofstr << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl
            << endl;

        cout << "Shipping Order for " << shipped << " times saved!" << endl
            << endl;
    }

    void AidMan::exit() {
        cout << "Exiting Program!" << endl;
        save();
        deallocate();
    }

    void AidMan::run(){
        int select = -1;
        while (select != 0) {
            select = menu();
            if (select != 0 && select != 7 && m_fileName == nullptr) 
                select = 7;

            switch (select){
            case 0:
                exit();
                break;
            case 1:
                list();
                break;
            case 2:
                add();
                break;
            case 3:
                remove();
                break;
            case 4:
                update();
                break;
            case 5:
                sort();
                break;
            case 6:
                ship();
                break;
            case 7:
                load();
                break;
            }
        }
    }
} 