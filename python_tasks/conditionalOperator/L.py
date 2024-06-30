len_1 = int(input())
len_2 = int(input())
len_3 = int(input())

if len_1 + len_2 > len_3 and len_1 + len_3 > len_2 and len_3 + len_2 > len_1:
    print("YES")
else:
    print("NO")