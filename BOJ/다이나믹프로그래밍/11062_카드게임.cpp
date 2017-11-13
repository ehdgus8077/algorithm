#include <iostream>
#include <algorithm>
#define Max 1001
using namespace std;

int dp[Max][Max][2];
//dp[i][j][k] : i부터 j까지 k가 최선의 전략으로 뽑았을 때의 최대 점수

int main() {
    ios::sync_with_stdio(false);
    int case_count,num_count,sum;
    cin >>case_count;
    while(case_count--){

        cin >>num_count;
        for(int idx = 1 ; idx <= num_count ; idx++ ){
            sum=0;
            cin >> dp[idx][idx][0];
            sum+=dp[idx][idx][0];
            for ( int left = idx-1 ; left>0 ; left-- ){
                sum+=dp[left][left][0];
                dp[left][idx][0] = max(dp[left][left][0]+dp[left+1][idx][1], dp[idx][idx][0]+dp[left][idx-1][1]);
                dp[left][idx][1] = abs(sum-dp[left][idx][0]);
            }
            dp[1][idx][0]= max(dp[1][idx][0], dp[1][idx-1][1]+dp[idx][idx][0]);
            dp[1][idx][1]= abs(dp[1][idx][0]-sum);
        }
        cout << dp[1][num_count][0] << "\n";
    }
    return 0;
}

