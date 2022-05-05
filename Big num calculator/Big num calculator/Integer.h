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
	bool DivJudgement(string l, string r);
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
		Integer tmp=rhs;
		Integer tmp2=rhs;
		
		while (tmp2.value != "1") {
			tmp2.value = tmp2.BigNumMinus(tmp2.value, "1");
			tmp.value = tmp.BigNumMultiply(tmp.value, tmp2.value);
			cout << tmp.value << "\n";
		}
		return tmp;
	}; 
	Integer changeSign() {
		this->value=BigNumDivision("0", this->value);

		return *this;
	};
	Integer factorial(){
		string r = "1";
		string g = this->value;
		while (g != "1") {
			
			r = BigNumMultiply(r, g);
			g = BigNumMinus(g, "1");
			
		}
		this->value = r;
		return *this;
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
