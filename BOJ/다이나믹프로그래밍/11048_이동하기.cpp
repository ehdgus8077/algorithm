#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];
int miro[MAX][MAX];


long long solution( int r, int c ){
    for ( int i = 1 ; i <= r ; i++ ){
        for ( int j = 1 ; j <=c ; j++ ){
            dp[i][j] = max( max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + miro[i][j];
                        // dp[i-1][j-1]은 생략 가능
        }
    }
    return dp[r][c];
}

int main(){
    int row,col;
    cin >> row >> col ;
    for ( int i = 1 ; i <= row ; i++ ){
        for ( int j = 1 ; j <=col ; j++ ){
            cin >> miro[i][j];
        }
    }
    cout << solution(row, col);
    return 0;
}
