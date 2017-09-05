#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include <fstream>
#include <cstdlib>
using namespace std;
class myPolynomial;
class myTerm
{
public:
	myTerm(int c = 0, unsigned e = 0);
	// copy constructor
	myTerm(const myTerm &term);
	// overloaded operators
	bool operator == (const myTerm& term) const;
	bool operator != (const myTerm& term) const;
	bool operator < (const myTerm& term) const;
	myTerm operator - () const;
	// accessor functions
	int getCoeff() const { return coeff; }
	unsigned getExp() const { return exp; }
	// mutator functions
	void setCoeff(int c) { coeff = c; }
	void setExp(unsigned e) { exp = e; }
	// member functions
	myTerm ddx() const; // derivative of a term
						// friend functions and classes
	friend ostream& operator <<(ostream &outStream, const myTerm& term);
	friend class myPolynomial;
private:
	int coeff; // integer coefficient
	unsigned exp; // exponent (non-negative integer)
};
// Constructor
myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e)
{
}
// copy constructor
myTerm::myTerm(const myTerm &term) : coeff(term.coeff), exp(term.exp)
{
}
// overloaded operators
bool myTerm::operator == (const myTerm& term) const
{
	return coeff == term.coeff && exp == term.exp;
}
// overloaded operators
bool myTerm::operator != (const myTerm& term) const
{
	return coeff != term.coeff || exp != term.exp;
}
// overloaded operators
bool myTerm::operator < (const myTerm& term) const
{
	return exp > term.exp;
}
myTerm myTerm::operator - () const
{
	return myTerm(-1*coeff, exp);
}
// derivative of a term
myTerm myTerm::ddx() const
{
	if (exp == 0)
		return myTerm(0, 0);
	return myTerm(exp*coeff, exp - 1);
}
// output operator
ostream& operator <<(ostream &outStream, const myTerm& term)
{
	if (term.exp == 0)
		if (term.coeff == 0) // nothing to output
			return outStream;
		else
			return outStream << term.coeff;
	if (term.coeff == 1)
		outStream << "x";
	else if (term.coeff == -1)
		outStream << "-x";
	else
		outStream << term.coeff << "x";
	if (term.exp == 1)
		return outStream;
	else
		return outStream << "^" << term.exp;
}
class myPolynomial
{
public:
	myPolynomial(int c = 0, unsigned e = 0);
	myPolynomial(int nTerms, int mono[]);
	// copy constructor
	myPolynomial(const myPolynomial &poly);
	// overloaded operators
	bool operator == (const myPolynomial &poly) const;
	bool operator != (const myPolynomial &poly) const;
	myPolynomial& operator += (const myPolynomial &poly);
	myPolynomial& operator -= (const myPolynomial &poly);
	myPolynomial& operator *= (const myPolynomial &poly);
	myPolynomial& operator *= (int k);
	myPolynomial operator -() const;
	myPolynomial operator *(int k) const;
	myPolynomial operator +(const myPolynomial &poly) const;
	myPolynomial operator -(const myPolynomial &poly) const;
	myPolynomial operator *(const myPolynomial &poly) const;
	long operator() (int x) const; // evaluate the polynomial
	int getDegree() const; // get a degree of the polynomial
	unsigned getNumTerms() const; // number of terms in the polynomial
	myPolynomial ddx() const; // derivative of a polynomial
	// friend operators and functions
	friend myPolynomial operator *(int k, const myPolynomial &poly);
	friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);
	static const myPolynomial ZERO; // P(x) = 0
	static const myPolynomial ONE; // P(x) = 1
	static const myPolynomial X; // P(x) = x
private:
	int degree; // maximum expnent
	int NumTerms;
	/********************* add your code here ********************************/
	vector<myTerm> v;
};
/********************* add your code here ********************************/
// output operator

myPolynomial operator*(int k, const myPolynomial & poly)
{
	return poly * k;
}

ostream& operator <<(ostream &outStream, const myPolynomial& poly)
{
	if (poly == myPolynomial::ZERO)
		return outStream << 0;
	/********************* add your code here ********************************/

	bool flag = false;
	for (int i = 0;i < poly.NumTerms;i++) {

		int coeff = poly.v[i].getCoeff();
		int exp = poly.v[i].getExp();
		if (coeff == 0)
			continue;
		else if (exp == 0) {

				if(coeff > 0&&i!=0)
					outStream << "+";
			outStream << coeff;
		}
		else if (coeff == 1 || coeff == -1) {

				if (coeff > 0&&i!=0)
					outStream << "+";

			if(coeff < 0)
				outStream << "-";
			outStream << "x";
			if (exp != 1)
				outStream << "^"<< exp;
		}
		else {

				if (coeff > 0&&i!=0)
					outStream << "+";

			outStream << coeff << "x";
			if(exp != 1)
				outStream << "^" << exp;
		}
		flag = true;
	}
	if(flag == false)
		return outStream << 0;
	return outStream;
}

