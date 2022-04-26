#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

int priority(char op) {

}

string infixToPostfix(string infix) {

}

string calculate(string postfix) {

}

int main() {
	string input;
	while (true)
	{
		getline(cin, input);

		//stop input
		if (input == "exit")	break;

		//set variable
		else if ((input[0] == 's' && input[1] == 'e') && input[2] == 't') {

		}

		//calculation
		else {
			string postfix = infixToPostfix(input);
			string result = calculate(postfix);
			cout << result << endl;
		}
	}
}