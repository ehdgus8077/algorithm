#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;



class myDate {
public:
	// Constructor (생성자)
	myDate(int year = 1582, int month = 1, int day = 1);
	// Accessor functions (접근자)
	int getDayOfMonth() const;
	int getMonth() const;
	int getYear() const;
	// Mutator functions (변경자)
	void setDayOfMonth(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int year, int month, int day);
	// Operators overloaded
	friend ostream &operator <<(ostream &outStream, const myDate& date);
	friend istream &operator >>(istream &inStream, myDate& date);
	friend myDate operator+(int num, myDate& ref);
	friend myDate operator-(int num, myDate& ref);
	int operator -(const myDate& date) const; // difference between two days
	myDate operator +(int num) const;
	myDate operator -(int num) const;
	myDate& operator ++(); // prefix increment
	myDate& operator --(); // prefix decrement
	myDate operator ++(int); // postfix increment
	myDate operator --(int); // postfix decrement
	myDate& operator =(const myDate& date);
	myDate& operator +=(int num);
	myDate& operator -=(int num);
	bool operator >(const myDate& date) const;
	bool operator >=(const myDate& date) const;
	bool operator <(const myDate& date) const;
	bool operator <=(const myDate& date) const;
	bool operator ==(const myDate& date) const;
	bool operator !=(const myDate& date) const;
	// utility functions
	bool isLeapYear() const; //윤년
	int getDayOfWeek() const; //0=Sunday, 1=Monday, ..., 6=Saturday
	int getDayOfYear() const; //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
	int getNumHolidays() const; //휴일수 계산
	int getNumSummerTimeDays() const; //써머타임 날짜수
	void printCalendarOfMonth() const; // 달력출력하기
private:
	// information hiding : implement as you wish
	int year, month, day;
	static int day_of_month[];
};

using namespace std;

int myDate::day_of_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

myDate::myDate(int year, int month, int day) : year(year), month(month), day(day) {

}
int myDate::getDayOfMonth() const {
	return day;
}
int myDate::getMonth() const {
	return month;
}
int myDate::getYear() const {
	return year;
}
void myDate::setDayOfMonth(int day) {
	this->day = day;
}
void myDate::setMonth(int month) {
	this->month = month;
}
void myDate::setYear(int year) {
	this->year = year;
}
void myDate::setDate(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}
int myDate::operator-(const myDate & date) const
{
	int num_1 = 0, num_2 = 0;
	myDate tmp;
	for (num_1 = 0;;num_1++) {
		if (tmp == date)
			break;
		tmp.day++;
		if (tmp.month == 2) {
			if (tmp.isLeapYear()) {
				if (tmp.day > day_of_month[tmp.month - 1] + 1) {
					tmp.month++;
					tmp.day = 1;
				}
			}
			else {
				if (tmp.day > day_of_month[tmp.month - 1]) {
					tmp.month++;
					tmp.day = 1;
				}
			}
		}
		else if (tmp.day > day_of_month[tmp.month - 1]) {
			tmp.month++;
			tmp.day = 1;
		}
		if (tmp.month > 12) {
			tmp.month = 1;
			tmp.year++;
		}
		if (tmp.year == 2008) {
			tmp.year = 2008;
		}

	}
	tmp.setDate(1582, 1, 1);
	for (num_2 = 0;;num_2++) {
		if (tmp == *this)
			break;
		tmp.day++;
		if (tmp.month == 2) {
			if (tmp.isLeapYear()) {
				if (tmp.day > day_of_month[tmp.month - 1] + 1) {
					tmp.month++;
					tmp.day = 1;
				}
			}
			else {
				if (tmp.day > day_of_month[tmp.month - 1]) {
					tmp.month++;
					tmp.day = 1;
				}
			}
		}
		else if (tmp.day > day_of_month[tmp.month - 1]) {
			tmp.month++;
			tmp.day = 1;
		}
		if (tmp.month > 12) {
			tmp.month = 1;
			tmp.year++;
		}
	}
	return num_2 - num_1;
}
myDate myDate::operator+(int num) const
{
	if (num < 0)
		return this->operator-(-num);
	else {
		myDate tmp(year, month, day);
		for (int i = 0;i < num;i++) {
			tmp.day++;
			if (tmp.month == 2) {
				if (tmp.isLeapYear()) {
					if (tmp.day > day_of_month[tmp.month - 1] + 1) {
						tmp.month++;
						tmp.day = 1;
					}
				}
				else {
					if (tmp.day > day_of_month[tmp.month - 1]) {
						tmp.month++;
						tmp.day = 1;
					}
				}
			}
			else if (tmp.day > day_of_month[tmp.month - 1]) {
				tmp.month++;
				tmp.day = 1;
			}
			if (tmp.month > 12) {
				tmp.month = 1;
				tmp.year++;
			}
		}
		return tmp;
	}
}
myDate myDate::operator-(int num) const
{
	if (num < 0)
		return this->operator+(-num);
	else {
		myDate tmp(year, month, day);
		for (int i = 0;i < num;i++) {
			tmp.day--;
			if (tmp.day == 0) {
				tmp.month--;
				if (tmp.month == 0) {
					tmp.month = 12;
					tmp.year--;
				}
				tmp.day = day_of_month[tmp.month - 1];
				if (tmp.month == 2 && tmp.isLeapYear())
					tmp.day++;
			}
		}
		return tmp;
	}
}
myDate & myDate::operator++()
{
	day++;
	if (month == 2 && isLeapYear()) {
		if (day > 29) {
			month++;
			day = 1;
		}
	}
	else if (day > day_of_month[month - 1]) {
		month++;
		day = 1;
	}
	if (month > 12) {
		month = 1;
		year++;
	}
	return *this;
}
myDate & myDate::operator--()
{
	day--;
	if (day == 0) {
		month--;
		if (month == 0) {
			year--;
			month = 12;
		}
		day = day_of_month[month - 1];
		if (month == 2 && isLeapYear())
			day++;
	}
	return *this;
}
myDate myDate::operator++(int)
{
	myDate retObj(year, month, day);
	day++;
	if (month == 2 && isLeapYear()) {
		if (day > 29) {
			month++;
			day = 1;
		}
	}
	else if (day > day_of_month[month - 1]) {
		month++;
		day = 1;
	}
	if (month > 12) {
		month = 1;
		year++;
	}
	return retObj;
}
myDate myDate::operator--(int)
{
	myDate retObj(year, month, day);
	day--;
	if (day == 0) {
		month--;
		if (month == 0) {
			year--;
			month = 12;
		}
		day = day_of_month[month - 1];
		if (month == 2 && isLeapYear())
			day++;
	}
	return retObj;
}
bool myDate::operator==(const myDate & date) const
{
	return (this->year == date.year && this->month == date.month && this->day == date.day);
}
bool myDate::operator!=(const myDate & date) const
{
	return !(this->operator==(date));
}
bool myDate::isLeapYear() const {
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}
int myDate::getDayOfWeek() const {
	int y = getYear();
	int m = getMonth();
	int d = getDayOfMonth();
	if (m <= 2)
	{
		y -= 1;
		m += 12;
	}
	int a = y / 100;
	int b = y % 100;
	return ((21 * a / 4) + (5 * b / 4) + (26 * (m + 1) / 10) + d - 1) % 7;
}
int myDate::getDayOfYear() const {

	int sum_day = 0;
	for (int i = 1;i < month;i++) {
		sum_day += day_of_month[i - 1];
		if (i == 2 && isLeapYear())
			sum_day += 1;
	}
	sum_day += day;
	return sum_day;
}

