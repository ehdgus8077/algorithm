import math
def check_decimal(num):
    if(num==1):
        return False
    for i in range(2,int(math.sqrt(num))+1):
        if(num%i==0):
            return False
    return True
if __name__=="__main__":
    num = int(input())
    while(num):
        if(num%2==1):
            print("Goldbach's conjecture is wrong.")
        for i in range(3,int(num/2)+1,2):
            if(check_decimal(i) and check_decimal(num-i)):
                print( "%d = %d + %d"%(num,i,num-i) )
                break
            elif(i==int(num/2)-1):
                print("Goldbach's conjecture is wrong.")
        num = int(input())
