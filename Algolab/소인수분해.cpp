#include <fstream>
#include<iostream>
#include <vector>
using namespace std;
int  main(void)
{
ifstream inStream;
int testcase,num,count=0,c;

     inStream.open("input.txt");

    inStream >> testcase ;
    for(int k=0;k<testcase;k++)
    {   vector<int> ve;
        inStream >> num;
        int i=2;
        int c=0;
        count=0;
       while(true){
        if(num%i==0){
            if(count==0){ve.push_back(i);}
           num/=i;
           count++;
           }

        else {i++;
            if(count!=0){ve.push_back(count); c++;}
            if(num==1){break;}
            count=0;}
       }

       cout<<c<<" ";



        for (vector<int>::iterator iter=ve.begin(); iter != ve.end(); ++iter){
        cout << *iter << " ";
    }


       cout<<endl;

    }
    return 0;
}