int myDate::getNumHolidays() const {
	myDate tmp(year, 1, 1);
	int cnt = 0;
	int sunday = 1 + (7 - tmp.getDayOfWeek() ) % 7;
	int saturday = 1 + (6 - tmp.getDayOfWeek());
	int day_cnt = 365;
	if (isLeapYear())
		day_cnt += 1;
	cnt += (day_cnt - sunday) / 7 + 1;
	cnt += (day_cnt - saturday) / 7 + 1;
	static int holiday_month[] = { 1, 3, 5, 6, 7, 8, 10, 12, 2, 2, 2, 5, 9, 9, 9 };
	static int holiday_day[] = {1, 1, 5, 6, 17, 15, 3, 25, 1, 2, 3, 15, 15, 16, 17};
	for (int i = 0;i < sizeof(holiday_day) / sizeof(int);i++) {
		tmp.setDate(year, holiday_month[i], holiday_day[i]);
		int day_of_week = tmp.getDayOfWeek();
		if (day_of_week != 0 && day_of_week != 6)
			cnt++;
	}
	return cnt;
}

int myDate::getNumSummerTimeDays() const
{
	myDate tmp(year, 3, 31);
	int day_of_week = tmp.getDayOfWeek();
	tmp.setDayOfMonth(31-day_of_week);
	int start = tmp.getDayOfYear();
	tmp.setDate(year, 10, 31);
	day_of_week = tmp.getDayOfWeek();
	tmp.setDayOfMonth(31 - day_of_week);
	int end = tmp.getDayOfYear();
	return end - start;
}

void myDate::printCalendarOfMonth() const {
	myDate tmp(year, month, 1);
	int h = tmp.getDayOfWeek();
	int number = 1;
	int end_of_month = day_of_month[month-1];
	if (month == 2 && isLeapYear())
		end_of_month++;
	cout << year << " " << month << endl;
	for (int i = 0;;i++) {
		if (h <= i) {
			if (number <= end_of_month)
				cout << number++ << " ";
			else
				cout << "0 ";
			if (i % 7 == 6) {
				if (number > end_of_month)
					break;
				cout << endl;
			}
		}
		else
			cout << "0 ";
	}
}

