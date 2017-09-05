#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class myRational
{
public :
	myRational(long num = 0, long den = 1);
	myRational(const myRational &rat);
	long getNumerator() const;
	long getDenominator() const;
	myRational reciprocal() const;
	myRational operator +(myRational &rat);
	myRational operator -(myRational &rat);
	myRational operator *(myRational &rat);
	myRational operator /(myRational &rat);

	bool operator <(myRational &rat) const;
	bool operator <=(myRational &rat) const;
	bool operator >(myRational &rat) const;
	bool operator >=(myRational &rat) const;
	bool operator ==(myRational &rat) const;
	bool operator !=(myRational &rat) const;

	myRational & operator +=(myRational &rat);
	myRational & operator -=(myRational &rat);
	myRational & operator *=(myRational &rat);
	myRational & operator /=(myRational &rat);

	myRational& operator -();
	myRational& operator ++();
	myRational& operator --();
	myRational operator ++(int);
	myRational operator --(int);

	myRational operator +(int value);
	myRational operator -(int value);
	myRational operator *(int value);
	myRational operator /(int value);
	friend myRational operator +(long value, myRational number);
	friend myRational operator -(long value, myRational number);
	friend myRational operator *(long value, myRational number);
	friend myRational operator /(long value, myRational number);
	friend ostream &operator <<(ostream &outStream, const myRational& r);
	friend istream &operator >>(istream &inStream, myRational& r);
	bool operator()(myRational& left, myRational& right);
private:

	long _num; // numerator
	long _den; // denominator
	long gcd(long m, long n);
	long gcd(long m, long n) const;
	void reduce();
};
myRational operator+(long value, myRational number)
{
	return number + value;
}

myRational operator-(long value, myRational number)
{
	return -(number - value);
}

myRational operator*(long value, myRational number)
{
	return number * value;
}

myRational operator/(long value, myRational number)
{
	return myRational(value, 1) / number;
}

ostream &operator <<(ostream &outStream, const myRational& r)
{

	if (r._num == 0)
		outStream << 0;
	else {
		long g = r.gcd(abs(r._num), abs(r._den));
		long num = r._num / g;
		long den = r._den / g;
		if (den == 1)
			outStream << num;
		else
			outStream << num << "/" << den;
	}
	return outStream;
}
istream &operator >>(istream &inStream, myRational& r)
{
	inStream >> r._num >> r._den;
	if (r._den == 0)
	{
		r._num = 0;
		r._den = 1;
	}
	r.reduce();
	return inStream;
}
myRational::myRational(long num, long den)
{
	_num = num;
	_den = den;
}
myRational::myRational(const myRational & rat)
{
	_num = rat._num;
	_den = rat._den;
}
long myRational::getNumerator() const
{
	long n = _num;
	long d = _den;
	long gc = gcd(abs(n), abs(d));
	return n / gc;
}
long myRational::getDenominator() const
{
	long n = _num;
	long d = _den;
	long gc = gcd(abs(n), abs(d));
	return d / gc;
}
myRational myRational::reciprocal() const
{
	myRational newobj(getNumerator(), getDenominator());
	return newobj;
}
myRational myRational::operator+(myRational & rat)
{
	myRational newobj(_num * rat._den + rat._num * _den, _den * rat._den);
	return newobj;
}
myRational myRational::operator-(myRational & rat)
{
	myRational newobj(_num * rat._den - rat._num * _den, _den * rat._den);
	return newobj;
}
myRational myRational::operator*(myRational & rat)
{
	myRational newobj(_num * rat._num, _den * rat._den);
	return newobj;
}
myRational myRational::operator/(myRational & rat)
{
	if (rat._num == 0) {
		myRational newobj;
		return newobj;
	}
	myRational newobj(_num * rat._den, _den * rat._num);
	return newobj;
}
bool myRational::operator<(myRational & rat) const
{
	return _num * rat._den < rat._num * _den;
}
bool myRational::operator<=(myRational & rat) const
{
	return _num * rat._den <= rat._num * _den;
}
bool myRational::operator>(myRational & rat) const
{
	return _num * rat._den > rat._num * _den;
}
bool myRational::operator>=(myRational & rat) const
{
	return _num * rat._den >= rat._num * _den;
}
bool myRational::operator==(myRational & rat)  const
{
	return _num * rat._den == rat._num * _den;
}
bool myRational::operator!=(myRational & rat) const
{
	return _num * rat._den != rat._num * _den;
}
myRational & myRational::operator+=(myRational & rat)
{

	_num = _num * rat._den + rat._num * _den;
	_den = _den * rat._den;
	return *this;
}
myRational & myRational::operator-=(myRational & rat)
{
	_num = _num * rat._den - rat._num * _den;
	_den =  _den * rat._den;
	return *this;
}
myRational & myRational::operator*=(myRational & rat)
{
	_num =  _num * rat._num;
	_den = _den * rat._den;
	return *this;
}
myRational & myRational::operator/=(myRational & rat)
{

	if (rat._num == 0)
		_num = 0;
	else {
		_num =  _num * rat._den;
		_den = _den * rat._num;
	}
	return *this;
}
myRational& myRational::operator-()
{
	_num*=-1;
	return *this;
}
myRational& myRational::operator++()
{
	_num += abs(_den);
	return *this;
}
myRational& myRational::operator--()
{
	_num -= abs(_den);
	return *this;
}
myRational myRational::operator++(int)
{
	myRational newobj(_num, _den);
	_num += abs(_den);
	return newobj;
}
myRational myRational::operator--(int)
{
	myRational newobj(_num, _den);
	_num -= abs(_den);
	return newobj;
}
myRational myRational::operator+(int value)
{
	myRational newobj(_num + value * abs(_den), _den);
	return newobj;
}
myRational myRational::operator-(int value)
{
	myRational newobj(_num - value * abs(_den), _den);
	return newobj;
}
myRational myRational::operator*(int value)
{
	myRational newobj(_num * value, _den);
	return newobj;
}
myRational myRational::operator/(int value)
{
	if (value == 0) {
		myRational newobj;
		return newobj;
	}
	myRational newobj(_num , _den*value);
	return newobj;
}
long myRational::gcd(long m, long n)
{
	if (m == n)
		return n;
	else if (m < n)
		return gcd(m, n - m);
	else
		return gcd(m - n, n);
}
long myRational::gcd(long m, long n) const
{
	if (m == n)
		return n;
	else if (m < n)
		return gcd(m, n - m);
	else
		return gcd(m - n, n);
}
void myRational::reduce()
{
	if (_num == 0 || _den == 0)
	{
		_num = 0;
		_den = 1;
		return;
	}
	if (_den < 0)
	{
		_den *= -1;
		_num *= -1;
	}
	if (_num == 1)
		return;
	int sgn = (_num < 0 ? -1 : 1);
	long g = gcd(abs(sgn * _num), abs(_den));
	_num /= g;
	_den /= g;
}


