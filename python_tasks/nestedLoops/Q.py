n = int(input())
counter = 0

for i in range(n):
    num = int(input())
    tmp = num
    reversed_num = ""
    while tmp != 0:
        reversed_num += str(tmp % 10)
        tmp //= 10
    if str(num) == reversed_num:
        counter += 1
print(counter)