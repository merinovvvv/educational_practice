height = int(input())
width = int(input())
tmp = 0
max = height * width
column_width = len(str(max))

for i in range(1, height + 1):
    for j in range(1 + tmp, width + 1 + tmp):
        print(f"{j: >{column_width}}", end=" ")
    print()
    tmp = width * i