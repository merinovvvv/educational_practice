number = int(input())
lastDigit = number % 10
thirdDigit = number // 10 % 10
secondDigit = number // 100 % 10
firstDigit = number // 1000

reversedNumber = str(str(secondDigit) + str(firstDigit) + str(lastDigit) + str(thirdDigit))
print(reversedNumber)