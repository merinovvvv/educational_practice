list = []
counter = 0

places = int(input())

for i in range(places):
    str = input()
    list.append(str)
for j in range(len(list)):
    counter += list[j].count("зайка")
print(counter)