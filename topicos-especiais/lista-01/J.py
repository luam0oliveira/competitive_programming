cases = int(input())
cont = 1
def getNumber(card):
    try:
        num = int(card[0])
        return num
    except:
        return 10


while cases:
    pile = []
    cards = input().split()
    for i in range(27):
        pile.append(cards[i])
    
    y = 0
    for i in range(3):
        x = getNumber(pile.pop())
        y += x
        for _ in range(10 - x):
            pile.pop()

    pile = pile + cards[28:]
    print("Case %d: %s"%(cont,pile[y-2]))
    cont += 1
    cases -= 1