x = 0
y = 0

while (string := input()) != "СТОП":
    coord = int(input())
    if string == "СЕВЕР":
        x += coord
    elif string == "ЮГ":
        x -= coord
    elif string == "ВОСТОК":
        y += coord
    elif string == "ЗАПАД":
        y -= coord

print(x)
print(y)