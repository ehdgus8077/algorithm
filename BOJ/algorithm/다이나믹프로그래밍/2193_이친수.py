dp=[[0]*2 for i in range(91)]
dp[1][1]=1

def solution(n):
    for i in range(2,n+1):
        dp[i][0]=dp[i-1][0]+dp[i-1][1]
        dp[i][1]=dp[i-1][0]
    return dp[n]

print(sum(solution(int(input()))))
