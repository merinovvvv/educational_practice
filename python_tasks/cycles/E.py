total_price = 0

while (price := float(input())) != 0:
    if price >= 500:
        price = price - price * 0.1
    total_price += price

print(total_price)