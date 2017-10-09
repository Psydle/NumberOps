/* The Dynamically Linked list file
   Holds all of the Identifiers
*/
//#include "Identifier.h"
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Node { //this is the node, couldnt think of a name for our data
public:
	string idName;
	string idOp;
	int idValue;
	int pos;
	Node *child;
	Node *parent;
	Node(string name, string op, int value); //constructor
	Node(); //default contructor
	void printName();

};

Node::Node()
{
	cout << "Object Created: Node" << '\n';
	this->idName = "";
	this->idOp = "";
	this->idValue = 0;
	this->child = NULL;
	this->parent = NULL;
}

Node::Node(string name, string op, int value)
{
	cout << "Object Created: Node" << '\n';
	this->idName = name;
	this->idOp = op;
	this->idValue = value;
	this->child = NULL;
	this->parent = NULL;
}

void Node::printName()
{
	cout << "Print Name Function: " << idName  
		<< " " << idOp << " " << idValue << '\n';
}





class LinkedList { //the linked list class, holds all the values and functions within itself
private:
	//lol nothing
public:
	Node *head, *tail;
	int tailPos;
	LinkedList(); //constructor
	void createList(string name, string op, int value);
	int lookup(string str);
	void printList();
	void insertionSort(string name, string op, int value, int code);
	void incrementPos(Node *item);
	void insertStart(string name, string op, int value);
	void insertPos(string name, string op, int value, int pos);
	void performOperation(string name, string op, int value);

//commented out because should be defined outside of class
/*
void createList(string name, string op, int value)
{
	//Identifier *temp = new Identifier(name,op,value); //create new item
	Identifier *temp = Identifier(name, op, value);
	cout << '\n' << "WOOOOOOOOOOOOOWWWWWWW" << temp->idName; //tests that it was created successfully
	temp->child = NULL;
	temp->parent = NULL;
	if (head == NULL) //for the first added item
	{
		head = temp; //lets us point to this list
		tail = temp;
		tailPos = 0; //tail pos = 0 be default, increases to 1 when 2 items are in the list. etc.
		temp = NULL; //clears the temporary Identifier
	}
	else //if we messed up then append to the end
	{   
		tail->child = temp;
		tail = temp;
	}
}

int lookup(string str) //searches through the list for
                        //an item with an identical idName
	//returns pos(n - 1) where it should go
	//(n)1 - 1 = 0 means it should go before the head(1).
	// a pos = -1 means the item is already in the list
{
	Identifier *temp = new Identifier;
	int position = 0;

	temp = head;
	do //until you hit the end of the list
	{
		if (temp->idName == str)
		{
			return -1; //item in the list
		}
		else if (str.compare(temp->idName) < 0) //if idName (str) comes before temp lexicographically
		{
			return position;
		}
		else if (temp->child == NULL) //if tail of list
		{
			return (position + 1); //return a number 1 greater than the current tail position
		}
		temp = temp->child; //progress to next item
		position = (position + 1); //increment the returned position value to the next item
	} while (true) //leaving as true until i think of a better exit
}

void insertStart(Identifier temp)
{
	temp.child = head;
	head.parent = temp;

}
*/
};

LinkedList::LinkedList()
{
	cout << "Object Created: List" << '\n';
	this->head = NULL;
	this->tail = NULL;
	this->tailPos = NULL;
}


void LinkedList::createList(string name, string op, int value)
{
	Node *temp = new Node(name, op, value);
	//cout << '\n' << "WOO " << temp->idName << '\n'; //tests that it was created successfully
	temp->child = NULL;
	temp->parent = NULL;
	if (head == NULL) //for the first added item
	{
		cout << "We Made a Head!";
		head = temp; //lets us point to this list
		tail = temp;
		tailPos = 0; //tail pos = 0 be default, increases to 1 when 2 items are in the list. etc.
		head->pos = 0;
		temp = NULL; //clears the temporary node
	}
	else //append to the end
	{
		tail->child = temp;
		temp->parent = tail;
		temp->pos = (tail->pos + 1);
		tailPos = tailPos + 1;
		tail = temp;
	}
}


