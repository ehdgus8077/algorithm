/*
    ���� ��� : ���� �����忡�� ������ ���� ���������� �����ʰ� �Ʒ������� �� �̵��ϴµ�, ������ ���Ḧ ����Ͽ�
            ���� ���� �ð� ���� ���� �Ҷ��� �ð��� ����ض�
            ( �� ���ο� �ð��� ��� n�̰�, ������ �ٲܶ����� 1�� �ð��� �� �ɸ���. �� ���� ������ ���� ���� ���� ����)
    ���� ��ȹ�� dp[i][j][k][d] i�� j������ k�� ������ �ٲ�� �������� d�������� �̵��� ���� �ּҽð� (d :0 ������, d: 1�Ʒ�)
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
