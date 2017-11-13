# 다이나믹 프로그래밍 Bottom-Up
dp=[[0]*100001 for i in range(3)]
# dp[n][0]= 안 붙일 때 최대, dp[n][1]= 위쪽 스티커를 붙일 때 최대
# dp[n][2]= 아래쪽 스티커를 붙일 때 최대
score=[[0]*100001 for i in range(2)]
compare=[0]*4

for case in range(int(input())):
    #값을 입력받은 다음 각각 알맞은 변수에 넣는다.
    n=int(input())
    score[0] = [int(i) for i in input().split()]
    score[1] = [int(i) for i in input().split()]

    # dp[i]= 2i개의 스티커를 가지고 있을 때 최대 점수를 담는 배열이다

    # dp와 인덱스를 맞춰 햇갈리지 않도록 함
    score[0].insert(0, 0)
    score[1].insert(0, 0)

    for idx in range(1,n+1):
        dp[0][idx] = max(dp[0][idx - 1], dp[1][idx - 1], dp[2][idx - 1])
        dp[1][idx] = max(dp[2][idx - 1], dp[0][idx - 1]) + score[0][idx]
        dp[2][idx] = max(dp[1][idx - 1], dp[0][idx - 1]) + score[1][idx]
    print(max(dp[0][n],dp[1][n],dp[2][n]))