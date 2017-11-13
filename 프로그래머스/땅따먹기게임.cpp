#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int hopscotch(vector<vector<int> > board)
{
	// �Լ��� �ϼ��ϼ���.
	int answer = 0;
    int row_cnt = board.size();
    int dp[row_cnt][4];
    dp[0][0] = board[0][0];
    dp[0][1] = board[0][1];
    dp[0][2] = board[0][2];
    dp[0][3] = board[0][3];
    for ( int i = 1 ; i < row_cnt ; i++ ){
        for ( int j = 0 ; j < 4 ; j++ ){
            dp[i][j] = 0;
            for ( int k = 0 ; k < 4 ; k ++ ){
                if(i==j)
                    continue;
                dp[i][j] = max(dp[i][j],dp[i-1][k]+);

            }
        }
    }
    for (int i = 0 ; i < 4 ; i ++ ){
        answer = max(answer, dp[row_cnt-1][i]);
    }
	return answer;
}

int main()
{
	vector<vector<int> > test{{1,2,3,5},{5,6,7,8},{4,3,2,1}};
 //�Ʒ��� �׽�Ʈ�� ����� ���� ���� �ڵ��Դϴ�.
	cout << hopscotch(test);
}