using namespace std;
void testSimpleCase();
void testDataFromFile();
int main()
{
	testSimpleCase();
	testDataFromFile();
	return 0;
}
void testSimpleCase()
{
	myRational mr1(2), mr2(3, 2),mr3(6, 4), mr4(12, 8), mr5, mr6, mr7;
	cout << mr1 << " " << mr2 << " " <<mr3 << " "<< mr4 << " " << mr5 << endl;
	cout << mr1.getNumerator() << " " << mr1.getDenominator() << endl;
	// Check arithmetic operators
	cout << mr1 * mr2 << " ";
	cout << mr1 +mr3 << " ";
	cout << mr2 - mr1 << " ";
	cout <<mr3 / mr2 << endl;
	// Check comparison operators
	cout << ((mr1 < mr2) ? 1 : 0) << " "
		<< ((mr1 <= mr2) ? 1 : 0) << " "
		<< ((mr1 > mr2) ? 1 : 0) << " "
		<< ((mr1 >= mr2) ? 1 : 0) << " "
		<< ((mr1 == mr2) ? 1 : 0) << " "
		<< ((mr1 != mr2) ? 1 : 0) << " "
		<< ((mr2 <mr3) ? 1 : 0) << " "
		<< ((mr2 <=mr3) ? 1 : 0) << " "
		<< ((mr2 >mr3) ? 1 : 0) << " "
		<< ((mr2 >=mr3) ? 1 : 0) << " "
		<< ((mr2 ==mr3) ? 1 : 0) << " "
		<< ((mr2 !=mr3) ? 1 : 0) << endl;
	cout << (mr6 =mr3) << " ";
	cout << (mr6 +=mr3) << " ";
	cout << (mr6 -=mr3) << " ";
	cout << (mr6 *=mr3) << " ";
	cout << (mr6 /=mr3) << endl;
	cout << -mr6 << endl;
	mr6 = (++mr4) + 2;
	mr7 = 2 + (mr4++);
	cout << mr4 << " " << mr6 << " " << mr7 << endl;
	mr6 = (--mr4) - 2;
	mr7 = 2 - (mr4--);
	cout << mr4 << " " << mr6 << " " << mr7 << endl;
	cout << 2 *mr3 << " " <<mr3 * 2 << " "
		<< 2 /mr3 << " " <<mr3 / 2 << endl;
}
void testDataFromFile()
{
	ifstream inStream;
	int numTestCases;
	inStream.open("input.txt");
	inStream >> numTestCases;
	while(numTestCases--)
	{
		int num;
		inStream >> num;
		myRational * arr = new myRational[num];
		for (int j = 0;j < num;j++)
			inStream >> arr[j];
        for (int j = 0;j < num;j++){
            for(int k=j+1;k<num;k++){
                if(arr[j] > arr[k]){
                    myRational tmp = arr[j];
                    arr[j] = arr[k];
                    arr[k] = tmp;
                }
            }
        }
		for (int j = 0;j < num;j++)
			cout << arr[j] << " ";
		cout << endl;
		delete[] arr;
	}
	inStream.close();
}

