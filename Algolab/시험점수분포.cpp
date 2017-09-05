#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
   ifstream inStream("input.txt");
   int numTestCases,count,numIntegers,j,target;

   inStream >> numTestCases;
   for (int i = 0; i < numTestCases; i++)
   {
      inStream >> numIntegers;
      int a[numIntegers];
      for(int l=0;l<numIntegers;l++){
        inStream >> a[l];
      }

      sort(a,a+numIntegers);
      j=0;
      target=a[0];
      count=1;
      for(int l=1;l<numIntegers;l++){

        if(target==a[l]){count++; }
        else{
            cout<<target<<" "<<count<<" ";
            target=a[l];
            count=1;
        }
      }
        cout<<target<<" "<<count<<endl;

   }
   inStream.close();
   return 0;         //close input file
}
