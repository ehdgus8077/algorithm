#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
   ifstream inStream;
   int numTestCases,num,idx,result,temp;
   int arr[6][7];
   inStream.open("input.txt");
   inStream >> numTestCases;
   while (numTestCases--)
   {
    int check[7]={0,};
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){

            arr[i][j]=0;
        }
    }
    inStream >> num;
    temp=0;
    for(int i=0;i<num;i++){
        inStream >> idx;
        if(i%2==0)
            arr[5-check[idx-1]][idx-1]=1;
        else
            arr[5-check[idx-1]][idx-1]=2;
        check[idx-1]++;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            result=arr[i][j];
            if(result!=0&&result==arr[i][j+1]&&result==arr[i][j+2]&&result==arr[i][j+3]){
                cout<<result<<endl;
                 temp=1;
                break;
            }
            if(result!=0&&result==arr[i+1][j]&&result==arr[i+2][j]&&result==arr[i+3][j]){
                cout<<result<<endl;
                temp=1;
                break;
            }
             if(result!=0&&result==arr[i+1][j+1]&&result==arr[i+2][j+2]&&result==arr[i+3][j+3]){
                cout<<result<<endl;
                temp=1;
                break;
            }
            result=arr[i+3][j];
            if(result!=0&&result==arr[i+3][j+1]&&result==arr[i+3][j+2]&&result==arr[i+3][j+3]){
                cout<<result<<endl;
                temp=1;
                break;
            }
            result=arr[i][j+3];
            if(result!=0&&result==arr[i+1][j+3]&&result==arr[i+2][j+3]&&result==arr[i+3][j+3]){
                cout<<result<<endl;
                temp=1;
                break;
            }

            result=arr[5-i][j];
            if(result!=0&&result==arr[5-i-1][j+1]&&result==arr[5-i-2][j+2]&&result==arr[5-i-3][j+3]){
                cout<<result<<endl;
                temp=1;
                break;
            }


        }
        if(temp==1)
            break;
    }
        if(temp==0)
            cout<<0<<endl;
   }
   inStream.close();
   return 0;
}
