#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream inStream;
   int numTestCases,k,sum;
   inStream.open("input.txt");
   inStream >> numTestCases;
   for (int i = 0; i < numTestCases; i++)
   {   string str;
        inStream >>str;
        if(str.size()!=13||str[str.size()-1]=='-'||str[str.size()-2]!='-'){
            cout<<0<<endl;
            continue;
        }

        int arr[4]={0}, count=0,num=0;
        k=0; sum=0;
        for( int j=0;j<str.size()-1;j++){
             if(str[j]=='-'){
                k++;
                if(count==0||k>3||(k==1&&count>5)
                    ||(k==2&&count>7)||(k==3&&count>6)||(k==4&&count>1)){
                    cout<<0<<endl;
                    num=0;
                    break;
                    }

                count=0;
                }
            else{

                if(!(str[j]-'0'>=0&&str[j]-'0'<10)){
                        num=0;
                    cout<<0<<endl;
                    break;
                }
                else
                    sum+=(str[j]-'0')*(10-num);
                count++; num++;
            }

        }
        if(num>8){
            sum%=11;
            if(k==3&&(sum==0&&str[str.size()-1]-'0'==0||(sum==1&&str[str.size()-1]=='X')||
               (11-sum)==str[str.size()-1]-'0'))
               cout<<1<<endl;
            else
               cout<<0<<endl;
        }
    }


   inStream.close();
   return 0;
}
