dp=[[0]*2 for i in range(301)] # dp[i]는 i번째 계단을 포함한 최대 점수
# dp[i][0] 은 두칸 뒤에서 올라 올때, dp[i][1] 은 한칸 뒤에서 올라 올때
num=[0]*301
n = int( input() )
for idx in range(1,n+1):
    num[idx]=int( input() )

dp[1][0]=dp[1][1]=num[1]

for target in range(2,n+1):
    dp[target][0]=max(dp[target-2])+num[target]
    dp[target][1]=dp[target-1][0]+num[target]

print(max(dp[n]))