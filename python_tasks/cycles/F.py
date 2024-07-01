num_1 = int(input())
num_2 = int(input())

if num_1 < num_2:
    num_1, num_2 = num_2, num_1
    
while num_2 != 0:
    num_1, num_2 = num_2, num_1 % num_2
print(num_1)