for i in range (3):
    n = int(input())
    sum = 0
    for i in range(n):
        k = int(input())
        sum += k
    if sum > 0:
        print("+")
    elif sum < 0:
        print("-")
    else:
        print("0")