# n진수를 10진수로 바꾸기

if __name__=="__main__":
    number,n=[i for i in input().split()]
    n=int(n)
    sum=0
    mul=1
    for i in range(len(number)-1,-1,-1):
        if(ord(number[i])>47 and ord(number[i])<58):
            sum+=(ord(number[i])-48)*mul
        else:
            sum += (ord(number[i]) - 55) * mul
        mul*=n
    print(sum)