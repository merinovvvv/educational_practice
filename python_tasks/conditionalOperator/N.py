number = int(input())

num_1 = str(number // 100) + str(number % 10)
num_2 = str(number // 10 - number // 100 * 10) + str(number % 10)

num_3 = str(number % 10) + str(number // 100) 
num_4 = str(number % 10) + str(number // 10 - number // 100 * 10)

num_5 = str(number // 100) + str(number // 10 - number // 100 * 10)
num_6 = str(number // 10 - number // 100 * 10) + str(number // 100)

min_num = int(min(num_1, num_2, num_3, num_4, num_5, num_6))
max_num = int(max(num_1, num_2, num_3, num_4, num_5, num_6))

if min_num // 10 == 0:
    min_num = str(min_num % 10) + str(0)

if max_num // 10 == 0:
    max_num = str(max_num % 10) + str(0)

print(min_num, max_num)