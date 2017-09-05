#include <iostream>
#include <fstream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
   ifstream inStream("input.txt");
   int numTestCases,num;
   inStream >> numTestCases;
   vector<int> a;
   for(int i=1;;i*=2){
        for(int j=1;;j*=3){
           for(int k=1;;k*=5){
                if(i*k*j>398580750 ){break;}
                a.push_back(i*k*j);
            }
            if(i*j>398580750 ){break;}
       }
        if(i>398580750 ){break;}
   }
   sort(a.begin(),a.end());

   for (int i = 0; i < numTestCases; i++)
   {    inStream>> num;
        cout<<a.at(num-1)<<endl;

   }

   inStream.close();
   return 0;         //close input file
}
