from math import factorial


cases = int(input())

while (cases):
    n, m = map(int, input().split())

    ls = n - m * 2
    l = ls + m

    d = (factorial(l) * 2**(m))//factorial(ls)
    print(d % 1300031)
    cases -= 1