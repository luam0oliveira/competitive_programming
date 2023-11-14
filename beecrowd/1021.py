# -*- coding: utf-8 -*-

m = float(input())

m *= 100

n100 = m // 10000
m -= n100 * 10000

n50 = m // 5000
m -= n50 * 5000

n20 = m // 2000
m -= n20 * 2000

n10 = m // 1000
m -= n10 * 1000

n5 = m // 500
m -= n5 * 500

n2 = m // 200
m -= n2 * 200

m100 = m // 100
m -= m100 * 100

m50 = m // 50
m -= m50 * 50

m25 = m // 25
m -= m25 * 25

m10 = m // 10
m -= m10 * 10

m5 = m // 5
m -= m5 * 5

m1 = m

print("NOTAS:")
print("%d nota(s) de R$ 100.00" % n100)
print("%d nota(s) de R$ 50.00" % n50)
print("%d nota(s) de R$ 20.00" % n20)
print("%d nota(s) de R$ 10.00" % n10)
print("%d nota(s) de R$ 5.00" % n5)
print("%d nota(s) de R$ 2.00" % n2)
print("MOEDAS:")
print("%d moeda(s) de R$ 1.00" % m100)
print("%d moeda(s) de R$ 0.50" % m50)
print("%d moeda(s) de R$ 0.25" % m25)
print("%d moeda(s) de R$ 0.10" % m10)
print("%d moeda(s) de R$ 0.05" % m5)
print("%d moeda(s) de R$ 0.01" % m1)
