#include<iostream>

using namespace std;

int solution(int n) {
    int dp[1001][10]={{1,1,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1}};
    int answer = 0;

    if (n>1){
        for ( int i = 2 ; i <=n ; i ++){
            for ( int j = 0 ;j <10 ; j++){
                dp[i][j] = 0;
                for(int k = 0 ; k <=j ;k ++ ){
                    dp[i][j] = (dp[i][j]+dp[i-1][k])%10007;
                }
            }

        }
    }
    for ( int i = 0 ; i< 10 ; i++){
        answer = (answer+dp[n][i])%10007;
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    cout << solution(n) << '\n';
    return 0;
}
