# Basicamente criar uma matrix com diagonal principal com 1, secundaria com 2
# e o restante 3 (diagonal seundaria tem prioridade sobre a primeira)

while True:
    try:
        pass
        n = int(input())
        matrix = []
        for i in range(n):
            linha = []
            for j in range(n):
                valor = 3

                if i + j == n - 1:
                    valor = 2
                elif i == j:
                    valor = 1
                linha.append(valor)
            matrix.append(linha)
        for i in range(n):
            print(*matrix[i], sep="")
    except:
        break
