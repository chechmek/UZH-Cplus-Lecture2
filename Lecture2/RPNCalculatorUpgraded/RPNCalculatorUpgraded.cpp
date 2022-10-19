#include <iostream>
#include <vector>
#include <string>
using namespace std;

class fraction {
	int c, d;
	int findgcf(int n1, int n2) {
		while (n1 != n2) {
			if (n1 > n2)
				n1 -= n2;
			else
				n2 -= n1;
		}
		return n1;
	}
	int findlcm(int n1, int n2) {
		int max = (n1 > n2) ? n1 : n2;

		do
		{
			if (max % n1 == 0 && max % n2 == 0)
			{
				return max;
			}
			else
				++max;
		} while (true);
	}
public:
	fraction() : c(0), d(0) {}
	fraction(int cntr, int denom)
		: c(cntr), d(denom) { }

	friend istream& operator>>(istream& is, fraction& f);
	friend ostream& operator<<(ostream& os, fraction f);
	fraction operator+(const fraction b) {
		int lcmd = findlcm(d, b.d);
		int newc = c * lcmd / d;
		int newcb = b.c * lcmd / b.d;
		return fraction(newc + newcb, lcmd);
	}
	fraction operator-(const fraction b) {
		int lcmd = findlcm(d, b.d);
		int newc = c * lcmd / d;
		int newcb = b.c * lcmd / b.d;
		return fraction(newc - newcb, lcmd);
	}
	fraction operator*(const fraction b) {
		int newc = c * b.c;
		int newd = d * b.d;
		int gc = findgcf(newc, newd);
		return fraction(newc / gc, newd / gc);
	}
	fraction operator/(const fraction b) {
		int newc = c * b.d;
		int newd = d * b.c;
		int gc = findgcf(newc, newd);
		return fraction(newc / gc, newd / gc);
	}
	operator string() {
		return "(" + c + '/' + d + ')';
	}
};

ostream& operator<<(ostream& os, fraction f) {
	os << '(' << f.c << '/' << f.d << ')';
	return os;
}
void check_char(istream& is, char ch) {
	char c;
	is >> c;
	if (c != ch) {
		is.putback(c);
		is.setstate(ios::badbit);
	}
}
istream& operator>>(istream& is, fraction& f) {
	fraction g(0, 0);
	check_char(is, '(');
	is >> g.c;
	check_char(is, '/');
	is >> g.d;
	check_char(is, ')');
	if (is) f = g;
	return is;
}

template<typename T>
class RPNCalculator {
	string input;
	T inputEl;
	int last_index;
	vector<T> stack;
public:
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
				T res = stack[last_index - 1] + stack[last_index];
				stack.pop_back();
				stack.pop_back();
				stack.push_back(res);
				cout << res << endl;
			}
			else if (input == "-") {
				T res = stack[last_index - 1] - stack[last_index];
				stack.pop_back();
				stack.pop_back();
				stack.push_back(res);
				cout << res << endl;
			}
			else if (input == "*") {
				T res = stack[last_index - 1] * stack[last_index];
				stack.pop_back();
				stack.pop_back();
				stack.push_back(res);
				cout << res << endl;
			}
			else if (input == "/") {
				T res = stack[last_index - 1] / stack[last_index];
				stack.pop_back();
				stack.pop_back();
				stack.push_back(res);
				cout << res << endl;
			}
		}
	}
};

int main() {
	while (true)
	{
		cout << "type i for int caltulator, f - float, fr - fraction" << endl;
		string response;
		cin >> response;
		if (response == "i") {
			RPNCalculator<int> calc;
			calc.Run();
		}
		else if (response == "f") {
			RPNCalculator<float> calc;
			calc.Run();
		}
		else if (response == "fr") {
			RPNCalculator<fraction> calc;
			calc.Run();
		}
	}
}

