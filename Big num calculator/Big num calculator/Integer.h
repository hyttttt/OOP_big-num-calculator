#pragma once
#include <algorithm>
#include<iostream>
#include<string>
using namespace std;




class Integer {
public:
	string value;
	//constructor
	Integer() {};
	Integer(const char rhs[]) : value(rhs) {};
	//function

	string BigNumAdd(string l, string s);
	string BigNumMinus(string l, string s);
	string BigNumMultiply(string l, string s);
	string BigNumDivision(string l, string s);
	//operator overloading
	Integer operator=(const Integer& rhs) {
		this->value = rhs.value;
		return *this;
	}
	Integer operator=(string& rhs) {
		this->value = rhs;
		return *this;
	};
	Integer operator+(Integer& rhs) {
		Integer tmp;
		tmp.value = Integer::BigNumAdd(this->value, rhs.value);
		return tmp;
	}
	Integer operator-(Integer& rhs) {
		Integer tmp;
		tmp.value = Integer::BigNumMinus(this->value, rhs.value);
		return tmp;
	}
	Integer operator*(Integer& rhs) {
		Integer tmp;
		tmp.value = Integer::BigNumMultiply(this->value, rhs.value);
		return tmp;
	}
	Integer operator/(const Integer& rhs) {
		Integer tmp;
		tmp.value = Integer::BigNumDivision(this->value, rhs.value);
		return tmp;
	};Integer operator^(const Integer& rhs) {
		Integer tmp;
		tmp.value = Integer::BigNumDivision(this->value, rhs.value);
		return tmp;
	};
	friend ostream& operator<<(ostream& os, Integer& I) {
		os << I.value;
		return os;
	}
	friend istream& operator>>(istream& os, Integer& I) {
		os >> I.value;
		return os;
	}
};
