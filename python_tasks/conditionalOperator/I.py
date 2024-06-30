name_1 = input()
name_2 = input()
name_3 = input()

if name_1 < name_2:
    if name_1 < name_3:
        print(name_1)
    elif name_3 < name_1:
        print(name_3)
elif name_2 < name_1:
    if name_2 < name_3:
        print(name_2)
    elif name_3 < name_2:
        print(name_3)