# -*- coding: utf-8 -*-

string = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./"

inpt = ""
while True:
    try:
        inpt += input().upper() + "\n"
    except:
        break
    

new_inpt = []
    
for i in inpt:
    if i == " ":
        new_inpt.append(" ")
        continue
    elif i == "\n":
        new_inpt.append("\n")
        continue
    index = string.index(i)
    new_inpt.append(string[index - 1])

new_inpt = "".join(new_inpt)

print(new_inpt, end="")
