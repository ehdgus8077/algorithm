#include <fstream>
#include<iostream>
using namespace std;
int  main(void)
{
ifstream inStream;
int testcase,num;
 inStream.open("input.txt");

inStream >> testcase ;
for(int k=0;k<testcase;k++)
{int sum=1,quan=1, j=2;
   inStream >>num;
   while(num/j>=j){
    if(num%j==0){
        sum+=num/j+j;
        quan+=2;
       if(num/j==j){quan--; sum-=j;}
    }
    j++;
   }
    cout<<quan<<" "<<sum<<endl;
}
return 0;
}
