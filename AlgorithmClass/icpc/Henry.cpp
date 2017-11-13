#include <iostream>
using namespace std;

int gcd(int x ,int y){
    int i;
    for( i = x ; i >1 ; i --){
        if(x%i==0 && y%i==0)
            break;
    }
    return i;
}

int main(){
    int case_cnt,deno,molecule,temp,div;
    ios::sync_with_stdio(false);
    cin >>case_cnt;
    while(case_cnt--){
        cin >>molecule >>deno;
        while(molecule!=1){
            temp=deno/molecule+1;
            molecule = temp*molecule - deno;
            deno *=temp;
            div = gcd(molecule,deno);
            molecule/=div;
            deno/=div;
        }
        cout <<deno<<"\n";
    }
    return 0;
}
