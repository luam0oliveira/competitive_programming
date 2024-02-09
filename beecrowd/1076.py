def main():
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
