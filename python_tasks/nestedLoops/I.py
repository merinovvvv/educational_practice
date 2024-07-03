children = int(input())

num_1 = int(input())

sum = ""

if num_1 // 10 == 0:
    max_digit = num_1

else:
    max_digit = 0
    tmp = num_1
    while tmp != 0:
        if tmp % 10 > max_digit:
            max_digit = tmp % 10
        tmp //= 10

sum += str(max_digit)

for i in range(children - 1):
    num_2 = int(input())
    if num_2 // 10 == 0:
        max_digit_2 = num_2
    else:
        max_digit_2 = 0
        tmp = num_2
        while tmp != 0:
            if tmp % 10 > max_digit_2:
                max_digit_2 = tmp % 10
            tmp //= 10

    sum += str(max_digit_2)
    
print(sum)
