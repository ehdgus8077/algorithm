/*
    문제 요약: 곱셈이 가능한 행렬을 나열이 되있다. 곱셈은 결합법칙이 적용되므로 무엇을 먼저 곱하는 상관이 업다.
           그럼 곱셈 순서를 비교하여 가장 적은 계산으로 할 경우의 총 계산수를 출력하시오.


        dp[i][j] | 0        ( i == j )
                 | min(dp[i][k]+dp[k+1][j]) + matrix[i][0]*matrix[k][0]*matrix[j][1]
                   ( i !=j  && i<=k<j )
        -> 핼렬 i번쨰 부터 j번째 까지의 최소 계산 수
        -> matrix[i][n] : i뻔째 행렬의 n(0: 행, 1:열)
*/
#include <cstdio>
#include <algorithm>
#define MAX 501
using namespace std;
int dp[MAX][MAX];
int matrix[MAX][2];

int solution(int cnt){
    int row,col;
    for ( int i = 2 ; i <=cnt ; i++ ){
        for( int j = 0 ; j <= cnt-i ; j++ ){
            row =  j+1, col=i+j;
            dp[row][col] = dp[row+1][col]+matrix[row][0]*matrix[row][1]*matrix[col][1];

            for (int k = row+1 ; k<col ;k++){
                dp[row][col]=min(dp[row][col],dp[row][k]+dp[k+1][col]+matrix[row][0]*matrix[k][1]*matrix[col][1]);
            }

        }
    }

    return dp[1][cnt];
}

int main(){
    int matrix_cnt;
    scanf("%d",&matrix_cnt);
    for( int i = 1 ; i <= matrix_cnt ; i ++ ){
        scanf("%d %d",&matrix[i][0],&matrix[i][1]);
    }
    printf("%d",solution(matrix_cnt));
    return 0;
}
