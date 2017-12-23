/*
    dp[i][j] = |  1      ( i==j )   base case
               |  1      ( |i-j| == 1 && num[i] == num[j] ) base case
               |  1      ( dp[i+1][j-1] == 1 && num[i] == num[j]) recursive step
    -> i번째 부터 j까지 팰린드롬이 맞는지의 여부
*/
#include <cstdio>
#define MAX 2001

using namespace std;

bool dp[MAX][MAX];
int num[MAX];
int main(){
    int num_size, temp_num, question_size, start,End;
    scanf("%d",&num_size);

    for ( int i = 1 ; i<=num_size ; i++ ){
        // base case
        dp[i][i] = true;
        scanf("%d",&num[i]);
    }

    // base case
    for ( int i = 1 ; i < num_size ; i++ ){
        if(num[i] == num[i+1]){
            dp[i][i+1] = true;
        }
    }

    // recursive step

    for ( int i = 2 ; i < num_size ; i++ ){
        for ( int j = 1 ; j<= num_size-i ; j++ ){
            if( dp[j+1][i-1+j] == true && (num[j] == num[i+j]) ){
                dp[j][i+j] = true;
            }
        }
    }

    scanf("%d",&question_size);
    for ( int i = 0 ; i < question_size ; i++ ){
        scanf("%d %d",&start,&End);
        printf("%d\n",dp[start][End]);
    }
    return 0;
}
