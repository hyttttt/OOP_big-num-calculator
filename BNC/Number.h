#pragma once
#ifndef NUMBER_H
#define	NUMBER_H
#include <string>
using namespace std;

class Number {
public:
	//member
	string name;
	//constructor

	//function
	void changeSign();

	//operator overloading
	Number& operator=(const Number& n);
};

#endif // !NUMBER_H