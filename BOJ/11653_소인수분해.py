import math
if __name__=="__main__":
    num=int(input())
    last=math.sqrt(num)
    div=2
    if(num<4):
        print(num)
    else:
         div=2
         while(num!=1 and div<=last):
            if(num%div==0):
                print(div)
                num=int(num/div)
            else:
                div+=1
         if(num!=1):
            print(num)


