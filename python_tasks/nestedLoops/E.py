placeAmount = int(input())
counter = 0

isZayka = False

for i in range(placeAmount):
    while ((str := input()) != "ВСЁ"):
        if (isZayka is False):
            if str == "зайка":
                counter += 1
                isZayka = True
    isZayka = False
print(counter)
