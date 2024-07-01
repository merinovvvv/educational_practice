num_1 = int(input())
num_2 = int(input())

old_num_1 = num_1
old_num_2 = num_2

if num_1 < num_2:
    num_1, num_2 = num_2, num_1
    
while num_2 != 0:
    num_1, num_2 = num_2, num_1 % num_2

nok = old_num_1 * old_num_2 // num_1
print(nok)