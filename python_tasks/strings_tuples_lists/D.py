list = []
while (str := input()) != "":
    sub_str = str
    if str.endswith("@@@"):
        continue
    elif str.startswith("##"):
        sub_str = ""
        for i in range(2, len(str)):
            sub_str += str[i]
    list.append(sub_str)
for i in range(len(list)):
    print(list[i])
