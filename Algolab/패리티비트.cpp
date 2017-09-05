#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
   ifstream inStream;
   int numTestCases,count=0,numIntegers,result=0;

   inStream.open("input.txt");   //open input file
   if (inStream.fail())
   {
      cerr << "Input file opening failed.\n";
      exit(1);
   }

   inStream >> numTestCases;   //read the number of test cases.

   for (int i = 0; i < numTestCases; i++)
   {

      inStream >> numIntegers;
      result=numIntegers;
      while(numIntegers>1){
        if(numIntegers/2!=0){
            count+=numIntegers%2;
            numIntegers/=2;
            }

      }

      if((numIntegers+count)%2==1){
        cout<<2147483648+result<<endl;
      }
      else{
         cout<<result<<endl;
      }

       count=0;         //마지막으로 21의 자리 남기기
   }
   inStream.close();
   return 0;         //close input file
}
