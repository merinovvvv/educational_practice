elf_num = int(input())
dwarf_num = int(input())
man_num = int(input())

if elf_num // 10 == dwarf_num // 10 == man_num // 10:
    print(elf_num // 10)
elif elf_num % 10 == dwarf_num % 10 == man_num % 10:
    print(elf_num % 10)