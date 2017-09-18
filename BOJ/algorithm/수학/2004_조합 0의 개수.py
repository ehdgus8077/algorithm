def zero_count_Combination(n,m):
    f_num = 1
    two_count = 0
    five_count = 0
    for i in range(m+1, n + 1):
        while (i % 2 == 0):
            two_count += 1
            i=int(i/2)
        while (i % 5 == 0):
            five_count +=1
            i = int(i / 5)
    for i in range(2,n-m+1):
        while (i % 2 == 0):
            two_count -= 1
            i=int(i/2)
        while (i % 5 == 0):
            five_count -=1
            i = int(i / 5)

    if(two_count<five_count):
        return two_count
    else:
        return five_count


if __name__ == "__main__":
    #nCm 조합 n!/(m!*(n-m)!)
    n,m=[int(i) for i in input().split()]
    print(zero_count_Combination(n,m))