#include <iostream>

using namespace std;

// Pair class template

template <class T>
class Pair {
public:
	Pair(T f = T(), T s = T()) :fop(f), sop(s) {};
	T& getFirst() { return fop; };
	T& getSecond() { return sop; };
	Pair operator+(const Pair&) const;

	template <class M>
	friend istream& operator>>(istream&, const Pair<M>&);
	template <class M>
	friend ostream& operator<<(ostream&, const Pair<M>&);

private:
	T fop, sop;
};

// Arithmetic operator +:
template <class T>
Pair<T> Pair<T>::operator+(const Pair<T>& r) const {
	Pair<T> result;
	result.fop = fop + r.fop;
	result.sop = sop + r.sop;
	return result;
}

// Input operator to read a pair:
template <class M>
istream& operator>>(istream& in, const Pair<M>& r) {
	in >> r.fop >> r.sop;
	return in;
}

// Output operator to print a pair:
template <class M>
ostream& operator<<(ostream& out, const Pair<M>& r) {
	out << " <" << r.fop << "," << r.sop << "> ";
	return out;
}

// Driver
int main(void) {
	Pair<int> p1, p2(3, 5), p3(1, 2);
	cout << p1 << p2 << p3 << endl;
	// They return references to private data members! 
	// Hence, one can modify these privates. 
	p1.getFirst() = 7;
	p1.getSecond() = 8;
	p2 = p2 + p3;
	cout << p1 << p2 << p3 << endl;

	Pair<double> t1, t2(3.5, 6.3), t3(2.2, -1);
	t1 = t2 + t3;
	cout << t1 << t2 << t3 << endl;

	Pair<Pair<int>> y;
	cout << y << endl;

	// Will work if you include Rational class 
	// Pair<Rational> r1, r2(3,5);
	// cout << r1 << r2 << endl; 

	return 0;
}
