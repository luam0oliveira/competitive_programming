# -*- coding: utf-8 -*-

ax, ay = [int(i) for i in input().split()]
bx, by = [int(i) for i in input().split()]
cx, cy = [int(i) for i in input().split()]

a = (not (bx + cx > ax) and by <= ay and cy <= ay) or (not (bx + cx > ay) and by <= ax and cy <= ax)
b = (not (bx + cy > ax) and by <= ay and cx <= ay) or (not (bx + cy > ay) and by <= ax and cx <= ax) 
c = (not (by + cx > ax) and bx <= ay and cy <= ay) or (not (by + cx > ay) and bx <= ax and cy <= ax)
d = (not (by + cy > ax) and bx <= ay and cx <= ay) or (not (by + cy > ay) and bx <= ax and cx <= ax)


if a or b or c or d:
    print("S")
else:
    print("N")
