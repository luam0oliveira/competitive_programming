from sys import stdin, stdout
input, print = stdin.readline, stdout.write

def main():
    num_estrelas = int(input())
    estrelas = list(map(int, input().split()))
    ovelhas = sum(estrelas);
    pos = maior_pos = 0
    while 0 <= pos < num_estrelas:
        par = estrelas[pos] % 2 == 0
        if estrelas[pos] != 0:
            estrelas[pos] -= 1
            ovelhas -= 1
        if maior_pos < pos:
            maior_pos = pos
        if par:
            pos -= 1
        else:
            pos += 1

    print(str(maior_pos+1) +' '+ str(ovelhas) + '\n')
if __name__ == "__main__":
    main()