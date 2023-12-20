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


#include <iostream>
#include "Word.h"
using namespace sdds;
using namespace std;
int main() {
	char filename[256];
	programTitle();
	cout << "Enter filename: ";
	cin >> filename;
	wordStats(filename);
	return 0;
}
