#include <cstdio>
#define MAX 201
#define INF 1000000000

using namespace std;

int solution(int n, int k){
    int dp[MAX][MAX];
    if( k == 1 )
        return 1;

    for ( int i = 0 ; i <= n ; i++ ){
        dp[2][i] = 1;
    }
    for ( int i = 3 ; i <=k ; i ++ ){
        dp[i][n] = 1;
        for ( int j = n-1 ; j >=0 ; j-- ){
            dp[i][j] = (dp[i-1][j]+dp[i][j+1])%INF;
        }
    }
    int answer = 0 ;
    for (int i = 0 ; i <=n ; i++ ){
        answer = (answer+dp[k][i])%INF;
    }
    return answer;
}

int main(){
    int N,K;
    scanf("%d %d",&N,&K);
    printf("%d",solution(N,K));
    return 0 ;
}
