#include <cstdio>
#define MAX 1001
using namespace std;

int memo[MAX][2]; // memo[i][0] ½Â¸®È½¼ö memo[i][1] ÆÐ¹èÈ½¼ö
int main(){
    int case_cnt, team_cnt, game_cnt, team_A,team_B, win_A, win_B;
    float temp;
    int max_result;
    int min_result,com;
    scanf("%d",&case_cnt );
    while(case_cnt--){
        max_result = -1;
        min_result = MAX;
        scanf("%d %d",&team_cnt,&game_cnt);
        for( int i = 1 ; i <=team_cnt ; i ++ ){
            memo[i][0] =0;
            memo[i][1] =0;
        }

        for ( int i = 0 ; i < game_cnt ; i ++ ){
            scanf("%d %d %d %d",&team_A,&team_B,&win_A,&win_B);
            memo[team_A][0] +=win_A;
            memo[team_B][0] +=win_B;
            memo[team_A][1] +=win_B;
            memo[team_B][1] +=win_A;
        }
        for( int i = 1 ; i <=team_cnt ; i ++ ){
            temp=(double)(memo[i][0]*memo[i][0])/(memo[i][0]*memo[i][0]+memo[i][1]*memo[i][1]);
            com = temp*1000;
            if( com>max_result )
                max_result = com;
            if( com<min_result )
                min_result = com;
        }
        printf("%d\n",max_result);
        printf("%d\n",min_result);
    }

    return 0;
}
