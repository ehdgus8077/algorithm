#include <cstdio>
#include <algorithm>
#define MAX 1001
/*
    dp[i][j][k] == i초에 j번째 나무에 있으면서 k번 옮겼을때의 최대 자두 개수를 의미한다.
*/
using namespace std;
int dp[MAX][3][31];
int main(){
    int t,w,case_w,result = 0;
    scanf("%d %d ",&t,&w);

    for ( int i = 1 ; i <= t ; i++ ){
        scanf("%d",&case_w);
        dp[i][1][0] = dp[i-1][1][0];
        dp[i][2][0] = dp[i-1][2][0];
        for ( int j = 1 ; j<=w ; j++ ){
            dp[i][1][j] = max(dp[i-1][1][j],dp[i-1][2][j-1]);
            dp[i][2][j] = max(dp[i-1][2][j],dp[i-1][1][j-1]);
        }
        for (int j = 0 ; j <= w ; j++ ){
            dp[i][case_w][j] ++;
        }
    }
    for ( int i = 0 ; i <=w ; i++){
       result = max(result,max(dp[t][1][i],dp[t][2][i] ));
    }
    printf("%d\n",result);
    return 0;
}
