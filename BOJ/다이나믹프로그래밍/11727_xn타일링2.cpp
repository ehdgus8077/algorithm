#include <cstdio>
#define MAX 1001

using namespace std;

int solution(int n){
    int dp[MAX];
    dp[1] = 1;
    dp[2] = 3;
    for ( int i = 3 ; i <= n ; i++ ){
        dp[i] = (2*dp[i-2] + dp[i-1])%10007;
    }
    return dp[n];
}
int main(){
    int N;
    scanf("%d",&N);
    printf("%d",solution(N));
    return 0;
}
