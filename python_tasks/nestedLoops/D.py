n = int(input())
sum = 0

for i in range(n):
    num = int(input())
    while num != 0:
        if num // 10 == 0:
            sum += num
        else:
            sum += num % 10
        num //= 10
print(sum)
