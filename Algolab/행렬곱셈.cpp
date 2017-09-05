#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    int testcase,x,y,z,num ;
    inStream >> testcase;
    while(testcase--){
         inStream >>x>>y>>z;
         int arr[x][y];
         int arr2[y][z];
         for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                inStream >>num;
                arr[i][j]=num;

            }
         }
         for(int i=0;i<y;i++){
            for(int j=0;j<z;j++){
                 inStream >>num;
                arr2[i][j]=num;
            }
         }
         int k=0, sum=0;
         for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                sum+=arr[i][j]*arr2[j][k];
            }
            if(k==z-1){
                cout<<sum<<" ";
                k=0;
                sum=0;
                cout<<endl;
            }
            else {cout<<sum<<" ";
                   i--;
                  sum=0;
                  k++;}

         }
    }
    return 0;
}
