itemName = input()
itemPrice = int(input())
itemWeight = int(input())
money = int(input())

totalPrice = itemPrice * itemWeight
change = money - totalPrice

print(f"{'Чек':=>19}{'':=<16}")
print("Товар:" + f"{itemName: >29}")
print("Цена:" + f"{str(itemWeight) + 'кг' + ' * ' + str(itemPrice) + 'руб/кг': >30}")
print("Итого:" + f"{str(totalPrice) + 'руб': >29}")
print("Внесено:" + f"{str(money) + 'руб': >27}")
print("Сдача:" + f"{str(change) + 'руб': >29}")
print("=" * 35)