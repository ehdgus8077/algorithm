#import math
# num = int( input() )
# result=0
# while(num):
#     value=int(math.sqrt(num))
#     print(value)
#     result+=int(num/(value*value))
#     num%=(value*value)
# print(result)

dp=[0]*100001
dp[1]=1
num = int( input() )
for idx in range(2,num+1):
    #value = int(math.sqrt(idx))
    dp[idx]=1000001
    i=1
    while(i*i<=idx):
        dp[idx]=min(dp[idx],dp[idx-(i*i)]+1)
        i+=1
print(dp[num])