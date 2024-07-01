playersNum = int(input())
name = input()
minName = name

for i in range(playersNum - 1):
    name = input()
    if name < minName:
        minName = name
print(minName)