const myPolynomial myPolynomial::ZERO(0); // the zero polynomial P(x) = 0
const myPolynomial myPolynomial::ONE(1, (unsigned)0); // the monomial P(x) = 1
const myPolynomial myPolynomial::X(1, 1); // the monomial P(x) = x

myPolynomial::myPolynomial(int c, unsigned e) : NumTerms(1), degree(e)
{
	v.push_back(myTerm(c, e));
}

myPolynomial::myPolynomial(int nTerms, int mono[])
{
	NumTerms = nTerms;
	for (int i = 0;i < nTerms*2;i+=2){
		v.push_back(myTerm(mono[i], mono[i + 1]));

    }
	sort(v.begin(), v.end());
	degree = v[0].exp;
}

myPolynomial::myPolynomial(const myPolynomial & poly)
{
	NumTerms = poly.NumTerms;
	degree = poly.degree;
	for (int i = 0;i < poly.NumTerms;i++)
		v.push_back(myTerm(poly.v.at(i)));
}

bool myPolynomial::operator==(const myPolynomial & poly) const
{
	if (NumTerms != poly.NumTerms)
		return false;
	for (int i = 0;i < NumTerms;i++) {
		if (v.at(i) != poly.v.at(i))
			return false;
	}
	return true;
}

bool myPolynomial::operator!=(const myPolynomial & poly) const
{
	if (NumTerms != poly.NumTerms)
		return true;
	for (int i = 0;i < NumTerms;i++) {
		if (v.at(i) == poly.v.at(i))
			return false;
	}
	return true;
}

myPolynomial & myPolynomial::operator+=(const myPolynomial & poly)
{
    int i=0,j=0;

while (i < poly.NumTerms && j < NumTerms) {
		if (poly.v.at(i).exp < v.at(j).exp)
			j++;
		else if (poly.v.at(i).exp == v.at(j).exp) {
			v.at(j) = myTerm(v.at(j).coeff + poly.v.at(i).coeff, v.at(j).exp);
			i++;
			j++;
		}
		else {
			v.push_back(poly.v.at(i));
			i++;
		}
	}
	while (i < poly.NumTerms) {
		v.push_back(poly.v.at(i));
		i++;
	}

	sort(v.begin(), v.end());
	degree = v.at(0).exp;
	NumTerms = v.size();
	return *this;
}

myPolynomial & myPolynomial::operator-=(const myPolynomial & poly)
{
	 int i = 0, j = 0;
   while (i < poly.NumTerms && j < NumTerms) {
      if (poly.v.at(i).exp < v.at(j).exp)
         j++;
      else if (poly.v.at(i).exp == v.at(j).exp) {
         v.at(j) = myTerm(v.at(j).coeff - poly.v.at(i).coeff, v.at(j).exp);
         i++;
         j++;
      }
      else {
         v.push_back(-poly.v.at(i));
         i++;
      }
   }
   while (i < poly.NumTerms) {
      v.push_back(-poly.v.at(i));
      i++;
   }
   sort(v.begin(), v.end());
   degree = v.at(0).exp;
   NumTerms = v.size();
   return *this;
}

myPolynomial & myPolynomial::operator*=(const myPolynomial & poly)
{
	vector < myTerm > temp_vec;
	for (int i = 0;i < NumTerms;i++) {
		for (int j = 0;j < poly.NumTerms;j++)
			temp_vec.push_back(myTerm(v.at(i).coeff * poly.v.at(j).coeff, v.at(i).exp + poly.v.at(j).exp));
	}
	sort(temp_vec.begin(), temp_vec.end());
	int coeff = temp_vec.at(0).coeff;
	unsigned exp = temp_vec.at(0).exp;
	v.clear();
	for (int i = 1;i < temp_vec.size();i++) {
		if (temp_vec.at(i).exp == temp_vec.at(i - 1).exp) {
			coeff += temp_vec.at(i).coeff;
		}
		else {
			v.push_back(myTerm(coeff, exp));
			coeff = temp_vec.at(i).coeff;
			exp = temp_vec.at(i).exp;
		}
	}
	v.push_back(myTerm(coeff, exp));
	sort(v.begin(), v.end());
	degree = v.at(0).exp;
	NumTerms = v.size();
	return *this;
}

