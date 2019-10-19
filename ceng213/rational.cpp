#include <iostream>
#include <stdlib.h>

using namespace std;

// A Rational number arithmetic package

class Rational {
public:
	Rational(int p = 0, int q = 1);
	int getNumerator() const;
	int getDenominator() const;
	bool operator==(const Rational&) const;
	bool operator<(const Rational&) const;
	bool operator>(const Rational&) const;
	Rational operator+(const Rational&) const;
	Rational operator+(const int) const;
	Rational operator*(const Rational&) const;
	Rational operator*(const int) const;
	Rational& operator+=(const Rational&);
	Rational reciprocal();

	friend Rational operator+(int, const Rational&);
	friend Rational operator-(const Rational&);
	friend Rational operator*(int, const Rational&);
	friend istream& operator>>(istream&, const Rational&);
	friend ostream& operator<<(ostream&, const Rational&);

private:
	int num, denom;
	void normalize(Rational&) const;
	int gcd(int, int) const;
};

// Constructor:
Rational::Rational(int p, int q) {
	if (q == 0) throw "denom is zero";
	num = p; denom = q;
	normalize(*this);
}

// Accessor functions:
int Rational::getNumerator() const {
	return num;
}

int Rational::getDenominator() const {
	return denom;
}

// An equality operator:
bool Rational::operator==(const Rational& r) const {
	// Both operands are guaranteed to be normalized 
	return(num == r.num && denom == r.denom);
}

// Comparison operators:
bool Rational::operator<(const Rational& r) const {
	return(num*r.denom < r.num*denom);
}

bool Rational::operator>(const Rational& r) const {
	return(num*r.denom > r.num*denom);
}

// Arithmetic operator +:
Rational Rational::operator+(const Rational& r) const {
	Rational result;
	result.num = num * r.denom + r.num*denom;
	result.denom = denom * r.denom;
	normalize(result);
	return result;
}
Rational Rational::operator+(int r) const {
	Rational m(r);
	return (*this) + m;
}
Rational operator+(int l, const Rational& r) {
	Rational m(l);
	return m + r;
}

// Unary -:
Rational operator-(const Rational& r) {
	Rational result(-r.num, r.denom);
	return result;
}

// Arithmetic operator *:
Rational Rational::operator*(const Rational& r) const {
	Rational result;
	result.num = num * r.num;
	result.denom = denom * r.denom;
	normalize(result);
	return result;
}
Rational Rational::operator*(int r) const {
	Rational m(r);
	return (*this)*m;
}
Rational operator*(int l, const Rational& r) {
	Rational m(l);
	return m * r;
}

// Assignment operator:
Rational& Rational::operator+=(const Rational& r) {
	num = num * r.denom + r.num*denom;
	denom = denom * r.denom;
	normalize(*this);
	return *this;
}

// Reciprocal:
Rational Rational::reciprocal() {
	if (num == 0) throw "denom is zero";
	Rational result(denom, num);
	if (result.denom < 0) { result.num = -result.num; result.denom = -result.denom; }
	return result;
}

// Input operator to read a rational number:
istream& operator>>(istream& in, const Rational& r) {
	in >> r.num >> r.denom;
	return in;
}

// Output operator to print a rational number:
ostream& operator<<(ostream& out, const Rational& r) {
	out << " " << r.num << "/" << r.denom << " ";
	return out;
}

// Private function normalize
void Rational::normalize(Rational& r) const {
	int factor = gcd(abs(r.num), abs(r.denom));
	r.num /= factor;
	r.denom /= factor;
	if (r.denom < 0) { r.num = -r.num; r.denom = -r.denom; }
}

// Private function gcd
int Rational::gcd(int p, int q) const {
	while (p && q)
		if (p > q) p %= q;
		else q %= p;
	return(p ? p : q);
}

// Driver
int main(void) {
	Rational r1(-3, 2), r2(6, -4), r3(5), *p1, *p2;
	Rational zero;
	int i;

	cout << r1 << r2 << r3 << endl;

	r1 = r2 = r2 + r3 + 1;
	// The default assignment operator is used

	if (r1 == r2)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	p1 = new Rational(-5);

	if (*p1 + r3 == zero)
		cout << "zero" << endl;
	else
		cout << "not zero" << endl;

	r2 += r3;

	if (r1 < r2)
		cout << "smaller" << endl;
	else
		cout << "not smaller" << endl;

	p2 = new Rational(0);
	(*p2) = r1.reciprocal();

	r1 = 5 + r2;
	r3 = r2 + 7;

	cout << r1 << r2 << r3 << endl;
	cout << (*p1) << (*p2) << endl;

	delete p1;
	delete p2;

	r1 = r2 * r3;
	r2 = 3 * r3;
	r3 = 3 + (-r3);

	cout << r1 << r2 << r3 << endl;

	return 0;
}
