dp=[0 for i in range(12)]
dp[0]=1
dp[1]=1
dp[2]=2
def solution(n):
    if dp[n]:
        return dp[n]
    dp[n]=solution(n-1)+solution(n-2)+solution(n-3)
    return dp[n]

for i in range(int(input())):
    print(solution(int(input())))