myPolynomial & myPolynomial::operator*=(int num)
{
	for (int i = 0;i < v.size();i++)
		v.at(i).coeff *= num;
	return *this;
}

myPolynomial myPolynomial::operator-() const
{
	myPolynomial newobj = *this;
	for (int i = 0;i < newobj.NumTerms;i++)
		newobj.v.at(i) = myTerm(-1*newobj.v.at(i).coeff, newobj.v.at(i).exp);
	return newobj;
}

myPolynomial myPolynomial::operator*(int num) const
{
	myPolynomial newobj = *this;
	if (num == 0) {
		newobj.degree = 0;
		newobj.NumTerms = 1;
	}

	for (int i = 0;i < newobj.NumTerms;i++) {
		newobj.v[i] = myTerm(newobj.v[i].coeff*num, newobj.v[i].exp);
	}

	return newobj;
}

myPolynomial myPolynomial::operator+(const myPolynomial & poly) const
{
	int i = 0, j = 0;
	myPolynomial newobj = *this;
	while (i < poly.NumTerms && j < newobj.NumTerms) {
		if (poly.v.at(i).exp < newobj.v.at(j).exp)
			j++;
		else if (poly.v.at(i).exp == newobj.v.at(j).exp) {
			newobj.v.at(j) = myTerm(newobj.v.at(j).coeff + poly.v.at(i).coeff, newobj.v.at(j).exp);
			i++;
			j++;
		}
		else {
			newobj.v.push_back(poly.v.at(i));
			i++;
		}
	}
	while (i < poly.NumTerms) {
		newobj.v.push_back(poly.v.at(i));
		i++;
	}
	sort(newobj.v.begin(), newobj.v.end());
	newobj.degree = newobj.v.at(0).exp;
	newobj.NumTerms = newobj.v.size();
	return newobj;
}

myPolynomial myPolynomial::operator-(const myPolynomial & poly) const
{
	int i = 0, j = 0;
	myPolynomial newobj = *this;
	while (i < poly.NumTerms && j < newobj.NumTerms) {
		if (poly.v.at(i).exp < newobj.v.at(j).exp)
			j++;
		else if (poly.v.at(i).exp == newobj.v.at(j).exp) {
			newobj.v.at(j) = myTerm(newobj.v.at(j).coeff - poly.v.at(i).coeff, newobj.v.at(j).exp);
			i++;
			j++;
		}
		else {
			newobj.v.push_back(-poly.v.at(i));
			i++;
		}
	}
	while (i < poly.NumTerms) {
		newobj.v.push_back(-poly.v.at(i));
		i++;
	}
	sort(newobj.v.begin(), newobj.v.end());
	newobj.degree = newobj.v.at(0).exp;
	newobj.NumTerms = newobj.v.size();
	return newobj;
}

myPolynomial myPolynomial::operator*(const myPolynomial & poly) const
{
	myPolynomial newobj;
	vector < myTerm > temp_vec;
	for (int i = 0;i < NumTerms;i++) {
		for (int j = 0;j < poly.NumTerms;j++)
			temp_vec.push_back(myTerm(v.at(i).coeff * poly.v.at(j).coeff, v.at(i).exp + poly.v.at(j).exp));
	}
	sort(temp_vec.begin(), temp_vec.end());
	int coeff = temp_vec.at(0).coeff;
	unsigned exp = temp_vec.at(0).exp;
	for (int i = 1;i < temp_vec.size();i++) {
		if (temp_vec.at(i).exp == temp_vec.at(i - 1).exp) {
			coeff += temp_vec.at(i).coeff;
		}
		else {
			newobj.v.push_back(myTerm(coeff, exp));
			coeff = temp_vec.at(i).coeff;
			exp = temp_vec.at(i).exp;
		}
	}
	newobj.v.push_back(myTerm(coeff, exp));
	sort(newobj.v.begin(), newobj.v.end());
	if (newobj.v.size() >= 2 && newobj.v.at(newobj.v.size() - 1).exp == newobj.v.at(newobj.v.size() - 2).exp) {
		newobj.v.at(newobj.v.size() - 2).coeff += newobj.v.at(newobj.v.size() - 1).coeff;
		newobj.v.pop_back();
	}
	newobj.degree = newobj.v.at(0).exp;
	newobj.NumTerms = newobj.v.size();
	return newobj;
}

