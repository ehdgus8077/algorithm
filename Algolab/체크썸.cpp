#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    int testcase,arr[4];
    unsigned int num;
    string a;
    inStream >> testcase ;
    while(testcase--){
       inStream >>num;
       arr[0]=num%256;
       num/=256;
       arr[1]=num%256;
       num/=256;
       arr[2]=num%256;
       num/=256;
       arr[3]=num;
       for(int i=0;i<4;i++){
        cout<<arr[i]<<endl;
       }
       if(arr[0]==255-(arr[1]+arr[2]+arr[3])%256){cout<<1<<endl;}
       else {cout<<0<<endl;}

        }

    return 0;
}
