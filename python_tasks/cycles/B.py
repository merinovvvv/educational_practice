counter = 0

while (str := input()) != "Приехали!":
    if "зайка" in str:
        counter += 1
print(counter)