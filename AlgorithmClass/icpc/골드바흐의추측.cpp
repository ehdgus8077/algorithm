#include <cstdio>
#include <math.h>
#define MAX 10001
using namespace std;

int prime[MAX];
void get_prime(int n){
    for ( int i = 0 ; i <= n ; i++ )
        prime[i] = i ;
    int End = sqrt(n);
    for ( int i = 2 ; i <=  End ; i ++){
        if( prime[i]==0)
            continue;
        else{
            for( int j = i+i ; j <=n ; j+=i )
                prime[j] = 0;
        }
    }

}
int main(){
    int case_cnt, number;
    scanf("%d",&case_cnt);
    get_prime(MAX);
    while(case_cnt--){
        scanf("%d",&number);

        for (int i = number/2 ; i >1 ; i -- ){
            if(prime[i]!=0 && prime[number-i]!=0){
                printf("%d %d\n",i,number-i);
                break;
            }
        }

    }


    return 0;
}
