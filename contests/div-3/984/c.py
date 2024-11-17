t=int(input())
for _ in range(t):
    s = list(input())
    n = int(input())
    for __ in range(n):
        a,b = input().split()
        a = int(a)
        # s = list(s)
        s[a-1] = b
        if ("".join(s).__contains__("1100")):
            print("Yes")
        else:
            print("No")
    