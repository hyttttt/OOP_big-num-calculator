#pragma once
#ifndef INTEGER_H
#define INTEGER_H
#include <algorithm>
using namespace std;

string BigNum();



class Integer{
public:
	string value;
	//constructor
	Integer(){};
	Integer(const char rhs[]) : value(rhs) {};
	//function
	Integer plus(const Integer&);
	Integer minus(const Integer&);
	Integer multiply(const Integer&);
	Integer divide(const Integer&);
	Integer power(const Integer&);
	Integer sqrt();
	Integer factorial();
	string BigNumAdd(string l, string s);
	string BigNumMinus(string l, string s);
	string BigNumMultiply(string l, string s);
	string BigNumDivision(string l, string s);


	//operator overloading
	Integer operator=(const Integer& rhs){
		this->value = rhs.value;
		return *this;
	}
	Integer operator=(string& rhs){
		this->value = rhs;
		return *this;
	};
	Integer operator+(Integer& rhs){
		Integer tmp;
	    tmp.value = Integer::BigNumAdd(this->value,rhs.value);
		return tmp;
	}
	Integer operator-(Integer& rhs){
		Integer tmp;
		tmp.value = Integer::BigNumMinus(this->value, rhs.value);
		return tmp;
	}
	Integer operator*(Integer& rhs){
		Integer tmp;
		tmp.value = Integer::BigNumMultiply(this->value, rhs.value);
		return tmp;
	}
	Integer operator/(Integer& rhs){
		Integer tmp;
		tmp.value = Integer::BigNumDivision(this->value, rhs.value);
		return tmp;
	}
	friend ostream& operator<<(ostream& os, Integer& I){
		os << I.value;
		return os;
	}
	friend istream& operator>>(istream& os, Integer& I){
		os >> I.value;
		return os;
	}
};

#endif // !INTEGER_H