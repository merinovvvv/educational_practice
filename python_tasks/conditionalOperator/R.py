a = int(input())
b = int(input())
c = int(input())

max_len = max(a, b, c)

if max_len == c:
    if a**2 + b**2 == c**2:
        print("100%")
    elif a**2 + b**2 > c**2:
        print("крайне мала")
    else:
        print("велика")
elif max_len == b:
    if a**2 + c**2 == b**2:
        print("100%")
    elif a**2 + c**2 > b**2:
        print("крайне мала")
    else:
        print("велика")
else:
    if b**2 + c**2 == a**2:
        print("100%")
    elif b**2 + c**2 > a**2:
        print("крайне мала")
    else:
        print("велика")