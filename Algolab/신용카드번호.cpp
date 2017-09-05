#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream inStream;
   int numTestCases,length,sum;
   inStream.open("input.txt");
   inStream >> numTestCases;
   for (int i = 0; i < numTestCases; i++)
   {   string str;
       inStream >> str;
       length=str.size();
       sum=0;
       if((str[0]=='3'&&length==15)||(str[0]=='3'&&length==14)||
          (str[0]=='6'&&length==16)||(str[0]=='5'&&length==16)||
          (str[0]=='4'&&(length==13||length==16))){

              for(int j=0;j<length-1;j++){
                if(j%2==1)
                    sum+=str[length-2-j]-'0';
                else{
                    if((str[length-2-j]-'0')*2>=10)
                        sum-=9;
                    sum+=(str[length-2-j]-'0')*2;

                    }

              }
              if(str[length-1]-'0'==0&&(sum%10==0))
                cout<<1<<endl;
              else if((10-sum%10)==(str[length-1]-'0'))
                cout<<1<<endl;
              else
                cout<<0<<endl;
       }
       else
        cout<<0<<endl;

   }
   inStream.close();
   return 0;
}
