a1 = int(input())
a2 = int(input())
a3 = int(input())

total1 = a3 * 4 + a2 * 2
total2 = a1 * 2 + a3 * 2
total3 = a1 * 4 + a2 * 2

if total1 <= total2 and total1 <= total3:
    print(total1)
elif total2 <= total1 and total2 <= total3:
    print(total2)
else:
    print(total3)