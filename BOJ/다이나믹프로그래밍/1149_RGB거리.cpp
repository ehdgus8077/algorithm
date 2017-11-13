/*
    ���� ��� : n���� ���� �ְ�, ���� ��ĥ�Ѵ�. �̿��� ���� �ٸ� ���̿����ϰ�,
             ���� ������ ����,�ʷ�,�Ķ��̴�. �� ������ ����Ʈ ������ �ٸ���.
             ���� ���� ������ ������ ���� �ּ� �����?
*/
#include <cstdio>
#include <algorithm>
#define MAX 1001
using namespace std;


int dp[MAX][3];
// dp[i][j] --> i��° ������ (i��°����)j ���� �������� ���� �ּҺ��,
// ����, �ʷ�, �Ķ������� ��������
int main(){
    int house_cnt,red_cost,green_cost,blue_cost;
    int cost_inf[MAX][3];
    scanf("%d",&house_cnt);
    for( int i = 1 ; i <= house_cnt ; i++ ){
        scanf("%d %d %d",&red_cost,&green_cost,&blue_cost);
        cost_inf[i][0] = red_cost;
        cost_inf[i][1] = green_cost;
        cost_inf[i][2] = blue_cost;
    }

    dp[1][0] = cost_inf[1][0];
    dp[1][1] = cost_inf[1][1];
    dp[1][2] = cost_inf[1][2];
    for ( int i = 2 ; i <= house_cnt ; i++ ){
        dp[i][0]= min(dp[i-1][1],dp[i-1][2])+cost_inf[i][0];
        dp[i][1]= min(dp[i-1][0],dp[i-1][2])+cost_inf[i][1];
        dp[i][2]= min(dp[i-1][1],dp[i-1][0])+cost_inf[i][2];
    }
    printf("%d",min(min(dp[house_cnt][0],dp[house_cnt][1]),dp[house_cnt][2]));
    return 0;
}
