nn=int(input())

dp=[0]*(46)
dp[1]=1

def solution(n):
    if n>1:
        for idx in range(2,n+1):
            dp[idx]=dp[idx-1]+dp[idx-2]
    return dp[n]

print(solution(nn))
