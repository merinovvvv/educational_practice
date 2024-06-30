number = int(input())

digit_1 = str(number // 1000)
digit_2 = str(number // 100 % 10)
digit_3 = str(number // 10 % 10)
digit_4 = str(number % 10)

if digit_1 + digit_2 == digit_4 + digit_3:
    print("YES")
else:
    print("NO")