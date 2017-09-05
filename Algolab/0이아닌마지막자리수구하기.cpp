#include <fstream>
#include<iostream>

using namespace std;
int  main(void)
{
ifstream inStream;
int testcase,num,count1=0,count2=0,zero_count,end_num,numcase;

     inStream.open("input.txt");

    inStream >> testcase ;
    for(int k=0;k<testcase;k++)
    {
        end_num=1,zero_count=0;
        count1=0,count2=0;
        inStream >> numcase;

        while(numcase--){
           inStream >> num;


                while(num%2==0){
                     count1++;
                     num/=2;}
                while(num%5==0){
                    count2++;
                     num/=5;
                }
                    end_num*=num%10;
                    end_num%=10;

           }

        if(count1>count2){
           zero_count=count2;
            for(int j=0;j<count1-count2;j++){
                end_num*=2;
                end_num%=10;
            }
        }
        else {
            zero_count=count1;
            for(int j=0;j<count2-count1;j++){
                end_num*=5;
                end_num%=10;
            }
        }
       cout<<end_num<<" "<<zero_count;
       cout<<endl;

    }
    return 0;
}
