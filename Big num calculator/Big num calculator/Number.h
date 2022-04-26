#pragma once
#ifndef NUMBER_H
#define	NUMBER_H
#include <string>
using namespace std;

class Number {
public:
	//member
	string num;

	//constructor
	Number(string);
	Number(Number&);

	//function
	void changeSign();

	//operator overloading
	Number& operator=(const Number& n);
};

#endif // !NUMBER_H