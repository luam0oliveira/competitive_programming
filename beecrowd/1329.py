# -*- coding: utf-8 -*-

while True:
    n = int(input())
    
    if n == 0:
        break
    
    mary = 0
    john = 0
    for i in [int(i) for i in input().split()]:
        if i == 0:
            mary += 1
        else:
            john += 1
    
    print("Mary won %d times and John won %d times" % (mary, john))
