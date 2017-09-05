#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream inStream("input.txt");
    int testcase,num1,num2,x,sum;
    inStream >> testcase ;
    while(testcase--){
            sum=0;
        inStream >>num1>>num2;
        if(num1>num2){
            x=num1;
            num1=num2;
            num2=x;
        }
        for(int i=num1;i<=num2;i++){
            sum+=i;
        }
        cout<<sum<<endl;
    }
    return 0;
}
