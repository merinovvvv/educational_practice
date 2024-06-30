petya = int(input())
vasya = int(input())
tolya = int(input())

if petya > vasya > tolya:
    print(f"{'Петя': ^24}")
    print(f"{'Вася': ^8}")
    print(" " * 16 + f"{'Толя': ^8}")
    print(f"{'II': ^8}" + f"{'I': ^8}" + f"{'III': ^8}")

elif petya > tolya > vasya:
    print(f"{'Петя': ^24}")
    print(f"{'Толя': ^8}")
    print(" " * 16 + f"{'Вася': ^8}")
    print(f"{'II': ^8}" + f"{'I': ^8}" + f"{'III': ^8}")

elif vasya > petya > tolya:
    print(f"{'Вася': ^24}")
    print(f"{'Петя': ^8}")
    print(" " * 16 + f"{'Толя': ^8}")
    print(f"{'II': ^8}" + f"{'I': ^8}" + f"{'III': ^8}")

elif vasya > tolya > petya:
    print(f"{'Вася': ^24}")
    print(f"{'Толя': ^8}")
    print(" " * 16 + f"{'Петя': ^8}")
    print(f"{'II': ^8}" + f"{'I': ^8}" + f"{'III': ^8}")

elif tolya > vasya > petya:
    print(f"{'Толя': ^24}")
    print(f"{'Вася': ^8}")
    print(" " * 16 + f"{'Петя': ^8}")
    print(f"{'II': ^8}" + f"{'I': ^8}" + f"{'III': ^8}")

elif tolya > petya > vasya:
    print(f"{'Толя': ^24}")
    print(f"{'Петя': ^8}")
    print(" " * 16 + f"{'Вася': ^8}")
    print(f"{'II': ^8}" + f"{'I': ^8}" + f"{'III': ^8}")
