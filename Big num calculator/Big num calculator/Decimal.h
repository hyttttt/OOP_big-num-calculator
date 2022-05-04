#pragma once
#include "Integer.h"

class Decimal  {


public:
	string whole = "";
	string numerator = "";
	string denominator = "";

	Decimal& substring(string& a) {

		if (a.find('.', 0) != string::npos) {
			this->numerator = a.substr(0, a.find('.', 0));
			this->denominator = a.substr(a.find('.', 0) + 1, a.size() - a.find('.', 0));
		}
		else {
			this->numerator = a;
		}
		whole = a;

		return*this;
	}
	//constructor
	Decimal() {};
	Decimal(const char rhs[]) : whole(rhs) {
		substring(this->whole);
	}
	
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

	friend ostream& operator<<(ostream& os, Decimal& I) {
		os << I.numerator;
		if (I.denominator != "") {
			os << "." << I.denominator;
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
