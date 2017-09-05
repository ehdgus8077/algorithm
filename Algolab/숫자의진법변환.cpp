#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int change_ten(int pre, string value){
    int sum=0,idx=value.size()-1;

    for(int i=1;idx>=0;i*=pre){
            if((int)value[idx]>96){
                sum+=(value[idx--]-87)*i;
            }
            else{
                 sum+=(value[idx--]-48)*i;
            }
        }
    return sum;
}

void change_next_num(int next, int sum){
    int arr[32],i=0;
    if(sum==0){cout<<0;}
    while(sum!=0){
        arr[i++]=sum%next;
        sum/=next;
    }
    i--;
    while(i!=-1){
        if(arr[i]>9)
            cout<<(char)(87+arr[i]);
        else
            cout<<arr[i];
        i--;
    }
    cout<<endl;
}

int main(){
    ifstream inStream("input.txt");
    int testcase,num_pre,num_next,sum;
    string value;
    inStream >> testcase ;
    while(testcase--){
       inStream >> num_pre >> value >> num_next;
       if(num_pre!=10)
            sum = change_ten(num_pre,value);
       else
            sum = atoi(value.c_str());
        change_next_num(num_next,sum);

    }

    return 0;
}
