# -*- coding: utf-8 -*-

for i in range(int(input())):
    x, y = [int(i) for i in input().split()]
    
    if x > y:
        x, y = y, x
    
    x += 1 if x % 2 == 0 else 2
    y -= 1 if y % 2 == 0 else 2
    
    if x <= y:
        soma = (x + y) * ((y - x + 2) // 2) // 2   
    else:
        soma = 0
    print(soma)
    
# for i in range(int(input())):
#     x, y = [int(i) for i in input().split()]
    
#     if x > y:
#         x, y = y, x
    
#     soma = 0
#     for j in range (x + 1, y):
#         if (j % 2 == 1):
#             soma += j
#     print(soma)
