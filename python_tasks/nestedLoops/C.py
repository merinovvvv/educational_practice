num = int(input())

current_number = 1
row = 1

while current_number <= num:
    for i in range(row):
        if current_number > num:
            break
        print(current_number, end=" ")
        current_number += 1
    print("")
    row += 1