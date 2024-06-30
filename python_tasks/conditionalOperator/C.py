petyaSpeed = int(input())
vasyaSpeed = int(input())
tolyaSpeed = int(input())

timePetya = 43872 // petyaSpeed
timeVasya = 43872 // vasyaSpeed
timeTolya = 43872 // tolyaSpeed

if timePetya < timeVasya:
    if timePetya < timeTolya:
        print("Петя")
    elif timeTolya < timePetya:
        print("Толя")
elif timeVasya < timePetya:
    if timeVasya < timeTolya:
        print("Вася")
    elif timeTolya < timeVasya:
        print("Толя")
