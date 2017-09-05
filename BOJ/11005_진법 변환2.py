#10진법을 n진수로 바꾸기



if __name__=="__main__":
    number,n=[int(i) for i in input().split()]
    result=[]
    while(number):
        if(number%n<10):
            result.insert(0,number%n)
        else:
            result.insert(0, chr(number % n+55))
        number=int(number/n)
    for i in result:
        print(i,end="")