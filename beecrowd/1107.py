while True:
    altura, largura = list(map(int, input().split()))
    if altura == largura == 0:
        break
    alturas = list(map(int, input().split()))

    total = altura - alturas[0]
    for i in range(1, largura):
        if alturas[i-1] > alturas[i]:
            total += alturas[i-1] - alturas[i]

    print(total)