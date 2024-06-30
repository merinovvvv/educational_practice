str_1 = input()
str_2 = input()
str_3 = input()

bool_str_1 = False
bool_str_2 = False
bool_str_3 = False

if "зайка" in str_1:
    bool_str_1 = True

if "зайка" in str_2:
    bool_str_2 = True

if "зайка" in str_3:
    bool_str_3 = True

if bool_str_1 and bool_str_2 and bool_str_3:
    if str_1 < str_2 < str_3 or str_1 < str_3 < str_2:
        print(str_1, len(str_1))
    elif str_2 < str_1 < str_3 or str_2 < str_3 < str_1:
        print(str_2, len(str_2))
    elif str_3 < str_1 < str_2 or str_3 < str_2 < str_1:
        print(str_3, len(str_3))

elif bool_str_1 and bool_str_2:
    if str_1 < str_2:
        print(str_1, len(str_1))
    elif str_2 < str_1:
        print(str_2, len(str_2))

elif bool_str_1 and bool_str_3:
    if str_1 < str_3:
        print(str_1, len(str_1))
    elif str_3 < str_1:
        print(str_3, len(str_3))

elif bool_str_2 and bool_str_3:
    if str_2 < str_3:
        print(str_2, len(str_2))
    elif str_3 < str_2:
        print(str_3, len(str_3))
    
elif bool_str_1:
    print(str_1, len(str_1))

elif bool_str_2:
    print(str_2, len(str_2))

elif bool_str_3:
    print(str_3, len(str_3))