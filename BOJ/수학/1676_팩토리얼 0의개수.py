def zero_count_factorial(n):
    f_num = 1
    two_count = 0
    five_count = 0
    for i in range(2, n + 1):

        while (i % 2 == 0):
            two_count += 1
            i=int(i/2)
        while (i % 5 == 0):
            five_count +=1
            i = int(i / 5)
    if(two_count<five_count):
        return two_count
    else:
        return five_count


if __name__ == "__main__":
    print(zero_count_factorial(int(input())))