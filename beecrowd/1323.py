# -*- coding: utf-8 -*-

inp = "1"

while inp != "0":
    qua = 0
    inp = input()
    for i in range(int(inp)):
        qua += (i + 1) ** 2
    if inp != "0": print(qua)
