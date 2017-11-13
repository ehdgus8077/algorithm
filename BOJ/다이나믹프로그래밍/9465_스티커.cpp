#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;
int dp[MAX][3];
int solution(vector < vector < int > > stiker){
    int n = stiker[0].size();
    dp[1][0] = 0 ;
    dp[1][1] = stiker[0][0];
    dp[1][2] = stiker[1][0];
    for ( int i = 2 ; i <= n ; i ++ ){
        dp[i][0] = max( max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
        dp[i][1] = max(dp[i-1][2],dp[i-1][0])+stiker[0][i-1];
        dp[i][2] = max(dp[i-1][1],dp[i-1][0])+stiker[1][i-1];
    }
    return max(dp[n][1],dp[n][2]);
}
int main() {
    int testCase;
    cin >> testCase;
    while(testCase--){
        int n;
        cin >> n;
        vector < vector < int > > stiker(2, vector<int>(n));
        for(int i=0;i<n;i++)
            cin >> stiker[0][i];
        for(int i=0;i<n;i++)
            cin >> stiker[1][i];
        cout << solution(stiker) << '\n';
    }
    return 0;
}
