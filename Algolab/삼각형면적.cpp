#include <fstream>
#include<iostream>
using namespace std;
int  main(void)
{
ifstream inStream;
int testcase,fo,result,h;

 inStream.open("input.txt");

inStream >> testcase ;
for(int k=0;k<testcase;k++)
{    result=0;
    inStream>>fo;
    int x[fo],y[fo];
    for(int g=0;g<fo;g++){
       inStream>> x[g]>>y[g];
    }
    for(int j=0;j<fo-1;j++){
       // h=(j+1)%fo;
        result+=(x[j]+x[j+1])*(y[j+1]-y[j]);
    }
    result+=(x[fo-1]+x[0])*(y[0]-y[fo-1]);
    if(result<0){result*=-1; cout<<result<<" "<<-1<<endl;}
    else if(result>0){cout<<result<<" "<<1<<endl;}
    else{cout<<result<<" "<<0<<endl;}

}
return 0;
}
