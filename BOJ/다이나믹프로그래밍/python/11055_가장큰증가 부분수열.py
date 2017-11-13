dp=[0]*1001
num=[0]*1001
n=int(input())
num=[int(i) for i in input().split()]
num.insert(0,0)
dp[1]=num[1]


for target in range(2,n+1):
    max2 = 0
    for check in range(1,target):
        if(num[target]>num[check] and max2<dp[check]):
            max2=dp[check]
    dp[target]=max2+num[target]
print(max(dp))
