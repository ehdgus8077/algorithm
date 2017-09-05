#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    int testcase,num;
    inStream >> testcase ;
    while(testcase--){
         inStream >>num;
         for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                if(i==num/2&&j==num/2){cout<<'O';}
                else if(i==num/2){cout<<'+';}
                else if(j==num/2){cout<<'I';}
                else if(j==num-i-1){cout<<'*';}
                else {cout<<'.';}
            }
            cout<<endl;
         }
    }
    return 0;
}
