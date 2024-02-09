alfa = {
    "*.....": 1,
    "*.*...": 2,
    "**....": 3,
    "**.*..": 4,
    "*..*..": 5,
    "***...": 6,
    "****..": 7,
    "*.**..": 8,
    ".**...": 9,
    ".***..": 0,
    "0": ".***..",
    "9": ".**...",
    "8": "*.**..",
    "7": "****..",
    "6": "***...",
    "5": "*..*..",
    "4": "**.*..",
    "3": "**....",
    "2": "*.*...",
    "1": "*.....",
}


def main():
    while True:
        d = int(input())
        if d == 0: break
        op = input()

        if op == 'S':
            string = input()
            code(string)

        else:
            partes = []
            for i in range(3):
                partes.append(input().split())
            string = []

            for i in range(d):
                string.append(partes[0][i] + partes[1][i] + partes[2][i])

            decode(string)




def code(string):
    tam = len(string)
    for i in range(3):
        inicio = i * 2
        fim = i * 2 + 2
        print(alfa[string[0]][inicio:fim], end = "")
        for j in range(1,tam):
            print(" ", end="")
            print(alfa[string[j]][inicio:fim], end = "")
        print()

def decode(string):
    tam = len(string)
    for i in range(tam):
        print(alfa[string[i]], end="")
    print()

main()