while True:
    try:
        m, d = [int(i) for i in input().split()]
        td = 360 - d
        for i in range(1, m):
            if i % 2 == 1 and i != 9 and i != 11 or i == 8 or i == 10:
                td -= 31
            elif i % 2 == 0 and i == 2:
                td -= 29
            else:
                td -= 30
        if td == 1:
            print("E vespera de natal!")
        elif td == 0:
            print("E natal!")
        elif td < 0:
            print("Ja passou!")
        else:
            print("Faltam %d dias para o natal!" % td)
    except:
        break
