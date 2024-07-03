size = int(input())
width = int(input())

for i in range(1, size + 1):
    for j in range(1, size + 1):
        j *= i
        if j != size * i:
            print(f"{j: ^{width}}", end="|")
        else:
            print(f"{j: ^{width}}")
    if i != size:
        print("-" * ((width + 1) * (size - 1) + width))
