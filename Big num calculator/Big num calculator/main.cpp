#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <map>

using namespace std;
class VariableInfo {
	//vType 0��Integer 1��Decimal 
public: 
	int vType;
	//
    string value;
};

int priority(char op) {
	return 0;
}

vector<string> infixToPostfix(vector<string> infix) {
	vector<string>output;
	return output;
}

string calculate(vector<string> postfix) {
	return"";
}

int main() {
	string input;

	
	//�x�s�ܼƸ�T
	map < string, VariableInfo > variable= map < string, VariableInfo >();
	
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

			ss >> temp;
			//get name
			ss >> name;
			ss >> variableInfo.value;
			if (temp == "int" || temp == "Integer") {
				//get type
				variableInfo.vType = 0;
				//�x�s�ܼƸ�T
				if (variable.find(name) != variable.end()) {
					variable[name] = variableInfo;
				}
				else {
					variable.insert(pair<string, VariableInfo>(name, variableInfo));
				};
			}
			else if (temp == "float" || temp == "Decimal") {
				//get type
				variableInfo.vType = 1;
				//�x�s�ܼƸ�T
				if (variable.find(name) != variable.end()) {
					variable[name] = variableInfo;
				}
				else {
					variable.insert(pair<string, VariableInfo>(name, variableInfo));
				};
			}
		}

		//calculation
		else {
			vector<string>stemp;
			stemp.push_back(temp);
			while (!ss) {
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