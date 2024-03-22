from functools import reduce

rounds = int(input())

cards = [4] * 14

a,b = map(int,input().split())
cards[a] -=1
cards[b] -=1
j = min(a,10)+min(b,10)

a,b = map(int,input().split())
cards[a] -=1
cards[b] -=1
m = min(a,10)+min(b,10)

c = 0
cmm = list(map(int,input().split()))
for i in range(rounds):
    cards[cmm[i]] -= 1
    c += min(cmm[i], 10)

m += c
j += c

mGanhar = 23 - m
jPerder = 24 - j
ganha = False
cont = 1
while cont <= 13:
    valor = min(10, cont)
    if ((valor == mGanhar) or (jPerder <= valor and valor <= mGanhar)) and cards[cont] > 0:
        ganha = True
        break
    cont +=1

if ganha:
    print(cont)
else:
    print(-1)