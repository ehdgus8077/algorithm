# 두쌍의 최대공약수들의 합
def Greatest_Common_Measure(x,y):
    if(x<y):
        num=x
    else:
        num=y
    while(True):
        if(x%num==0 and y%num==0):
            return num
        num-=1

if(__name__=='__main__' ):
    for i in range(int(input())):
        sum=0
        numbers = [int(i) for i in input().split()]
        for i in range(1,numbers[0]):
            for j in range(i+1,numbers[0]+1):
                sum+=Greatest_Common_Measure(numbers[i],numbers[j])
        print(sum)
