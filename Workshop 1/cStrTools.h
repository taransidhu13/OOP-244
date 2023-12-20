/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #1 (P1)
Full Name  : Tarandeep Kaur
Student ID#: 139389225
Email      : tarandeep-kaur6@myseneca.ca
Section    : ZEE
Authenticity Declaration:
I declare this submission is the result of my own work. I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments. It has not been
shared with any other student or 3rd party content provider.
/////////////////////////////////////////////////////////////////////////*/


#ifndef SDDS_CSTRTOOLS_H 
#define SDDS_CSTRTOOLS_H
namespace sdds {


    char toLower(char ch);
    int strCmp(const char* s1, const char* s2);
    int strnCmp(const char* s1, const char* s2, int len);
    void strCpy(char* des, const char* src);
    int strLen(const char* str);
    const char* strStr(const char* str, const char* find);
    int isAlpha(char ch);
    int isSpace(char ch);
    void trim(char word[]);
    void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif