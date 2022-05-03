#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include"Decimal.h"

using namespace std;
class VariableInfo {
	//vType 0為Integer 1為Decimal 
public: 
	int vType;
	//
    string value;
	
};


//儲存變數資訊
map < string, VariableInfo > variable = map < string, VariableInfo >();

int priority(string op) {
	if (op == "+"  || op == "-") {
		return 1;
	}
	if (op == "*" || op == "/") {
		return 2;
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
		else if (infix[i]=="+" || infix[i] == "-" || infix[i] == "*" || infix[i] == "/") {
			if (istack.size()==0 || istack[istack.size() - 1] == "(") {
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
	while (istack.size() != 0) {
		output.push_back(istack[istack.size() - 1]);
		istack.pop_back();
	}
	return output;
}

string calculate(vector<string> postfix) {
	vector<string>istack;
	for (int i = 0; i < postfix.size(); i++) {
		
	}
	return variable[postfix[0]].value;
}

int main() {
	string input;

	
	
	
	while (true)
	{
		getline(cin, input);
		stringstream ss;
		ss.str("");
		ss.clear();

		string temp;
		ss << input;

		ss >> temp;

		//stop input
		if (temp == "exit")	break;

		//set variable
		else if (temp=="set"|| temp == "Set"|| temp == "SET") {

			VariableInfo variableInfo = VariableInfo();
			string name;
			string garbageMessage;
			ss >> temp;
			//get name
			ss >> name;
			//清除 =
			ss >> garbageMessage;
			ss >> variableInfo.value;
			if (temp == "int" || temp == "Integer") {
				//get type
				variableInfo.vType = 0;
				
			}
			else if (temp == "float" || temp == "Decimal") {
				//get type
				variableInfo.vType = 1;
				
			}
			//儲存變數資訊
			if (variable.find(name) != variable.end()) {
				variable[name] = variableInfo;
			}
			else {
				variable.insert(pair<string, VariableInfo>(name, variableInfo));
			};
		}

		//calculation
		else {
			vector<string>stemp;
			stemp.push_back(temp);
			while (ss) {
				temp = "";
				ss >> temp;
				stemp.push_back(temp);
			}
			vector <string> postfix = infixToPostfix(stemp);
			string result = calculate(postfix);
			cout << result << endl;
		}
	}
}