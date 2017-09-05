#include <fstream>
#include<iostream>
using namespace std;
int  main(void)
{
ifstream inStream;
int testcase,num[8];
 inStream.open("input.txt");

inStream >> testcase ;
for(int k=0;k<testcase;k++)
{   int l=0;
    inStream>>num[0]>>num[1]>>num[2]>>num[3];
    inStream>>num[4]>>num[5]>>num[6]>>num[7];
    if(num[0]!=num[2]){l=4;}
    if(num[1+l]>num[3+l])
    {
        int a=num[3+l];
        num[3+l]=num[1+l];
        num[1+l]=a;
    }
    if(num[4-l]>num[6-l])
    {
        int a=num[6-l];
        num[6-l]=num[4-l];
        num[4-l]=a;
    }
    if(num[1+l]<=num[5-l]&&num[5-l]<=num[3+l]&&num[4-l]<=num[0+l]&&num[0+l]<=num[6-l]){
           if(num[5-l]==num[1+l]||num[5-l]==num[3+l]||num[0+l]==num[4-l]||num[0+l]==num[6-l]){ cout<<2<<endl;}
           else{cout<<1<<endl;}
           }
    else {cout<<0<<endl;}

}
return 0;
}
