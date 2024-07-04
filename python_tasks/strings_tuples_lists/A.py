num = int(input())

isOk = True

for i in range(num):
    str = input()
    if not str.startswith(("А", "Б", "В", "а", "б", "в")):
        isOk = False

if not isOk:
    print("NO")
else:
    print("YES")
