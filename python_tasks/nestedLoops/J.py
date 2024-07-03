slices = int(input())

print("А", "Б", "В")

a = 1
b = 1
v = slices - a - b
print(a, b, v)

while True:
    while v != 1:
        v -= 1
        b += 1
        print(a, b, v)
    a += 1
    b = 1
    v = slices - a - b
    if v == 0:
        break
    print(a, b, v)
    if a + b + v > slices or (a + b + v == slices and a == slices - 2):
        break