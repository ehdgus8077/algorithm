#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

class MyDigitalClock
{
private:
     int hour;
     int min;
     bool am_pm;
public:
     friend ostream& operator<< (ostream&, const MyDigitalClock&);
     // constructors
     MyDigitalClock (char clock[]);
     MyDigitalClock tick();
     MyDigitalClock operator++(int);
     MyDigitalClock operator--(int);
     MyDigitalClock untick();
     MyDigitalClock operator++(); // prefix, ++
     MyDigitalClock operator--(); // prefix, --c

};

MyDigitalClock::MyDigitalClock (char clock[])
{
    hour=(clock[0]-'0')*10 + (clock[1]-'0') ;
    min=(clock[3]-'0')*10 + (clock[4]-'0');
    if (clock[5] == 'P')
      am_pm = true;
    else
      am_pm = false;
}
MyDigitalClock MyDigitalClock::tick()
{
     ++min;
     if(min == 60)
     {
         hour++;
         min = 0;
     }
     if(hour == 13)
        hour = 1;
     if(hour == 12 && min == 0)
        am_pm = !am_pm;
     return *this;
}
MyDigitalClock MyDigitalClock::untick()
{
     --min;
     if(min == -1)
     {
        hour--;
        min = 59;
     }
     if(hour == 0)
        hour = 12;

     if(hour == 11 && min == 59)
        am_pm = !am_pm;
    return *this;

}
MyDigitalClock MyDigitalClock::operator ++()
{
    return tick();
}

MyDigitalClock MyDigitalClock::operator --()
{
    return untick();
}
MyDigitalClock MyDigitalClock::operator ++(int)
{
     MyDigitalClock c = *this;
     tick();
     return c;
}
MyDigitalClock MyDigitalClock::operator --(int)
{
     MyDigitalClock c = *this;
     untick();
     return c;
}
ostream& operator<<(ostream& oStream, const MyDigitalClock& c)
{
     oStream << setfill('0') << setw(2) << c.hour<< ':' << setw(2) << c.min;
     if(!c.am_pm)
        oStream << "AM";
     else
        oStream << "PM";
     oStream << endl;
     return oStream;
}
int main()
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
     for (int i=0; i<numTestCases; i++)
     {
         char clock[8];
         int lap;
         inStream >> clock >> lap;
         MyDigitalClock digitalClock(clock);
         for(int j=0; j<abs(lap); j++){
         if(lap > 0)
            digitalClock++;
         else
            --digitalClock;}
         cout << digitalClock;
     }
     inStream.close();

     return 0;
}
