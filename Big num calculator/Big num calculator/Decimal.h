#pragma once
#ifndef DECIMAL_H
#define DECIMAL_H
#include "Number.h"
#include "Integer.h"

class Decimal :public Number{
public:
	//member
	string numerator;
	string denominator;

	//constructor
	Decimal(string);
	Decimal(Decimal&);

	//function
	Decimal plus(const Decimal&);
	Decimal minus(const Decimal&);
	Decimal multiply(const Decimal&);
	Decimal divide(const Decimal&);

	Decimal plus(const Integer&);
	Decimal minus(const Integer&);
	Decimal multiply(const Integer&);
	Decimal divide(const Integer&);
	Decimal power(const Integer&);
	Decimal sqrt();
	Decimal factorial();

	//operator overloading
	Decimal& operator=(const Decimal&);
	Decimal& operator=(const Integer&);

	Decimal operator+(const Decimal&);
	Decimal operator-(const Decimal&);
	Decimal operator*(const Decimal&);
	Decimal operator/(const Decimal&);
	Decimal operator^(const Decimal&);

	Decimal operator+(const Integer&);
	Decimal operator-(const Integer&);
	Decimal operator*(const Integer&);
	Decimal operator/(const Integer&);
	Decimal operator^(const Integer&);

	friend Decimal operator+(const Integer&, const Decimal&);
	friend Decimal operator-(const Integer&, const Decimal&);
	friend Decimal operator*(const Integer&, const Decimal&);
	friend Decimal operator/(const Integer&, const Decimal&);
};

#endif // !DECIMAL_H