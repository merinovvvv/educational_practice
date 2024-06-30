petyaSpeed = int(input())
vasyaSpeed = int(input())
tolyaSpeed = int(input())

timePetya = 43872 // petyaSpeed
timeVasya = 43872 // vasyaSpeed
timeTolya = 43872 // tolyaSpeed

if timePetya < timeVasya < timeTolya:
    print("1. Петя")
    print("2. Вася")
    print("3. Толя")
elif timePetya < timeTolya < timeVasya:
    print("1. Петя")
    print("2. Толя")
    print("3. Вася")
elif timeVasya < timePetya < timeTolya:
    print("1. Вася")
    print("2. Петя")
    print("3. Толя")
elif timeVasya < timeTolya < timePetya:
    print("1. Вася")
    print("2. Толя")
    print("3. Петя")
elif timeTolya < timePetya < timeVasya:
    print("1. Толя")
    print("2. Петя")
    print("3. Вася")
else:
    print("1. Толя")
    print("2. Вася")
    print("3. Петя")