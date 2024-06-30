number = int(input())

lastDigit = number % 10
secondDigit = number // 10 - number // 100 * 10
firstDigit = number // 100

min_num = min(lastDigit, secondDigit, firstDigit)
max_num = max(lastDigit, secondDigit, firstDigit)

if min_num + max_num == (lastDigit + secondDigit + firstDigit - min_num - max_num) * 2:
    print("YES")
else:
    print("NO")

