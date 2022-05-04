#pragma once

#include <sstream>
#include <stack>

#include <vector>
#include <map>
#include "Decimal.h"

using namespace std;

int priority(string op)
{
	if (op == "!")
		return 5;
	else if (op == "^")
		return 4;
	else if (op == "++" || op == "--") // positive and negative number
		return 3;
	else if (op == "*" || op == "/")
		return 2;
	else if (op == "+" || op == "-") // add and substract
		return 1;
	else
		return 0;
}

inline bool isDec(string num)
{
	if (num.find(".") != std::string::npos)
		return true;
	else
		return false;
}

inline bool isSign(char pre)
{
	if (isdigit(pre))
		return false;
	else
		return true;
}

inline bool isVar(string str, map<string, string>& varList)
{
	auto iter = varList.find(str);
	if (iter != varList.end())
		return true;

	else
		return false;
}

inline bool isOperation(string input) {
	if (input.find("+") != std::string::npos ||
		input.find("-") != std::string::npos ||
		input.find("*") != std::string::npos ||
		input.find("/") != std::string::npos ||
		input.find("!") != std::string::npos ||
		input.find("^") != std::string::npos )
		return true;
	else
		return false;
}

void pushOrPop(vector<string>& postfix, stack<string>& opList, string op, bool left)
{
	if (left)
	{
		while (opList.size() != 0 && opList.top() != "(" && priority(opList.top()) >= priority(op))
		{
			postfix.push_back(opList.top());
			opList.pop();
		}
	}
	else
	{
		while (opList.size() != 0 && opList.top() != "(" && priority(opList.top()) > priority(op))
		{
			postfix.push_back(opList.top());
			opList.pop();
		}
	}
}

void infixToPostfix(string infix, vector<string>& postfix)
{
	string currNum;
	stack<string> opList;

	for (int i = 0; i < infix.size(); i++)
	{

		// positive or negative sign
		if ((infix[i] == '+' || infix[i] == '-') && (i == 0 || isSign(infix[i - 1])))
		{

			string op;
			if (infix[i] == '+')
				op = "++";
			else
				op = "--";

			pushOrPop(postfix, opList, op, false);
			opList.push(op);
		}
		// mathematics operators
		else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '!' || infix[i] == '^' || infix[i] == '+' || infix[i] == '-')
		{

			// put current number in postfix operation
			postfix.push_back(currNum);
			currNum.clear();

			// check whether to pop operator
			string op(1, infix[i]);
			pushOrPop(postfix, opList, op, true);

			// put operator into opList
			opList.push(op);
		}
		// left bracket
		else if (infix[i] == '(')
		{
			// put current number in postfix operation
			postfix.push_back(currNum);
			currNum.clear();

			// put operator into opList
			string op(1, infix[i]);
			opList.push(op);
		}
		// right bracket
		else if (infix[i] == ')')
		{
			// put current number in postfix operation
			postfix.push_back(currNum);
			currNum.clear();

			// pop all operators until meet left bracket
			while (opList.top() != "(")
			{
				postfix.push_back(opList.top());
				opList.pop();
			}
			opList.pop();
		}
		// number or varibale
		else
		{
			currNum.push_back(infix[i]);
		}
	}

	while (!opList.empty()) {
		postfix.push_back(opList.top());
		opList.pop();
	}
}

