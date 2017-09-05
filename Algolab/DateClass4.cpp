#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class myDate
{
// friend 함수
    friend ostream &operator <<(ostream &outStream, const myDate& date);
    friend istream &operator >>(istream &inStream, myDate& date);
    friend myDate operator +(int num, const myDate& date);
    friend myDate operator -(int num, const myDate& date);

public:
// Constructor (생성자)
    myDate(int y=1582, int m=1, int d=1);
// Copy Constructor (복사 생성자)
   // myDate(const myDate& date);
// Accessor functions (접근자)
    int getDayOfMonth() const;
    int getMonth() const;
    int getYear() const;
// Mutator functions (변경자)
    void setDayOfMonth(int day);
    void setMonth(int month);
    void setYear(int year);
    void setDate(int s_year, int s_month, int s_day);
// Operators overloaded
    int operator -(const myDate& date) ; // difference between two days
    myDate operator +(int num) ;
    myDate operator -(int num) ;
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
    int getNumSummerTimeDays()const; //써머타임 날짜수
    void printCalendarOfMonth() const; // 달력출력하기
    int month_days(int y, int m);
private:
    int year;
    int month;
    int day;
// information hiding : implement as you wish
};
myDate::myDate(int y, int m, int d):year(y),month(m),day(d){}
void myDate::setDate(int s_year, int s_month, int s_day)
{
    year=s_year;
    month=s_month;
    day=s_day;

}

int myDate::getDayOfMonth() const
{
    return day;
}
int myDate::getMonth() const
{
    return month;
}
int myDate::getYear() const
{
    return year;
}

void myDate::setDayOfMonth(int s_day)
{
    day=s_day;
}
void myDate::setMonth(int s_month)
{
    month=s_month;
}
void myDate::setYear(int s_year)
{
    year=s_year;
}
bool myDate::isLeapYear() const //윤년
{
    if((year%4==0&&year%100!=0)||year%400==0)
        return true;
    else
        return false;
}
int myDate::getDayOfWeek() const //0=Sunday, 1=Monday, ..., 6=Saturday
{
    int d=day;
    d+=(year-1582)*365;
    for(int i=1; i<month; i++)
    {
        switch(i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            d += 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            d += 30;
            break;
        case 2:
            d += 28;
            break;
        }
    }
    if(month<=2)
    {
        d+=((year-1)/4-(year-1)/100+(year-1)/400)-(1582/4-1582/100+1582/400);
    }
    else
        d+=(year/4-year/100+year/400)-(1582/4-1582/100+1582/400);
    return (d+4)%7;


}
int myDate::getDayOfYear() const //1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
{
    int days=0;
    for(int i=1; i<month; ++i)
    {
        if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
            days+=31;
        else if(i==2)
        {
            if(isLeapYear())
                days+=29;
            else
                days+=28;
        }
        else
            days+=30;
    }
    return days+day;

}
ostream& operator <<(ostream &outStream, const myDate& date){
    if(date.day<10)
        outStream << 0;
    outStream<<date.day<<'/';
    if(date.month<10)
        outStream << 0;
    outStream <<date.month<<'/'<<date.year;
    return outStream;
}
istream &operator >>(istream &inStream, myDate& date){
    int y, m, d;
	inStream >> y >> m >> d;
	date.setDate(y, m, d);
	return inStream;
}
int myDate::month_days(int y , int m){
    int j;
    switch(m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        j= 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        j= 30;
        break;
    case 2:
        if((y%4==0&&y%100!=0)||y%400==0)
            j=29;
        else
            j=28;
        break;
    }
    return j;
}

myDate myDate::operator +(int num) {

   // cout<<"!!"<<num<<"-"<<year<<"-"<<month<<"-"<<day<<endl;
    int y=year;
    int m=month;
    int d=day;
    int j=month_days(y,m);

    while(num--){
        d++;
        if(d>j){
           d=1;
           m++;
           if(m>12){
                m=1;
                y++;
           }
          j=month_days(y,m);

        }
    }

    myDate nDate(y,m,d);
    return nDate;
}
myDate operator-(int num, myDate & date)
{
	if (num < 0)
		return date + (-num);
	else
		return date - num;
}
myDate& myDate::operator --(){
     day--;
        if(day<1){
           day=month_days(year,month);
           month--;
           if(month<1){
                month=12;
                year--;
           }
        }
    return *this;
}
myDate myDate::operator -(int num) {

    int y=year;
    int m=month;
    int d=day;

    while(num--){
        d--;
        if(d<1){
            m--;


           if(m<1){
                m=12;
                y--;
           }
           d=month_days(y,m);


        }
    }
    myDate nDate(y,m,d);
    return nDate;
}
myDate operator +(int num,  myDate& date){
    if (num < 0)
		return date - (-num);
	else
		return date + num;
}

