from math import gcd

n = int(input())

val = 1
for i in range(n):
    a,b = map(int, input().split())
    div = gcd(a,b)

    a//=div
    b//=div

    val = (val * (b // gcd(val, b))) %  998244353

print(val)
