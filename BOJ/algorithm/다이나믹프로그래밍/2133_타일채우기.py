dp = [0]*32

dp[2]=3
dp[3]=1
n = int( input() )

for idx in range(4,n+1,2):
    dp[idx]=dp[idx-2]*3
print(dp[n])