ostream & operator<<(ostream & outStream, const myDate & date)
{
	if (date.day < 10)
		cout << 0;
	cout << date.day;
	cout << '/';
	if (date.month < 10)
		cout << 0;
	cout << date.month;
	cout << '/';
	cout << date.year;
	return outStream;
}

istream & operator>>(istream & inStream, myDate & date)
{
	int y, m, d;
	inStream >> y >> m >> d;
	date.setDate(y, m, d);
	return inStream;
}

myDate operator+(int num, myDate & ref)
{
	if (num < 0)
		return ref - (-num);
	else
		return ref + num;
}

myDate operator-(int num, myDate & ref)
{
	if (num < 0)
		return ref + (-num);
	else
		return ref - num;
}

myDate & myDate::operator=(const myDate & date)
{
	year = date.year;
	month = date.month;
	day = date.day;
	return *this;
}

myDate & myDate::operator+=(int num)
{
	this->operator=(this->operator+(num));
	return *this;
}

myDate & myDate::operator-=(int num)
{
	this->operator=(this->operator-(num));
	return *this;
}

bool myDate::operator>(const myDate & date) const
{
	if (year > date.year)
		return true;
	else if (year == date.year)
		return getDayOfYear() > date.getDayOfYear();
	else
		return false;
}

bool myDate::operator>=(const myDate & date) const
{
	return (this->operator>(date) || this->operator==(date));
}

bool myDate::operator<(const myDate & date) const
{
	if (year < date.year)
		return true;
	else if (year == date.year)
		return getDayOfYear() < date.getDayOfYear();
	else
		return false;
}

bool myDate::operator<=(const myDate & date) const
{
	return (this->operator<(date) || this->operator==(date));
}

const int MAX_SIZE = 100;
void testSimpleCase();
void testDataFromFile();
const myDate& getMinDate(const myDate dates[], int n);
const myDate& getMaxDate(const myDate dates[], int n);
void sortDates(myDate dates[], int n);
void swap(myDate &d1, myDate &d2);
int main(void)
{
	testSimpleCase();
	testDataFromFile();
	return 0;
}
void testSimpleCase()
{
	myDate d1, d2(99999, 12, 31), d3(2008, 2, 20);
	myDate d4, d5, d6, d7, d8, d9(d3);
	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3 << endl;
	cout << d9 << endl;
	cout << d3 - d1 << endl;
	d4 = d5 = d6 = d7 = d8 = d9;
	cout << ++d7 + 365 << " " << d7 << endl;
	cout << d7++ + 365 << " " << d7 << endl;
	cout << --d7 - 365 << " " << d7 << endl;
	cout << d7-- - 365 << " " << d7 << endl;
	cout << -365 + d7 << " " << d7 << endl;
	d4.setDate(2999, 12, 31);
	d5.setDate(2000, 1, 1);
	d6.setDate(3000, 1, 1);
	d6 += d5 - d4;
	cout << d6 << endl;
	d6 -= d5 - d4;
	cout << d6 << endl;
	cout << (d6 == d8) << " " << (d6 != d8) << endl;
	cout << (d7 == d8) << " " << (d7 != d8) << endl;
	cout << (d6 >= d8) << " " << (d6 > d8) << endl;
	cout << (d6 <= d8) << " " << (d6 < d8) << endl;
	cout << (d7 >= d8) << " " << (d7 > d8) << endl;
	cout << (d7 <= d8) << " " << (d7 < d8) << endl;
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
		int j;
		int numData;
		myDate dates[MAX_SIZE], minDate, maxDate;
		inStream >> numData;
		for (j = 0; j<numData; j++)
			inStream >> dates[j];
		minDate = getMinDate(dates, numData);
		maxDate = getMaxDate(dates, numData);
		cout << minDate << " " << maxDate << " " << maxDate - minDate << endl;
		sortDates(dates, numData);
		for (j = 0; j<numData; j++)
			cout << dates[j] << " ";
		cout << endl;
	}
	inStream.close();
}


// 날짜 중에서 가장 이른 날짜를 계산함
const myDate& getMinDate(const myDate dates[], int n)
{
	int min = 0;
	for (int i = 1; i<n; i++)
	{
		if (dates[min] > dates[i])
			min = i;
	}
	return dates[min];
}
// 날짜 중에서 가장 늦은 날짜를 계산함
const myDate& getMaxDate(const myDate dates[], int n)
{
	int max = 0;
	for (int i = 1; i<n; i++)
	{
		if (dates[max] < dates[i])
			max = i;
	}
	return dates[max];
}
//
// 날짜를 오름차순으로 정렬함
//
void sortDates(myDate dates[], int n)
{
	for (int i = n - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			if (dates[j] > dates[j + 1])
				swap(dates[j], dates[j + 1]);
}
// 두 날짜를 서로 바꿈
void swap(myDate &d1, myDate &d2)
{
	myDate tmp;
	tmp = d1;
	d1 = d2;
	d2 = tmp;
}
