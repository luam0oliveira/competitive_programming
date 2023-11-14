# -*- coding: utf-8 -*-

while True:
    try:
        alunos = int(input())

        dados = {
            "EPR": 0,
            "EHD": 0,
            "INTRUSOS": 0
        }
        for i in range(alunos):
            matricula, curso = input().split()
            if curso in ["EPR", "EHD"]:
                dados[curso] += 1
            else: dados["INTRUSOS"] += 1
        
        print("EPR: %d" %(dados["EPR"]))
        print("EHD: %d" %(dados["EHD"]))
        print("INTRUSOS: %d" %(dados["INTRUSOS"]))
    except:
        break;
