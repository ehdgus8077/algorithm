#include <iostream>
#define MAX 1001
using namespace std;

bool is_not_prime[MAX];
int main(){
    int end_num, k;
    cin >> end_num >>k;
    for (int i = 2 ; i<=end_num ; i++ ){
        if(is_not_prime[i] == 0 ){
            for(int j = i ; j<=end_num ;j+=i){
                if(!is_not_prime[j]){
                    is_not_prime[j] = true;
                    k--;
                }
                if(!k){
                    cout << j <<"\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
