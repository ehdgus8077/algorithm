/*
    ���� ���: ������ ������ ����� ������ ���ִ�. ������ ���չ�Ģ�� ����ǹǷ� ������ ���� ���ϴ� ����� ����.
           �׷� ���� ������ ���Ͽ� ���� ���� ������� �� ����� �� ������ ����Ͻÿ�.


        dp[i][j] | 0        ( i == j )
                 | min(dp[i][k]+dp[k+1][j]) + matrix[i][0]*matrix[k][0]*matrix[j][1]
                   ( i !=j  && i<=k<j )
        -> �۷� i���� ���� j��° ������ �ּ� ��� ��
        -> matrix[i][n] : i��° ����� n(0: ��, 1:��)
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
