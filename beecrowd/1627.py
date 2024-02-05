cases = int(input())

for i in range(cases):
    at,ad,bt,bd = list(map(int,input().split()))
    life = int(input())
    ta = tb = 0;
    while True:
        if ta <= tb:
            life -= at
            ta += ad
            if life <= 0:
                print("Andre")
                break
        else:
            life -= bt
            tb += bd
            if life <= 0:
                print("Beto")
                break