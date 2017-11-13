import math
def check_decimal(num):
    if(num==1):
        return False
    for i in range(2,int(math.sqrt(num))+1):
        if(num%i==0):
            return False
    return True
if __name__=="__main__":
    count=int(input())
    result=0
    numbers=[int(i) for i in input().split()]
    for i in numbers:
        if(check_decimal(i)):
            result+=1
    print(result)