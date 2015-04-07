/**  
*  @file    main.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    03/25/2014  
*  @version 2.0  
*
*  @brief CSC 112, Lab 8, Inventory Database
*
*  @section DESCRIPTION
*
*  This program maintains a company's inventory database
*  where each product has a unique ID number. The program
*  can remove duplicate entries, sort entires, and add or
*  delete ID numbers from the database.
*
*  @bug No known bugs
*
*/



#include <iostream>
#include <fstream>
#include <cstdlib>
#include "database.h"
using namespace std;



int main(int argc, char* argv[])
{

	int* list = 0;		///< Dynamic database array
	int value;		///< ID number values in the database
	int n = 0;		///< Number of entries in the array (logical size)
	char action;		///< Letter indicating action-code from file
	int loc;		///< Location of a deletion from the database  
	
	if(argc < 4)
	{
		cerr << "Usage: " << argv[0] << " inventory update final" << '\n';
		cout << "Error, please enter three valid file names" << '\n';	
		return 1;
	}

	string inFileName = argv[1];
	fstream inFile(inFileName.c_str(), ios :: in);

	while(inFile >> value)
	{
		if(search(value, list, n) == -1)
			storeValue(value, list, n);
	}

	inFile.close();

	cout << "Reading " << inFileName << '\n';
	cout << "Database has " << n << " ID numbers" << " and requires " << sizeof(int)*n << " bytes" << '\n';
	cout << "---------------------------------------------------" << '\n';

	string upFileName = argv[2];
	fstream upFile(upFileName.c_str(), ios :: in);
	

	while(upFile >> action >> value) 
	{
		if(action == 'a' || action == 'A')
		{
			if(search(value, list, n) == -1)
				storeValue(value, list, n);
		}
		else if(action == 'd' || action == 'D')
		{
			loc = search(value, list, n);
			if(loc != -1)
				deleteValue(loc, list, n);
		}

	}
	
	cout << "Reading " << upFileName << '\n';
	cout << "Updated database" << '\n';
	cout << "Database has " << n << " ID numbers" << " and requires " << sizeof(int)*n << " bytes" << '\n';
	cout << "---------------------------------------------------" << '\n';

	writeFile(value, list, n, argv);



	return 0;

}



