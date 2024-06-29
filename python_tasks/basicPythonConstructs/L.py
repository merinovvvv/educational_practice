number_1 = int(input())
number_2 = int(input())

lastDigit_1 = number_1 % 10
lastDigit_2 = number_2 % 10

secondDigit_1 = number_1 // 10 % 10
secondDigit_2 = number_2 // 10 % 10

firstDigit_1 = number_1 // 100
firstDigit_2 = number_2 // 100

lastDigit = (lastDigit_1 + lastDigit_2) % 10
secondDigit = (secondDigit_1 + secondDigit_2) % 10
firstDigit = (firstDigit_1 + firstDigit_2) % 10

number = str(firstDigit) + str(secondDigit) + str(lastDigit)
print(number)