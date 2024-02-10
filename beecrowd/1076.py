import sys
sys.setrecursionlimit(100000)

# Most correct form
def dfs(node, caminhos, visitados):
    if visitados[node]:
        return 0
    elif not caminhos[node]:
        visitados[node] = True
        return 2
    
    i = 2

    visitados[node] = True
    while caminhos[node]:
        paths = dfs(caminhos[node][0], caminhos, visitados)
        i += paths
        caminhos[node].pop(0)
    return i

def main():
    cases = int(input())
    for case in range(cases):
        inicio = int(input())

        num_nodes, num_caminhos = list(map(int, input().split()))

        visitados = [False] * num_nodes
        caminhos = []

        for i in range(num_nodes):
            caminhos.append([])

        for i in range(num_caminhos):
            orig, dest = list(map(int, input().split()))
            caminhos[orig].append(dest)
            caminhos[dest].append(orig)

        print(dfs(inicio, caminhos, visitados) - 2)


# Alternative form, the problem don't force to use graphs to resolve'
def main1():
    cases = int(input())
    for case in range(cases):
        inicio = int(input())

        num_nodes, num_caminhos = list(map(int, input().split()))

        caminhos = []

        for i in range(num_nodes):
            rel = [0] * num_nodes
            caminhos.append(rel)
        cont = 0
        for i in range(num_caminhos):
            x,y = list(map(int, input().split()))
            if caminhos[y][x] == 0 and caminhos[x][y] != 1:
                caminhos[x][y] = 1
                cont+=1

        print(cont*2)

main()
