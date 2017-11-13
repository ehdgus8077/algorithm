/*
���� ��� : ���� ���� ������ ��ģ��. �� ���Ͽ� ũ�Ⱑ �ְ�, �� ������ ��ġ�� �� ũ���� �հ� ũ�Ⱑ �ʿ��ϴ�.(���⼭ ũ��� ����̴�)
        ���� �ռ����� �� �����Ͽ� ���� ���� ����� ���ض�.
dp[i][j] =  | 0     (i == j)
            | a[i]+a[j} (i == j-1)
            | min((dp[i][k]+dp[k+1][j])+sum(a[i]+...a[j]))   ( i != j-1 && i!=j)
*/
#include <cstdio>
#include <algorithm>
#define MAX 501
using namespace std;
int file_size[MAX];
int sum[MAX];
int solution(int F_cnt){
    int dp[MAX][MAX],row,col;
    for ( int i = 1 ; i <= F_cnt ; i++){

        for ( int j = 0 ; j <=F_cnt-i ; j++ ){
            row = 1+j,col = i+j;
            if(row == col){
                dp[row][col] = 0;
            }
            else if(row == col-1){
                dp[row][col] = file_size[row] + file_size[col];
            }
            else{

                dp[row][col]=(dp[row][row]+dp[row+1][col]);
                for ( int k = row+1 ; k < col ;k++){
                    if(dp[row][col]> dp[row][k]+dp[k+1][col]){
                         dp[row][col]= dp[row][k]+dp[k+1][col];
                    }
                }
                dp[row][col] = dp[row][col] + sum[col]-sum[row-1];
            }

        }
    }

    return dp[1][F_cnt];
}

int main(){
    int case_cnt, file_cnt;
    scanf("%d",&case_cnt);
    while(case_cnt--){
        scanf("%d",&file_cnt);
        for ( int idx = 1 ; idx <= file_cnt ; idx++ ){
            scanf("%d",&file_size[idx]);
        }
        sum[1] = file_size[1];
        for ( int i = 2 ; i <= file_cnt ; i++ ){
            sum[i]=sum[i-1]+file_size[i];
        }
        printf("%d\n",solution(file_cnt));
    }
    return 0;
}
