#pragma once
/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
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
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	bool read(char*& name);
	bool read(int& empNo);
	bool read(double& salary);
}

#endif