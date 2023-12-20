/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #1 (P2)
Full Name  : Tarandeep Kaur
Student ID#: 139389225
Email      : tarandeep-kaur6@myseneca.ca
Section    : ZEE
Authenticity Declaration:
I declare this submission is the result of my own work. I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. It has not been
shared with any other student or 3rd party content provider.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include "Phone.h"
#include "cStrTools.h"

using namespace std;
namespace sdds {

    void phoneDir(const char* programTitle, const char* fileName) {
      
        cout << programTitle << " phone direcotry search" << endl;
        cout << "-------------------------------------------------------" << endl;

        FILE* file = fopen(fileName, "r");

        if (!file) {
            cout << fileName << " file not found!" << endl;
            cout << "Thank you for using " << programTitle << " directory." << endl;
            cout << endl;
            cout << "Press any key to close this window . . ." << endl;
            return;
        }

        char partialName[51]; // Max length for a name is 50 characters

        while (true) {
            
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
            cout << "> ";
            cin.getline(partialName, sizeof(partialName));

            if (partialName[0] == '!') {
                break;
            }

            
            char record[40]; 

            rewind(file); // Move the file pointer back to the beginning

            char lowercasePartialName[51];
            toLowerCaseAndCopy(lowercasePartialName, partialName);
            

            while (fgets(record, sizeof(record), file)) {
                char name[51], areaCode[4], prefix[4], number[5];
                sscanf(record, "%[^\t]\t%s\t%s\t%s", name, areaCode, prefix, number);

                char lowercaseName[51];
                toLowerCaseAndCopy(lowercaseName, name);
                

                if (strStr(lowercaseName, lowercasePartialName)) {
                    cout << name << ": (" << areaCode << ") " << prefix << "-" << number << endl;
                    
                }
            }

           
        }

        fclose(file);
        cout << "Thank you for using " << programTitle << " directory." << endl;
    }

}


