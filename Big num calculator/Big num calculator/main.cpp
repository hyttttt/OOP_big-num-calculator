#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include"Decimal.h"

using namespace std;

int priority(string op) {
	if (op == "!")
		return 4;
	else if (op == "++" || op == "--") //positive and negative number
		return 3;
	else if (op == "*" || op == "/")
		return 2;
	else if (op == "+" || op == "-") //add and substract
		return 1;
	else
		return 0;
}

inline bool isSign(char pre) {
	if (isdigit(pre))
		return false;
	else
		return true;
}

void pushOrPop(vector<string>& postfix, stack<string>& opList, string op, bool left) {
	if (left)
	{
		while (opList.size() != 0 && opList.top() != "("
			&& priority(opList.top()) >= priority(op))
		{
			postfix.push_back(opList.top());
			opList.pop();
		}
	}
	else
	{
		while (opList.size() != 0 && opList.top() != "("
			&& priority(opList.top()) > priority(op))
		{
			postfix.push_back(opList.top());
			opList.pop();
		}
	}
}

void infixToPostfix(string infix, vector<string>& postfix) {
	string currNum;
	stack<string> opList;

	for (int i = 0; i < infix.size(); i++) {

		//positive or negative sign
		if ((infix[i] == '+' || infix[i] == '-') && (i == 0 || isSign(infix[i - 1]))) {

			string op;
			if (infix[i] == '+')	op = "++";
			else	op = "--";

			pushOrPop(postfix, opList, op, false);
			opList.push(op);

		}
		//mathematics operators
		else if (infix[i] == '*' || infix[i] == '/'
			|| infix[i] == '!' || infix[i] == '^'
			|| infix[i] == '+' || infix[i] == '-') {

			//put current number in postfix operation
			postfix.push_back(currNum);
			currNum.clear();

			//check whether to pop operator
			string op(1, infix[i]);
			pushOrPop(postfix, opList, op, true);

			//put operator into opList
			opList.push(op);
		}
		//left bracket
		else if (infix[i] == '(') {
			//put current number in postfix operation
			postfix.push_back(currNum);
			currNum.clear();

			//put operator into opList
			string op(1, infix[i]);
			opList.push(op);
		}
		//right bracket
		else if (infix[i] == ')') {
			//put current number in postfix operation
			postfix.push_back(currNum);
			currNum.clear();

			//pop all operators until meet left bracket
			while (opList.top() != "(")
			{
				postfix.push_back(opList.top());
				opList.pop();
			}
			opList.pop();
		}
		//number or varibale
		else {
			currNum.push_back(infix[i]);
		}
	}
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

}

inline bool isDec(string num) {
	if (num.find(".") != std::string::npos)
		return true;
	else
		return false;
}

inline void isVar(string str, map<string, string>& varList) {
	auto iter = varList.find(str);
	if (iter != varList.end())
		cout << varList[str] << endl;
	else
		cout << "Variable does not exist" << endl;
}

void setVar(string type, string var, string value, map<string, string>& varList) {
	if ((type == "int" || type == "Integer") && isDec(value)) {
		string::size_type end = value.find(".");
		value = value.substr(0, end - 0);
	}
	else if ((type == "float" || type == "Decimal") && !isDec(value)) {
		value += ".0";
	}

			}
			if (postfix[i] == "/") {
				integerA = integerA / integerB;

			}
			
			istack.push_back(integerA.value);
	varList[var] = value;
}

void splitInput(string input, vector<string>& inputVector) {
	string::size_type begin, end;
	string pattern = " ";

	begin = 0;
	end = input.find(pattern);

	while (end != std::string::npos) {
		if (end - begin != 0) {
			inputVector.push_back(input.substr(begin, end - begin));
		}
		begin = end + pattern.size();
		end = input.find(pattern, begin);
	}

	if (begin != input.length()) {
		inputVector.push_back(input.substr(begin));
	}
}

int main() {
	string input;

	while (getline(cin, input))
	{
		vector<string>inputVector;
		map<string, string>varList;

		splitInput(input, inputVector);

		//stop input
		if (input == "exit") {
			break;
		}

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
		else if (inputVector[0] == "set" || inputVector[0] == "Set" || inputVector[0] == "SET") {
			setVar(inputVector[1], inputVector[2], inputVector[4], varList);
		}

		//calculation
		else if (inputVector.size() == 1) {
			vector<string> postfix;
			infixToPostfix(input, postfix);
		}

		//output variable
		else {
			isVar(input, varList);
		}
	}
}