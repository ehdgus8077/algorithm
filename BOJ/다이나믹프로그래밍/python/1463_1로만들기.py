dp=[ 0 for i in range(1000001) ]
def solution(n):
    global dp
    if n==1:
        return 0
    if dp[n]:
        return dp[n]
    dp[n]=solution(n-1)+1
    if(n%2==0 ):
        temp=solution(int(n/2))+1
        if(temp<dp[n]):
            dp[n]=temp
    if (n % 3 == 0):
        temp = solution(int(n / 3)) + 1
        if (temp < dp[n]):
            dp[n] = temp
    return dp[n]

print(solution(int(input())))