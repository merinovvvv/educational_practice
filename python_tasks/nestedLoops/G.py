num = int(input())
sec = 3
people = 0
to_add = 0

for i in range(num):
    people += 1
    tmp = sec + to_add
    for j in range(tmp + 1, 1, -1):
        print(f"До старта {tmp} секунд(ы)")
        tmp -= 1
    print(f"Старт {people}!!!")
    to_add += 1
