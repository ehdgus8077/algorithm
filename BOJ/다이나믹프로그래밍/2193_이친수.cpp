/*
    ���� ��� : n�ڸ��� ��ģ���� ����� ���� ����Ͻÿ�. ��ģ���� ù���ڰ� 0�� �ƴϰ� ���ӵ� 1�� ���� ������ �����̴�.
    dp[i][2] = dp[i][k] i�ڸ� �������� ���� ���ڸ��� k�� ����� ��
    dp[i][0] = | 0   ( i==1 )
               | dp[i-1][1]+dp[i-1][0] (i!=1)
    dp[i][0] = | 1   ( i==1 )
               | dp[i-1][0] (i!=1)

*/
#include<iostream>

using namespace std;

long long solution(int a) {
    long long dp[91][2];
    dp[1][0] = 0;
    dp[1][1] = 1;
    for ( int i=2 ; i <= a ;i++ ){
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }
    return dp[a][0]+dp[a][1];
}

int main() {
    int n;
    cin >> n;
    cout << solution(n) << '\n';
    return 0;
}
