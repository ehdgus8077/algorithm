#include <fstream>
#include<iostream>
using namespace std;
int  main(void)
{
ifstream inStream;
int testcase,num,x,y,sum=0;

     inStream.open("input.txt");

    inStream >> testcase ;
    for(int k=0;k<testcase;k++)
    {
        inStream >> num;
        int arr[num];
        for( int i=0;i<num;i++){
            inStream >> x;
            arr[i]=x;
        }
        inStream >> y;

        cout<<num-y+1<<" ";
        for( int i=0;i<num-y+1;i++){

            for( int j=0;j<y;j++){
                sum+=arr[i+j];
            }
            cout<<sum/y<<" ";
            sum=0;
        }
        cout<<endl;

    }
    return 0;
}
