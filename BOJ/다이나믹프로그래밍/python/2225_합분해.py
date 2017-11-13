dp=[[1]*201 for i in range(201)]
#dp[i][j] j 정수까지 i개의 수를 했을 때 i가 되는 경우의 수
n,k=[int(i) for i in input().split()]


for idx in range(2,k+1): # idx개의 수로 .. 1개일 때는 모두 1임
    for i in range(1,n+1): # i 정수를 만들 때
        dp[idx][i]=sum(dp[idx-1][0:i+1])%1000000000
print(dp[k][n])