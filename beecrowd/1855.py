import sys

sys.setrecursionlimit(10000)

def main():
    largura = int(input())
    altura = int(input())

    mapa = []
    visitados = []
    baus = []

    for i in range(altura):
        linha = input()
        linhavis = [False] * largura
        visitados.append(linhavis)
        mapa.append(linha)
        if '*' in linha:
            posBauX = linha.index('*')
            posBauY = i
            baus.append([posBauX, posBauY])


    x, y = 0,0

    if mapa[y][x] == "^":
        direction = 0
    elif mapa[y][x] == ">":
        direction = 1
    elif mapa[y][x] == "<":
        direction = 3
    else:
        direction = 2

    dfs(visitados, mapa, largura, altura, x, y, direction)


    num_bau = len(baus)
    achado = False
    print(baus)
    for coord in range(num_bau):
        if visitados[baus[coord][1]][baus[coord][0]]:
            achado = True
            break 

    if achado:
        print("*")
    else:
        print("!")
    


# Direction = cima, direita, baixo, esquerda de 0 a 3
def dfs(visitados, mapa, largura, altura, x, y, direction):
    if x == -1 or x == largura or y == -1 or y == altura:
        return
    elif visitados[y][x] and mapa[y][x] not in ".*":
        return

    visitados[y][x] = True

    if mapa[y][x] == "^":
        direction = 0
    elif mapa[y][x] == ">":
        direction = 1
    elif mapa[y][x] == "<":
        direction = 3
    elif mapa[y][x] != "." and mapa[y][x] != "*":
        direction = 2

    if direction == 0:
        y -= 1
    elif direction == 1:
        x += 1
    elif direction == 2:
        y += 1
    else:
        x -= 1

    dfs(visitados, mapa, largura, altura, x, y, direction)

    return



main()