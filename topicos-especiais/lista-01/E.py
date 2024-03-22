def generateCode(string):
    newString = ""

    for i in string:
        if i != " ":
            newString += i
    newString = list(newString)
    newString.sort()

    return "".join(newString)

def displayList(palavras):
    lista = []

    for key in palavras:
        palavras[key].sort()
        tam = len(palavras[key])
        for j in range(tam):
            for k in range(j+1, tam):
                lista.append(palavras[key][j] + " = " + palavras[key][k])

    lista.sort()

    print(*lista, sep="\n")

cases = int(input())

inp = input()
while cases:
    palavras = {}
    possui = False
    while True:
        try:
            inp = input().replace('\r','')
            if inp.strip() == "":
                raise Exception("")
        except Exception as e:
            break
        
        coded = generateCode(inp.strip())
        
        if palavras.get(coded):
            palavras[coded].append(inp)
            possui = True
        else:
            palavras[coded] = [inp]
    if possui:
        displayList(palavras)
    cases -= 1
    
    if cases:
        print()
    