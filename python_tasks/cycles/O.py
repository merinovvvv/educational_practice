placeNumber = int(input())
counter = 0

for i in range(placeNumber):
    string = input()
    if "зайка" in string:
        counter += 1
print(counter)