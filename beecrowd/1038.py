# -*- coding: utf-8 -*-

cd, qt = [int(i) for i in input().split()]
total = 0

if cd == 1:
    total = qt * 4.0
elif cd == 2:
    total = qt * 4.5
elif cd == 3:
    total = qt * 5.0
elif cd == 4:
    total = qt * 2.0
else:
    total = qt * 1.5

print("Total: R$ %.2f" % total)