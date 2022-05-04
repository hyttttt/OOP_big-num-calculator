#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include "Decimal.h"

using namespace std;
class VariableInfo {
public:
	int vType;
	Decimal decimal= Decimal();
	Integer integer = Integer();
	VariableInfo() {
		decimal= Decimal();
		integer = Integer();
	}
};


map < string, VariableInfo > variable = map < string, VariableInfo >();

int priority(string op) {
	if (op == "+" || op == "-") {
		return 1;
	}
	else if (op == "*" || op == "/") {
		return 2;
	}
	else if (op == "^") {
		return 4;
	}
	else if (op == "!") {
		return 5;
	}
	return 0;
}

vector<string> infixToPostfix(vector<string> infix) {
	vector<string>istack;
	vector<string>output;
	istack.clear();
	output.clear();



	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == "(") {
			istack.push_back(infix[i]);
		}
		else if (infix[i] == "+" || infix[i] == "-" || infix[i] == "*" || infix[i] == "/") {
			if (istack.size() == 0 || istack[istack.size() - 1] == "(") {
				istack.push_back(infix[i]);
			}
			else if (priority(istack[istack.size() - 1]) < priority(infix[i])) {
				istack.push_back(infix[i]);
			}
			else {
				output.push_back(istack[istack.size() - 1]);
				istack.pop_back();
				istack.push_back(infix[i]);
			}
		}
		else if (infix[i] == ")") {
			while (istack[istack.size() - 1] != "(") {
				output.push_back(istack[istack.size() - 1]);
				istack.pop_back();
			}
			istack.pop_back();
		}
		else {
			output.push_back(infix[i]);
		}
	}
	output.pop_back();
	while (istack.size() > 0) {
		output.push_back(istack[istack.size() - 1]);
		istack.pop_back();
	}
	return output;
}

string calculate(vector<string> postfix) {
	vector<string>istack;
	for (int i = 0; i < postfix.size(); i++) {
		   if (postfix[i] == "+" || postfix[i] == "-" || postfix[i] == "*" || postfix[i] == "/" || postfix[i] == "^") {
			string A = istack[istack.size()-2];
			Integer integerA = Integer();
			if (variable.find(istack[istack.size() - 2]) != variable.end()) {
				integerA = variable[istack[istack.size() - 2]].integer;
			}
			else {
				integerA = istack[istack.size() - 2];
			}
            

			
			string B = istack[istack.size() - 1];
			Integer integerB = Integer();
			if (variable.find(istack[istack.size() - 1]) != variable.end()) {
				integerB = variable[istack[istack.size() - 1]].integer;
			}
			else {
				integerB = istack[istack.size() - 1];
			}

			
			
			istack.pop_back();
			istack.pop_back();

			if (postfix[i] == "+") {
				integerA = integerA + integerB;
				
			}
			if (postfix[i] == "-") {
				integerA = integerA - integerB;

			}
			if (postfix[i] == "*") {
				integerA = integerA * integerB;

			}
			if (postfix[i] == "/") {
				integerA = integerA / integerB;

			}
			
			istack.push_back(integerA.value);

		}
		else if (postfix[i] == "!") {

		}
		else {
			istack.push_back(postfix[i]);
		}
	}
	if (variable.find(istack[0]) != variable.end()) {
		return variable[istack[0]].integer.value;
	}
	return istack[0];
}

int main() {
	string input;
	while (true)
	{
		getline(cin, input);
		stringstream ss;
		ss.str("");
		ss.clear();

		string temp=input;
		ss << temp;

		ss >> temp;

		//stop input
		if (temp == "exit")	break;

		//set variable
		else if (temp == "set" || temp == "Set" || temp == "SET") {

			
			string name;
			string garbageMessage;
			string value;
			ss >> temp;
			//get name
			ss >> name;
			ss >> garbageMessage;
			ss >> value;
			
			if (temp == "int" || temp == "Integer") {
				//get type

				if (variable.find(name) != variable.end()) {
					variable[name].vType = 0;
					variable[name].integer = value;
				}
				else {
					VariableInfo variableInfo = VariableInfo();
					variableInfo.vType = 0;
					variableInfo.integer = value;
					variable.insert({ name, variableInfo });
				}
			}
			else if (temp == "float" || temp == "Decimal") {
				//get type

				if (variable.find(name) != variable.end()) {
					variable[name].vType = 1;
					variable[name].decimal = value;
				}
				else {
					VariableInfo variableInfo = VariableInfo();
					variableInfo.vType = 1;
					variableInfo.decimal = value;
					variable.insert({ name, variableInfo });
				}
				cout << variable[name].decimal.denominator;
			}
		}
		//calculation
		else if(input.find("=",0)==string::npos) {
			vector<string>stemp;
			stemp.clear();
			stemp.push_back(temp);
			while (ss) {
				temp = "";
				ss >> temp;
				stemp.push_back(temp);
			}
			vector <string> postfix = infixToPostfix(stemp);
			string result = calculate(postfix);
			cout << result << "\n";
		}
		else {
			vector<string>stemp;
			stemp.clear();
			string temp2 = "";
			ss >> temp2;
			while (ss) {
				temp2 = "";
				ss >> temp2;
				stemp.push_back(temp2);
			}
			if (variable.find(temp) != variable.end()) {
				vector <string> postfix = infixToPostfix(stemp);
				if (variable[temp].vType) {
					string result = calculate(postfix);
						variable[temp].decimal = result;
				}
				else {
					string result = calculate(postfix);
					variable[temp].integer = result;
				}
			}
			else {

			}
		}
	}
}