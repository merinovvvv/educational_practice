password = int(input())

num_1 = (password % 10) + ((password // 10) - (password // 100 * 10))
num_2 = (password // 100) + ((password // 10) - (password // 100 * 10))
if num_1 <= num_2:
    num_3 = str(num_2) + str(num_1)
else:
    num_3 = str(num_1) + str(num_2)

print(num_3)