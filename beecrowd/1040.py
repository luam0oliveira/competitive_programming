# -*- coding: utf-8 -*-

n1, n2, n3, n4 = [float(i) for i in input().split()]
m = (n1 * 2 + n2 * 3 + n3 * 4 + n4) / 10

print("Media: %.1f" % m)

if m >= 7:
    print("Aluno aprovado.")
elif m >= 5:
    print("Aluno em exame.")
    e = float(input())
    print("Nota do exame: %.1f" % e)
    m = (m + e) / 2
    if m >= 5:
        print("Aluno aprovado.")
    else:
        print("Aluno reprovado.")
    print("Media final: %.1f" % m)
else:
    print("Aluno reprovado.")