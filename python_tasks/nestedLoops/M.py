height = int(input())
width = int(input())
max_value = height * width
column_width = len(str(max_value))

for i in range(1, height + 1):
    for j in range(i, max_value + 1, height):
        print(f"{j: >{column_width}}", end=" ")
    print()