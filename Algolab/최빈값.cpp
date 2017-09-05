#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
   ifstream inStream("input.txt");
   int numTestCases,count,numIntegers,j,target;
   int count2;

   inStream >> numTestCases;
   for (int i = 0; i < numTestCases; i++)
   {
      inStream >> numIntegers;
      int a[numIntegers];
      for(int l=0;l<numIntegers;l++){
        inStream >> a[l];
      }

      sort(a,a+numIntegers);
      count2=0;
      j=0;
      target=a[0];
      count=1;
      for(int l=1;l<numIntegers;l++){
        if(target==a[l]){count++; }
        else{

            if(count>count2){count2=count; j=0; a[j]=target; j++; }
            else if(count==count2){
               a[j]=target; j++;
            }
            target=a[l];
            count=1;
        }
      }
        if(count>count2){count2=count; j=0; a[j]=target; j++; }
            else if(count==count2){
               a[j]=target; j++;
            }
        cout<<j<<" "<<count2<<" ";
        for(int l=0;l<j;l++){
            cout<<a[l]<<" ";
        }
        cout<<endl;

   }
   inStream.close();
   return 0;         //close input file
}