int LinkedList::lookup(string str) //searches through the list for
					   //an item with an identical idName
					   //returns pos(n - 1) where it should go
					   //(n)1 - 1 = 0 means it should go before the head(1).
					   // a pos = -1 means the item is already in the list
{
	//string str = cur.idName;
	Node *temp = head; //the pointer Node temp points to the head of the list Node
	int position = 0;

	temp = head;
	do //until you hit the end of the list
	{
		if (temp->idName == str)
		{
			return -1; //item in the list
		}
		else if (str.compare(temp->idName) < 0) //if idName (str) comes before temp lexicographically
		{
			return position;
		}
		else if (temp->child == NULL) //if tail of list
		{
			return (position + 1); //return a number 1 greater than the current tail position
		}
		temp = temp->child; //progress to next item
		position = (position + 1); //increment the returned position value to the next item
	} while (true);//leaving as true until i think of a better exit
}

void LinkedList::printList()
{
	Node *temp = new Node();
	//cout << "SUPER TEST YEAH DUDE " << temp->idName;             //error test 10-8-2017
	temp = this->head;
	//test to see if head exists
	if (head == NULL)
	{
		cout << "Head is NULL dude " << '\n';
	}

	while (temp != NULL) //while not on the tail
	{
		temp->printName();
		temp = temp->child;
	}
	//then print the last one
	//temp->printName();
}

void LinkedList::insertionSort(string name, string op, int value, int code)
{
	if (code == 0)
	{
		this->insertStart(name, op, value);
	}
	else if (code > tailPos)
	{
		createList(name, op, value);
	}
	else
	{
		insertPos(name, op, value, code); //LEFT OFF HERE 10-8-17 17:17
	}
}

void LinkedList::incrementPos(Node *item)
{
	item = item->child;
	while (item != NULL)
	{
		item->pos++;
		item = item->child;
	}
	tailPos++;
}

void LinkedList::insertStart(string name, string op, int value) //10-4-2017 11:13 AM
{
	Node *newGuy = new Node(name, op, value);
	newGuy->child = head;
	newGuy->pos = 0;
	head->parent = newGuy;
	head = newGuy;                            //10-04-2017 11:28 AM
	incrementPos(newGuy);
	
	//test to see if inserted at head
	cout << "We changed the head to: ";
		head->printName();
		cout << "Head child is: ";
		head->child->printName();
}

void LinkedList::insertPos(string name, string op, int value, int pos)
{
	Node *temp = new Node();
	Node *newGuy = new Node(name, op, value);

	temp = head;
	for (int i = 0; i < pos; i++)
	{
		temp = temp->child;
	}

	newGuy->parent = temp->parent;
	newGuy->child = temp;
	newGuy->pos = temp->pos;
	temp->parent->child = newGuy;
	incrementPos(newGuy);
}

/* Operations are as follows:
= assign value
+= add value to current value
-= subtract value from current value
*= multiply current value by new value
/= divide current value by new value
*/
void LinkedList::performOperation(string name, string op, int value) 
{ //handles all operations
	Node *temp = new Node();
	temp = head;
	cout << "\nName of Node should be: " << name;     //TEST FOR CORRECT NAME
	while (temp->idName != name) {
			temp = temp->child;
	}
	if (temp == NULL) //catches an error
	{
		cout << "ERROR WITH PERFORM OP";
	}
	cout << "\nName of Node   is   be: " << temp->idName << '\n';     //TEST FOR CORRECT NAME

	//perform operation if statement hell:
	//if (op == "=") temp->idValue = value;
	if (op == "+=") temp->idValue += value;
	if (op == "-=") temp->idValue = temp->idValue - value;
	if (op == "*=") temp->idValue = temp->idValue * value;
	if (op == "/=") temp->idValue = temp->idValue / value;
	
	return;
}