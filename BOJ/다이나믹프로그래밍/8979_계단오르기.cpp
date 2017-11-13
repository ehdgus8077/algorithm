#include <cstdio>
#include <algorithm>
#define MAX 301

using namespace std;

int solution(int *arr, int n ){
    int dp[MAX];
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = dp[1]+arr[2];
    for ( int i = 3 ; i<=n; i++ ){
        dp[i] = max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
    }
    return dp[n];
}

int main(){
    int N;
    scanf("%d",&N);
    int num[MAX];
    for ( int i = 1 ; i <= N ; i++ ){
        scanf("%d",&num[i]);
    }
    printf("%d",solution(num, N));
    return 0 ;
}
