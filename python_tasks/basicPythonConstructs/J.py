name = input()
lockerNum = int(input())

listNum = lockerNum % 10
bedNum = lockerNum // 10 % 10
groupNum = lockerNum // 100

print(f"Группа №{groupNum}.")
print(f"{listNum}. {name}.")
print(f"Шкафчик: {lockerNum}.")
print(f"Кроватка: {bedNum}.")