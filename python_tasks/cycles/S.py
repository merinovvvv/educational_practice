low = 1
high = 1000
attempts = 0

while attempts <= 10:
    guess = (low + high) // 2
    print(guess)
    response = input()
    attempts += 1

    if response == "Угадал!":
        break
    elif response == "Больше":
        low = guess + 1
    elif response == "Меньше":
        high = guess - 1

if attempts > 10:
    print("Не удалось угадать за 10 попыток.")