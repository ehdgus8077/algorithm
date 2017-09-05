#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
   ifstream inStream("input.txt");
   int numTestCases,num,numIntegers,max,count2,count1,count3;
   inStream >> numTestCases;
   for (int i = 0; i < numTestCases; i++)
   {
      int x[132]={0};
      max=0,count2=0,count1=0,count3=0,num=0;
      inStream >> numIntegers;
      for(int l=0;l<numIntegers;l++){
        inStream >> num;
        if(max<num){max=num;}
        x[num]+=1;
      }

      inStream >> numIntegers;
      for(int l=0;l<numIntegers;l++){

        inStream >> num;
        if(max<num){max=num;}
        x[num]+=3;
        if(x[num]==4){count2++; count3++;}



      }
        cout<<count2<<" ";
     for(int j=0;j<=max;j++){
        if(x[j]==4){cout<<j<<" ";}
        else if(x[j]==1){count1++; count3++;}
        else if(x[j]==3){count3++;}
     }
        cout<<endl<<count3<<" ";
       for(int j=0;j<=max;j++){
        if(x[j]!=0){cout<<j<<" ";}
     }
      cout<<endl<<count1<<" ";
       for(int j=0;j<=max;j++){
        if(x[j]==1){cout<<j<<" ";}
     }
     cout<<endl;
   }
   inStream.close();
   return 0;         //close input file
}
