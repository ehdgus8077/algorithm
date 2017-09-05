#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream inStream;
   int numTestCases,fir,sec,count[3];

   inStream.open("input.txt");
   inStream >> numTestCases;
   for (int i = 0; i < numTestCases; i++)
   {  count[0]=0;
      count[1]=0;
      count[2]=0;
      inStream >>fir >>sec;
      while(fir!=0||sec!=0){
        if(fir%2!=sec%2)
            count[0]++;
        if(fir%2==1)
            count[1]++;
        if(sec%2==1)
            count[2]++;
        fir/=2;
        sec/=2;

      }
      cout<<count[1]<<" "<<count[2]<<" "<<count[0]<<endl;
   }
   inStream.close();
   return 0;         //close input file
}
