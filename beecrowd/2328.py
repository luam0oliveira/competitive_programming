# -*- coding: utf-8 -*-

directions = [(-1,0,1,1), (0,1,1,-1),(1,0,-1,-1), (0,-1,-1,1)]

def mark(x, y, d, ilha):
    tam = len(ilha)
    for i in range(4):
        for j in range(d):
            new_x = x + (d * directions[i][0]) + (j * directions[i][2])
            new_y = y + (d * directions[i][1]) + (j * directions[i][3])
            if new_x >= 0 and new_x < tam and new_y >= 0 and new_y < tam:
                ilha[new_y][new_x] += 1


def main():
    n, k = [int(i) for i in input().split()]

    ilha = []

    for i in range(n):
        ilha.append([0] * n)
    
    for _ in range(k):
        x, y, d = [int(i) for i in input().split()]

        mark(x, y, d, ilha)

    contn = 0
    pos = [-1,-1]
    for i in range(n):
        for j in range(n):
            if ilha[i][j] == k:
                if contn == 1:
                    pos = [-1,-1]
                    break 

                contn = 1
                pos = [j,i]

    print(*pos)


if __name__ == "__main__":
    main()
