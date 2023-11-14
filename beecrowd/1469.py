# -*- coding: utf-8 -*-

import sys
sys.setrecursionlimit(10 ** 8)

class Node:
    def __init__(self, idade, pos, tras=None):
        self.idade = idade
        self.tras = tras
        self.pos = pos

    def __repr__(self):
        return f"<NODE idade={self.idade} tras={self.tras} pos={self.pos} NODE/>"

    def __str__(self):
        return self.__repr__()

def main():
    while(True):
        try:
            n, m, o = [int(i) for i in input().split()]

            idades = [int(i) for i in input().split()]

            relacoes = []

            for i in range(n):
                node = Node(idades[i], i, [])
                relacoes.append(node)
            
            for i in range(m):
                part, cheg = [int(j) - 1 for j in input().split()]
                relacoes[cheg].tras.append(relacoes[part])

            for i in range(o):
                inp = input().split()
                if inp[0] == 'P':
                    alvo = int(inp[1]) - 1
                    menorIdade = pergunta(relacoes[alvo], 101, [0] * n)
                    if menorIdade == 101:
                        print("*")
                    else:
                        print(menorIdade)
                
                else:
                    a1 = int(inp[1]) - 1
                    a2 = int(inp[2]) - 1
                    relacoes[a1], relacoes[a2] = relacoes[a2], relacoes[a1]
                    relacoes[a1].idade, relacoes[a2].idade = relacoes[a2].idade, relacoes[a1].idade
        except:
            break

def pergunta(alvo, menorIdade, visitados):
    visitados[alvo.pos] = 1
    for t in alvo.tras:
        if visitados[t.pos] == 0:
            menorIdade = min(t.idade, pergunta(t, menorIdade, visitados))
    
    return menorIdade

main()