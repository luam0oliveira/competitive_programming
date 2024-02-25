import sys
sys.setrecursionlimit(10000)

def dfs(node, rel, visitados, atual):
    atual[node] = True
    visitados[node] = True
    temLoop = False
    if rel[node]:
        for con in rel[node]:
            if not visitados[con]:
                temLoop = dfs(con, rel, visitados, atual)
            elif atual[con]:
                temLoop = True
            if temLoop:
                break

    atual[node] = False
    return temLoop


def main():
    cases = int(input())

    while cases:
        n, m = map(int, input().split())

        visitados = [False] * (n+1)

        dependencias = []
        for i in range(n+1):
            dependencias.append([])

        for i in range(m):
            orig, depen = map(int,input().split())
            dependencias[orig].append(depen)

        temLoop = False
        atual = [False] * (n+1)
        for documento in range(1,n+1):
            if not visitados[documento]:
                temLoop = dfs(documento, dependencias, visitados, atual)
            if temLoop:
                break
        if temLoop:
            print("SIM")
        else:
            print("NAO")
        cases -= 1

main()