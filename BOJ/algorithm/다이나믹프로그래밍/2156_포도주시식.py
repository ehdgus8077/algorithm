# 다이나믹 프로그래밍 Bottom Up
dp=[[0]*2 for i in range(10001)]
count=[0]*10001
n=int(input())
for idx in range(1,n+1):
    count[idx]=int(input())

dp[1][1]=count[1]

for idx in range(2,n+1):
    dp[idx][0]=max(dp[idx-1][1],dp[idx-1][0])
    dp[idx][1]=max(dp[idx-1][0]+count[idx],dp[idx-2][0]+count[idx-1]+count[idx])

print(max(dp[n][1],dp[n][0]))
