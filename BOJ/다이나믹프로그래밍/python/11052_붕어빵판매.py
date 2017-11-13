dp=[0 for i in range(1001)]
sum=int(input())
coin=[int(i) for i in input().split()]
coin.insert(0,0)

# dp[i]= i개의 붕어빵을 팔 때의 최대 수익
"""
dp[0]=0
dp[1]=dp[0]+coin[1]
dp[2]=dp[1]+coin[1], dp[2]=dp[0]+coin[2] 중 최소값

"""
def solutioo(n):
    for i in range(1,n+1):
        dp[i]=dp[i-1]+coin[1]
        for j in range(2,i+1):
            if(dp[i]<dp[i-j]+coin[j]):
                dp[i]=dp[i-j]+coin[j]
    return dp[n]
print(solutioo(sum))


