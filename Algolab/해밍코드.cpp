#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
   ifstream inStream;
   int numTestCases,check,num,result,count[5],k,sum,pow_num;
   inStream.open("input.txt");
   inStream >> numTestCases;
   for (int i = 0; i < numTestCases; i++)
   {    count[0]=0; count[1]=0; count[2]=0; count[3]=0; count[4]=0;
        k=0; sum=0;
     inStream >> check >> num;
     if(check==0){
        result=(((num/2048*4096+num%2048)/16*32+num%16)/2*4+num%2)*4;
        num=result;
     }
     else
        result=num;

     for(int j=1;j<32;j++){

        if(result%2==1&&j%2==1)
            count[0]++;
        if(result%2==1&&(j%4>1))
            count[1]++;
        if(result%2==1&&(j%8>3))
            count[2]++;
        if(result%2==1&&(j%16>7))
            count[3]++;
        if(result%2==1&&(j>15))
            count[4]++;

        result/=2;
        if(result==0)
            break;
     }
     count[0]%=2; count[1]%=2; count[2]%=2; count[3]%=2; count[4]%=2;
     if(check==0){
        num+=count[0]+count[1]*2+count[2]*8+count[3]*128+count[4]*32768;
        cout<<num<<endl;
     }
     else{
        k=1;
        for(int j=0;j<5;j++){

                if(count[j]==1)
                    sum+=k;
                k*=2;
        }
        if(sum!=0){
            pow_num=pow(2,sum-1);
            if(num/pow_num%2==0)
                num+=pow_num;
            else
                num-=pow_num;
        }
        result=(((num/65536*32768+num%32768)/256*128+num%128)/16*8+num%8)/4;
        cout<<result<<endl;
     }
   }
   inStream.close();
   return 0;
}
