# -*- coding: utf-8 -*-

n1 = input()
n2 = input()
n3 = input()

if n1 == "vertebrado":
    if n2 == "ave":
        if n3 == "carnivoro":
            print("aguia")
        else:
            print("pomba")
    else:
        if n3 == "onivoro":
            print("homem")
        else:
            print("vaca")
else:
    if n2 == "inseto":
        if n3 == "hematofago":
            print("pulga")
        else:
            print("lagarta")
    else:
        if n3 == "hematofago":
            print("sanguessuga")
        else:
            print("minhoca")
