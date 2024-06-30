coord_1 = float(input())
coord_2 = float(input())

if coord_1 ** 2 + coord_2 ** 2 > 100:
    print("Вы вышли в море и рискуете быть съеденным акулой!")

elif coord_1 ** 2 + coord_2 ** 2 <= 100 and coord_1 ** 2 + coord_2 ** 2 > 25:
    print("Зона безопасна. Продолжайте работу.")

else:
    parab = (1 / 4) * coord_1 ** 2 + (1 / 2) * coord_1 - (35 / 4)
    line_1 = (5 / 3) * coord_1 + (35 / 3)
    line_2 = 5

    if coord_2 >= parab and coord_2 <= line_1 and coord_2 <= line_2 and coord_1 ** 2 + coord_2 ** 2 <= 25:
        print("Опасность! Покиньте зону как можно скорее!")
    else:
        print("Зона безопасна. Продолжайте работу.")