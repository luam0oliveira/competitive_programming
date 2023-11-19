# -*- coding: utf-8 -*-

def main():
    cases = 1
    while True:
        try:
            tam = int(input())
            menor = float("inf")
            alunos = []
            
            for _ in range(tam):
                nome, nota = input().split()
                nota = int(nota)

                if menor == nota:
                    alunos.append(nome)

                elif menor > nota:
                    alunos = [nome]
                    menor = nota
                    
            alunos.sort()

            print("Instancia %d" %cases)
            print(alunos[len(alunos) - 1])

            print()
            cases += 1
        except:
            break

if __name__ == "__main__":
    main()
