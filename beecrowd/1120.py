# -*- coding: utf-8 -*-

while True:
    dig, num = input().split()
    
    if dig == num == '0':
        break
    num = list(num)
    
    new_num = []
    for i in num:
        if dig != i:
            new_num.append(i)
    
    if len(new_num) == 0:
        new_num = ["0"]
    
    new_num = int("".join(new_num))
    
    print(new_num)
