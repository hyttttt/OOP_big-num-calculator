#pragma once
#ifndef INTEGER_H
#define INTEGER_H
#include "Number.h"
using namespace std;

class Integer :public Number {
public:
	//constructor
	Integer(string);
	Integer(Integer&);

	//function
	Integer plus(const Integer&);
	Integer minus(const Integer&);
	Integer multiply(const Integer&);
	Integer divide(const Integer&);
	Integer power(const Integer&);
	Integer sqrt();
	Integer factorial();

	//operator overloading
	Integer& operator=(const Number&);

	Integer operator+(const Integer&);
	Integer operator-(const Integer&);
	Integer operator*(const Integer&);
	Integer operator/(const Integer&);

	Integer operator^(const Number&);
};

#endif // !INTEGER_H