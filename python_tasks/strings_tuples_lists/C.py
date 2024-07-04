L = int(input())
N = int(input())
list = []

for i in range(N):
    list.append(input())

for i in range(N):
    if len(list[i]) <= L:
        print(list[i])
    elif len(list[i]) > L:
        for j in range(L - 3):
            print(list[i][j], end="")
        print("...")
