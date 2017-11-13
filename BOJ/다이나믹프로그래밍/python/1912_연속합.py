# 다이나믹 프로그래밍 bottom_up


n= int(input())
dp=[0]*(n+1)
# dp[i] = 1번쨰 수열을 포함할 때 최대 연속된 합
dp[0]=-1001
num=[int(i) for i in input().split()]
num.insert(0,0)

for idx in range(1,n+1):
    dp[idx]=max(num[idx],dp[idx-1]+num[idx])


print(max(dp))