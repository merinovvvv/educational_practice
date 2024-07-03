numsAmount = int(input())
num = int(input())

for i in range(numsAmount - 1):
    num_2 = int(input())
    if num < num_2:
        num, num_2 = num_2, num
    while num_2 != 0:
        num, num_2 = num_2, num % num_2
    
print(num)