myDate& myDate::operator ++(){
     day++;
     int j=month_days(year,month);
        if(day>j){
           day=1;
           month++;
           if(month>12){
                month=1;
                year++;
           }
          int j=month_days(year,month);
        }
    return *this;
}
myDate myDate::operator --(int){
     myDate nDate(year,month,day);
     day--;

        if(day<1){
           day=month_days(year,month);
           month--;
           if(month<1){
                month=12;
                year--;
           }
        }

    return nDate;
}
myDate myDate::operator ++(int){
    myDate nDate(year,month,day);
     day++;
     int j=month_days(year,month);
        if(day>j){
           day=1;
           month++;
           if(month>12){
                month=1;
                year++;
           }
          int j=month_days(year,month);
        }

    return nDate;
}
bool myDate::operator==(const myDate & date) const
{
	return (this->year == date.year && this->month == date.month && this->day == date.day);
}
bool myDate::operator!=(const myDate & date) const
{
	return !(this->operator==(date));
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

    if (num < 0){
        num*=-1;
        while(num--){
            day--;
            if(day<1){
               day=month_days(year,month);
               month--;
               if(month<1){
                    month=12;
                    year--;
               }
            }
        }
    }
	else{
         int j=month_days(year,month);
         while(num--){
            day++;
            if(day>j){
               day=1;
               month++;
               if(month>12){
                    month=1;
                    year++;
               }
               j=month_days(year,month);
            }
        }
	}
	return *this;
}

myDate & myDate::operator-=(int num)
{
    if (num < 0){
        num*=-1;
		int j=month_days(year,month);
         while(num--){
            day++;
            if(day>j){
               day=1;
               month++;
               if(month>12){
                    month=1;
                    year++;
               }
               j=month_days(year,month);
            }
        }
    }
	else{
        while(num--){
            day--;
            if(day<1){
               day=month_days(year,month);
               month--;
               if(month<1){
                    month=12;
                    year--;
               }
            }
        }
	}
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
int myDate::operator-(myDate const & md){
        int y=year;
        int m=month;
        int d=day;
        d+=(y-1582)*365;
          for(int i=1;i<m;i++){
          switch(i) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
          d += 31;
          break;
        case 4: case 6: case 9: case 11:
          d += 30;
          break;
        case 2:
          d += 28;
          break;
      }
        }
        if(m<=2){y-=1;}
        d+=(y/4-y/100+y/400)-(1582/4-1582/100+1582/400);

        y=md.year;
        m=md.month;
        d-=md.day;
        d-=(y-1582)*365;
          for(int i=1;i<m;i++){
          switch(i) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
          d -= 31;
          break;
        case 4: case 6: case 9: case 11:
          d -= 30;
          break;
        case 2:
          d -= 28;
          break;
      }
        }
        if(m<=2){y-=1;}
        d-=(y/4-y/100+y/400)-(1582/4-1582/100+1582/400);

    return d;

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
void testSimpleCase(){


    myDate d1, d2(99999,12,31), d3(2008,2,20);
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
    for(int i=0; i<numTestCases; i++)
    {
        int j;
        int numData;
        myDate dates[MAX_SIZE], minDate, maxDate;
        inStream >> numData;
        for(j=0; j<numData; j++)
            inStream >> dates[j];
        minDate = getMinDate(dates, numData);
        maxDate = getMaxDate(dates, numData);
        cout << minDate << " " << maxDate << " " << maxDate - minDate << endl;
        sortDates(dates, numData);
        for(j=0; j<numData; j++)
            cout << dates[j] << " ";
        cout << endl;
    }
    inStream.close();
}
// 날짜 중에서 가장 이른 날짜를 계산함
const myDate& getMinDate(const myDate dates[], int n)
{
    int min = 0;
    for(int i=1; i<n; i++)
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
    for(int i=1; i<n; i++)
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
    for(int i=n-2; i>=0; i--)
        for(int j=0; j<=i; j++)
            if(dates[j] > dates[j+1])
                swap(dates[j], dates[j+1]);
}
// 두 날짜를 서로 바꿈
void swap(myDate &d1, myDate &d2)
{
    myDate tmp;
    tmp = d1;
    d1 = d2;
    d2 = tmp;
}
