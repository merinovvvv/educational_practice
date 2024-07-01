num_1 = int(input())
num_2 = int(input())

if num_1 <= num_2:
    for i in range(num_1, num_2 + 1):
        print(i, end=" ")
elif num_1 > num_2:
    for i in range(num_1, num_2 - 1, -1):
        print(i, end=" ")