goodName = input()
price = int(input())
weight = int(input())
money = int(input())

totalSum = price * weight
change = money - totalSum

print("Чек")
print(f"{goodName} - {weight}кг - {price}руб/кг")
print(f"Итого: {totalSum}руб")
print(f"Внесено: {money}руб")
print(f"Сдача: {change}руб")