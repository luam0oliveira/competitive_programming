def tirarPilha(lista):
    return lista.pop()


def tirarFila(lista):
    return lista.pop(0)


def tirarPrioridade(lista):
    maior = max(lista)
    lista.remove(maior)
    return maior

def addElement(lista, elemento):
    lista.append(elemento)


while True:
    try:
        ops = int(input())

        fila = []
        pilha = []
        prioridade = []
        pos = [1]*3 #pilha, fila, prioridade

        for i in range(ops):
            op, elemento = list(map(int, input().split()))

            if op == 1:
                addElement(fila, elemento)
                addElement(pilha, elemento)
                addElement(prioridade, elemento)
            else:
                outPilha = tirarPilha(pilha)
                outFila = tirarFila(fila)
                outPrioridade = tirarPrioridade(prioridade)

                if outPilha != elemento:
                    pos[0] = 0

                if outFila != elemento:
                    pos[1] = 0

                if outPrioridade != elemento:
                    pos[2] = 0

        quant = pos.count(1)

        if quant == 0:
            print("impossible")
        elif quant == 1:
            if pos[0] == 1:
                print("stack")
            elif pos[1] == 1:
                print("queue")
            else:
                print("priority queue")
        else:
            print("not sure")

    except:
        break