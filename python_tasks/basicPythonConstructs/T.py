weight = int(input())
price = int(input())
price_1 = int(input())
price_2 = int(input())

total_price = price * weight

x1 = (total_price - price_2 * weight) // (price_1 - price_2)
x2 = weight - x1

print(x1, x2)