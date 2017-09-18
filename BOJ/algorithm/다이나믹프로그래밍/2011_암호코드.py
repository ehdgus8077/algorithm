dp=[0]*5001
code=input()
code="0"+code
dp[0]=1
dp[1]=1
n=len(code)
for idx in range(2,n):
    if(10<=int(code[idx-1:idx+1])<27): # 0인경우는 무조건 10 또는 20 임으로 이 조건에 만족
        dp[idx] = dp[idx - 2]
        if(code[idx]!='0'):
            dp[idx]+=dp[idx-1]
    else:
        dp[idx]=dp[idx-1]
print(dp[n-1]%1000000)

