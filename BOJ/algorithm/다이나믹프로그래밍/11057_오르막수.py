
dp = [[0]*10 for i in range(101)]
dp[1]=[1,1,1,1,1,1,1,1,1,1]

# dp[i][j] i인 계단 수에서 마지막에 j인 개수

def solution(n):
    for i in range(2,n+1):
        for j in range(0,10):
            for k in range(j,-1,-1):
                dp[i][j]+=dp[i-1][k]

    return dp[n]

print(sum(solution(int(input())))%10007)


