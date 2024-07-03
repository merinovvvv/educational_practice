num = int(input())

name = input()
number = int(input())

max_name = name

if number // 10 == 0:
    max_sum = number
    
else:
    max_sum = 0
    tmp_num = number
    while tmp_num != 0:
        max_sum += tmp_num % 10
        tmp_num //= 10


for i in range(num - 1):
    name_2 = input()
    number_2 = int(input())

    if number_2 // 10 == 0:
        max_sum_2 = number_2
    else:
        max_sum_2 = 0
        tmp_num_2 = number_2
        while tmp_num_2 != 0:
            max_sum_2 += tmp_num_2 % 10
            tmp_num_2 //= 10
    if max_sum_2 >= max_sum:
        max_name = name_2
        max_sum = max_sum_2

print(max_name)