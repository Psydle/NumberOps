/* Luke Young
*  Programming Assignment 1, Identifier operations
*  Due October 4th, 2017
*  EECS 2510
*
* Brief: Read in a text file containing strings in the format: "identifier operator value"
         Assign each unique identifier a value and sort lexicographically
		 When a repeat name occurs, preform the operation specified in the new string
		 Print out result with up to 100 unique identifiers
*/

// NumberOps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include "LinkedList.h"


using namespace std;

int readFile();
LinkedList theList; //our main list to hold values

int main() {
	int a = 50;
	cout << "Value of 'a' = " << a << endl; //display value of a in console

	readFile();

	system("pause"); //keeps window open until user presses a key
    return 0;
}

int readFile() //reads in the file word by word, assuming correct format
{
	string idName;
	int idValue;
	int code; //int to determine what the current line should do
	string idOp;

	ifstream file;
	file.open("numbers.txt");
	if (!file.is_open()) return 0;

	string word;
	//initiate the linked list with the first object
	file >> word;
	idName = word;
	file >> word;
	idOp = word;
	file >> word;
	idValue = std::stoi(word);

	Node *initial = new Node(idName, idOp, idValue);
	Node *temp2 = new Node();                      //EXTRA 10-8-2017
	

	cout << "this is the idName: " << initial->idName << '\n';
	initial->printName();

	LinkedList theList = LinkedList();
	theList.createList(idName, idOp, idValue);
	initial = theList.head;
	cout << "The head name is: " << theList.head->idName << '\n';
	

	while (file >> word)
	{
		//first value should be the name
		cout << word << " "; //outputs name
		idName = word; //store name variable temprarily
		file >> word;
		cout << word << " "; //debugging input of file
		idOp = word;
		file >> word;
		cout << word << '\n'; //debugging input of file
		idValue = std::stoi(word);
		
		//test lookup codes
		code = theList.lookup(idName);             //error in lookup? 10-8-17 4:11pm
		cout << "Return code: " << code << '\n';
		//Insert based on code
		if (code != -1)
		{
			theList.insertionSort(idName, idOp, idValue, code);
		}
		else if (code == -1)
		{
			theList.performOperation(idName, idOp, idValue);
		}
		//else if already in the list
		//performOp();
		   
	}
	theList.printList();                 //possible Error
	return 0;
}

/* Operations are as follows:
 = assign value
+= add value to current value
-= subtract value from current value
*= multiply current value by new value
/= divide current value by new value
*/
int performOperation() { //handles all operations
	return 0;
}

