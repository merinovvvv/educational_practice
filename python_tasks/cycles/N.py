num = int(input())

isSimple = True

if num == 1:
    print("NO")
else:
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            isSimple = False
    if isSimple:
        print("YES")
    else:
        print("NO")