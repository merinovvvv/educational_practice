childrenNumber = int(input())
sweetsNumber = int(input())

sweetsForAChild = sweetsNumber // childrenNumber
sweetsLeft = sweetsNumber - sweetsForAChild * childrenNumber

print(sweetsForAChild)
print(sweetsLeft)