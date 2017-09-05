#include <iostream>
#include <fstream>
using namespace std;

bool result(int arr[][5]){
    for( int i=0;i<5;i++){
        if(0==arr[0][i]+arr[1][i]+arr[2][i]+arr[3][i]+arr[4][i])
            return 1;
        if(0==arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]+arr[i][4])
            return 1;

    }

    if(0==arr[0][0]+arr[1][1]+arr[2][2]+arr[3][3]+arr[4][4])
            return 1;
    if(0==arr[0][4]+arr[1][3]+arr[2][2]+arr[3][1]+arr[4][0])
            return 1;
    if(0==arr[0][0]+arr[4][4]+arr[0][4]+arr[4][0])
            return 1;
    return 0;
}
int main()
{
   ifstream inStream;
   int arr[5][5];
   int check[75];
   int numTestCases,num;
   inStream.open("input.txt");
   inStream >> numTestCases;
   while (numTestCases--)
   {
       for( int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                inStream >> num;
                arr[i][j]=num;
            }
       }
       for( int i=0;i<75;i++)
            inStream >> check[i];
       for( int i=0;i<75;i++){
            for( int k=0;k<5;k++){
                for(int j=0;j<5;j++){
                    if(arr[k][j]==check[i]){
                        arr[k][j]=0;
                        k=5;
                        j=5;
                    }
                }
            }
            if(i>2)
                if(result(arr)){
                    cout<<i+1<<endl;
                    break;
                }
       }

   }
   inStream.close();
   return 0;
}
