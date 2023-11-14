# -*- coding: utf-8 -*-

for i in range(int(input())):
    x, y = [int(j) for j in input().split()]
    r = (3 * x) ** 2 + y ** 2;
    b = 2 * (x**2 ) + (5*y)**2;
    c = -100*x + y**3;
    
    if r > b and b > c or r > c and c > b:
        print("Rafael ganhou")
    elif b > r and r > c or b > c and c > r:
        print("Beto ganhou")
    else:
        print("Carlos ganhou")
