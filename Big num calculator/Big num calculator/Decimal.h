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
	string saveWhole(Decimal a) {
		string r= a.BigNumDivision(a.numerator, a.denominator);

		string n = a.BigNumDivision(a.numerator, a.denominator);
		if (a.BigNumMultiply(n, a.denominator) != a.numerator) {
			r=r+ ".";
			int i = 0;
			string input = a.BigNumMinus(a.numerator, a.BigNumMultiply(n, a.denominator));
			while (input != "0" && i < 100) {
				i++;
				input = input + "0";
				n = a.BigNumDivision(input, a.denominator);
				input = a.BigNumMinus(a.numerator, a.BigNumMultiply(n, a.denominator));
				r=r+ n;
			}
		}



		return r;
	}
	//function

	//operator overloading
	Decimal& operator=(const Decimal& rhs) {
		this->numerator = rhs.numerator;
		this->denominator = rhs.denominator;
		this->whole = saveWhole(*this);
		return *this;
	}
	Decimal& operator=(const Integer& rhs) {
		this->numerator = rhs.value;
		this->denominator = "1";
		this->whole = saveWhole(*this);
		return *this;
	};
	Decimal operator=(string& rhs) {
		*this=substring(rhs);
		this->whole = saveWhole(*this);
		return *this;
	};


	Decimal operator+(const Decimal&rhs) {
		this->numerator=BigNumAdd( BigNumMultiply(this->numerator, rhs.denominator), BigNumMultiply(rhs.numerator, this->denominator));
		this->numerator = BigNumMultiply(this->denominator, rhs.denominator) ;
		this->whole = saveWhole(*this);
		return *this;
	};
	Decimal operator-(const Decimal&rhs) {
		this->numerator = BigNumMinus(BigNumMultiply(this->numerator, rhs.denominator), BigNumMultiply(rhs.numerator, this->denominator));
		this->numerator = BigNumMultiply(this->denominator, rhs.denominator);
		this->whole = saveWhole(*this);
		return *this;
	};
	Decimal operator*(const Decimal&rhs) {
		this->numerator = BigNumMultiply(this->numerator , rhs.numerator);
		this->denominator = BigNumMultiply(this->denominator , rhs.denominator);
		*this = About_minutes(this->numerator, this->denominator);
		this->whole = saveWhole(*this);
		return *this;
	};
	Decimal operator/(const Decimal&rhs) {
		this->numerator = BigNumMultiply(this->numerator, rhs.denominator);
		this->denominator = BigNumMultiply(this->denominator, rhs.numerator);
		*this = About_minutes(this->numerator, this->denominator);
		this->whole = saveWhole(*this);
		return *this;
	};
	Decimal operator^(const Decimal&D) {
		return D;
	};

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
		
		return os;
	}
	friend istream& operator>>(istream& os, Decimal& I) {
		string a;
		os >> a;
		I = I.substring(a);
		return os;
	}
};
