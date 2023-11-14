# -*- coding: utf-8 -*-

while True:
    a, b = input().split()
    
    if (a == "0" and b == "0"):
        break
    
    if int(a) < int(b):
        a, b = b, a

    carry = 0
    sum = 0
    
    for i in range(len(a)):
        digitB = 0
        digitSum = 0
        
        if len(b) >= i + 1:
            digitB = int(b[-(i + 1)])
            
        if len(str(sum)) >= i + 1:
            digitSum = int(str(sum)[-(i+1)])
        
        if digitB + int(a[-(i + 1)]) + digitSum > 9:
            carry += 1
        
        sum += int(digitB + int(a[-(i+1)])) * 10 ** i
    
  
    print("No carry operation." if carry == 0 else "%d carry operation." % carry if carry == 1 else "%d carry operations." % carry)
