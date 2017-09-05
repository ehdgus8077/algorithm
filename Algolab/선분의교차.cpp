#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class MyPoint
{
private:
  int x, y;

public:
// constructors
  MyPoint ();
  MyPoint (int coordX, int coordY);
  MyPoint (const MyPoint& p);
// accessor functions
  int getX() const;
  int getY() const;
// mutator function
  void setX(int x);
  void setY(int y);
// comparison operators
  bool operator== (const MyPoint& p) const;
  bool operator!= (const MyPoint& p) const;
// utility functions
  int dist2sqr(const MyPoint& p) const; // 직선거리(Euclidean distance)의 제곱을 계산
  int dist1(const MyPoint& p) const;
// 직각거리(rectilinear distance)를 계산

};

MyPoint::MyPoint () :x(0), y(0) {}

MyPoint::MyPoint (int coordX, int coordY) :x(coordX), y(coordY){
}
MyPoint::MyPoint (const MyPoint& p)
{
   x = p.x;
   y = p.y;
}

int MyPoint::getX () const
{
  return x;
}
int MyPoint::getY () const
{
  return y;
}
void MyPoint::setX (int coordX)
{
  x = coordX;
}
void MyPoint::setY (int coordY)
{
  y = coordY;
}
bool MyPoint::operator== (const MyPoint& p) const
{
  return (p.x == x && p.y == y);
}
bool MyPoint::operator!= (const MyPoint& p) const
{
  return !operator == (p);
}
// 직선거리(Euclidean distance)의 제곱을 계산
int MyPoint::dist2sqr(const MyPoint& p) const
{
  return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y);
}
// 직각거리(rectilinear distance)를 계산
int MyPoint::dist1(const MyPoint& p) const
{
  return abs(p.x - x) + abs(p.y - y);
}
class MyLineSegment
{
private:
 MyPoint p1, p2;
 int getArea2(const MyPoint &p) const;
public:

 MyLineSegment ();
 MyLineSegment (const MyPoint& p, const MyPoint& q);
 MyLineSegment (const MyLineSegment& seg);

 bool isEndOfSegment(const MyPoint & p) const;
 bool isOnSegment(const MyPoint& p) const;
 bool properIntersection(const MyLineSegment &s) const;
 bool improperIntersection(const MyLineSegment &s) const;
 bool isLeftSide(const MyPoint &p) const;
 bool isCollinear(const MyPoint &p) const;

 int length2sqr() const; // square of (Euclidean) length

};

MyLineSegment::MyLineSegment ()
: p1(0,0), p2(0,0)
{
}

MyLineSegment::MyLineSegment (const MyPoint& p, const MyPoint& q)
: p1(p), p2(q)
{
}

MyLineSegment::MyLineSegment (const MyLineSegment& s)
: p1(s.p1), p2(s.p2)
{
}

// 점 p 가 삼각형의 꼭지점에 위치하는 지를 검사
bool MyLineSegment::isEndOfSegment(const MyPoint & p) const
{

    if(isCollinear(p)==1){

        if(p1.getX()>p2.getX()){
           if(p.getX() <=p1.getX()&&p.getX()>= p2.getX())
                return true;
           else
                return false;

        }
        else {if(p.getX()>=p1.getX()&&p.getX()<= p2.getX())
                return true;
              else
                return false;
        }
    }
    else{
        return false;
    }
}

// 점 p 가 삼각형의 꼭지점을 제외한 삼각형의 변 위에 위치하는 지를 검사
bool MyLineSegment::isOnSegment(const MyPoint& p) const
{
}

bool MyLineSegment::properIntersection(const MyLineSegment &s) const

{
}

bool MyLineSegment::improperIntersection(const MyLineSegment &s) const
{
}

// square of (Euclidean) length
int MyLineSegment::length2sqr() const
{
return p1.dist2sqr(p2);
}
// signed area of triangle p1, p2, p
int MyLineSegment::getArea2(const MyPoint &p) const // signed area of triangle p1, p2, p
{
  int p1x, p2x, px, p1y, p2y, py;
  p1x = p1.getX();
  p1y = p1.getY();
  p2x = p2.getX();
  p2y = p2.getY();
  px  = p.getX();
  py  = p.getY();

  return p1x * p2y - p1y * p2x + p1y * px - p1x * py +  p2x * py - px * p2y;

}

bool MyLineSegment::isLeftSide(const MyPoint &p) const
{
  return getArea2(p) > 0;
}
// test whether p1, p2, p3 is collinear
bool MyLineSegment::isCollinear(const MyPoint &p) const
{
  return getArea2(p) == 0;
}
int main()
{
   ifstream inStream;
   int numTestCases;
   inStream.open("input.txt");
   inStream >> numTestCases;
   int arr[8];
   while (numTestCases--)
   {    for(int i=0;i<8;i++)
            inStream >> arr[i];
        MyPoint p1(arr[0],arr[1]); MyPoint p2(arr[2],arr[3]);
        MyPoint p3(arr[4],arr[5]); MyPoint p4(arr[6],arr[7]);
        MyLineSegment line1(p1,p2);
        MyLineSegment line2(p3,p4);
        if (!line1.isCollinear(p3) && !line1.isCollinear(p4) && !line2.isCollinear(p1) && !line2.isCollinear(p2)) {
            if (line1.isLeftSide(p3) != line1.isLeftSide(p4) && line2.isLeftSide(p1) != line2.isLeftSide(p2))
                    cout<<"1"<<endl;
            else
                cout<<"0"<<endl;
        }
        else{
            if (line1.isEndOfSegment(p3)||line1.isEndOfSegment(p4)||line2.isEndOfSegment(p1)||line2.isEndOfSegment(p2))
                cout<<"2"<<endl;
            else
                cout<<"0"<<endl;
        }
    }
   inStream.close();
   return 0;
}