string calculate(vector<string> postfix, map<string, string>& varList)
{
	vector<string> temp;
	for (int i = 0; i < postfix.size(); i++) {
		cout << postfix[i];
	}
	for (int i = 0; i < postfix.size(); i++)
	{
		// is operator
		if (priority(postfix[i]))
		{
			if (postfix[i] == "--")
			{
				string tempStr = temp[temp.size() - 1];
				temp.pop_back();

				// change sign
				Integer integer = Integer();
				integer=tempStr;
				//integer.changeSign();

				temp.push_back(integer.value);
			}
			else if (postfix[i] == "!")
			{
				string tempStr = temp[temp.size() - 1];
				temp.pop_back();

				if (isDec(tempStr))
					return "Invalid Input (factorial)";
				else {
					//factorial
					Integer integer = Integer();
					integer = tempStr;
					//integer.factorial();

					temp.push_back(integer.value);
				}
			}
			else
			{
				string temp1, temp2;
				temp1 = temp[temp.size() - 2];
				temp2 = temp[temp.size() - 1];
				temp.pop_back();
				temp.pop_back();

				if (postfix[i] == "+")
				{
					//int and int
					if (!isDec(temp1) && !isDec(temp2)) {
						Integer intA = Integer();
						intA=temp1;
						Integer intB = Integer();
						intB = temp2;
						intA = intA + intB;
						temp.push_back(intA.value);
					}
					//int and dec
					else if (!isDec(temp1) && isDec(temp2)) {
						Integer num1 = Integer();
						num1 = temp1;
						Decimal num2= Decimal();
						num2 = temp2;
						num2 = num1 + num2;
						temp.push_back(num2.whole);
					}
					//dec and int
					else if (isDec(temp1) && !isDec(temp2)) {
						Decimal num1 = Decimal();
						num1 = temp1;
						Integer num2 = Integer();
						num2 = temp2;

						num1 = num1 + num2;
						temp.push_back(num1.whole);
					}
					//dec and dec
					else if (isDec(temp1) && isDec(temp2)) {
						Decimal num1 = Decimal();
						num1 = temp1;
						Decimal num2 = Decimal();
						num2 = temp2;

						num1 = num1 + num2;
						temp.push_back(num1.whole);
					}
				}
				else if (postfix[i] == "-")
				{
					//int and int
					if (!isDec(temp1) && !isDec(temp2)) {
						Integer intA = Integer();
						intA = temp1;
						Integer intB = Integer();
						intB = temp2;
						intA = intA - intB;
						temp.push_back(intA.value);
					}
					//int and dec
					else if (!isDec(temp1) && isDec(temp2)) {
						Integer num1 = Integer();
						num1 = temp1;
						Decimal num2 = Decimal();
						num2 = temp2;
						num2 = num1 - num2;
						temp.push_back(num2.whole);
					}
					//dec and int
					else if (isDec(temp1) && !isDec(temp2)) {
						Decimal num1 = Decimal();
						num1 = temp1;
						Integer num2 = Integer();
						num2 = temp2;

						num1 = num1 - num2;
						temp.push_back(num1.whole);
					}
					//dec and dec
					else if (isDec(temp1) && isDec(temp2)) {
						Decimal num1 = Decimal();
						num1 = temp1;
						Decimal num2 = Decimal();
						num2 = temp2;

						num1 = num1 - num2;
						temp.push_back(num1.whole);
					}
				}
				else if (postfix[i] == "*")
				{
					//int and int
					if (!isDec(temp1) && !isDec(temp2)) {
						Integer intA = Integer();
						intA = temp1;
						Integer intB = Integer();
						intB = temp2;
						intA = intA / intB;
						temp.push_back(intA.value);
					}
					//int and dec
					else if (!isDec(temp1) && isDec(temp2)) {
						Integer num1 = Integer();
						num1 = temp1;
						Decimal num2 = Decimal();
						num2 = temp2;
						num2 = num1 / num2;
						temp.push_back(num2.whole);
					}
					//dec and int
					else if (isDec(temp1) && !isDec(temp2)) {
						Decimal num1 = Decimal();
						num1 = temp1;
						Integer num2 = Integer();
						num2 = temp2;

						num1 = num1 / num2;
						temp.push_back(num1.whole);
					}
					//dec and dec
					else if (isDec(temp1) && isDec(temp2)) {
						Decimal num1 = Decimal();
						num1 = temp1;
						Decimal num2 = Decimal();
						num2 = temp2;

						num1 = num1 / num2;
						temp.push_back(num1.whole);
					}
				}
				else if (postfix[i] == "^")
				{
				//int and int
				if (!isDec(temp1) && !isDec(temp2)) {
					Integer intA = Integer();
					intA = temp1;
					Integer intB = Integer();
					intB = temp2;
					intA = intA ^ intB;
					temp.push_back(intA.value);
				}
				//int and dec
				else if (!isDec(temp1) && isDec(temp2)) {
					Integer num1 = Integer();
					num1 = temp1;
					Decimal num2 = Decimal();
					num2 = temp2;
					num2 = num1 ^ num2;
					temp.push_back(num2.whole);
				}
				//dec and int
				else if (isDec(temp1) && !isDec(temp2)) {
					Decimal num1 = Decimal();
					num1 = temp1;
					Integer num2 = Integer();
					num2 = temp2;

					num1 = num1 ^ num2;
					temp.push_back(num1.whole);
				}
				//dec and dec
				else if (isDec(temp1) && isDec(temp2)) {
					Decimal num1 = Decimal();
					num1 = temp1;
					Decimal num2 = Decimal();
					num2 = temp2;

					num1 = num1 ^ num2;
					temp.push_back(num1.whole);
				}
				}
			}
		}
		// is varibale
		else if (isVar(postfix[i], varList))
		{
			temp.push_back(varList[postfix[i]]);
		}
		// is number
		else
		{
			temp.push_back(postfix[i]);
		}
	}

	return temp[0];
}

void setVar(string type, string var, string value, map<string, string>& varList)
{
	if ((type == "int" || type == "Integer") && isDec(value))
	{
		string::size_type end = value.find(".");
		value = value.substr(0, end - 0);
	}
	else if ((type == "float" || type == "Decimal") && !isDec(value))
	{
		value += ".0";
	}

	//varList[var] = value;
	varList.insert(pair<string, string>(var, value));
}

void splitInput(string input, vector<string>& inputVector)
{
	string::size_type begin, end;
	string pattern = " ";

	begin = 0;
	end = input.find(pattern);

	while (end != std::string::npos)
	{
		if (end - begin != 0)
		{
			inputVector.push_back(input.substr(begin, end - begin));
		}
		begin = end + pattern.size();
		end = input.find(pattern, begin);
	}

	if (begin != input.length())
	{
		inputVector.push_back(input.substr(begin));
	}
}

int main()
{
	/*string input;
	map<string, string> varList;

	while (getline(cin, input))
	{
		vector<string> inputVector;

		splitInput(input, inputVector);

		// stop input
		if (input == "exit")
		{
			break;
		}

		// set variable
		else if (inputVector[0] == "set" || inputVector[0] == "Set" || inputVector[0] == "SET")
		{
			setVar(inputVector[1], inputVector[2], inputVector[4], varList);
		}

		// calculation
		else if (isOperation(input))
		{
			vector<string> postfix;
			infixToPostfix(input, postfix);
			cout << calculate(postfix, varList) << endl;
		}

		// output variable
		else
		{
			if (isVar(input, varList))
				cout << varList[input] << endl;
			else
				cout << "Variable does not exist" << endl;
		}
	}*/
	Integer a = Integer();
	a = "99999999999999999999";
	Integer b = Integer();
	b = "4";
	a = a / b;
	cout << a;
}