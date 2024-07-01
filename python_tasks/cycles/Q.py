num_1 = int(input())
num_2 = ""
num_3 = ""

while num_1 != 0:
    if num_1 % 10 % 2 != 0:
        num_2 += str(num_1 % 10)
    num_1 //= 10

num_2 = int(num_2)

while num_2 != 0:
    num_3 += str(num_2 % 10)
    num_2 //= 10

print(num_3)
