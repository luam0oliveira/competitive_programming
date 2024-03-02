import sys 
from collections import deque
sys.setrecursionlimit(10000)
input, print = sys.stdin.readline, sys.stdout.write

class node:
    def __init__(self, number):
        self.number = number
        self.rel = []
        self.visited = False

def bfs(node, maxprof, convidad):
    fila = deque([[node, 0]])

    while fila:
        act = fila.popleft()
        for i in act[0].rel:
            if not i.visited and act[1] < maxprof:
                convidad[i.number] = 1
                i.visited = True
                fila.append([i, act[1] + 1])

def main():
    n,g = map(int, input().split())
    
    rel = {}

    while n:
        part, cheg = input().split()

        if part not in rel:
            rel[part] = node(part)

        if cheg not in rel:
            rel[cheg] = node(cheg)


        rel[part].rel.append(rel[cheg])
        rel[cheg].rel.append(rel[part])
        n-=1
    
    convidad = {}
    rel["Rerisson"].visited = True
    bfs(rel["Rerisson"], g, convidad)
    convidad = list(convidad)
    print(str(len(convidad)) + "\n")
    convidad.sort()
    for i in convidad:
        print(i + "\n")
            
main()