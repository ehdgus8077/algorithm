#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
   ifstream inStream;
   int numTestCases,num,count;
   inStream.open("input.txt");
   inStream >> numTestCases;
   while (numTestCases--)
   {
        inStream >> num;
        int arr[num][num]={0,};
        if(num%4!=0){
            int i=0;
            int j=(num-1)/2;
            arr[i][j]=4; arr[i][j+1]=1; arr[i+1][j]=2; arr[i+1][j+1]=3;
            for(int key=5;key<=num*num;key+=4){
                if((key/4)%(num/2)!=0){
                    i-=2; j+=2;}
                else
                    i+=2;
                if(i<0)
                    i=num-2;
                if(j>=num)
                    j=0;
                if(i>=num)
                    i=0;
                if((i/2>=0&&(i/2)<(num-2)/4)||((i/2)==(num-2)/4&&j!=(num-1)/2)||((i/2)==(num-2)/4+1&&j==(num-1)/2)){
                    arr[i][j]=key+3; arr[i][j+1]=key; arr[i+1][j]=key+1; arr[i+1][j+1]=key+2;// L
                }
                else if(((i/2)==(num-2)/4&&j==(num-1)/2)||((i/2)==(num-2)/4+1)){
                    arr[i][j]=key; arr[i][j+1]=key+3; arr[i+1][j]=key+1; arr[i+1][j+1]=key+2;//U
                }
                else{
                    arr[i][j]=key; arr[i][j+1]=key+3; arr[i+1][j]=key+2; arr[i+1][j+1]=key+1;//X
                }

            }

        }
        else{
             count=1;
            for(int row=0; row<num;row++){
                for(int col=0;col<num;col++){
                    arr[row][col]=count++;
                }
            }
            for(int i=0;i<num;i+=4){
                for(int j=0;j<num;j+=4){
                    for(int k=0;k<4;k++){
                        arr[i+k][j+k]=num*num+1-arr[i+k][j+k];
                        arr[i+k][j-k+3]=num*num+1-arr[i+k][j-k+3];
                    }
                }
            }
        }
        for(int row=0; row<num;row++){
            for(int col=0;col<num;col++){
                cout<<arr[row][col]<<" ";
            }
            cout<<endl;
        }
   }
   inStream.close();
   return 0;
}
