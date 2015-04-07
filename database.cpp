/**  
*  @file    database.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    03/25/2014  
*  @version 2.0  
*
*  @brief CSC 112, Lab 8, Inventory Database
*
*  @section DESCRIPTION
*
*  database.cpp is the source file that contains the function
*  defintions that can be utitlized in a program that maintains
*  a company's inventory database.
*
*  @bug No known bugs
*
*/



#include "database.h"
using namespace std;



/**
*  @brief search is a function that searches the database to
*  ensure that all the values are in the array and are unique.
*
*
*  @param value is a variable for each ID number read 
*  @param list is the database array of product ID numbers
*  @param n is the logical size of the array 
*
*  @return the location of the value in the array
*/
int search(int& value, int* list, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(value == list[i])
			return i;
	}
	
	return -1;

}



/**
*  @brief storeValue is a function that stores the unique ID
*  values in ascending order in the list array
*
*  @param value is an ID number in the database
*  @param list is the database array of product ID numbers
*  @param n is the logical size of the array
*
*  @return void
*/
void storeValue(int value, int*& list, int& n)
{
	int* tempList = new (nothrow) int[n + 1]; ///< Temporary array for storing entries in list
	int temp;			///< Temporary array for sorting into ascending order 
	bool done = false;		///< Boolean testing if values are in ascending order
	
	for(int i = 0; i < n; i++)
	{
		tempList[i] = list[i];
	}

	tempList[n] = value;
	if(list) 
		delete[] list;

	list = tempList;
	n++;

	while(!done)
	{
		done = true;

		{
			for(int k = 1; k < (n - 1); k++)
			{
				if(list[k] < list[k + 1])
				{
					done = false;
					temp = list[k + 1];
					list[k + 1] = list[k];
					list[k] = temp;
				}
			}
		}
					
	}
}



/**
*  @brief deleteValue is a function that deletes specified
*  values in the database array
*
*  @param loc is the location of the deletion
*  @param list is the database array of product ID numbers
*  @param n is the logical size of the array
*
*  @return void
*/
void deleteValue(int loc, int*& list, int& n)
{
	int* tempList = new (nothrow) int[n - 1]; ///< Temporary array for deleting from dynamic list
	if((tempList == 0))
	{
		exit(1);
	}

	int i;				///< Counter 
	for(i = 0; i < loc; i++)
	{
		tempList[i] = list[i];
	}
	for(i = loc; i < (n - 1); i++)
	{
		tempList[i] = list[i + 1];
	}

	n--;

	if(list)
		delete[] list;
	list = tempList;	

}



/**
*  @brief writeFile is a function that writes the updated
*  database information from the array into a new file to
*  print to the screen
*
*  @param value is an ID number in the database
*  @param list is the database array of product ID numbers
*  @param n is the logical size of the array
*  @param argv is the command line argument from user
*
*  @return void
*/
void writeFile(int value, int* list, int n, char* argv[])
{
	string dataFileName = argv[3];
	fstream dataFile(dataFileName.c_str(), ios :: out);
	
	for(int i = 0; i < n; i++)
	{
		dataFile << list[i]; 
		dataFile << endl;
	}

	dataFile.close();

	cout << "Output written to " << dataFileName << '\n';

}



