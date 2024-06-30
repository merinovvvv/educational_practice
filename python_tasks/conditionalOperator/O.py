a = int(input())
b = int(input())

a1 = a // 10
a2 = a % 10

b1 = b // 10
b2 = b % 10

ma = max(a1, a2, b1, b2)
mi = min(a1, a2, b1, b2)
s = (a1 + a2 + b1 + b2 - ma - mi) % 10
n = ma * 100 + s * 10 + mi
print(n)