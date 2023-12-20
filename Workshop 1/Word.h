#pragma once

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

#ifndef SDDS_WORD_H 
#define SDDS_WORD_H
#include <cstdio>

namespace sdds {
    const int MAX_WORD_LEN = 21;
    

    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };

    int searchWords(const Word words[], int num, const char word[]);
    int readWord(char* word, FILE* fptr, int maxLen);
    void addWord(Word words[], int* index, const char newWord[]);
    void title(const char* value, int len);
    void endList();
    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
    void print(const Word* w, int gotoNextLine, int len);
    int findMaxLen(const Word words[], int noOfWords);
    void listWords(const Word words[], int noOfWords, const char* theTitle);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt, int sortType);
    int totalCount(const Word* words, int num);
    void wordStats(const char* filename);
    void programTitle();
}

#endif