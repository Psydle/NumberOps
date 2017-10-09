/*The doubly linked list data type.
* Holds the name, value, previous item, next item
* Possibly holds the operator fuctions as well, not sure yet
* 
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

//int idValue = 0;
//string idName = ""; defining it here caused errors
//string idOp = "";

class Identifier {
public:
	string idName;
	string idOp;
	int idValue;
	Identifier *child;
	Identifier *parent;
	Identifier(string name, string op, int value); //constructor
	void printName();

};

Identifier::Identifier(string name, string op, int value)
{
	cout << "Object Created: Identifier" << '\n';
	this->idName = name;
	this->idOp = op;
	this->idValue = value;
	this->child = NULL;
}

void Identifier::printName()
{
	cout << "Print Name Function: " << idName << '\n';
}
