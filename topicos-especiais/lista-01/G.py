import sys
input = sys.stdin.readline
print = sys.stdout.write

result = {
    ("paper", "rock"): 1,
    ("rock", "paper"): 2,
    ("scissors", "rock"): 2,
    ("rock", "scissors"): 1,
    ("scissors", "paper"): 1,
    ("paper", "scissors"): 2
}

first = True
while True:
    inp = input()
    if inp.strip() == "0":
        break
    elif not first:
        print("\n")
    jog, part = map(int, inp.split())
    first = False
    num_jogos = part*jog*(jog-1) // 2

    # jogos ganhos
    ganhas = [0] * jog
    # partidas jogadas
    partidas = [0] * jog

    for i in range(num_jogos):
        p1, m1, p2, m2 = input().split()
        p1, p2 = int(p1), int(p2)
        hr = False
        if result.get((m1,m2)) == 1:
            ganhas[p1-1] += 1
            hr = True
        elif result.get((m1,m2)) == 2:
            ganhas[p2-1] += 1
            hr = True
        
        if hr:
            partidas[p1-1] += 1 
            partidas[p2-1] += 1 

    for i in range(jog):
        if partidas[i] != 0:
            print("{:.3f}\n".format((ganhas[i]/partidas[i])))
        else:
            print("-\n")
