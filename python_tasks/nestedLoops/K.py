n = int(input())
counter = 0

for i in range(n):
    num = int(input())
    isSimple = True
    if num == 1:
        continue
    else:
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                isSimple = False
        if isSimple:
            counter += 1
        else:
            continue
print(counter)