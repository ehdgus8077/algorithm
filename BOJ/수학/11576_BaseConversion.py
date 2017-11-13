if __name__=="__main__":
    result=[]
    next,pre=[int(i) for i in input().split()]
    count=int(input())
    numbers = [int(i) for i in input().split()]
    mul=1
    decimal_number=0
    for i in range(len(numbers)-1,-1,-1):
        decimal_number+=numbers[i]*mul
        mul*=next
    while(decimal_number):
        result.insert(0,decimal_number%pre)
        decimal_number=int(decimal_number/pre)
    for value in result:
        print(value,end=" ")
