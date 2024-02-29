import sys
from collections import deque
sys.setrecursionlimit(10000)

class node:
    def __init__(self, number):
        self.number = number
        self.rel = []
        self.visited = False
    
    def add_node(self, node):
        self.rel.append(node)

    def __str__(self):
        return str(self.number) + str(self.visited)

def dfs(node, prev, prof, stack):
    if node.rel and not stack[node.number]:
        stack[node.number] = True
        for i in node.rel:
            print(" "*(prof*2), end="")
            if i.visited:
                print(f"{node.number}-{i.number}")
            else:
                print(f"{node.number}-{i.number} pathR(G,{i.number})")
                i.visited = True
                node.visited = True
                dfs(i, node.number, prof+1, stack)
    stack[node.number] = False

def main():
    cases = int(input())
    cont = 1
    
    while cases >= cont:
        v, e = map(int, input().split())
        
        grap = []

        for i in range(v):
            n = node(i)
            grap.append(n)

        for _ in range(e):
            orig, cheg = map(int, input().split())
            grap[orig].add_node(grap[cheg])

        for _ in range(v):
            grap[_].rel.sort(key=lambda x: x.number)

        stack = [False] * v
        print(f"Caso {cont}:")
        for i in grap:
            if not i.visited and i.rel:
                dfs(i, -1, 1, stack)
                print()
        cont+=1
        
main()
