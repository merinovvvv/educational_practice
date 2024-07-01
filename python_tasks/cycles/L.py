num = int(input())
max = num % 10

while num != 0:
    num //= 10
    if num % 10 > max:
        max = num % 10
print(max)