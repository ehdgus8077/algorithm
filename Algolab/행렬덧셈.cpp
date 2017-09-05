#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    int testcase,x,y,num ;
    inStream >> testcase;
    while(testcase--){
         inStream >>x>>y;
         int arr[x][y];
         for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                inStream >>num;
                arr[i][j]=num;

            }
         }
         for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                 inStream >>num;

                cout<<arr[i][j]+num<<" ";
            }
            cout<<endl;
         }
    }
    return 0;
}
