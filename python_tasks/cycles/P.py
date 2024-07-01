num = int(input())
tmp = num
reversed_num = ""

while tmp != 0:
    reversed_num += str(tmp % 10)
    tmp //= 10

if str(num) == reversed_num:
    print("YES")
else:
    print("NO")