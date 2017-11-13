/*
    문제 요약 : 운전 면허장에서 시작점 부터 도착점까지 오른쪽과 아래쪽으로 만 이동하는데, 제현된 연료를 사용하여
            가장 빠른 시간 내에 도착 할때의 시간을 출력해라
            ( 각 라인에 시간은 상수 n이고, 방향을 바꿀때마다 1의 시간이 더 걸린다. 즉 가장 방향을 적게 돌릴 때를 말함)
    동적 계획법 dp[i][j][k][d] i행 j열까지 k번 방향이 바뀌며 마지막에 d방향으로 이동할 때의 최소시간 (d :0 오른쪽, d: 1아래)
    dp[i][j][k][0] | 0  (i == 1 && j ==1 )
                   |  min(dp[i][j][k][0],dp[i][j-1][k][0])+ horizontal[i-1][j-2] (i != 1 || j !=1 )
    dp[i][j][k+1][0] | 0  (i == 1 && j ==1 )
                   |  min( dp[i][j][k+1][0],dp[i][j-1][k][1])+ horizontal[i-1][j-2] (i != 1 || j !=1 )
    dp[i][j][k][1] | 0  (i == 1 && j ==1 )
                   | min( dp[i][j][k][1],dp[i-1][j][k][1])+ vertical[i-2][j-1] (i != 1 || j !=1 )
    dp[i][j][k+1][1] | 0  (i == 1 && j ==1 )
                   | min( dp[i][j][k+1][1],dp[i-1][j][k][0])+ vertical[i-2][j-1] (i != 1 || j !=1 )


*/
#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#define MAX 101
#define ChangeMAX 202

using namespace std;
int dp[MAX][MAX][ChangeMAX][2];
int main(){
    int case_cnt, row_cnt, col_cnt, leng, limit_fuel;
    int vertical[MAX][MAX],horizontal[MAX][MAX];
    scanf("%d",&case_cnt);
    while(case_cnt--){
        scanf("%d %d %d %d",&row_cnt,&col_cnt,&leng,&limit_fuel);
        for ( int i = 0 ; i <row_cnt ; i++ ){
            for( int j = 0 ; j<col_cnt-1 ; j++){
                scanf("%d",&horizontal[i][j]);
            }
        }
        for ( int i = 0 ; i <row_cnt-1 ; i++ ){
            for( int j = 0 ; j<col_cnt ; j++){
                scanf("%d",&vertical[i][j]);
            }
        }
        memset(dp, 0x2f, sizeof(dp));
        dp[1][1][0][0] = 0;
        dp[1][1][0][1] = 0;

        for ( int i = 1 ; i <= row_cnt ; i++ ){
            for( int j = 1 ; j <= col_cnt; j++ ){
                for( int k = 0 ; k <= 2*(i-1) ;k++ ){
                    if(j!=1){
                        dp[i][j][k][0] = min(dp[i][j][k][0],dp[i][j-1][k][0] + horizontal[i-1][j-2]);
                        dp[i][j][k+1][0] = min(dp[i][j][k+1][0],dp[i][j-1][k][1] + horizontal[i-1][j-2]);
                    }
                    if(i!=1){
                        dp[i][j][k][1] = min(dp[i][j][k][1],dp[i-1][j][k][1] + vertical[i-2][j-1]);
                        dp[i][j][k+1][1] =min(dp[i][j][k+1][1],dp[i-1][j][k][0] + vertical[i-2][j-1]);
                    }
                }
            }
        }

        int answer =2000000000;
        for ( int k = 0 ; k <= 2*(row_cnt-1) ; k++){
            if(dp[row_cnt][col_cnt][k][0]<=limit_fuel){
                answer = min(answer,k);
            }
            if(dp[row_cnt][col_cnt][k][1]<=limit_fuel){
                answer = min(answer,k);
            }
        }
        printf("%d\n",answer==2000000000?-1:leng*(row_cnt+col_cnt-2)+answer);

    }

    return 0 ;
}
