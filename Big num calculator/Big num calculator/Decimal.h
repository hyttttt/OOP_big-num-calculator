#pragma once
#include "Integer.h"
#include <math.h>
class Decimal  {


public:
	string whole = "";
	string numerator = "";
	string denominator = "";


	string BigNumAdd(string l, string s);
	string BigNumMinus(string l, string s);
	string BigNumMultiply(string l, string s);
	string BigNumDivision(string l, string s);
	Decimal& About_minutes(string l, string s);

	Decimal& substring(string& a) {

		if (a.find('.', 0) != string::npos) {
			this->numerator = a.substr(0, a.find('.', 0))+ a.substr(a.find('.', 0) + 1, a.size() - a.find('.', 0));
			this->denominator = "1";
			for (int i = 0; i < a.size() - a.find('.', 0) - 1; i++) {
				this->denominator = this->denominator + "0";
			}
		}
		else {
			this->numerator = a;
			this->denominator = "1";
		}
		whole = a;

		return About_minutes(this->numerator, this->denominator = "1");
	}
	//constructor
	Decimal() {};
	Decimal(const char rhs[]) : whole(rhs) {
		substring(this->whole);
	}
	
	//function

	//operator overloading
	Decimal& operator=(const Decimal& rhs) {
		this->numerator = rhs.numerator;
		this->denominator = rhs.denominator;
		return *this;
	}
	Decimal& operator=(const Integer& rhs) {
		this->numerator = rhs.value;
		return *this;
	};
	Decimal operator=(string& rhs) {
		return this->substring(rhs);
	};


	Decimal operator+(const Decimal&rhs) {
		this->numerator=BigNumAdd( BigNumMultiply(this->numerator, rhs.denominator), BigNumMultiply(rhs.numerator, this->denominator));
		this->numerator = BigNumMultiply(this->denominator, rhs.denominator) ;
		return *this;
	};
	Decimal operator-(const Decimal&rhs) {
		this->numerator = BigNumMinus(BigNumMultiply(this->numerator, rhs.denominator), BigNumMultiply(rhs.numerator, this->denominator));
		this->numerator = BigNumMultiply(this->denominator, rhs.denominator);
		return *this;
	};
	Decimal operator*(const Decimal&rhs) {
		this->numerator = BigNumMultiply(this->numerator , rhs.numerator);
		this->denominator = BigNumMultiply(this->denominator , rhs.denominator);
		return About_minutes(this->numerator, this->denominator);
	};
	Decimal operator/(const Decimal&rhs) {
		this->numerator = BigNumMultiply(this->numerator, rhs.denominator);
		this->denominator = BigNumMultiply(this->denominator, rhs.numerator);
		return About_minutes(this->numerator, this->denominator);
	};
	Decimal operator^(const Decimal&);

	friend Decimal& operator+(Decimal& D, Integer& I) {
		return D;
	}friend Decimal& operator-(Decimal& D, Integer& I) {
		return D;
	}friend Decimal& operator*(Decimal& D, Integer& I) {
		return D;
	}friend Decimal& operator/(Decimal& D, Integer& I) {
		return D;
	}friend Decimal& operator^(Decimal& D, Integer& I) {
		return D;
	}friend Integer& operator+(Integer& I, Decimal& D ) {
		return I;
	}friend Integer& operator-(Integer& I, Decimal& D ) {
		return I;
	}friend Integer& operator*(Integer& I, Decimal& D ) {
		return I;
	}friend Integer& operator/(Integer& I, Decimal& D ) {
		return I;
	}friend Integer& operator^(Integer& I, Decimal& D ) {
		return I;
	}
	friend ostream& operator<<(ostream& os, Decimal& I) {
		os << I.BigNumDivision(I.numerator, I.denominator);

		string n = I.BigNumDivision(I.numerator, I.denominator);
		if (I.BigNumMultiply(n, I.denominator) != I.numerator) {
			os << ".";
			int i = 0;
			string input = I.BigNumMinus(I.numerator,I.BigNumMultiply(n, I.denominator) );
			while (input != "0"&&i<100) {
				i++;
				input = input + "0";
				n= I.BigNumDivision(input, I.denominator);
				input= I.BigNumMinus(I.numerator,I.BigNumMultiply(n, I.denominator));
				os << n;
			}
		}

		

		os << endl;
		return os;
	}
	friend istream& operator>>(istream& os, Decimal& I) {
		string a;
		os >> a;
		I = I.substring(a);
		return os;
	}
};
