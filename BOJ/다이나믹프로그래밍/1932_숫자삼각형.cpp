/*
    ���� ���: N�� ���� �ﰢ���� �ִ�. �Ʒ������� �̵��ϸ鼭 �������̳� �������� �����Ѵ�.
            �� �� �ִ밡 �Ǵ� ����� ����ض�
*/

#include <cstdio>
#include <algorithm>
#define MAX 501
using namespace std;

int dp[MAX][MAX];

int main(){
    int triangle_inf[MAX][MAX];
    int triangle_cnt, result;
    scanf("%d",&triangle_cnt);
    for( int i = 1 ; i <= triangle_cnt ; i++ ){
        for(int j = 0 ; j < i ; j++ ){
            scanf("%d",&triangle_inf[i][j]);
        }
    }
    dp[1][0]= triangle_inf[1][0];

    for( int i = 2 ; i <= triangle_cnt ; i++ ){
        for(int j = 0 ; j < i ; j++ ){
            if( j==0 )
                dp[i][j] = dp[i-1][j] + triangle_inf[i][j];
            else if( j == i-1 )
                dp[i][j] = dp[i-1][j-1] + triangle_inf[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle_inf[i][j];
        }
    }
    result = dp[triangle_cnt][0];
    for ( int i = 1 ; i < triangle_cnt ; i++ )
        result = max(result, dp[triangle_cnt][i]);
    printf("%d",result);

    return 0;
}
