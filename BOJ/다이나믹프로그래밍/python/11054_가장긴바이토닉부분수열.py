dp=[0]*1001
dp2=[0]*1001
num=[0]*1001
n=int(input())
num=[int(i) for i in input().split()]
num.insert(0,0)
dp[1]=1
dp2[n]=1

for target in range(2,n+1):
    max2 = 0
    for check in range(1,target):
        if(num[target]>num[check] and max2<dp[check]):
            max2=dp[check]
    dp[target]=max2+1
for target in range(n-1,-1,-1):
    max2 = 0
    for check in range(n,target,-1):
        if(num[target]>num[check] and max2<dp2[check]):
            max2=dp2[check]
    dp2[target]=max2+1
for idx in range(1,n+1):
    dp[idx]+=dp2[idx]
print(max(dp)-1)
