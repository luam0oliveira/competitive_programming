# -*- coding: utf-8 -*-

while True:
    v, n, m = input().split()
    v = float(v)

    if n == m == "0" and v == 0.0:
        break
    tamM = len(m)
    ms, ns = False, False
    tamN = len(n)

    for i in [4,3,2,1]:
        if tamM >= i and not ms:
            m = "0" * (4 - i) + m[-i:]
            ms = True

        if tamN >= i and not ns:
            n = "0" * (4 - i) + n[-i:]
            ns = True

    valor = 0

    if m == n:
        valor = v * 3000
    elif m[1:] == n[1:]:
        valor = v * 500
    elif m[2:] == n[2:]:
        valor = v * 50
    else:
        bichoM = (int(m[2:]) - 1) // 4
        bichoN = (int(n[2:]) - 1) // 4
        if bichoM == bichoN:
            valor = v * 16

    print("%.2f" % valor)
