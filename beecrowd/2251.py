# -*- coding: utf-8 -*-

class Node:
    def __init__(self, prox = None, tam = 0):
        self.prox = prox
        self.tam = tam
    
    def __str__(self) -> str:
        return str(self.tam)

class Pilha:
    def __init__(self, topo = None) -> None:
        self.topo = None

    def mover(self):
        self.topo = self.topo.prox
    
    def adicionar(self, node):
        node.prox = self.topo
        self.topo = node

def main():
    cases = 1
    while True:
        nm = int(input())
        if nm == 0:
            break
        
        cont = 2 ** nm - 1
        # orig = Pilha()
        # dest = Pilha()
        # temp = Pilha()
        
        # for i in range(nm):
        #     node = Node(None, nm - i)
        #     orig.adicionar(node)
        
        # hanoi(nm, orig, dest, temp)
        print("Teste %d" %cases)
        print(cont)
        print()

        cases += 1

# def hanoi(n, orig, dest, temp):
#     global cont
#     cont += 1

#     if n == 1:
#         node = orig.topo
#         orig.mover()
#         dest.adicionar(node)
#     else:
#         hanoi(n-1, orig,temp,dest)
#         node = orig.topo
#         orig.mover()
#         dest.adicionar(node)
#         hanoi(n-1,temp,dest,orig)
main()