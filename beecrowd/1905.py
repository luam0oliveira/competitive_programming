# -*- coding: utf-8 -*-

def main():
    n = int(input())
    for _ in range(n):
        sc = ""

        while len(sc) == 0:
            sc = input().strip()
        global visitados
        visitados = [[0] * 7]
        matrix = [[1] * 7]

        for i in range(5):
            line = [1]
            linha_visitados = [0] * 7
            visitados.append(linha_visitados)            
            line.extend([int(j) for j in sc.split()])
            line.append(1)
            matrix.append(line)
            if i != 4:
                sc = input()
        
        visitados.append([0] * 7)
        matrix.append([1] * 7)

        if matrix[5][5] != 1:
            dfs(matrix, (5,5))
        
        if visitados[1][1] == 1:
            print("COPS")
        else:
            print("ROBBERS")

visitados = []
vizinhos = [(0,1), (1,0), (0,-1), (-1,0)]

def dfs(matrix, coord):
    x,y = coord
    global visitados
    visitados[x][y] = 1
    for i in range(len(vizinhos)):
        coord_x, coord_y =  vizinhos[i] 

        if visitados[x+coord_x][y+coord_y] == 0 and matrix[coord_x + x][coord_y + y] == 0:
            dfs(matrix, (x + coord_x, y + coord_y))

if __name__ == "__main__":
    main()