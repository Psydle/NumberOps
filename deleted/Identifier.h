// This is start of the header guard.  ADD_H can be any unique name.  By convention, we use the name of the header file.
#ifndef Identifier_h
#define Identifier_h

// This is the content of the .h file, which is where the declarations go
#include <string>

using namespace std;

class Identifier {
public:
	string idName;
	string idOp;
	int idValue;
	Identifier *child;
	Identifier *parent;
	Identifier(string name, string op, int value);
	void printName();
};

					   // This is the end of the header guard
#endif