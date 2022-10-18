#include <iostream>
#include <vector>
#include <string>
#include "Fraction.h"
using namespace std;

//template<typename int>
class RPNCalculator {
	string input;
	fraction inputEl;
	int last_index;
	vector<fraction> stack;
public :
	void Run() {
		while (true) {
			cin >> input;
			last_index = stack.size() - 1;
			if (input == "q") break;
			if (input == "n") {
				cin >> inputEl;
				stack.push_back(inputEl);
			}
			else if (input == "d") {
				if (!stack.empty())
					stack.pop_back();
			}
			else if (stack.size() < 2) {
				continue;
			}
			else if (input == "+") {
				fraction res = stack[last_index - 1] + stack[last_index];
				stack.pop_back();
				stack.pop_back();
				stack.push_back(res);
				cout << res << endl;
			}
			else if (input == "-") {
				fraction res = stack[last_index - 1] - stack[last_index];
				stack.pop_back();
				stack.pop_back();
				stack.push_back(res);
				cout << res << endl;
			}
			else if (input == "*") {
				fraction res = stack[last_index - 1] * stack[last_index];
				stack.pop_back();
				stack.pop_back();
				stack.push_back(res);
				cout << res << endl;
			}
			else if (input == "/") {
				fraction res = stack[last_index - 1] / stack[last_index];
				stack.pop_back();
				stack.pop_back();
				stack.push_back(res);
				cout << res << endl;
			}
		}
	}
};

int main() {
	cout << "type i for int caltulator, f - fraction, fr - fraction" << endl;
	string response;
	cin >> response;
	if (response == "i") {
		RPNCalculator calc;
		calc.Run();
	}
	else if (response == "f") {
		RPNCalculator calc;
		calc.Run();
	}
	else if (response == "fr") {
		/*RPNCalculator<fraction> calc;
		calc.Run();*/
	}
	

	
}

