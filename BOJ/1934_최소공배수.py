
def Least_Common_Multiple(x,y):
    num=1
    while(True):
        if(y*num%x==0):
            return y*num
        num+=1


if(__name__=='__main__' ):
    for i in range(int(input())):
        numbers = [int(i) for i in input().split()]
        numbers.sort()
        print(Least_Common_Multiple(numbers[0],numbers[1]))