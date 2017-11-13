"""
1 2 3 4 5 6 7 8 9 ---9
10 12 23 21 34 32 45 43 56 54 67 65 78 76 89 87 98  ---17

"""
dp = [[0]*10 for i in range(101)]
dp[1]=[0,1,1,1,1,1,1,1,1,1]

# dp[i][j] i인 계단 수에서 마지막에 j인 개수

def solution(n):
    for i in range(2,n+1):
        dp[i][0]+=dp[i-1][1]
        for j in range(1,9):
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]
        dp[i][9]=dp[i-1][8]
    return dp[n]

print(sum(solution(int(input())))%1000000000)


