
def Greatest_Common_Measure(x,y):
    num=x
    while(True):
        if(x%num==0 and y%num==0):
            return num
        num-=1

def Least_Common_Multiple(x,y):
    num=1
    while(True):
        if(y*num%x==0):
            return y*num
        num+=1


if(__name__=='__main__' ):
    numbers = [int(i) for i in input().split()]
    numbers.sort()
    print(Greatest_Common_Measure(numbers[0],numbers[1]))
    print(Least_Common_Multiple(numbers[0],numbers[1]))