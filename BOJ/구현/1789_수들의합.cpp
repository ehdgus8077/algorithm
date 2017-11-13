#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long sum,temp=0;
    cin >> sum;
    for ( int i = 1 ;  ; i ++ ){
        temp+=i;
        if(temp>sum){
            cout << i - 1 << "\n";
            return 0;
        }

    }

    return 0;
}
