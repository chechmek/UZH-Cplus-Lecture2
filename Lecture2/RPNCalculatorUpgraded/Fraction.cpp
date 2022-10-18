#include <iostream>

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
	fraction() : c(0), d(0){}
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