long myPolynomial::operator()(int x) const
{
	long sum = 0;
	for (int i = 0;i < NumTerms;i++) {
		sum += v[i].coeff*pow(x, v[i].exp);
	}
	return sum;
}

int myPolynomial::getDegree() const
{
	return degree;
}

unsigned myPolynomial::getNumTerms() const
{
	return NumTerms;
}

myPolynomial myPolynomial::ddx() const
{
	myPolynomial newobj = *this;
	for (int i = 0;i < NumTerms;i++) {
		newobj.v[i] = v[i].ddx();
	}
	return newobj;
}

void testSimpleCase();
void testDataFromFile();
int main(void)
{
	testSimpleCase();
	testDataFromFile();
	return 0;
}
void testSimpleCase()
{
	// test static variables
	cout << myPolynomial::ZERO << endl;
	cout << myPolynomial::ONE << endl;
	cout << myPolynomial::X << endl;
	myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
	int testData4[10] = { 1, 0, 1, 1, 1, 2, 1, 3, 1, 4 };
	int testData5[10] = { -1, 0, -1, 1, -1, 2, -1, 3, -1, 4 };
	int testData6[10] = { 1, 0, -1, 1, 1, 2, -1, 3, 1, 4 };
	int testData7[10] = { 2, 2, 5, 5, 4, 4, 1, 1, 3, 3 };
	int testData8[12] = { 1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0 };
	myPolynomial p4(5, testData4);
	myPolynomial p5(5, testData5);
	myPolynomial p6(5, testData6);
	myPolynomial p7(5, testData7);
	myPolynomial p8(6, testData8);
	myPolynomial p9(p7);
	// test constructor
	cout << p0 << endl << p1 << endl << p2 << endl;
	cout << p4 << endl << p8 << endl;
	// test copy constructor
	cout << p9 << endl;
	// test accessor function
	cout << p8.getDegree() << " " << p8.getNumTerms() << endl;
	// test evaluation function
	cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
	cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;
	// test comparison operators
	cout << (p7 == p9) << " " << (p7 != p9) << endl;

	// test derivative function
	cout << myPolynomial::ZERO.ddx() << endl;
	cout << myPolynomial::ONE.ddx() << endl;
	cout << myPolynomial::X.ddx() << endl;
	cout << p4.ddx() << endl;
	cout << p8.ddx() << endl;

	// test unary operator -
	cout << -myPolynomial::ZERO << endl;
	cout << -p4 << endl;

	// test k*p(x) or p(x) * k
	cout << 3 * myPolynomial::ZERO << endl;
	cout << 3 * myPolynomial::ONE << endl;

	cout << myPolynomial::X * 3 << endl;
	cout << 3 * p4 << " " << p4 * 3 << endl;
	cout << 0 * p5 << " " << p5 * 5 << endl;

	// test binary operator +
	cout << p4 + p5 << endl;
	// test binary operator -
	cout << p6 - p7 << endl;

	// test binary operator *
	cout << p8 * p9 << endl;

	myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
	tmp4 = tmp3 = tmp2 = tmp1;
	cout << (tmp1 += p5) << endl;
	cout << (tmp2 -= p5) << endl;
	cout << (tmp3 *= p5) << endl;
	cout << (tmp4 *= 3) << endl;
}
void testDataFromFile()
{
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	if (inStream.fail())
	{
		cerr << "Input file opening failed.\n";
		exit(1);
	}
	inStream >> numTestCases;
	for (int i = 0; i<numTestCases; i++)
	{
		int numTerms, terms[100];
		/* read first polynomial */
		inStream >> numTerms;
		for (int j = 0; j<numTerms; j++)
			inStream >> terms[2 * j] >> terms[2 * j + 1];
		myPolynomial p1(numTerms, terms);
		/* read second polynomial */
		inStream >> numTerms;
		for (int j = 0; j<numTerms; j++)
			inStream >> terms[2 * j] >> terms[2 * j + 1];
		myPolynomial p2(numTerms, terms);
		cout << p1 << endl << p2 << endl;
		if(p1 ==  myPolynomial::ZERO)
            cout << -1 << " ";
        else
            cout << p1.getDegree() << " ";
		//cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
		cout << p2.getNumTerms() << endl;
		cout << p1.ddx() << endl << p2.ddx() << endl;
		cout << (p1 == p2) << " " << (p1 != p2) << endl;
		cout << p1(1) << endl;
		cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;
		myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
		p3 += p1;
		p4 -= p2;
		p5 *= p4;
		p5 *= 2;
		cout << p5 << endl;
	}
	inStream.close();
}
