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

#include "cStrTools.h"

namespace sdds {
    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
        return ch;
    }

    int strCmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return s1[i] - s2[i];
    }

    int strnCmp(const char* s1, const char* s2, int len) {
        int i = 0;
        while (i < len - 1 && s1[i] && s2[i] && s1[i] == s2[i]) {
            i++;
        }
        return s1[i] - s2[i];
    }

    void strCpy(char* des, const char* src) {
        int i;
        for (i = 0; src[i]; i++) des[i] = src[i];
        des[i] = 0;
    }

    int strLen(const char* str) {
        int len;
        for (len = 0; str[len]; len++);
        return len;
    }

    const char* strStr(const char* str, const char* find) {
        const char* faddress = nullptr;
        int i, flen = strLen(find), slen = strLen(str);
        for (i = 0; i <= slen - flen && strnCmp(&str[i], find, flen); i++);
        if (i <= slen - flen) faddress = &str[i];
        return faddress;
    }

    int isAlpha(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    int isSpace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
    }

    void trim(char word[]) {
        int i;
        while (word[0] && !isAlpha(word[0])) {
            strCpy(word, word + 1);
        }
        i = strLen(word);
        while (i && !isAlpha(word[i - 1])) {
            word[i-- - 1] = 0;
        }
    }

    void toLowerCaseAndCopy(char des[], const char source[]) {
        int i = 0, j = 0;
        for (; source[i] != 0; i++) {
            des[j++] = toLower(source[i]);
        }
        des[j] = 0;
    }
}