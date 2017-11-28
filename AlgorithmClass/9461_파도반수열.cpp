#include <cstdio>
#define MAX 101

using namespace std;
long long dp[MAX];
long long solution(int n ){
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;

    for ( int i = 5 ; i <= n ; i++ ){
        dp[i] = dp[i-1]+dp[i-5];
    }
    return dp[n];
}

int main(){
    int case_cnt,n;
    scanf("%d",&case_cnt);
    while(case_cnt--){
        scanf("%d",&n);
        printf("%lld\n",solution(n));
    }
    return 0;
}
