n = int(input())

fila = []
for i in range(n):
    t, d = map(int, input().split())
    fila.append((t,d))

fila.sort()

UltimaPessoa = [None, None]
direcaoAtual = fila[0][1]
tempoAtual = 0

while len(fila) > 0 or UltimaPessoa[0] or UltimaPessoa[1]:
    while len(fila) > 0 and (fila[0][0] <= tempoAtual or (not UltimaPessoa[0] and not UltimaPessoa[1])):
        tempo, direcao = pessoa =  fila.pop(0)
        if not UltimaPessoa[0] and not UltimaPessoa[1] and tempo > tempoAtual:
            tempoAtual = tempo
        UltimaPessoa[direcao] = pessoa
    
    if UltimaPessoa[direcaoAtual]:
        tempo, direcao = UltimaPessoa[direcaoAtual]
        tempoAtual = tempo + 10
        UltimaPessoa[direcaoAtual] = None
    else:
        direcaoAtual = (direcaoAtual + 1) % 2 
        tempo, direcao = UltimaPessoa[direcaoAtual]
        tempoAtual += 10
        UltimaPessoa[direcaoAtual] = None

print(tempoAtual)