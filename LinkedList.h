// This is start of the header guard.  ADD_H can be any unique name.  By convention, we use the name of the header file.
#ifndef LinkedList_h
#define LinkedList_h

// This is the content of the .h file, which is where the declarations go
#include <string>
#include <iostream>


using namespace std;

class Node {
public:
	string idName;
	string idOp;
	int idValue;
	int pos;
	Node *child;
	Node *parent;
	Node(string name, string op, int value);
	Node();
	void printName();
};

class LinkedList
{
	//trying to make all of this data public instead
private:
	//Identifier *head, *tail;
	//int *tailPos;

public:
	Node *head, *tail;
	int tailPos;
	LinkedList();
	void createList(string name, string op, int value);
	int lookup(string str);
	void printList();
	void insertionSort(string name, string op, int value, int code);
	void incrementPos(Node *item);
	void insertStart(string name, string op, int value);
	void insertPos(string name, string op, int value, int pos);
	void performOperation(string name, string op, int value);
};

// This is the end of the header guard
#endif